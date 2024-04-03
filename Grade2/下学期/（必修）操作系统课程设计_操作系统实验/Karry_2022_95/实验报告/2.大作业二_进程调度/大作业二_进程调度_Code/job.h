#ifndef JOB_H
#define JOB_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#define FIFO "./js" //  ����ͨ���ļ�

#ifndef DEBUG
    #define DEBUG
#endif
#undef DEBUG

#define BUFLEN 100
#define GLOBALFILE "screendump"

// ö����ҵ״̬�����������У���� �������ÿһ����ҵ���ڴ�����һ�� �����¼��
enum jobstate {
    READY, RUNNING, DONE
};

// ö���������ͣ����ӣ����ӣ���ǰ״̬��ѯ ���õ�����һ�����
enum cmdtype {
    ENQ = -1, DEQ = -2, STAT = -3
};

// ��ҵ��������ṹ ��һ������ӵ����Щ���ݣ�
struct jobcmd {
    enum cmdtype type; 
    int argnum;        // ��������Ŀ
    int owner;         // ��ҵ�� owner
    int defpri;        // Ĭ�����ȼ�
    int deftime;       // ����ʱĬ�ϵ���ҵʱ��
    char data[BUFLEN]; // ��ҵ����Ϣ
};

#define DATALEN sizeof(struct jobcmd)
#define error_sys printf

// ��ҵ��Ϣ�Ľṹ ��һ������<��ҵ>Ӧ�ð�����Щ���ԣ�
struct jobinfo {
    int jid; /* ��ҵ id */
    int pid; /* ���� id */
    char** cmdarg; /* ִ�е�������߲��� */
    int defpri; /* Ĭ������Ȩ*/
    int deftime; /* Ĭ�ϵ���ҵʱ��*/
    int curpri; /* ���ڵ�����Ȩ*/
    int ownerid; /* ��ҵӵ����*/
    int wait_time; /* �ڵȴ������еȴ���ʱ��*/
    time_t create_time; /* ������ҵ��ʱ��*/
    int run_time; /* ��ҵ���е�ʱ�� */
    enum jobstate state; /* ��ҵ״̬ */
};

// ��ҵ���ȵ����ݽṹ 
struct waitqueue { 
    struct waitqueue *next; //��һ���ȴ���ҵ
    struct jobinfo *job; //��ǰ�ȴ���ҵ����Ϣ
};

void schedule();//���Ⱥ���
void sig_handler(int sig, siginfo_t *info, void *notused);//�źŴ���
int allocjid();//������ҵ id
void do_enq(struct jobinfo *newjob, struct jobcmd enqcmd);//��Ӻ���
void do_deq(struct jobcmd deqcmd);//���Ӻ���
void do_stat();//��ʾ��ҵ״̬
void updateall();//����������ҵ��Ϣ
struct waitqueue* jobselect();//�ȴ�������ѡ����ҵ
void jobswitch();//��ҵת��

#endif
