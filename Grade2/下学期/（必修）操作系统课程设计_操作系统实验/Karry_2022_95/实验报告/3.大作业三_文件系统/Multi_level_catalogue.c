#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define BLOCKSIZE 1024//磁盘块大小
#define SIZE 1024000//虚拟磁盘空间大小
#define END 65535//FAT中的文件结束标志
#define FREE 0//FAT中盘块空闲标志
#define ROOTBLOCKNUM 2//根目录区所占盘块数
#define MAXOPENFILE 10//最多同时打开文件个数t
#define MAXTEXT 10000

/*文件控制块*/
typedef struct FCB 
{
	char filename[8];//文件名
	char exname[3];//文件扩展名
	unsigned char attribute;//文件属性字段，值为0时表示目录文件，值为1时表示数据文件
	unsigned short time;//文件创建时间
	unsigned short date;//文件创建日期
	unsigned short first;//文件起始盘块号
	unsigned long length;//文件长度
	char free;//表示目录项是否为空，若值为0，表示空，值为1，表示已分配
}fcb;

/*文件分配表*/
typedef struct FAT
{
	unsigned short id;//磁盘块的状态（空闲的，最后的，下一个）
}fat;
/*用户打开文件表*/
typedef struct USEROPEN
{
	char filename[8];//文件名
	char exname[3];//文件扩展名
	unsigned char attribute;//文件属性字段，值为0时表示目录文件，值为1时表示数据文件
	unsigned short time;//文件创建时间
	unsigned short date;//文件创建日期
	unsigned short first;//文件起始盘块号
	unsigned long length;//文件长度（对数据文件是字节数，对目录文件可以是目录项个数）
	char free;//表示目录项是否为空，若值为0，表示空，值为1，表示已分配

	unsigned short dirno;//相应打开文件的目录项在父目录文件中的盘块号
	int diroff;//相应打开文件的目录项在父目录文件的dirno盘块中的目录项序号
	char dir[80];//相应打开文件所在的路径名，这样方便快速检查出指定文件是否已经打开
	int father;//父目录在打开文件表项的位置
	int count;//读写指针在文件中的位置,文件的总字符数
	char fcbstate;//是否修改了文件的FCB的内容，如果修改了置为1，否则为0
	char topenfile;//表示该用户打开表项是否为空，若值为0，表示为空，否则表示已被某打开文件占据
}useropen;

/*引导块*/
typedef struct BLOCK0
{
	char magic[10];//文件系统魔数
	char information[200];//存储一些描述信息，如磁盘块大小、磁盘块数量、最多打开文件数等
	unsigned short root;//根目录文件的起始盘块号
	unsigned char*startblock;//虚拟磁盘上数据区开始位置
}block0;

unsigned char*myvhard;//指向虚拟磁盘的起始地址
useropen openfilelist[MAXOPENFILE];//用户打开文件表数组
int curdir;//用户打开文件表中的当前目录所在打开文件表项的位置
char currentdir[80];//记录当前目录的目录名（包括目录的路径）
unsigned char*startp;//记录虚拟磁盘上数据区开始位置
char myfilename[]="my file sys";//文件系统的文件名

void startsys();//进入文件系统
void my_format();//磁盘格式化
void my_cd(char*dirname);//更改当前目录
void my_mkdir(char*dirname);//创建子目录
void my_rmdir(char*dirname);//删除子目录
void my_ls();//显示目录
void my_create(char*filename);//创建文件
void my_rm(char*filename);//删除文件
int my_open(char*filename);//打开文件
int my_close(int fd);//关闭文件
int my_write(int fd);//写文件
int do_write(int fd,char*text,int len,char wstyle);//实际写文件
int my_read(int fd,int len);//读文件
int do_read(int fd,int len,char*text);//实际读文件
void my_exitsys();//退出文件系统
unsigned short findblock();//寻找空闲盘块
int findopenfile();//寻找空闲文件表项
void startsys()
{
	FILE*fp;//文件类型的指针变量
	unsigned char buf[SIZE];
	fcb*root;
	int i;
	myvhard=(unsigned char*)malloc(SIZE);//申请虚拟磁盘空间，用内存模拟磁盘空间
	memset(myvhard,0,SIZE);//将myvhard中前SIZE个字节用0替换并返回myvhard
	if((fp=fopen(myfilename,"r"))!=NULL)
	{
		fread(buf,SIZE,1,fp);//将二进制文件读取到缓冲区
		fclose(fp);
		if(strcmp(((block0*)buf)->magic,"10101010"))
		{
			printf("my file sys is not exist,begin to creat the file...\n");
			my_format();
		}
		else
		{
			for(i=0;i<SIZE;i++)
			myvhard[i]=buf[i];
		}
	}
	else
	{
		printf("my file sys is not exist,begin to creat the file...\n");
		my_format();
	}
	root=(fcb*)(myvhard+5*BLOCKSIZE);
	strcpy(openfilelist[0].filename,root->filename);
	strcpy(openfilelist[0].exname,root->exname);
	openfilelist[0].attribute=root->attribute;
	openfilelist[0].time=root->time;
	openfilelist[0].date=root->date;
	openfilelist[0].first=root->first;
	openfilelist[0].length=root->length;
	openfilelist[0].free=root->free;
	openfilelist[0].dirno=5;
	openfilelist[0].diroff=0;
	strcpy(openfilelist[0].dir,"\\root\\");
	openfilelist[0].father=0;
	openfilelist[0].count=0;
	openfilelist[0].fcbstate=0;
	openfilelist[0].topenfile=1;
	for(i=1;i<MAXOPENFILE;i++)
		openfilelist[i].topenfile=0;
	curdir=0;
	strcpy(currentdir,"\\root\\");
	startp=((block0*)myvhard)->startblock;
}

