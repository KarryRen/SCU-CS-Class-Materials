;=========================================================
; 文件名: ex1.ASM
; 功能描述: 使用8254定时功能，只用一个通道实现输出1Hz的方波
;=========================================================
A8254    EQU  0600H
B8254    EQU  0602H
C8254    EQU  0604H
CON8254  EQU  0606H

SSTACK SEGMENT STACK
	       DW 32 DUP(?)
SSTACK ENDS

CODE SEGMENT
	      ASSUME CS:CODE, SS:SSTACK
	START:MOV    DX, CON8254       	;8254
	      MOV    AL, 36H           	;计数器0，方式3
	      OUT    DX, AL
		
	      MOV    DX, A8254
	      MOV    AL, 020H          	;03E8H=1000
	      OUT    DX, AL
	      MOV    AL, 04EH
	      OUT    DX, AL

	AA1:  NOP
	      JMP    AA1
		
CODE ENDS
		END  START