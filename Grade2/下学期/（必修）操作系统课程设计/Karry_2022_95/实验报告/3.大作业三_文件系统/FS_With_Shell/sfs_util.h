#ifndef SFS_API_UTIL
#define SFS_API_UTIL
#include "sfs_header.h"

void FAT_init(FileAllocationTable *fat);
int FAT_getFreeNode(FileAllocationTable *fat);
void DirectoryDescriptor_init(DirectoryDescriptor *root);
int getIndexOfFileInDirectory(char *name, DirectoryDescriptor *rootDir);
void FileDescriptor_createFile(char *name, FileDescriptor *file);

#endif