void my_format()
{
	FILE*fp;
	fat*fat1,*fat2;
	block0 *blk0;
	time_t now;
	struct tm*nowtime;
	fcb*root;
	int i;
	blk0=(block0*)myvhard;
	fat1=(fat*)(myvhard+BLOCKSIZE);
	fat2=(fat*)(myvhard+3*BLOCKSIZE);
	root=(fcb*)(myvhard+5*BLOCKSIZE);
	strcpy(blk0->magic,"10101010");
	strcpy(blk0->information,"My File System Ver1.0\nBlocksize=1KBWholesize=1000KBBlocknum=1000RootBlocknum=2\n");
	blk0->root=5;
	blk0->startblock=(unsigned char*)root;
	for(i=0;i<5;i++)
	{
		fat1->id=END;
		fat2->id=END;
		fat1++;
		fat2++;
	}
	fat1->id=6;
	fat2->id=6;
	fat1++;
	fat2++;
	fat1->id=END;
	fat2->id=END;
	fat1++;
	fat2++;
	for(i=7;i<SIZE/BLOCKSIZE;i++)
	{
		fat1->id=FREE;
		fat2->id=FREE;
		fat1++;
		fat2++;
	}
	now=time(NULL);
	nowtime=localtime(&now);
	strcpy(root->filename,".");
	strcpy(root->exname,"");
	root->attribute=0x28;
	root->time=nowtime->tm_hour*2048+nowtime->tm_min*32+nowtime->tm_sec/2;
	root->date=(nowtime->tm_year-80)*512+(nowtime->tm_mon+1)*32+nowtime->tm_mday;
	root->first=5;
	root->length=2*sizeof(fcb);
	root->free=1;
	root++;
	now=time(NULL);
	nowtime=localtime(&now);
	strcpy(root->filename,"..");
	strcpy(root->exname,"");
	root->attribute=0x28;
	root->time=nowtime->tm_hour*2048+nowtime->tm_min*32+nowtime->tm_sec/2;
	root->date=(nowtime->tm_year-80)*512+(nowtime->tm_mon+1)*32+nowtime->tm_mday;
	root->first=5;
	root->length=2*sizeof(fcb);
	root->free=1;
	fp=fopen(myfilename,"w");
	fwrite(myvhard,SIZE,1,fp);
	fclose(fp);
}

void my_cd(char*dirname)
{
	char*dir;
	int fd;
	dir=strtok(dirname,"\\");//分解字符串为一组字符串。dirname为要分解的字符串，"\\"为分隔符字符串
	if(strcmp(dir,".")==0)
		return;
	else if(strcmp(dir,"..")==0)
	{
	if(curdir)
		curdir=my_close(curdir);
		return;
	}
	else if(strcmp(dir,"root")==0)
	{
		while(curdir)
			curdir=my_close(curdir);
			dir=strtok(NULL,"\\");
	}
	while(dir)
	{
		fd=my_open(dir);
		if(fd!=-1)
			curdir=fd;
		else
			return;
		dir=strtok(NULL,"\\");
	}
}

