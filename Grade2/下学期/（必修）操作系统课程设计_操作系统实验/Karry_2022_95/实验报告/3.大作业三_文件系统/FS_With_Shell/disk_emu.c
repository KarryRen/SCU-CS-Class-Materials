#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "disk_emu.h"

FILE* fp = NULL;
double L, p;
double r;
int BLOCK_SIZE, MAX_BLOCK, MAX_RETRY, lru;

/*----------------------------------------------------------*/
/*Close the disk file filled when you don't need it anymore. */
/*----------------------------------------------------------*/
int ds_close()
{
    if(NULL != fp)
    {
        fclose(fp);
    }
    return 0;
}

/*---------------------------------------*/
/*Initializes a disk file filled with 0's*/
/*---------------------------------------*/
int ds_init_fresh(char *filename, int block_size, int num_blocks)
{
    int i, j;
    
    /*Set up latency at 0.02 second*/
    L = 00000.f;
    /*Set up failure at 10%*/
    p = -1.f;
    /*Set up max retry attempts after failure to 3*/
    MAX_RETRY = 3;

    BLOCK_SIZE = block_size;
    MAX_BLOCK = num_blocks;
    
    /*Initializes the random number generator*/
    srand((unsigned int)(time( 0 )) );
    
    /*Creates a new file*/
    fp = fopen (filename, "w+b");

    if (fp == NULL)
    {
        printf("Could not create new disk file %s\n\n", filename);
        return -1;
    }
    
    /*Fills the file with 0's to its given size*/
    for (i = 0; i < MAX_BLOCK; i++)
    {
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            fputc(0, fp);
        }
    }
    return 0;
}
/*----------------------------*/
/*Initializes an existing disk*/
/*----------------------------*/
int ds_init(char *filename, int block_size, int num_blocks)
{
    /*Set up latency at 0.02 second*/
    L = 00000.f;
    /*Set up failure at 10%*/
    p = -1.f;
    /*Set up max retry attempts after failure to 3*/
    MAX_RETRY = 3;

    BLOCK_SIZE = block_size;
    MAX_BLOCK = num_blocks;
    
    /*Initializes the random number generator*/
    srand((unsigned int)(time( 0 )) );
    
    /*Opens a file*/
    fp = fopen (filename, "r+b");

    if (fp == NULL)
    {
        printf("Could not open %s\n\n", filename);
        return -1;
    }
    return 0;
}

/*-------------------------------------------------------------------*/
/*Reads a series of blocks from the disk into the buffer             */
/*-------------------------------------------------------------------*/
int ds_read_blocks(int start_node_index, int nblocks, void *buffer)
{
    int i, j, e, s;
    e = 0;
    s = 0;

    if (start_node_index == -1) return -1;

    /*Sets up a temporary buffer*/
    void* blockRead = (void*) malloc(BLOCK_SIZE);

    /*Checks that the data requested is within the range of addresses of the disk*/
    if (start_node_index + nblocks > MAX_BLOCK)
    {
        printf("out of bound error\n");
        return -1;
    }

    /*Goto the data requested from the disk*/
    fseek(fp, start_node_index * BLOCK_SIZE, SEEK_SET);

    /*For every block requested*/
    for (i = 0; i < nblocks; ++i)
    {
        /*Pause until the latency duration is elapsed*/
        usleep(L);

        s++;
        fread(blockRead, BLOCK_SIZE, 1, fp);

        for (j = 0; j < BLOCK_SIZE; j++)
        {
            memcpy(buffer+(i*BLOCK_SIZE), blockRead, BLOCK_SIZE);  
        }
    }

    free(blockRead);

    /*If no failure return the number of blocks read, else return the negative number of failures*/
    if (e == 0)
        return s;
    else
        return e;
}

/*------------------------------------------------------------------*/
/*Writes a series of blocks to the disk from the buffer             */
/*------------------------------------------------------------------*/
int ds_write_blocks(int start_node_index, int nblocks, void *buffer)
{
    int i, e, s;
    e = 0;
    s = 0;

    void* blockWrite = (void*) malloc(BLOCK_SIZE);

    /*Checks that the data requested is within the range of addresses of the disk*/
    if (start_node_index + nblocks > MAX_BLOCK)
    {
        printf("out of bound error\n");
        exit(0);
        return -1;
    }
	
    /*Goto where the data is to be written on the disk*/        
    fseek(fp, start_node_index * BLOCK_SIZE, SEEK_SET);
	
    /*For every block requested*/        
    for (i = 0; i < nblocks; ++i)
    {
        /*Pause until the latency duration is elapsed*/
        usleep(L);

        memcpy(blockWrite, buffer+(i*BLOCK_SIZE), BLOCK_SIZE);

        fwrite(blockWrite, BLOCK_SIZE, 1, fp);
        fflush(fp);
        s++;
    }
    free(blockWrite);

    /*If no failure return the number of blocks written, else return the negative number of failures*/
    if (e == 0)
        return s;
    else
        return e;
}
