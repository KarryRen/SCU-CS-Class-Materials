#include<stdio.h>
#include<memory.h>
#include<unistd.h>
#include <windows.h> //GetAsyncKeyState所需头文件
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件

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
        if(KEY_DOWN('A')) //按下 A 键暂停（A对应的 keyword 为 65） 
        	flag=false;
        if(KEY_DOWN('S')) //按下 S 键开始 （S 对应的 keyword 为 83） 
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