void my_mkdir(char*dirname)
{
	fcb*fcbptr;
	fat*fat1,*fat2;
	time_t now;
	struct tm*nowtime;
	char text[MAXTEXT];
	unsigned short blkno;
	int rbn,fd,i;
	fat1=(fat*)(myvhard+BLOCKSIZE);
	fat2=(fat*)(myvhard+3*BLOCKSIZE);
	openfilelist[curdir].count=0;
	rbn=do_read(curdir,openfilelist[curdir].length,text);
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)//在当前目录下找，是否有重名目录
	{
		if(strcmp(fcbptr->filename,dirname)==0&&strcmp(fcbptr->exname,"")==0)
		{
			printf("Error,the dir name is already exist!\n");
			return;
		}
		fcbptr++;
	}
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)
	{
		if(fcbptr->free==0)
		break;
		fcbptr++;
	}
	blkno=findblock();//寻找空闲盘块
	if(blkno==-1)
		return;
	(fat1+blkno)->id=END;
	(fat2+blkno)->id=END;
	now=time(NULL);
	nowtime=localtime(&now);
	strcpy(fcbptr->filename,dirname);
	strcpy(fcbptr->exname,"");
	fcbptr->attribute=0x30;
	fcbptr->time=nowtime->tm_hour*2048+nowtime->tm_min*32+nowtime->tm_sec/2;
	fcbptr->date=(nowtime->tm_year-80)*512+(nowtime->tm_mon+1)*32+nowtime->tm_mday;
	fcbptr->first=blkno;
	fcbptr->length=2*sizeof(fcb);
	fcbptr->free=1;
	openfilelist[curdir].count=i*sizeof(fcb);//把当前目录的文件读写指针定位到文件末尾
	do_write(curdir,(char*)fcbptr,sizeof(fcb),2);//从指针fcbptr开始写一个fcb大小的内容到当前目录文件末尾
	
	fd=my_open(dirname);//返回新建立的目录文件在用户打开文件数组的下标
	if(fd==-1)
		return;
	fcbptr=(fcb*)malloc(sizeof(fcb));//建立新目录的'.','..'目录
	now=time(NULL);
	nowtime=localtime(&now);
	strcpy(fcbptr->filename,".");
	strcpy(fcbptr->exname,"");
	fcbptr->attribute=0x28;
	fcbptr->time=nowtime->tm_hour*2048+nowtime->tm_min*32+nowtime->tm_sec/2;
	fcbptr->date=(nowtime->tm_year-80)*512+(nowtime->tm_mon+1)*32+nowtime->tm_mday;
	fcbptr->first=blkno;
	fcbptr->length=2*sizeof(fcb);
	fcbptr->free=1;
	do_write(fd,(char*)fcbptr,sizeof(fcb),2);
	now=time(NULL);
	nowtime=localtime(&now);
	strcpy(fcbptr->filename,"..");
	strcpy(fcbptr->exname,"");
	fcbptr->attribute=0x28;
	fcbptr->time=nowtime->tm_hour*2048+nowtime->tm_min*32+nowtime->tm_sec/2;
	fcbptr->date=(nowtime->tm_year-80)*512+(nowtime->tm_mon+1)*32+nowtime->tm_mday;
	fcbptr->first=blkno;
	fcbptr->length=2*sizeof(fcb);
	fcbptr->free=1;
	do_write(fd,(char*)fcbptr,sizeof(fcb),2);
	free(fcbptr);
	my_close(fd);
	
	fcbptr=(fcb*)text;
	fcbptr->length=openfilelist[curdir].length;
	openfilelist[curdir].count=0;
	do_write(curdir,(char*)fcbptr,sizeof(fcb),2);//更新当前目录文件的内容
	openfilelist[curdir].fcbstate=1;
}

void my_rmdir(char*dirname)
{
	fcb*fcbptr,*fcbptr2;
	fat*fat1,*fat2,*fatptr1,*fatptr2;
	char text[MAXTEXT],text2[MAXTEXT];
	unsigned short blkno;
	int rbn,rbn2,fd,i,j;
	fat1=(fat*)(myvhard+BLOCKSIZE);
	fat2=(fat*)(myvhard+3*BLOCKSIZE);
	if(strcmp(dirname,".")==0||strcmp(dirname,"..")==0)
	{
		printf("Error,can't remove this directory.\n");
		return;
	}
	openfilelist[curdir].count=0;
	rbn=do_read(curdir,openfilelist[curdir].length,text);
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)//查找要删除的目录
	{
		if(strcmp(fcbptr->filename,dirname)==0&&strcmp(fcbptr->exname,"")==0)
		break;
		fcbptr++;
	}
	if(i==rbn/sizeof(fcb))
	{
		printf("Error,the directory is not exist.\n");
		return;
	}
	fd=my_open(dirname);//目录在当前打开文件数组中的下标
	rbn2=do_read(fd,openfilelist[fd].length,text2);//读取要删除的目录的内容
	fcbptr2=(fcb*)text2;
	for(j=0;j<rbn2/sizeof(fcb);j++)//判断要删除目录是否为空
	{
		if(strcmp(fcbptr2->filename,".")&&strcmp(fcbptr2->filename,"..")&&strcmp(fcbptr2->filename,""))
		{
			my_close(fd);
			printf("Error,the directory is not empty.\n");
			return;
		}
		fcbptr2++;
	}
	blkno=openfilelist[fd].first;
	while(blkno!=END)//修改要删除目录在fat中所占用的目录项的属性
	{
		fatptr1=fat1+blkno;
		fatptr2=fat2+blkno;
		blkno=fatptr1->id;
		fatptr1->id=FREE;
		fatptr2->id=FREE;
	}
	my_close(fd);
	strcpy(fcbptr->filename,"");//修改已删除目录在当前目录的fcb的属性
	fcbptr->free=0;
	openfilelist[curdir].count=i*sizeof(fcb);//更新当前目录文件的内容
	do_write(curdir,(char*)fcbptr,sizeof(fcb),2);
	openfilelist[curdir].fcbstate=1;
}

