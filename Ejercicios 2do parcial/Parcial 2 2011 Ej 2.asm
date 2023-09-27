STACKSG SEGMENT
    PILA DW 100 DUP(0)
STACKSG ENDS

DATASG SEGMENT
    ARRAY1 DB 6,-2,15,0,16,7,2,-8,20,-3
    VAR1 DB 0
    VAR2 DB 0
    VAR3 DB 0
DATASG ENDS

CODESG SEGMENT
    BEGIN PROC
        ASSUME SS:STACKSG,DS:DATASG,CS:CODESG
        MOV AX,DATASG
        MOV DS,AX
        INICIO:
            CALL MAIN
        MOV AX,4C00h
        INT 21h
    BEGIN ENDP
    
    MAIN PROC
        CALL SUBR1
        RET
    MAIN ENDP
    
    SUBR1 PROC
        INIT:
            MOV SI,0
            MOV AX,0
            MOV DL,2
            LEA BX,ARRAY1
        SUBR1_MAIN:
            CMP SI,9
            JG SUBR1_RET
            MOV AL,BX[SI]
            DIV DL
            CMP AH,0
            JE AUMENTARV1
        CONTINUE:
            CMP BX[SI],0
            JG  AUMENTARV2
        CONTINUE2: 
            CMP BX[SI],-5
            JGE AUMENTARV3
        CONTINUE3:
            INC SI
            JMP SUBR1_MAIN
            
        AUMENTARV1:
            INC VAR1
            JMP CONTINUE
        AUMENTARV2:
            INC VAR2
            JMP CONTINUE2
        AUMENTARV3:
            CMP BX[SI],5
            JG  CONTINUE3
            INC VAR3
            JMP CONTINUE3
        SUBR1_RET:
            RET
    SUBR1 ENDP
CODESG ENDS
END BEGIN