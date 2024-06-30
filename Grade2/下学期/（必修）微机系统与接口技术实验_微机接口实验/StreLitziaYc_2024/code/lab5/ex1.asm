A8254   EQU 06C0H
C8254   EQU 06C4H
CON8254 EQU 06C6H
SSTACK SEGMENT STACK
           DW 32 DUP(?)
SSTACK ENDS
CODE SEGMENT
          ASSUME CS:CODE
    START:
          PUSH   DS
          MOV    AX, 0000H
          MOV    DS, AX
          MOV    AX, 0FFSET MIR7
          MOV    SI, 003CH
          MOV    [SI], AX
          MOV    AX, CS
          MOV    SI, 003EH
          MOV    [SI], AX
          CLI
          POP    DS
          MOV    AL, 11H
          OUT    20H, AL
          MOV    AL, 08H
          OUT    21H, AL
          MOV    AL, 04H
          OUT    21H, AL
          MOV    AL, 01H
          OUT    21H, AL
          MOV    AL, 6FH
          OUT    21H, AL

          MOV    DX, CON8254
          MOV    AL, 36H
          OUT    DX, AL
          MOV    DX, A8254
          MOV    AL, 00H
          OUT    DX, AL
          MOV    AL, 48H
          OUT    DX, AL
          STI
    AA1:  JMP    AA1
    MIR7: STI
          MOV    AX, 014DH
          INT    10H
          MOV    AX, 0120H
          INT    10H
          MOV    AL, 20H
          OUT    20H, AL
          IRET
CODE ENDS
         END START