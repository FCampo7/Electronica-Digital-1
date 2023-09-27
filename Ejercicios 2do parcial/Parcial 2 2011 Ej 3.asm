STACKSG SEGMENT
    PILA DW 100 DUP(0)
STACKSG ENDS

DATASG SEGMENT
    LISTA DB 6,-2,15,0,16,7,2,-8,20,-3
    ORDEN DB 5,8,1,3,9,2,4,7,10,6
    LISTANEW DB 10 DUP(0)
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
        CALL ORDENO
        RET
    MAIN ENDP
    
    ORDENO PROC
        INIT:
            MOV AX,0
            MOV CX,0 
            MOV SI,0
        ORDENO_MAIN:
            LEA BX,LISTA
            CMP SI,10
            JGE ORDENO_RET
            MOV CL,BX[SI]
            LEA BX,ORDEN
            MOV AL,BX[SI]
            DEC AL
            CBW
            PUSH SI
            MOV SI,AX
            LEA BX,LISTANEW
            MOV BX[SI],CL
            POP SI
            INC SI
            JMP ORDENO_MAIN            
        ORDENO_RET:
            RET
    ORDENO ENDP
CODESG ENDS
    END BEGIN