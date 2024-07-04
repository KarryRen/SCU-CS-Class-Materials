;=========================================================
; 文件名: 03.ASM
; 功能说明: 按照字节在内存中写入16个数字
;=========================================================
SSTACK SEGMENT STACK
           DW 32 DUP(?)
SSTACK ENDS
CODE SEGMENT
START PROC FAR
          ASSUME CS:CODE
          MOV    AX, 8000H    ; 存储器扩展空间段地址
          MOV    DS, AX
    AA0:  MOV    SI, 0000H    ; 数据首地址
          MOV    CX, 0010H
          MOV    AX, 0000H
    AA1:  MOV    [SI], AX
          INC    AX
          INC    SI
          LOOP   AA1
          MOV    AX,4C00H
          INT    21H          ;程序终止
START ENDP
CODE ENDS
END START