//提交了一个运行时间超过100毫秒的作业
#include <stdio.h>
#define N 5
int main(int argc,char *argv[])
{
	int i = 0;

	for(i = 0; i < argc; i++)
	{
		printf("%s: hello world 延迟 10s\n",argv[i]);
	}

	int j = 0;

	for(j=0; j<10; j++) { // N=10,程序运行时间为10s 保持程序运行的时间
		sleep(1);
	}

	return 0;
}
