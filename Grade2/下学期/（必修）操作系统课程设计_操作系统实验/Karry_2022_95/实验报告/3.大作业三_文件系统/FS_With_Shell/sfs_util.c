
#include "sfs_util.h"
#include "disk_emu.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int fatID = 0;

// 初始化FAT，将FAT中的所有节点设置为自由节点
void FAT_init(FileAllocationTable *fat)
{
	// 除了第0个和第1个块，其它全部块初始化均为-1代表没有被分配
	for (int i = 0; i < MAX_DISK; i++)
	{
		fat->table[i] = -1;
	}
	
}

// 获取一个自由块，代表
int FAT_getFreeNode(FileAllocationTable *fat)
{

	int i;
	for (i = 2; i < MAX_DISK; i++)
	{
		if (fat->table[i] == -1)
		{
			// fat->count++;		// 被占用块 + 1
			return i; 			// 返回第i个块
		}
	}
	
	fprintf(stderr, "Error: Cannot get free block in FAT.\n");
	// exit(0);
	return -1;
}

// 初始化目录表
void DirectoryDescriptor_init(DirectoryDescriptor *root)
{
	// 将目录的计数初始化为0
	root->count = 0;
}

/*
int DirectoryDescriptor_getFreeSpot(DirectoryDescriptor *root)
{

	if (++root->count < FILE_LIST_SIZE)
	{
		return root->count;
	}
	else
	{

		int i;
		for (i = 0; i < MAX_FILE; i++)
		{
			if (root->table[i].size == EMPTY)
			{
				return i;
			}
		}
	}
	root->count--;
	fprintf(stderr, "Error: Cannot get free block in DD.\n");
	return -1;
}
*/

// 打开文件，成功会非0的整数代表文件ID
// 当前系统中不存在该文件，返回 -1
// 当前系统中存在该文件，并且已经打开，返回 -2
int getIndexOfFileInDirectory(char *name, DirectoryDescriptor *rootDir)
{

	int i, fileID = -1;

	// Looks for the file and gets its index.
	for (i = 0; i < rootDir->count; i++)
	{
		if (!strcmp(rootDir->table[i].filename, name))
		{
			fileID = i;
			break;
		}
	}

	// Checks if the file was correctly closed.
	if (fileID != -1)
	{
		if (rootDir->table[fileID].fas.opened == 1)
		{
			// fprintf(stderr, "Warning: '%s' is already open.\n", name);
			return -2;
		}
	}

	return fileID;
}

void FileDescriptor_createFile(char *file_name, FileDescriptor *file)
{
	strcpy(file->filename, file_name);
	file->fas.opened = 1;
	file->size = 0;
	file->timestamp = time(NULL);
}
