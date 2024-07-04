;=========================================================
; 文件名: 02.ASM
; 功能描述: 实现流水灯
;=========================================================
SSTACK SEGMENT STACK
           DW 32 DUP(?)
SSTACK ENDS
CODE SEGMENT
          ASSUME CS:CODE
    START:MOV    DX, 0646H
          MOV    AL, 80H
          OUT    DX, AL
          MOV    BX, 8001H
    AA1:  MOV    DX, 0640H
          MOV    AL, BH
          OUT    DX, AL
          ROR    BH, 1
          MOV    DX, 0642H
          MOV    AL, BL
          OUT    DX, AL
          ROL    BL, 1
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