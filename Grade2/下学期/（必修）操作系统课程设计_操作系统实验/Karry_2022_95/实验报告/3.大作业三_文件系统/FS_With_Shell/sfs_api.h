#ifndef SYS_API_H
#define SYS_API_H

#define SAVE_FILE_NAME "disk.sfs"

// system
void sfs_system_init();
void sfs_system_close();
void sfs_block_info(int limit);

// directory
void sfs_ls();

// file
int sfs_open(char *name);
int sfs_close(int fileID);
int sfs_write(int fileID, char *buf, int length);
int sfs_read(int fileID, char *buf, int length);
void sfs_del(int fileID);
// 回收文件所占的block
void sfs_rec_block(unsigned short block_id);
#endif