void my_ls()
{
	fcb* fcbptr;//文件控制块 
	char text[MAXTEXT];
	int rbn,i;
	openfilelist[curdir].count=0;//用户打开当前文件表数组 
	rbn=do_read(curdir,openfilelist[curdir].length,text);
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)
	{
		if(fcbptr->free)
		{
			if(fcbptr->attribute&0x20)
				printf("%s\\\t\t<DIR>\t\t%d/%d/%d\t%02d:%02d:%02d\n",fcbptr->filename,(fcbptr->date>>9)+1980,(fcbptr->date>>5)&0x000f,fcbptr->date&0x001f,fcbptr->time>>11,(fcbptr->time>>5)&0x003f,fcbptr->time&0x001f*2);
			else
				printf("%s.%s\t\t%dB\t\t%d/%d/%d\t%02d:%02d:%02d\t\n",fcbptr->filename,fcbptr->exname,(int)(fcbptr->length),(fcbptr->date>>9)+1980,(fcbptr->date>>5)&0x000f,fcbptr->date&0x1f,fcbptr->time>>11,(fcbptr->time>>5)&0x3f,fcbptr->time&0x1f*2);
		}
		fcbptr++;
	}
}

void my_create(char*filename)
{
	fcb*fcbptr;
	fat*fat1,*fat2;
	char*fname,*exname,text[MAXTEXT];
	unsigned short blkno;
	int rbn,i;
	time_t now;
	struct tm*nowtime;
	fat1=(fat*)(myvhard+BLOCKSIZE);
	fat2=(fat*)(myvhard+BLOCKSIZE);
	fname=strtok(filename,".");
	exname=strtok(NULL,".");
	if(strcmp(fname,"")==0)
	{
		printf("Error,creating file must have a right name.\n");
		return;
	}
	if(!exname)
	{
		printf("Error,creating file must have a extern name.\n");
		return;
	}
	openfilelist[curdir].count=0;
	rbn=do_read(curdir,openfilelist[curdir].length,text);
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)
	{
		if(strcmp(fcbptr->filename,fname)==0&&strcmp(fcbptr->exname,exname)==0)
		{
			printf("Error,the file name is already exist!\n");
			return;
		}
		fcbptr++;
	}
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)
	{
		if(fcbptr->free==0)
		break;
		fcbptr++;
	}
	blkno=findblock();
	if(blkno==-1)
		return;
	(fat1+blkno)->id=END;
	(fat2+blkno)->id=END;
	
	now=time(NULL);
	nowtime=localtime(&now);
	strcpy(fcbptr->filename,fname);
	strcpy(fcbptr->exname,exname);
	fcbptr->attribute=0x00;
	fcbptr->time=nowtime->tm_hour*2048+nowtime->tm_min*32+nowtime->tm_sec/2;
	fcbptr->date=(nowtime->tm_year-80)*512+(nowtime->tm_mon+1)*32+nowtime->tm_mday;
	fcbptr->first=blkno;
	fcbptr->length=0;
	fcbptr->free=1;
	openfilelist[curdir].count=i*sizeof(fcb);
	do_write(curdir,(char*)fcbptr,sizeof(fcb),2);
	fcbptr=(fcb*)text;
	fcbptr->length=openfilelist[curdir].length;
	openfilelist[curdir].count=0;
	do_write(curdir,(char*)fcbptr,sizeof(fcb),2);
	openfilelist[curdir].fcbstate=1;
}

