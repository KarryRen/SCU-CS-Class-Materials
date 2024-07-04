;=========================================================
; 文件名: 01.ASM
; 功能描述: 定时应用实验，产生1s方波
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
	      MOV    AL, 0E8H          	;03E8H=1000
	      OUT    DX, AL
	      MOV    AL, 03H
	      OUT    DX, AL

	      MOV    DX, CON8254       	;8254
	      MOV    AL, 76H           	;计数器1，方式3
	      OUT    DX, AL
		
	      MOV    DX, B8254
	      MOV    AL, 0E8H
	      OUT    DX, AL
	      MOV    AL, 03H
	      OUT    DX, AL

	AA1:  NOP
	      JMP    AA1
		
CODE ENDS
		END  START