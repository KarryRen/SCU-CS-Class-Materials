
#ifndef min
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

#ifndef SFS_API_HEADER
#define SFS_API_HEADER

#include <time.h>
#include <stdint.h>

#define NB_BLOCK 4096   // 每个块有4096个 byte     
#define MAX_DISK 2047   // 磁盘总共有多少个块

typedef struct FileAccessStatus {       // 文件当前状态
    int opened;                         // 该文件是否已经打开
} FileAccessStatus;

typedef struct FileDescriptor {         // FCB
    char                filename[32];   // 文件名
    int                 fat_index;      // 在fat 上的index
    time_t              timestamp;      // 创建时间
    int                 size;           // 文件大小
	FileAccessStatus    fas;            // 文件状态
} FileDescriptor;

#define FILE_LIST_SIZE NB_BLOCK / sizeof(FileDescriptor)

// 目录结构体 整个文件系统中只有一个
typedef struct DirectoryDescriptor {    // 描述目录信息

    // 文件列表，最多保存 NB_BLOCK / sizeof(FileDescriptor) 个文件
    FileDescriptor table[FILE_LIST_SIZE];     
    int count;                          // 文件个数
} DirectoryDescriptor;

// 文件分配表，整个文件系统只有一个
typedef struct FileAllocationTable {
    int16_t table[MAX_DISK];           // 初始的时候为全-1，代表没有被分配
    int16_t count;                          // 已经分配的块的个数
} FileAllocationTable;

#endif