void my_rm(char*filename)
{
	fcb*fcbptr;
	fat*fat1,*fat2,*fatptr1,*fatptr2;
	char*fname,*exname,text[MAXTEXT];
	unsigned short blkno;
	int rbn,i;
	fat1=(fat*)(myvhard+BLOCKSIZE);
	fat2=(fat*)(myvhard+3*BLOCKSIZE);
	fname=strtok(filename,".");
	exname=strtok(NULL,".");
	if(strcmp(fname,"")==0)
	{
		printf("Error,removing file must have aright name.\n");
		return;
	}
	if(!exname)
	{
		printf("Error,removing file must have a extern name.\n");
		return;
	}
	openfilelist[curdir].count=0;
	rbn=do_read(curdir,openfilelist[curdir].length,text);
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)
	{
		if(strcmp(fcbptr->filename,fname)==0&&strcmp(fcbptr->exname,exname)==0)
		break;
		fcbptr++;
	}
	if(i==rbn/sizeof(fcb))
	{
		printf("Error,the file is not exist.\n");
		return;
	}
	blkno=fcbptr->first;
	while(blkno!=END)
	{
		fatptr1=fat1+blkno;
		fatptr2=fat2+blkno;
		blkno=fatptr1->id;
		fatptr1->id=FREE;
		fatptr2->id=FREE;
	}
	strcpy(fcbptr->filename,"");
	fcbptr->free=0;
	openfilelist[curdir].count=i*sizeof(fcb);
	do_write(curdir,(char*)fcbptr,sizeof(fcb),2);
	openfilelist[curdir].fcbstate=1;
}

int my_open(char*filename)
{
	fcb*fcbptr;
	char*fname,exname[3],*str,text[MAXTEXT];
	int rbn,fd,i;
	fname=strtok(filename,".");
	str=strtok(NULL,".");
	if(str)
		strcpy(exname,str);
	else
		strcpy(exname,"");
	for(i=0;i<MAXOPENFILE;i++)//在用户打开文件数组查找看当前文件是否已经打开
	{
		if(strcmp(openfilelist[i].filename,fname)==0&&strcmp(openfilelist[i].exname,exname)==0&&i!=curdir)
		{
			printf("Error,the file is already open.\n");
			return-1;
		}
	}
	openfilelist[curdir].count=0;
	rbn=do_read(curdir,openfilelist[curdir].length,text);
	fcbptr=(fcb*)text;
	for(i=0;i<rbn/sizeof(fcb);i++)//在当前目录下找要打开的文件是否存在
	{
		if(strcmp(fcbptr->filename,fname)==0&&strcmp(fcbptr->exname,exname)==0)
			break;
		fcbptr++;
	}
	if(i==rbn/sizeof(fcb))
	{
		printf("Error,the file is not exist.\n");
		return-1;
	}
	fd=findopenfile();//寻找空闲文件表项
	if(fd==-1)
		return-1;
	strcpy(openfilelist[fd].filename,fcbptr->filename);
	strcpy(openfilelist[fd].exname,fcbptr->exname);
	openfilelist[fd].attribute=fcbptr->attribute;
	openfilelist[fd].time=fcbptr->time;
	openfilelist[fd].date=fcbptr->date;
	openfilelist[fd].first=fcbptr->first;
	openfilelist[fd].length=fcbptr->length;
	openfilelist[fd].free=fcbptr->free;
	openfilelist[fd].dirno=openfilelist[curdir].first;
	openfilelist[fd].diroff=i;
	strcpy(openfilelist[fd].dir,openfilelist[curdir].dir);
	strcat(openfilelist[fd].dir,filename);
	if(fcbptr->attribute&0x20)
		strcat(openfilelist[fd].dir,"\\");
	openfilelist[fd].father=curdir;
	openfilelist[fd].count=0;
	openfilelist[fd].fcbstate=0;
	openfilelist[fd].topenfile=1;
	return fd;
}

int my_close(int fd)
{
	fcb* fcbptr;
	int father;
	if(fd<0||fd>=MAXOPENFILE)
	{
		printf("Error,the file is not exist.\n");
		return -1;
	}
	if(openfilelist[fd].fcbstate)
	{
		fcbptr=(fcb*)malloc(sizeof(fcb));
		strcpy(fcbptr->filename,openfilelist[fd].filename);
		strcpy(fcbptr->exname,openfilelist[fd].exname);
		fcbptr->attribute=openfilelist[fd].attribute;
		fcbptr->time=openfilelist[fd].time;
		fcbptr->date=openfilelist[fd].date;
		fcbptr->first=openfilelist[fd].first;
		fcbptr->length=openfilelist[fd].length;
		fcbptr->free=openfilelist[fd].free;
		father=openfilelist[fd].father;
		openfilelist[father].count=openfilelist[fd].diroff*sizeof(fcb);
		do_write(father,(char*)fcbptr,sizeof(fcb),2);
		free(fcbptr);
		openfilelist[fd].fcbstate=0;
	}
	strcpy(openfilelist[fd].filename,"");
	strcpy(openfilelist[fd].exname,"");
	openfilelist[fd].topenfile=0;
	return father;
}

