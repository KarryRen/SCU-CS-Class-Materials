#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include "job.h"

int jobid = 0;
int siginfo = 1;
int fifo;
int globalfd;

struct waitqueue *head = NULL;
struct waitqueue *next = NULL, *current = NULL;

void schedule()  {
/*函数功能：调度函数 从 FIFO 中读取到执行的命令|和|执行的作业（enq 需要）*/
	struct jobinfo *newjob = NULL;
	struct jobcmd cmd;
	int count = 0;
	
	bzero(&cmd, DATALEN);
	if ((count = read(fifo, &cmd, DATALEN)) < 0) // 读取管道内部的信息（从另外的终端中输入的）
		error_sys("read fifo failed");
	
// #ifdef DEBUG
	// if (count) {
	// 	printf("cmd cmdtype\t%d\n"
	// 		"cmd defpri\t%d\n"
	// 		"cmd data\t%s\n",
	// 		cmd.type, cmd.defpri, cmd.data);
	// }// else
	 //	printf("no data read\n");
// #endif
	
	// 识别 type 并执行
	switch (cmd.type) {
		case ENQ:
			do_enq(newjob,cmd);
			break;
		case DEQ:
			do_deq(cmd);
			break;
		case STAT:
			do_stat(cmd);
			break;
		default:
			// error_sys("no such a cmd!");
			break;
	}

	/* 更新等待序列中的作业 */
	updateall();
	
	/* 选出具有最高优先级的作业 */
	next = jobselect();
	
	/* 停下来当前的作业，进行队列中的下一个作业 */
	jobswitch();
}

int allocjid() {
	return ++jobid;
}

void updateall() {
/*函数功能：更新等待和正在执行的作业等待时间以及优先级*/
	struct waitqueue *p;
	
	/* 更新作业的运行时间 */
	if (current)
		current->job->run_time += 1;    /* add 1 represent 100 ms */
	
	/* 更新等待队列中的作业等待时间 */
	for (p = head; p != NULL; p = p->next) {
		p->job->wait_time += 100;

		if (p->job->wait_time >= 1000 && p->job->curpri < 3)
			p->job->curpri++;
	}
}

struct waitqueue* jobselect() {
/* 调整作业队列 <核心更改的地方> */
	struct waitqueue *p, *prev, *select, *selectprev;
	int highest = -1;
	int choice = 3; // 设置作业规划方式

	select = NULL;
	selectprev = NULL;

	
	if(choice == 0) { // 最高优先级优先（优先级会动态变化）
		if (head) {
			for (prev = head, p = head; p != NULL; prev = p, p = p->next) {
				if (p->job->curpri > highest) {
					select = p;
					selectprev = prev;
					highest = p->job->curpri;
				}
			}		   
			selectprev->next = select->next;

			if (select == selectprev) head = NULL;
		}
	} else if (choice == 1){  // 先到先服务 按照 jobid 来排序
		int curjid  = 1e5;
		if (head) {
			for (prev = head, p = head; p != NULL; prev = p, p = p->next) {
				if (p->job->jid < curjid) {
					select = p;
					selectprev = prev;
					curjid = p->job->jid;
				}
			}		   
			selectprev->next = select->next;

			if (select == selectprev) head = NULL;
		}
	} else if (choice == 2){  // 短作业优先
		int curtime  = 1e5;
		if (head) {
			for (prev = head, p = head; p != NULL; prev = p, p = p->next) {
				if (p->job->deftime < curtime) {
					select = p;
					selectprev = prev;
					curtime = p->job->deftime;
				}
			}		   
			selectprev->next = select->next;

			if (select == selectprev) head = NULL;
		}
	} else if (choice == 3){  // 高响应比优先
		int curCR  = 0;
		if (head) {
			for (prev = head, p = head; p != NULL; prev = p, p = p->next) {
				int jobCR = p->job->wait_time/p->job->deftime;
				if (jobCR > curCR) {
					select = p;
					selectprev = prev;
					curCR = jobCR;
				}
			}		   
			selectprev->next = select->next;

			if (select == selectprev) head = NULL;
		}
	}
	
	return select;
}

