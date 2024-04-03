#include "sfs_api.h"
#include "disk_emu.h"
#include "sfs_header.h"
#include "sfs_util.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

DirectoryDescriptor root;
FileAllocationTable fat;

void sfs_system_info()
{
    printf("\n ==== File System Info ==== \n");
    printf("\nDisk Size %d Bytes\n", NB_BLOCK * MAX_DISK);
    printf("\nAlready Use %d Bytes, (%.2f)%% \n", NB_BLOCK * fat.count, (fat.count * 100.0f / MAX_DISK));
    printf("\nFile Count %d \n", root.count);
}

void sfs_system_init()
{

    int fresh = access(SAVE_FILE_NAME, 0);

    if (fresh)
    {
        printf("文件不存在,创建文件!\n");
        // 创建磁盘文件
        ds_init_fresh(SAVE_FILE_NAME, NB_BLOCK, MAX_DISK);
        // 初始化 FAT
        FAT_init(&fat);
        // 初始化 目录
        DirectoryDescriptor_init(&root);

        ds_write_blocks(0, 1, (void *)&root); //  第0个块保存有目录表
        ds_write_blocks(1, 1, (void *)&fat);  // 第1个块保存FAT
        // 第0和第1个块已经被分配
        fat.table[0] = 0;
        fat.table[1] = 1;
        fat.count = 2;
    }
    else
    {
        printf("文件存在，初始化文件系统!\n");
        ds_init(SAVE_FILE_NAME, NB_BLOCK, MAX_DISK);
        ds_read_blocks(1, 1, (void *)&fat);
        ds_read_blocks(0, 1, (void *)&root);
    }
}

void sfs_system_close()
{
    // 系统退出之前关闭所有文件
    for (int i = 0; i < FILE_LIST_SIZE; i++)
    {
        root.table[i].fas.opened = 0;
    }

    ds_write_blocks(0, 1, (void *)&root);
    ds_write_blocks(1, 1, (void *)&fat);
    ds_close();
}

void sfs_block_info(int limit)
{
    printf("Count %d\n", fat.count);
    for (int i = 0; i < limit; i++)
    {
        printf("\t %d", fat.table[i]);
    }
    printf("\n");

}

void sfs_ls()
{
    int i;
    printf("\n");
    for (i = 0; i < root.count; i++)
    {
        if (root.table[i].size >= 0)
        {
            float kb = root.table[i].size / 1024.0;
            char *tm = ctime(&root.table[i].timestamp);
            tm[24] = '\0';
            printf("%25s\t%.2fKB\t%s\n", tm, kb, root.table[i].filename);
        }
    }
}

int sfs_open(char *name)
{
    int fileID = getIndexOfFileInDirectory(name, &root);
    // 如果找到了文件，将文件打开并返回
    if (fileID != -1)
    {
        root.table[fileID].fas.opened = 1;
        return fileID;
    }
    // 没有找到文件，则新增一个文件，初始化该文件的FCB，并将该FCB加入到目录中
    fileID = root.count++;
    FileDescriptor_createFile(name, &(root.table[fileID]));

    // 给当前文件分配一个新的块
    int free_node_index = FAT_getFreeNode(&fat);
    root.table[fileID].fat_index = free_node_index;
    fat.table[free_node_index] = free_node_index; // 文件最后一个块的 内容等于它本身的编号
    fat.count++;
    return fileID;
}

int sfs_close(int fileID)
{
    root.table[fileID].fas.opened = 0;
    return 0;
}

int sfs_write(int fileID, char *buf, int length)
{
    if (root.table[fileID].fas.opened == 0)
        return -1;

    // 写入之间回收 该文件所占的全部空间
    sfs_rec_block(root.table[fileID].fat_index);
    //  写入文件长度
    root.table[fileID].size = length;

    // 声明一个和块大小相等的缓冲区
    void *blockWrite = (void *)malloc(NB_BLOCK);
    
    if (blockWrite == 0) return -1;
    // 全部置为0
    int16_t last_node_index = -1;
    memset(blockWrite, 0, NB_BLOCK);
    
    while (length > 0)
    {
        if (length >= NB_BLOCK)
        {
            memcpy(blockWrite, (void *)buf, NB_BLOCK);

            int16_t free_node_index = FAT_getFreeNode(&fat); // 获取一个空闲块的编号
            ds_write_blocks(free_node_index, 1, blockWrite); // 写入一个块
            if (last_node_index != -1)
            {
                fat.table[last_node_index] = free_node_index;
                last_node_index = free_node_index;
            }
            else
            {
                last_node_index = free_node_index;
                root.table[fileID].fat_index = free_node_index; //  更新 FCB 中的初始块中的信息
                
            }
            fat.table[last_node_index] = last_node_index;
            fat.count ++;
            length -= NB_BLOCK; 
            buf += NB_BLOCK ; // 指针后移
        }
        else
        {
            memcpy(blockWrite, (void *)buf, length);
            int16_t free_node_index = FAT_getFreeNode(&fat);
            ds_write_blocks(free_node_index, 1, blockWrite); // 写入一个块
            if (last_node_index != -1)
            {
                fat.table[last_node_index] = free_node_index;
                last_node_index = free_node_index;
            }
            else
            {
                last_node_index = free_node_index;
                root.table[fileID].fat_index = free_node_index;
            }
            fat.table[last_node_index] = last_node_index;
            fat.count ++;
            buf += length;
            length -= length; 
        }
    }
    fat.table[last_node_index] = last_node_index; //标识文件结束
    free(blockWrite);
    return 0;
}

int sfs_read(int fileID, char *buf, int length)
{
    if (root.table[fileID].fas.opened == 0)
        return -1;
    
    int8_t read_flag = 1;

    void *blockRead = (void *)malloc(NB_BLOCK);
    // 全部置为0
    int16_t read_node_index = root.table[fileID].fat_index;

    memset(blockRead, 0, NB_BLOCK);

    while (length > 0 )
    {
        if (length >= NB_BLOCK)
        {
            ds_read_blocks(read_node_index, 1, blockRead);
            memcpy(buf, blockRead, NB_BLOCK);
            length -= NB_BLOCK;
            buf += (NB_BLOCK); // 指针后移
        }
        else
        {
            ds_read_blocks(read_node_index, 1, blockRead);
            memcpy(buf, blockRead, length);
            buf += (length); // 指针后移
            length -= length;
        }
        int16_t next_read_node_index = fat.table[read_node_index];
        if (next_read_node_index == read_node_index)
            break;
        else
            read_node_index = next_read_node_index;
    }
    free(blockRead);
    return root.table[fileID].size;
}

void sfs_del(int fileID)
{
    // printf("file block index is %d\n", root.table[fileID].fat_index);
    
    sfs_rec_block(root.table[fileID].fat_index);
    for (int i = fileID; i < root.count - 1; i++)
    {
        memcpy(&root.table[i], &root.table[i+1], sizeof(FileDescriptor));
    }
    root.count--;
}

void sfs_rec_block(unsigned short block_id)
{
    if (fat.table[block_id] == block_id) //文件的最后一个块
    {
        fat.table[block_id] = -1;
        fat.count--;
    }
    else
    {
        uint16_t next_block_index = fat.table[block_id];
        fat.table[block_id] = -1;
        fat.count--;
        sfs_rec_block(next_block_index);
    }
}