int my_write(int fd)
{
	fat*fat1,*fat2,*fatptr1,*fatptr2;
	int wstyle,len,ll,tmp;
	char text[MAXTEXT];
	unsigned short blkno;
	fat1=(fat*)(myvhard+BLOCKSIZE);
	fat2=(fat*)(myvhard+3*BLOCKSIZE);
	if(fd<0||fd>=MAXOPENFILE) //坚持fd正确性，不超出打开文件表数组最大下标 
	{
		printf("The file is not exist!\n");
		return -1;
	}
	while(1)//输入写方式 
	{
		printf("Please enter the number of write style:\n1.cut write\t2.cover write\t3.add write\n");
		scanf("%d",&wstyle);
		if(wstyle>0&&wstyle<4)
			break;
		printf("Input Error!");
	}	
	getchar();
	switch(wstyle)
	{
		case 1://截断写把原文件所占的虚拟磁盘空间重置为1
			blkno=openfilelist[fd].first;
			fatptr1=fat1+blkno;
			fatptr2=fat2+blkno;
			blkno=fatptr1->id;
			fatptr1->id=END;
			fatptr2->id=END;
			while(blkno!=END) //释放除第一块外其他的磁盘空间 
			{
				fatptr1=fat1+blkno;
				fatptr2=fat2+blkno;
				blkno=fatptr1->id;
				fatptr1->id=FREE;
				fatptr2->id=FREE;
			}
			openfilelist[fd].count=0;
			openfilelist[fd].length=0;
			break;
		case 2:
			openfilelist[fd].count=0;
			break;
		case 3:
			openfilelist[fd].count=openfilelist[fd].length;//将读写指针移动到文件末尾 
			break;
		default:
			break;
	}
	ll=0;
	printf("please input write data(end with Ctrl+Z):\n");
	while(gets(text))
	{
		len=strlen(text);
		text[len++]='\n';
		text[len]='\0';
		tmp=do_write(fd,text,len,wstyle);//写入文件 
		if(tmp!=-1)
			ll+=tmp;//写入成功，写入字节数增加 
		if(tmp<len)
		{
			printf("Wirte Error!");
			break;
		}
	}
	return ll;//实际写的字节数
}
int do_write(int fd,char*text,int len,char wstyle)//fd：文件描述符  text：要写入的文件指针  len 要写入的字节数  wstyle： 写入方式 
{
	fat* fat1,*fat2,*fatptr1,*fatptr2;
	unsigned char*buf,*blkptr;//buf为写入缓冲区 
	unsigned short blkno,blkoff;
	int i,ll;
	fat1=(fat*)(myvhard+BLOCKSIZE);//初始为起始位置 
	fat2=(fat*)(myvhard+3*BLOCKSIZE);
	buf=(unsigned char*)malloc(BLOCKSIZE);//申请1024B内存 
	if(buf==NULL)
	{
		printf("malloc failed!\n");
		return -1;
	}
	blkno=openfilelist[fd].first;//初始为当前文件的起始块号 
	blkoff=openfilelist[fd].count;//读写指针 
	fatptr1=fat1+blkno;
	fatptr2=fat2+blkno;
	/*将读写指针转化为逻辑块块号和块内偏移off，
	并利用打开文件表表项中的首块号及FAT表的相关内容将逻辑块块号转换成对应的磁盘块块号blkno
    */
	while(blkoff>=BLOCKSIZE)
	{
		blkno=fatptr1->id;
		if(blkno==END)
		{
			/*
			如果找不到对应的磁盘块则需要检索FAT为该逻辑块分配一新的磁盘块，
	 		并将对应的磁盘块块号blkno登记到FAT中，
	        若分配失败，则返回-1，并显示出错信息；
	       */
			blkno=findblock();//检索fat为该逻辑块分配一新的磁盘号 
			if(blkno==-1)
			{
				free(buf);//分配失败，释放内存 
				return -1;
			} 
			fatptr1->id=blkno;
			fatptr2->id=blkno;
			fatptr1=fat1+blkno;
			fatptr2=fat2+blkno;
			fatptr1->id=END;
			fatptr2->id=END;
		}
			//逻辑块号转化为相应磁盘块号
		else
		{
			fatptr1=fat1+blkno;
			fatptr2=fat2+blkno;
		}
		blkoff=blkoff-BLOCKSIZE;//让blkoff定位到文件最后一个磁盘块的读写位置
	}
    //blkno目前为磁盘块块号 
	ll=0;//实际写的字节数
	while(ll<len)//len是用户输入的字节数
	{
		blkptr=(unsigned char*)(myvhard+blkno*BLOCKSIZE);
		/* 
		如果是覆盖写，或者如果当前读写指针所对应的块内偏移off不等于0，
		则将块号为blkno的虚拟磁盘块全部1024B的内容读到缓冲区buf中；
		否则便用ASCII码0清空buf；
		*/
		for(i=0;i<BLOCKSIZE;i++)
			buf[i]=blkptr[i];//初始化buf 
		for(;blkoff<BLOCKSIZE;blkoff++)
		{
			/*
			将text中未写入的内容暂存到缓冲区buff的第off字节开始的位置，直到缓冲区满，
			或者接收到结束字符CTR+Z为止；将本次写入字节数记录到tmplen中
			*/ 
			buf[blkoff]=text[ll++];//将text内容写入buf 
			openfilelist[fd].count++;//读写指针移动 
			if(ll==len)
				break;
		}
		for(i=0;i<BLOCKSIZE;i++)
			blkptr[i]=buf[i];//将buf中1024B写入块号为blkno的块中 
		if(ll<len)//如果一个磁盘块写不下，则再分配一个磁盘块
		{
			blkno=fatptr1->id;
			if(blkno==END)
			{
				blkno=findblock();
				if(blkno==-1)
					break;
				fatptr1->id=blkno;
				fatptr2->id=blkno;
				fatptr1=fat1+blkno;
				fatptr2=fat2+blkno;
				fatptr1->id=END;
				fatptr2->id=END;
			}
			else
			{
				fatptr1=fat1+blkno;
				fatptr2=fat2+blkno;
			}
			blkoff=0;
		}
	}
	if(openfilelist[fd].count>openfilelist[fd].length)
		openfilelist[fd].length=openfilelist[fd].count;
	    openfilelist[fd].fcbstate=1;
	free(buf);
	return ll;
}