void jobswitch() {
/* 选择要执行的作业 */
	struct waitqueue *p;
	int i;
	
	if (current && current->job->state == DONE) {           
		// 当前的作业已经执行完毕 free 掉它就可以了
		for (i = 0; (current->job->cmdarg)[i] != NULL; i++) {
			free((current->job->cmdarg)[i]);
			(current->job->cmdarg)[i] = NULL;
		}

		free(current->job->cmdarg);
		free(current->job);
		free(current);
		
		current = NULL;
	}
	
	if (next == NULL && current == NULL)
		// 没有作业了
		return;
	else if (next != NULL && current == NULL) {
		// 有下一个作业，当前作业执行完毕了
	    printf("begin start new job\n");
		current = next;
		next = NULL;
		current->job->state = RUNNING;
		kill(current->job->pid, SIGCONT);
		return;
	} else if (next != NULL && current != NULL) { 
		// 现在在执行一个作业 同时还有一个作业在等待 （现在就需要选择了）
		kill(current->job->pid, SIGSTOP);
		current->job->curpri = current->job->defpri;
		current->job->wait_time = 0;
		current->job->state = READY;
		
		/* 放回队列 */
		if (head) {
			for (p = head; p->next != NULL; p = p->next);
			p->next = current;
		} else {
			head = current;
		}
		
		current = next;
		next = NULL;
		current->job->state = RUNNING;
		kill(current->job->pid, SIGCONT);
		
		// printf("\nbegin switch: current jid=%d, pid=%d\n",
		// 		 current->job->jid, current->job->pid);
		return;
		
	} else {    
	// next == NULL && current != NULL, no switch  没有要执行的任务了
		return;		
	}
}

void sig_handler(int sig, siginfo_t *info, void *notused)
{
	int status;
	int ret;
	
	switch (sig) {
	case SIGVTALRM:
		schedule();
		return;

	case SIGCHLD:
		ret = waitpid(-1, &status, WNOHANG);
		if (ret == 0 || ret == -1)
			return;
		
		if (WIFEXITED(status)) {
		#ifdef DEBUG
		//printf("%d %d %d\n", ret, info->si_pid, current->job->pid);
		//do_stat();
		#endif
			current->job->state = DONE;
			printf("normal termation, exit status = %d\tjid = %d, pid = %d\n\n",
				WEXITSTATUS(status), current->job->jid, current->job->pid);

		}  else if (WIFSIGNALED(status)) {
		    printf("abnormal termation, signal number = %d\tjid = %d, pid = %d\n\n",
				WTERMSIG(status), current->job->jid, current->job->pid);

		} else if (WIFSTOPPED(status)) {
		    printf("child stopped, signal number = %d\tjid = %d, pid = %d\n\n",
				WSTOPSIG(status), current->job->jid, current->job->pid);
		}
		return;
		
	default:
		return;
	}
}

void do_enq(struct jobinfo *newjob, struct jobcmd enqcmd)
{
	struct	waitqueue *newnode, *p;
	int		i=0, pid;
	char	*offset, *argvec, *q;
	char	**arglist;
	sigset_t	zeromask;
	
	sigemptyset(&zeromask);
	
	/* fill jobinfo struct */
	
	newjob = (struct jobinfo *)malloc(sizeof(struct jobinfo));
	newjob->jid = allocjid();
	newjob->defpri = enqcmd.defpri;
	newjob->curpri = enqcmd.defpri;
	newjob->ownerid = enqcmd.owner;
	newjob->state = READY;
	newjob->deftime = enqcmd.deftime;
	newjob->create_time = time(NULL);
	newjob->wait_time = 0;
	newjob->run_time = 0;
	arglist = (char**)malloc(sizeof(char*)*(enqcmd.argnum+1));
	newjob->cmdarg = arglist;
	offset = enqcmd.data;
	argvec = enqcmd.data;
	while (i < enqcmd.argnum) {
		if (*offset == ':') {
			*offset++ = '\0';
			q = (char*)malloc(offset - argvec);
			strcpy(q,argvec);
			arglist[i++] = q;
			argvec = offset;
		} else
			offset++;
	}

	arglist[i] = NULL;	
	
#ifdef DEBUG
	
	printf("enqcmd argnum %d\n",enqcmd.argnum);
	for (i = 0; i < enqcmd.argnum; i++)
		printf("parse enqcmd:%s\n",arglist[i]);
	
#endif
	
	/* 把作业装入队列 */
	newnode = (struct waitqueue*)malloc(sizeof(struct waitqueue));
	newnode->next = NULL;
	newnode->job = newjob;
	
	if (head) {
		for (p = head; p->next != NULL; p = p->next);
		p->next = newnode;
	} else
		head = newnode;
	
	/* create process for the job */
	if ((pid = fork()) < 0)
		error_sys("enq fork failed");
	
	printf("pid : %d***********\n", pid);

	/* In child process */
	if (pid == 0) {
		
		newjob->pid = getpid();
		
		/* block the child wait for run */
		
		raise(SIGSTOP);
		
		printf("begin running\n");
		for (i = 0; arglist[i] != NULL; i++)
			printf("arglist %s\n",arglist[i]);
		

		
		/* dup the globalfile descriptor to stdout */
		dup2(globalfd,1);
		if (execv(arglist[0],arglist) < 0)
			printf("exec failed\n");
		
		exit(1);
		
	} else {
		
		newjob->pid = pid;
		printf("\nnew job: jid=%d, pid=%d\n", newjob->jid, newjob->pid);
		
	}
}

