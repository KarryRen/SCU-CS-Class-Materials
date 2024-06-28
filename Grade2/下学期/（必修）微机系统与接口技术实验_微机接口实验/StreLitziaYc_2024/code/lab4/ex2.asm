;=========================================================
; 文件名: ex2.ASM
; 功能描述: 在ex1.asm的基础上加入8255，实现按动一次KK1后减少一倍波形频率
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
	START:

	      MOV    BX,4E20H
	AA0:  
		
		
	      MOV    DX, CON8254       	;8254
	      MOV    AL, 36H           	;计数器0，方式3
	      OUT    DX, AL
		
	      MOV    DX, A8254
	      MOV    AL, BL
	      OUT    DX, AL
	      MOV    AL, BH
	      OUT    DX, AL

	AA1:  NOP
	      MOV    DX, 0640H
	      IN     AL, DX
		
	      CALL   DELAY
	      CALL   DELAY
	      CALL   DELAY
	      CALL   DELAY
	      CALL   DELAY
	      CALL   DELAY
		
	      AND    AL,01H
	      CMP    AL,01H
	      JZ     AA3
	      JMP    AA1
		
	AA3:  
	      ROR    BX,01H
	      JMP    AA0
		
	DELAY:PUSH   CX
	      MOV    CX, 0F000H
	AA2:  PUSH   AX
	      POP    AX
	      LOOP   AA2
	      POP    CX
	      RET
		
CODE ENDS
		END  START