int my_read(int fd,int len)
{
	char text[MAXTEXT];
	int ll;
	if(fd<0||fd>=MAXOPENFILE)
	{
		printf("The File is not exist!\n");
		return -1;
	}
	openfilelist[fd].count=0;
	ll=do_read(fd,len,text);//ll是实际读出的字节数
	if(ll!=-1)
		printf("%s",text);
	else
		printf("Read Error!\n");
	return ll;
}

int do_read(int fd,int len,char*text)
{
	fat *fat1,*fatptr;//文件分配表 
	unsigned char*buf,*blkptr;
	unsigned short blkno,blkoff;
	int i,ll;
	fat1=(fat*)(myvhard+BLOCKSIZE);//取出当前虚拟磁盘块 myvhard：虚拟磁盘起始位置 
	buf=(unsigned char*)malloc(BLOCKSIZE); //暂存一个块 
	if(buf==NULL)
	{
		printf("malloc failed!\n");//分配失败 
		return -1; 
	}
	blkno=openfilelist[fd].first;//当前文件夹的起始盘块号 
	blkoff=openfilelist[fd].count;//读写指针在文件中的位置 
	if(blkoff>=openfilelist[fd].length)// 读写指针是否超过文件长度 
	{
		puts("Read out of range!");
		free(buf);
		return -1;
	}
   	fatptr=fat1+blkno;
 	while(blkoff>=BLOCKSIZE)//blkoff为最后一块盘块剩余的容量
	{
	 	blkno=fatptr->id;
		blkoff=blkoff-BLOCKSIZE;
		fatptr=fat1+blkno;
	}
	ll=0;
	while(ll<len)
	{
		blkptr=(unsigned char*)(myvhard+blkno*BLOCKSIZE);
		for(i=0;i<BLOCKSIZE;i++)//将最后一块盘块的内容读取到buf中
			buf[i]=blkptr[i];
		for(;blkoff<BLOCKSIZE;blkoff++)
		{
			text[ll++]=buf[blkoff];
			openfilelist[fd].count++;
			if(ll==len||openfilelist[fd].count==openfilelist[fd].length)
			break;
		}
		if(ll<len&&openfilelist[fd].count!=openfilelist[fd].length)
		{
			blkno=fatptr->id;
			if(blkno==END)
				break;
			blkoff=0;
			fatptr=fat1+blkno;
		}
	}
	text[ll]='\0';
	free(buf);
	return ll;
}

void my_exitsys()
{
	FILE*fp;
	while(curdir)
		curdir=my_close(curdir);
	fp=fopen(myfilename,"w");
	fwrite(myvhard,SIZE,1,fp);
	fclose(fp);
	free(myvhard);
}

