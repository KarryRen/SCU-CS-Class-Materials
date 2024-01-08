#ifndef DISK_EMU_H
#define DISK_EMU_H

// 第一次创建初始化文件系统
int ds_init_fresh(char *filename, int block_size, int num_blocks);
// 读取已经保存的文件系统文件
int ds_init(char *filename, int block_size, int num_blocks);
// 从start_node_index开始读取连续nblocks的内容
int ds_read_blocks(int start_node_index, int nblocks, void *buffer);
// 从start_node_index开始连续写入nblocks的内容
int ds_write_blocks(int start_node_index, int nblocks, void *buffer);
// 关闭当前打开的文件系统
int ds_close();

#endif
