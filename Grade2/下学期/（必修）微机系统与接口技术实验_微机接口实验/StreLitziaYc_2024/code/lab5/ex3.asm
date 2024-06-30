IOY3          EQU  06C0H
MY8254_COUNT0 EQU  IOY3+00H   ; 8254 计数器 0 端口地址
MY8254_COUNT1 EQU  IOY3+02H   ; 8254 计数器 1 端口地址
MY8254_COUNT2 EQU  IOY3+04H   ; 8254 计数器 2 端口地址
MY8254_MODE   EQU  IOY3+06H   ; 8254 控制寄存器端口地址

SSTACK SEGMENT STACK
           DW 32 DUP(?)
SSTACK ENDS

DATA SEGMENT
    FREQ_LIST DW 371,495,495,495,624,556,495,556,624        ; 频率表
              DW 495,495,624,742,833,833,833,742,624
              DW 624,495,556,495,556,624,495,416,416,371
              DW 495,833,742,624,624,495,556,495,556,833
              DW 742,624,624,742,833,990,742,624,624,495
              DW 556,495,556,624,495,416,416,371,495,0

    TIME_LIST DB 4, 6, 2, 4, 4, 6, 2, 4, 4                  ; 时间表
              DB 6, 2, 4, 4, 12, 1, 3, 6, 2
              DB 4, 4, 6, 2, 4, 4, 6, 2, 4, 4
              DB 12, 4, 6, 2, 4, 4, 6, 2, 4, 4
              DB 6, 2, 4, 4, 12, 4, 6, 2, 4, 4
              DB 6, 2, 4, 4, 6, 2, 4, 4, 12
DATA ENDS

CODE SEGMENT
                 ASSUME CS:CODE

    START:       
    ; 保存 DS 寄存器
                 PUSH   DS
                 MOV    AX, 0000H
                 MOV    DS, AX

    ; 设置 IRQ7 中断向量
                 MOV    AX, OFFSET IRQ7_HANDLER    ; 取中断入口地址
                 MOV    SI, 003CH                  ; 中断向量地址
                 MOV    [SI], AX                   ; 填 IRQ7 的偏移地址
                 MOV    AX, CS
                 MOV    SI, 003EH
                 MOV    [SI], AX                   ; 填 IRQ7 的段地址

                 CLI                               ; 禁用中断
                 POP    DS                         ; 恢复 DS

    ; 初始化主片 8259
                 MOV    SI, 0
                 MOV    AL, 11H
                 OUT    20H, AL                    ; ICW1
                 MOV    AL, 08H
                 OUT    21H, AL                    ; ICW2
                 MOV    AL, 04H
                 OUT    21H, AL                    ; ICW3
                 MOV    AL, 01H
                 OUT    21H, AL                    ; ICW4
                 MOV    AL, 6FH
                 OUT    21H, AL                    ; OCW1
                 MOV    BP, 0

                 STI                               ; 启用中断

    ; 设置数据段
                 MOV    AX, DATA
                 MOV    DS, AX

    ; 初始化 8254 工作方式
                 MOV    DX, MY8254_MODE
                 MOV    AL, 36H                    ; 定时器 0，方式 3
                 OUT    DX, AL

    BEGIN:       
    ; 装入频率表和时间表起始地址
                 MOV    SI, OFFSET FREQ_LIST
                 MOV    DI, OFFSET TIME_LIST

    PLAY:        
    ; 设置初始时钟频率 1MHz
                 MOV    DX, 0FH
                 MOV    AX, 4240H
                 DIV    WORD PTR [SI]              ; 计算计数初值，0F4240H / 输出频率
                 MOV    DX, MY8254_COUNT0
                 OUT    DX, AL                     ; 装入计数初值低字节
                 MOV    AL, AH
                 OUT    DX, AL                     ; 装入计数初值高字节

    ; 调用延时子程序，演奏相对时间
                 MOV    DL, [DI]
                 CALL   DELAY

    ; 更新指针
                 ADD    SI, 2
                 INC    DI

    ; 判断是否到达曲末
                 CMP    WORD PTR [SI], 0
                 JE     BEGIN

    ; 循环等待
    WAIT_LOOP:   
                 CMP    BP, 0FFFFH
                 JZ     WAIT_LOOP

                 JMP    PLAY

    ; 延时子程序
    DELAY:       
                 PUSH   CX
                 MOV    CX, 0F000H

    DELAY_LOOP:  
                 PUSH   AX
                 POP    AX
                 LOOP   DELAY_LOOP

                 POP    CX
                 RET

    ; 额外延时子程序
DALLY PROC
                 MOV    CX, 0010H
    D1:          MOV    AX, 0FF0H
    D2:          DEC    AX
                 JNZ    D2
                 LOOP   D1
                 DEC    DL
                 JNZ    D0
                 RET
DALLY ENDP

    ; IRQ7 中断处理程序
    IRQ7_HANDLER:
                 STI
                 NOT    BP
                 MOV    AL, 20H
                 OUT    20H, AL                    ; 中断结束命令
                 IRET

CODE ENDS
END  START
