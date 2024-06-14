;=========================================================
; 文件名: AD1.ASM
; 功能说明: 进行AD采样，将结果显示。 片选为IOY1
;=========================================================

SSTACK SEGMENT STACK
	       DW 64 DUP(?)
SSTACK ENDS

PUBLIC	VALUE			;设置全局变量以便变量监视

DATA SEGMENT
	VALUE DB ?
DATA ENDS

CODE SEGMENT
	      ASSUME CS:CODE,DS:DATA

	START:MOV    AX, DATA
	      MOV    DS, AX
	      MOV    DX, 640H       	;启动AD采样
	      OUT    DX, AL
	      CALL   DALLY
	      IN     AL, DX         	;读AD采样结果
	      MOV    VALUE, AL      	;将结果送变量
		
	      JMP    START          	;在此处设置断点
	DALLY:PUSH   CX
	      PUSH   AX
	      MOV    CX, 100H
	A5:   MOV    AX, 0800H
	A6:   DEC    AX
	      JNZ    A6
	      LOOP   A5
	      POP    AX
	      POP    CX
	      RET
	
CODE ENDS
		END START