unsigned short findblock()
{
	unsigned short i;
	fat*fat1,*fatptr;
	fat1=(fat*)(myvhard+BLOCKSIZE);
	for(i=7;i<SIZE/BLOCKSIZE;i++)
	{
		fatptr=fat1+i;
		if(fatptr->id==FREE)
			return i;
	}
	printf("Error,Can't find free block!\n");
	return -1;
}

int findopenfile()
{
	int i;
	for(i=0;i<MAXTEXT;i++)
	{
	if(openfilelist[i].topenfile==0)
		return i;
	}
	printf("Error,open too many files!\n");
	return -1;
}

int main()
{
	char cmd[15][10]={"cd","mkdir","rmdir","ls","create","rm","open","close","write","read","exit"};
	char s[30],*sp;
	int cmdn,flag=1,i;
	startsys();
	printf("*********************FileSystemV1.0*******************************\n\n");
	printf("命令名\t\t命令参数\t\t命令说明\n\n");
	printf("cd\t\t目录名(路径名)\t\t切换当前目录到指定目录\n");
	printf("mkdir\t\t目录名\t\t\t在当前目录创建新目录\n");
	printf("rmdir\t\t目录名\t\t\t在当前目录删除指定目录\n");
	printf("ls\t\t无\t\t\t显示当前目录下的目录和文件\n");
	printf("create\t\t文件名\t\t\t在当前目录下创建指定文件\n");
	printf("rm\t\t文件名\t\t\t在当前目录下删除指定文件\n");
	printf("open\t\t文件名\t\t\t在当前目录下打开指定文件\n");
	printf("write\t\t无\t\t\t在打开文件状态下，写该文件\n");
	printf("read\t\t无\t\t\t在打开文件状态下，读取该文件\n");
	printf("close\t\t无\t\t\t在打开文件状态下，读取该文件\n");
	printf("exit\t\t无\t\t\t退出系统\n\n");
	printf("*********************************************************************\n\n");
	while(flag)
	{
		printf("%s>",openfilelist[curdir].dir);
		gets(s);
		cmdn=-1;
		if(strcmp(s," "))
		{
			sp=strtok(s," ");
			for(i=0;i<15;i++)
			{
				if(strcmp(sp,cmd[i])==0)
				{
					cmdn=i;
					break;
				}
			}
		printf("%d\n",cmdn);
		switch(cmdn)
		{
			case 0:
				sp=strtok(NULL," ");
				if(sp&&(openfilelist[curdir].attribute&0x20))
					my_cd(sp);
				else
					printf("Please input the right command.\n");
				break;
			case 1:
				sp=strtok(NULL," ");
				if(sp&&(openfilelist[curdir].attribute&0x20))
					my_mkdir(sp);
				else
					printf("Please input the right command.\n");
				break;
			case 2:
				sp=strtok(NULL," ");
				if(sp&&(openfilelist[curdir].attribute&0x20))
					my_rmdir(sp);
				else
					printf("Please input the right command.\n");
				break;
			case 3:
				if(openfilelist[curdir].attribute&0x20)
					my_ls();
				else
					printf("Please input the right command.\n");
				break;
			case 4:
				sp=strtok(NULL," ");
				if(sp&&(openfilelist[curdir].attribute&0x20))
					my_create(sp);
				else
					printf("Please input the right command.\n");
				break;
			case 5:
				sp=strtok(NULL," ");
				if(sp&&(openfilelist[curdir].attribute&0x20))
					my_rm(sp);
				else
					printf("Please input the right command.\n");
				break;
			case 6:
				sp=strtok(NULL," ");
				if(sp&&(openfilelist[curdir].attribute&0x20))
				{
					if(strchr(sp,'.'))//查找sp中'.'首次出现的位置
						curdir=my_open(sp);
					else
						printf("the open file should have exname.\n");
				}
				else
					printf("Please input the right command.\n");
				break;
			case 7:
				if(!(openfilelist[curdir].attribute&0x20))
					curdir=my_close(curdir);
				else
					printf("No files opened.\n");
				break;
			case 8:
				if(!(openfilelist[curdir].attribute&0x20))
					my_write(curdir);
				else
					printf("No files opened.\n");
				break;
			case 9:
				if(! (openfilelist[curdir].attribute&0x20))
					my_read(curdir,openfilelist[curdir].length);
				else
					printf("No files opened.\n");
				break;
			case 10:
				if(openfilelist[curdir].attribute &0x20)
				{
					my_exitsys();
					flag=0;
				}
				else
					printf("Please input the right command.\n");
				break;
			default:
				printf("Please input the right command.\n");
				break;
			}
		}
	}
	return 0;
}

