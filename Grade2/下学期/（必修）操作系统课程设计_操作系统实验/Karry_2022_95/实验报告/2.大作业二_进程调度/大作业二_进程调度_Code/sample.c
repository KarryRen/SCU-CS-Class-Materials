//�ύ��һ������ʱ�䳬��100�������ҵ
#include <stdio.h>
#define N 5
int main(int argc,char *argv[])
{
	int i = 0;

	for(i = 0; i < argc; i++)
	{
		printf("%s: hello world �ӳ� 10s\n",argv[i]);
	}

	int j = 0;

	for(j=0; j<10; j++) { // N=10,��������ʱ��Ϊ10s ���ֳ������е�ʱ��
		sleep(1);
	}

	return 0;
}
