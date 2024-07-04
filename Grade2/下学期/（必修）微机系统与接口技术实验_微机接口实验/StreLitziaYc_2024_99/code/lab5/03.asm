;=========================================================
; 文件名: 03.ASM
; 功能描述: 计数产生中断实验
;=========================================================
A8254 EQU 06C0H
B8254 EQU 06C2H
C8254 EQU 06C4H
CON8254 EQU 06C6H
SSTACK SEGMENT STACK
           DW 32 DUP(?)
SSTACK ENDS
CODE SEGMENT
          ASSUME CS:CODE, SS:SSTACK
    START:PUSH   DS
          MOV    AX, 0000H
          MOV    DS, AX
          MOV    AX, OFFSET IRQ7       ;取中断入口地址
          MOV    SI, 003CH             ;中断矢量地址
          MOV    [SI], AX              ;填 IRQ7 的偏移矢量
          MOV    AX, CS                ;段地址
          MOV    SI, 003EH
          MOV    [SI], AX              ;填 IRQ7 的段地址矢量
          CLI
          POP    DS
    ;初始化主片 8259
          MOV    AL, 11H
          OUT    20H, AL               ;ICW1
          MOV    AL, 08H
          OUT    21H, AL               ;ICW2
          MOV    AL, 04H
          OUT    21H, AL               ;ICW3
          MOV    AL, 01H
          OUT    21H, AL               ;ICW4
          MOV    AL, 6FH               ;OCW1
          OUT    21H, AL
    ;8254
          MOV    DX, CON8254
          MOV    AL, 10H               ;计数器 0，方式 0
          OUT    DX, AL
          MOV    DX, A8254
          MOV    AL, 04H
          OUT    DX, AL
          STI
    AA1:  JMP    AA1
    IRQ7: MOV    DX, A8254
          MOV    AL, 04H
          OUT    DX, AL
          MOV    AX, 014DH
          INT    10H                   ;显示字符 M
          MOV    AX, 0120H
          INT    10H
          MOV    AL, 20H
          OUT    20H, AL               ;中断结束命令
          IRET
CODE ENDS
END START