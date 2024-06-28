;=========================================================
; 文件名: 01.ASM
; 功能描述: 基本输入输出实验
;=========================================================
SSTACK SEGMENT STACK
           DW 32 DUP(?)
SSTACK ENDS
CODE SEGMENT
          ASSUME CS:CODE
    START:MOV    DX, 0646H
          MOV    AL, 90H
          OUT    DX, AL
    AA1:  MOV    DX, 0640H
          IN     AL, DX
          CALL   DELAY
          MOV    DX, 0642H
          OUT    DX, AL
          JMP    AA1
    DELAY:PUSH   CX
          MOV    CX, 0F00H
    AA2:  PUSH   AX
          POP    AX
          LOOP   AA2
          POP    CX
          RET
CODE ENDS
END START