#ifndef JOB_H
#define JOB_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#define FIFO "./js" //  设置通道文件

#ifndef DEBUG
    #define DEBUG
#endif
#undef DEBUG

#define BUFLEN 100
#define GLOBALFILE "screendump"

// 枚举作业状态：就绪，运行，完成 （管理的每一个作业现在处于哪一步 方便记录）
enum jobstate {
    READY, RUNNING, DONE
};

// 枚举命令类型：进队，出队，当前状态查询 （用的是哪一个命令）
enum cmdtype {
    ENQ = -1, DEQ = -2, STAT = -3
};

// 作业调度命令结构 （一个命令拥有哪些内容）
struct jobcmd {
    enum cmdtype type; 
    int argnum;        // 参数的数目
    int owner;         // 作业的 owner
    int defpri;        // 默认优先级
    int deftime;       // 输入时默认的作业时间
    char data[BUFLEN]; // 作业的信息
};

#define DATALEN sizeof(struct jobcmd)
#define error_sys printf

// 作业信息的结构 （一个命令<作业>应该包含哪些属性）
struct jobinfo {
    int jid; /* 作业 id */
    int pid; /* 进程 id */
    char** cmdarg; /* 执行的命令或者参数 */
    int defpri; /* 默认优先权*/
    int deftime; /* 默认的作业时间*/
    int curpri; /* 当期的优先权*/
    int ownerid; /* 作业拥有者*/
    int wait_time; /* 在等待队列中等待的时间*/
    time_t create_time; /* 创建作业的时间*/
    int run_time; /* 作业运行的时间 */
    enum jobstate state; /* 作业状态 */
};

// 作业调度的数据结构 
struct waitqueue { 
    struct waitqueue *next; //下一个等待作业
    struct jobinfo *job; //当前等待作业的信息
};

void schedule();//调度函数
void sig_handler(int sig, siginfo_t *info, void *notused);//信号处理
int allocjid();//分配作业 id
void do_enq(struct jobinfo *newjob, struct jobcmd enqcmd);//入队函数
void do_deq(struct jobcmd deqcmd);//出队函数
void do_stat();//显示作业状态
void updateall();//更新所有作业信息
struct waitqueue* jobselect();//等待队列中选择作业
void jobswitch();//作业转换

#endif
