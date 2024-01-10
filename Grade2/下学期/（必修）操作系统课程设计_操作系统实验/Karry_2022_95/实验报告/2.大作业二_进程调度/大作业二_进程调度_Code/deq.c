#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include "job.h"

/*
* command syntax
*     deq jid
*/
//作业出队命令deq
void usage()
{
	printf("Usage:  deq jid\n"
		"\tjid\t\t the job id\n");
}

int main(int argc,char *argv[])
// 功能和 enq 性质相同只不过是变了结构体内容罢了
{
	struct jobcmd deqcmd;
	int fd;

	if (argc != 2) {
		usage();
		return 1;
	}

	deqcmd.type = DEQ;
	deqcmd.defpri = 0;
	deqcmd.deftime = 0;
	deqcmd.owner = getuid();
	deqcmd.argnum = 1;

	strcpy(deqcmd.data,*++argv);

	/*printf("deqcmd cmdtype\t%d\n"
		"deqcmd owner\t%d\n"
		"deqcmd defpri\t%d\n"
      	"deqcmd deftime\t%d\n"
		"deqcmd jobName\t%s\n",
		deqcmd.type, deqcmd.owner, deqcmd.defpri, deqcmd.deftime, deqcmd.data);*/


	if ((fd = open(FIFO,O_WRONLY)) < 0)
		error_sys("deq open fifo failed");

	if (write(fd,&deqcmd,DATALEN)< 0)		
		error_sys("deq write failed");

	close(fd);
	return 0;
}
