#include<stdio.h>
#include<memory.h>
#include<unistd.h>
#include <windows.h> //GetAsyncKeyState����ͷ�ļ�
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //������ⰴ���ĵ���¼�

void handleBar(){
    char buf[102];
    char Ch[]={'|','/','-','\\'};
    memset(buf,'\0',sizeof(buf));
    int count = 0;
    bool flag=true;
    while(count <= 100){
        buf[count] = '#';
        printf("[%-100s],[%c][%d%%]\r", buf, Ch[count%4], count);
        
        if(flag)
        	count++;
        if(KEY_DOWN('A')) //���� A ����ͣ��A��Ӧ�� keyword Ϊ 65�� 
        	flag=false;
        if(KEY_DOWN('S')) //���� S ����ʼ ��S ��Ӧ�� keyword Ϊ 83�� 
        	flag=true;
        	
        fflush(stdout);
		usleep(100000);
    }
    printf("\n");
}
int main(){
    handleBar();
    return 0;
}
