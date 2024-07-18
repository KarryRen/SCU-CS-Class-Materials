DATAS SEGMENT
    ;此处输入数据段代码  
    BUFFER DB 11,0;max_length,actual_length
    ARRAY DB 11 dup(?);RAW array
    NEW_LINE DB 0DH,0AH,'$'
    ARRAY2 DB 11 DUP(?);ARRAY WITHOUT NUMBER
DATAS ENDS

STACKS SEGMENT
    DW  40H  DUP(0) 
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;get line from console
    MOV  AH,0AH 
	MOV  DX,OFFSET BUFFER
	INT   21H 
    
    ;call remove_number function
    MOV SI,OFFSET BUFFER+1;LEN
    PUSH SI
    MOV SI,OFFSET ARRAY
    PUSH SI
    MOV SI,OFFSET ARRAY2
    PUSH SI
    CALL RM_NUM
    
    
    ;call to_upper function
    MOV AH,0
    MOV AL,BUFFER+1;LEN
    MOV SI,AX
    PUSH SI
    MOV SI,OFFSET ARRAY2
    PUSH SI
    CALL TO_UPPER
    
    ;IF THE ARRAY IS EMPTY,SET ITS VALUE TO '?'
    CMP BUFFER+1,0
    JNZ PRINT
    MOV BUFFER+1,1
    MOV ARRAY2,'?'
PRINT:
	;NEW LINE
	MOV DX,OFFSET NEW_LINE
	MOV AH,09H
	INT 21H
	
    ;print the array
    MOV BX,OFFSET ARRAY2
    MOV DX,BX
    ADD BL,BUFFER+1

	MOV BYTE PTR[BX],'$'
    MOV AH,09H
    INT 21H
    
    ;NEW LINE
	MOV DX,OFFSET NEW_LINE
	MOV AH,09H
	INT 21H
    
    ;EXIT
    MOV AH,4CH
    INT 21H

RM_NUM PROC;传入参数(len addr,RAW array addr,DST ARRAY ADDR)，传出修改len,dst array
	PUSH BP			;保护执行现场
	MOV BP,SP
	PUSHF
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH SI
	PUSH DI
	
	MOV SI,[BP+4]	;DST ARRAY ADDR
	MOV DI,[BP+6]	;SRC array addr
	MOV BX,[BP+8]	;LEN addr
	MOV CH,0		;清除CX高8位
	MOV CL,BYTE PTR[BX]
	JCXZ DONE
L1:
	MOV DH,0;将DH当作bool flag,表示这个数是否是数字
	CMP BYTE PTR[DI],'0'
	JB JUDGE;如果比'0'小，说明这不是数字
	CMP BYTE PTR[DI],'9'
	JA JUDGE;如果比'9'大，说明这不是数字
	;如果能运行到这里，说明这一定是数字	
	MOV DH,1;更改flag值
	DEC BYTE PTR [BX];DECREASE THE LENGTH
JUDGE:
	CMP DH,1;比较flag的值是不是1
	JZ NEXT_;如果是1，就跳过下面这段代码
	MOV DH,BYTE PTR [DI];将这个字符从源移动到目标
	MOV [SI],DH
	INC SI;偏移量指向目标字符串下一个元素
	
NEXT_:
	INC DI;偏移量指向源字符串下一个元素
	LOOP L1
DONE:
	POP DI;恢复执行现场
	POP SI
	POP DX
	POP CX
	POP BX
	POP AX
	POPF
	POP BP
	RET 6
RM_NUM ENDP

TO_UPPER PROC;(len,array addr)
	PUSH BP;保护执行现场
	MOV BP,SP
	PUSHF
	PUSH BX
	PUSH CX
	
	MOV BX,[BP+4];array addr
	MOV CH,0
	MOV CL,BYTE PTR[BP+6];LEN
	JCXZ DONE_
L1:
	CMP BYTE PTR[BX],'a';比较这个值与'a'的关系，如果比'a'小，说明不是小写字母
	JB NEXT
	CMP BYTE PTR[BX],'z';比较这个值与'z'的关系，如果比'z'大，也不是小写字母
	JA NEXT
	;如果能运行到这里，说明是小写字母
	SUB BYTE PTR[BX],32
NEXT:
	INC BX
	LOOP L1
DONE_:
	;恢复执行现场

	POP CX
	POP BX
	POPF
	POP BP
	RET 4
TO_UPPER ENDP

CODES ENDS
    END START