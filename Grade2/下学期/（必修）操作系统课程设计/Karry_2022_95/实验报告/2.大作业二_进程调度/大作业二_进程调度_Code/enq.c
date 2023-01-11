#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include "job.h"

/* 
* command syntax
*     enq [-p num] e_file args
*/
void usage()
{
	printf("Usage:  enq [-p num] [-t time] e_file args\n"
		"\t-p num\t\t specify the job priority\n"
        "\t-t time\t\t specift the job time\n"
		"\te_file\t\t the absolute path of the exefile\n"
		"\targs\t\t the args passed to the e_file\n");
}

int main(int argc,char *argv[]) 
// argc 表示有多少个参数 argv 是一个数组的指针（每一个数组是一个参数 ++argv 来访问下一个指针）
// 这一个 main 函数只不过是:
// 构建了一个 enqcmd 的结构体把所有的该有的信息都填充到其中 然后写入管道 与 scheduler 进行交互
{
	int	p = 0;
    int t = 0;
	int	fd;
	char c, *offset;
	struct jobcmd enqcmd;
	
	if (argc == 1) {
		usage();
		return 1;
	}

	while (--argc > 0 && (*++argv)[0] == '-') {
    // 找寻 p 优先级
		while ((c = *++argv[0]))
			switch (c) {
				case 'p':
					p = atoi(*(++argv));
					argc--;
					break;
                case 't':
                    t = atoi(*(++argv));
					argc--;
					break;
				default:
					printf("Illegal option %c\n",c);
					return 1;
			}
	}
	
	if (p < 0 || p > 3) {
		printf("invalid priority: must between 0 and 3\n");
		return 1;
	}
	
	enqcmd.type = ENQ;
	enqcmd.defpri = p;
	enqcmd.deftime = t;
	enqcmd.owner = getuid();
	enqcmd.argnum = argc;
	offset = enqcmd.data;
	
	while (argc-- > 0) {
		strcpy(offset,*argv);
		strcat(offset,":");
		offset = offset + strlen(*argv) + 1; // 向后取地址
		argv++;
	}

	/*printf("enqcmd cmdtype\t%d\n"
		"enqcmd owner\t%d\n"
		"enqcmd defpri\t%d\n"
       	"enqcmd deftime\t%d\n"
		"enqcmd data\t%s\n",
		enqcmd.type, enqcmd.owner, enqcmd.defpri, enqcmd.deftime, enqcmd.data);*/

	if ((fd = open(FIFO,O_WRONLY)) < 0)
		error_sys("enq open fifo failed");
	if (write(fd,&enqcmd,DATALEN)< 0)
		error_sys("enq write failed");

	
	close(fd);
	return 0;
}
