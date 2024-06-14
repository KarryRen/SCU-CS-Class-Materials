; 产生梯形波
SSTACK SEGMENT STACK
           DW 32 DUP(?)
SSTACK ENDS
CODE SEGMENT
           ASSUME CS:CODE
    START: MOV    AX, 00H      ;
           MOV    CX, 0FH

    AA1:   
           MOV    DX, 600H
           MOV    AL, 00H
           OUT    DX, AL
           CALL   DELAY2
		
    AA2:   
           MOV    DX, 600H
           OUT    DX, AL
           CALL   DELAY1
           CMP    AL, 0FFH
           JE     AA3
           INC    AL
           JMP    AA2
		
    AA3:   MOV    DX, 600H
           MOV    AL, 0FFH
           OUT    DX, AL
           CALL   DELAY2
		
    AA4:   
           MOV    DX, 600H
           OUT    DX, AL
           CALL   DELAY1
           CMP    AL, 00H
           JE     AA1
           DEC    AL
           JMP    AA4
    DELAY1:
           PUSH   CX
           MOV    CX,00FFH
    CC2:   
           PUSH   AX
           POP    AX
           LOOP   CC2
           POP    CX
           RET
		
    DELAY2:
           PUSH   CX
           MOV    CX,0FFFFH
    CC1:   PUSH   AX
           POP    AX
           LOOP   CC1
           POP    CX
           RET
CODE ENDS
		END START