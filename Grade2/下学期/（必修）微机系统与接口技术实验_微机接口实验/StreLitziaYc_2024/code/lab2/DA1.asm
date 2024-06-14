;=========================================================
; 文件名: DA1.ASM
; 功能描述: 利用DA0832产生锯齿波，通过延时变化波形
;=========================================================

STACK SEGMENT STACK
	      DW 32 DUP(?)
STACK ENDS

CODE SEGMENT
	      ASSUME CS:CODE, SS:STACK
	START:MOV    AX, 00H
	      MOV    DX, 600H
	      MOV    AL, 00H
	AA1:  OUT    DX, AL
	      CALL   DELAY
	      INC    AL
	      JMP    AA1
	   
	DELAY:PUSH   CX
	      MOV    CX, 03FFH
	AA2:  PUSH   AX
	      POP    AX
	      LOOP   AA2
	      POP    CX
	      RET
	   
CODE ENDS
	   END START