/* 待补全代码 */
void do_deq(struct jobcmd deqcmd)
{
	int deqid,i;
	struct waitqueue *p,*prev,*select,*selectprev;
	
	deqid = atoi(deqcmd.data);
	
#ifdef DEBUG
	printf("deq jid %d\n",deqid);
#endif
	
	/* 如果当前在执行的作业和 deq 命令指定作业相同的话就中断该作业 */
	if (current && current->job->jid == deqid) {
		
		printf("terminate job: %d\n", current->job->jid);
		kill(SIGTERM, current->job->pid);
		
		for (i = 0; (current->job->cmdarg)[i] != NULL; i++) {
			
			free((current->job->cmdarg)[i]);
			(current->job->cmdarg)[i] = NULL;
		}
		
		free(current->job->cmdarg);
		free(current->job);
		free(current);
		
		current = NULL;
		
	} else {  /* 如果没在执行的话 可能在等待队列中 从队列中进行寻找 */
		select = NULL;
		selectprev = NULL;

		if (head) {
			for (prev = head, p = head; p != NULL; prev = p, p = p->next) {
				if (p->job->jid == deqid) {
					select = p;
					selectprev = prev;
					break;
				}
			}			

			selectprev->next = select->next;
			if (select == selectprev)	head = NULL;
		}

		if (select) { /* 如果搜寻到 就结束它 */
			for (i = 0; (select->job->cmdarg)[i] != NULL; i++) {
				free((select->job->cmdarg)[i]);
				(select->job->cmdarg)[i] = NULL;
			}

			free(select->job->cmdarg);
			free(select->job);
			free(select);
			
			select = NULL;
		}
	}
}

void do_stat()
{
	/* 
	* Print job statistics of all jobs:
	* 1. job id
	* 2. job pid
	* 3. job owner
	* 4. job run time
	* 5. job wait time
	* 6. job create time
	* 7. job state
	*/
	
	struct waitqueue *p;
	char timebuf[BUFLEN];
	
	printf( "JID\tPID\tOWNER\tRUNTIME\tWAITTIME\tCREATTIME\tSTATE\n");
	
	if (current) {
		strcpy(timebuf,ctime(&(current->job->create_time)));
		timebuf[strlen(timebuf) - 1] = '\0';
		printf("%d\t%d\t%d\t%d\t%d\t%s\t%s\n",
			current->job->jid,
			current->job->pid,
			current->job->ownerid,
			current->job->run_time,
			current->job->wait_time,
			timebuf,
			"RUNNING" );
	}
	
	for (p = head; p != NULL; p = p->next) {
		strcpy (timebuf,ctime(&(p->job->create_time)));
		timebuf[strlen(timebuf) - 1] = '\0';		
		printf("%d\t%d\t%d\t%d\t%d\t%s\t%s\n",
			p->job->jid,
			p->job->pid,
			p->job->ownerid,
			p->job->run_time,
			p->job->wait_time,
			timebuf,
			"READY" );
	}

	printf("\n");
}

int main()
{
	struct timeval interval;
	struct itimerval new,old;
	struct stat statbuf;
	struct sigaction newact,oldact1,oldact2;

	/* 如果目录下有一个同名的管道，就把他给删去 */
	if (stat(FIFO,&statbuf) == 0) 
		if (remove(FIFO) < 0)
			error_sys("remove failed");
	/* 重新创建一个管道 */
	if (mkfifo(FIFO,0666) < 0)
		error_sys("mkfifo failed");
	/* 打开 FIFO 管道 读取信息  */
	if ((fifo = open(FIFO,O_RDONLY|O_NONBLOCK)) < 0)
		error_sys("open fifo failed");
	/* 将输出结果重定向输入在 /dev/null */
	if ((globalfd = open("/dev/null",O_WRONLY)) < 0)
		error_sys("open global file failed");
	
	/* 设置信号处理器 */
	newact.sa_sigaction = sig_handler;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = SA_SIGINFO;
	
	sigaction(SIGCHLD,&newact,&oldact1);
	sigaction(SIGVTALRM,&newact,&oldact2);
	
	/* timer interval: 0s, 100ms */
	interval.tv_sec = 0;
	interval.tv_usec = 100;
	
	new.it_interval = interval;
	new.it_value = interval;
	setitimer(ITIMER_VIRTUAL,&new,&old);

	printf("OK! Scheduler is starting now!!\n");
	
	while (siginfo == 1);
	
	close(fifo);
	close(globalfd);
	return 0;
}
