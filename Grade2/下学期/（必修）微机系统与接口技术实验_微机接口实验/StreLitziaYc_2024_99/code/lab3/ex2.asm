;=========================================================
; 文件名: ex2.ASM
; 功能描述: 把开关作为输入并计数
;=========================================================
CODE SEGMENT
          ASSUME CS:CODE
    START:MOV    DX, 0646H
          MOV    AL, 90H
          OUT    DX, AL
    L1:   MOV    BL, 00H
    AA1:  MOV    DX, 0640H
          IN     AL, DX
          CMP    AL, 00H
          JNZ    AA3
          JMP    AA1
    AA3:  INC    BL
          CMP    BL, 10H
          JZ     L1
    AA4:  MOV    DX, 0642H
          MOV    AL, BL
          OUT    DX, AL
          CALL   DELAY
          CALL   DELAY
          JMP    AA1
    DELAY:PUSH   CX
          MOV    CX, 0F000H
    AA2:  PUSH   AX
          POP    AX
          LOOP   AA2
          POP    CX
          RET
CODE ENDS
        END START
