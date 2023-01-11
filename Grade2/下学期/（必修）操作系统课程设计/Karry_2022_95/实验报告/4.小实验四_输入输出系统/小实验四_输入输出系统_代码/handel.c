#include <termio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <string.h>

#define DATALEN 5
#define FIFO "./js"

int scanKeyboard() {
	int in;

	struct termios new_settings;
	struct termios stored_settings;
	tcgetattr(0,&stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	tcgetattr(0,&stored_settings);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&new_settings);

	
	in = getchar();

	tcsetattr(0,TCSANOW,&stored_settings);

	return in;
}

//这个方法就可以，返回值是该键的ASCII码值，不需要回车的，
//测试函数
int main() {
	int fd;
	int keynum = 0;	
	while(1) {
		keynum = scanKeyboard();
		printf(":%d\n",keynum);

		if ((fd = open(FIFO,O_RDWR)) < 0 )
			printf("stat open fifo failed\n");
		//else printf("success open \n");
		if (write(fd,&keynum,DATALEN) < 0)
			printf("stat write failed\n");
		//else printf("success write \n");
		
		close (fd);
	}
}
