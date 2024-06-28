;=========================================================
; 文件名: 02.ASM
; 功能描述: 电子发声设计实验
;=========================================================
; 端口定义
IOY3			EQU 06C0H

MY8254_COUNT0	EQU IOY3+00H   ;8254计数器0端口地址
MY8254_COUNT1	EQU IOY3+02H   ;8254计数器1端口地址
MY8254_COUNT2	EQU IOY3+04H   ;8254计数器2端口地址
MY8254_MODE		EQU IOY3+06H   ;8254控制寄存器端口地址
                              
STACK1 SEGMENT STACK
	       DW 256 DUP(?)
STACK1 ENDS

DATA SEGMENT
	FREQ_LIST DW 371,495,495,495,624,556,495,556,624    	;频率表
	          DW 495,495,624,742,833,833,833,742,624
	          DW 624,495,556,495,556,624,495,416,416,371
	          DW 495,833,742,624,624,495,556,495,556,833
	          DW 742,624,624,742,833,990,742,624,624,495
	          DW 556,495,556,624,495,416,416,371,495,0
	TIME_LIST DB 4,  6,  2,  4,  4,  6,  2,  4,  4      	;时间表
	          DB 6,  2,  4,  4, 12,  1,  3,  6,  2
	          DB 4,  4,  6,  2,  4,  4,  6,  2,  4,  4
	          DB 12,  4,  6,  2,  4,  4,  6,  2,  4,  4
	          DB 6,  2,  4,  4, 12,  4,  6,  2,  4,  4
	          DB 6,  2,  4,  4,  6,  2,  4,  4,  12
DATA ENDS

CODE SEGMENT
	      ASSUME CS:CODE,DS:DATA

	START:MOV    AX,DATA
	      MOV    DS,AX

	      MOV    DX,MY8254_MODE     	;初始化8254工作方式
	      MOV    AL,36H             	;定时器0、方式3
	      OUT    DX,AL

	BEGIN:MOV    SI,OFFSET FREQ_LIST	;装入频率表起始地址
	      MOV    DI,OFFSET TIME_LIST	;装入时间表起始地址

	PLAY: MOV    DX,0FH             	;输入时钟为1MHz，1M = 0F4240H
	      MOV    AX,4240H
	      DIV    WORD PTR [SI]      	;取出频率值计算计数初值，0F4240H / 输出频率
	      MOV    DX,MY8254_COUNT0
	      OUT    DX,AL              	;装入计数初值
	      MOV    AL,AH
	      OUT    DX,AL

	      MOV    DL,[DI]            	;取出演奏相对时间，调用延时子程序
	      CALL   DALLY

	      ADD    SI,2
	      INC    DI
	      CMP    WORD PTR [SI],0    	;判断是否到曲末？
	      JE     BEGIN

	      JMP    PLAY

DALLY PROC                      		;延时子程序
	D0:   MOV    CX,0010H
	D1:   MOV    AX,0FF0H
	D2:   DEC    AX
	      JNZ    D2
	      LOOP   D1
	      DEC    DL
	      JNZ    D0
	      RET
DALLY ENDP

CODE ENDS
		END START
