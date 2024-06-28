;=========================================================
; 文件名: ex1.ASM
; 功能描述: 利用DA0832产生三角波，通过延时变化波形
;=========================================================
STACK SEGMENT STACK
          DW 32 DUP(?)
STACK ENDS
CODE SEGMENT
          ASSUME CS:CODE, SS:STACK
    START:MOV    AX, 00H
          MOV    DX, 600H
    L1:   MOV    AL, 00H
          MOV    CX, 0FFH
    AA1:  OUT    DX, AL
          CALL   DELAY
          INC    AL
          LOOP   AA1
          MOV    CX, 0FFH
    AA2:  OUT    DX, AL
          CALL   DELAY
          DEC    AL
          LOOP   AA2
          JMP    L1
    DELAY:PUSH   CX
          MOV    CX, 0FFH
    AA3:  PUSH   AX
          POP    AX
          LOOP   AA3
          POP    CX
          RET
CODE ENDS
      END START
