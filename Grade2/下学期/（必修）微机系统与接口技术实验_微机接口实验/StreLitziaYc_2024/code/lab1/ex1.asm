; 输出学号
DATA SEGMENT
    ID   DB '2021141440374','$'
DATA ENDS

CODE SEGMENT
    START:     
               PROC   FAR
               ASSUME CS:CODE,DS:DATA

               MOV    AX, 8000H          ; 存储器扩展空间段地址
               MOV    ES, AX
               MOV    AX, DATA           ; 存储器扩展空间段地址
               MOV    DS, AX

               MOV    SI, OFFSET ID      ; 数据首地址
               MOV    DI, 0000H

    LOOP_START:
               MOV    AL,[SI]
               CMP    AL,'$'
               JZ     END_LOOP
               SUB    AL,30H
               MOV    ES:[DI],AL
               INC    SI
               INC    DI
               JMP    LOOP_START

    END_LOOP:  
               MOV    AX,4C00H
               INT    21H                ;程序终止

               ENDP
CODE ENDS
END START