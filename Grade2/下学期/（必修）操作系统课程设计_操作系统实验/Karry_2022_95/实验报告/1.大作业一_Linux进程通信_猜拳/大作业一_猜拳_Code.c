/*##############################
# 工程名称 : game.c
# 脚本功能 : 划拳游戏
# 游戏规则 : 两玩家同时出拳既出数字又出猜的总和,谁猜对则胜
            (出拳的范围[0, 5] 猜拳的范围 [0, 10])
            总共进行 50 轮 谁获胜的次数更多谁就取得最终胜利
# 作    者 : RenKai	           	
# 版    本 : v1.0	     	     
###############################*/

#include <unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#define FIFO_P1 "fifo_P1" // 第一个玩家的管道
#define FIFO_P2 "fifo_P2" // 第二个玩家的管道
#define BUFSIZE 5 // 缓存区大小
#define COUNT 50 // 总回合数

int judge(int P1_num, int P1_guess, int P2_num, int P2_guess); // 判断输赢的函数

int main(void)  { 
    int fp, fp_P1, fp_P2, i=1;
    int status;
    int nread;
    int buf[BUFSIZE]={0};    // 缓存区用来暂存出拳信息
    int P1_num[COUNT]={0};   // 存放玩家 1 出的数
    int P1_guess[COUNT]={0}; // 存放玩家 1 猜的和
    int P2_num[COUNT]={0};   // 存放玩家 2 出的数
    int P2_guess[COUNT]={0}; // 存放玩家 2 猜的和

    /**************************************/
    // 创建玩家 1 和 玩家 2 的两个管道
    // printf("创建管道\n"); // 只有第一次没有管道,才会进行创建
    if((mkfifo(FIFO_P1,0777)<0)&&(errno!=EEXIST)) {
        printf("无法成功创建管道 1 .\n");
        exit(1);
    } else printf("管道 1 创建成功! \n");
    if((mkfifo(FIFO_P2,0777)<0)&&(errno!=EEXIST)) {
        printf("无法成功创建管道 2 .\n");
        exit(2);
    } else printf("管道 2 创建成功! \n");

    /**************创建子进程 1 - 表示玩家 1***************/
    pid_t P1 = fork(); 
    if(P1 == 0) { // 如果是子进程的话 
        srand(time(NULL)+1357);
        while((fp_P1=open(FIFO_P1, O_WRONLY|O_NONBLOCK))==-1); // 只写打开管道1,不断尝试直到成功
        for(; i <= COUNT; i++) {
            buf[0] = rand()%6;  // 随机产生 0-5  的数字写入缓存区作为出的数字
            buf[1] = rand()%11; // 随机产生 0-10 的数字写入缓存区作为猜的和
            while(write(fp_P1,buf,BUFSIZE)==-1);//不断尝试写直至成功
        }
        close(fp_P1);
        exit(0); 
    } 
    /**************创建子进程 1 - 表示玩家 1***************/
    pid_t P2 = fork(); 
    if(P2 == 0) { // 如果是子进程的话 
        srand(time(NULL));
        while((fp_P2=open(FIFO_P2, O_WRONLY|O_NONBLOCK))==-1); // 只写打开管道1,不断尝试直到成功
        for(; i <= COUNT; i++) {
            buf[0] = rand()%6;  // 随机产生 0-5  的数字写入缓存区作为出的数字
            buf[1] = rand()%11; // 随机产生 0-10 的数字写入缓存区作为猜的和
            while(write(fp_P2,buf,BUFSIZE)==-1);//不断尝试写直至成功
        }
        close(fp_P1);
        exit(0); 
    } 

    memset(buf,0,sizeof(buf));//清空缓冲区

    // 只读方式打开两个命名管道
    while((fp_P1=open(FIFO_P1,O_RDONLY|O_NONBLOCK,0))==-1);
    while((fp_P2=open(FIFO_P2,O_RDONLY|O_NONBLOCK,0))==-1);
 
    sleep(3);// 等待两个子进程中打开管道写端并输入数据，这是很必要的
    i=1;
    for(;i<=COUNT;i++) {
        nread=read(fp_P1,buf,BUFSIZE);
        if(nread!=-1&&nread!=0) {
            P1_num[i-1] = buf[0];  // P1 的出拳结果存放至 P1_num
            P1_guess[i-1] = buf[1]; // P1 的猜拳结果存放至 P1_guess
        }
    }
    i=1;
    for(;i<=COUNT;i++) {
        nread=read(fp_P2,buf,BUFSIZE);
        if(nread!=-1&&nread!=0) {
            P2_num[i-1] = buf[0];  // P2 的出拳结果存放至 P2_num
            P2_guess[i-1] = buf[1]; // P2 的猜拳结果存放至 P2_guess
        }
    }
 
 
    int j=1;
    int P1w_count = 0, P2w_count=0, pd=0; // 分别表示 P1 P2 win的次数和平局的次数
    for(;j<=COUNT;j++) {
        int tmp=judge(P1_num[j - 1], P1_guess[j - 1], P2_num[j - 1], P2_guess[j - 1]);
        printf("第 %d 轮:", j);
        if(tmp==0) {
            printf("平局! \n\n");
            pd++;// 平局
        }
        else {
            printf("%s 赢了!\n",(tmp>0)?"玩家 1 ":"玩家 2 ");
            if(tmp>0)P1w_count++;//p1胜
            else P2w_count++;    //p2胜
        }
    }
    // 打印最终统计结果
    printf("最终结果:\n");
    printf("玩家 1 赢了 %d  轮.\n",P1w_count);
    printf("玩家 2 赢了 %d  轮.\n",P2w_count);
    printf("总共有 %d 轮达成平手.\n",pd);
    printf("%s 赢下本次划拳比赛!\n",(P1w_count>P2w_count)?"玩家 1 ":"玩家 2 ");
 
    // 等待两个子进程结束
    if(waitpid(P1,&status,0) < 0) {
        perror("waitpid");
        exit(5);
    }
    if(waitpid(P2,&status,0)< 0) {
        perror("waitpid");
        exit(6);
    }
    exit(0);
}
 

int judge(int P1_num, int P1_guess, int P2_num, int P2_guess) // 规定游戏判定规则
{
    int r = 0;
    printf("玩家一出: %d, 玩家一猜: %d \n玩家二出: %d, 玩家二猜:%d \n", P1_num, P1_guess, P2_num, P2_guess);
    if (P1_guess == P1_num + P2_num && P2_guess == P1_num + P2_num){
        r = 0;
    } else if(P1_guess == P1_num + P2_num && P2_guess != P1_num + P2_num){
        r = 1;
    } else if(P1_guess != P1_num + P2_num && P2_guess == P1_num + P2_num){
        r = -1;
    } else {
        r = 0;
    }

    return r;
}
 
 
 