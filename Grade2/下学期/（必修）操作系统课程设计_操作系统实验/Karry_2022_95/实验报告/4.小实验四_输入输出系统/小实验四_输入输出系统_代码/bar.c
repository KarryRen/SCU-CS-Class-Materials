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

#define DATALEN 5
#define FIFO "./js"

int fifo;

void Sch(){
	char buf[102];
	char Ch[]={'|','/','-','\\'};
	int flag = 1;
	int knum, fkey;
	memset(buf,'\0',sizeof(buf));
	int count = 0;

	while(count <= 100){
		if ((fkey = read(fifo, &knum, DATALEN)) < 0) // 读取管道内部的信息（从另外的终端中输入的）
			printf("read fifo failed");
		
		buf[count] = '#';
        	printf("[%-100s],[%c][%d%%]\r", buf, Ch[count%4], count);
		if (flag==1)
			count++;
		if (knum==32)
			flag=0;
		if (knum==10)
			flag=1;

		fflush(stdout);
		usleep(100000);
	}
	printf("\n");
}



int main()
{
	struct stat statbuf;

	/* 如果目录下有一个同名的管道，就把他给删去 */
	if (stat(FIFO,&statbuf) == 0) 
		if (remove(FIFO) < 0)
			printf("remove failed");
	/* 重新创建一个管道 */
	if (mkfifo(FIFO,0666) < 0)
		printf("mkfifo failed");
	/* 打开 FIFO 管道 读取信息  */
	if ((fifo = open(FIFO,O_RDONLY|O_NONBLOCK)) < 0)
		printf("open fifo failed");

	printf("OK! bar is starting now!!\n");
	
	Sch();
	
	close(fifo);
	
	return 0;
}
