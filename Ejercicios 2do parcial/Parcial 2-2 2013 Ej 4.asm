STACKSG SEGMENT
    PILA DW 100 DUP(0)
STACKSG ENDS

DATASG SEGMENT                                                             
    LISTA DB 70h,8Eh,40h,3Fh,4Ah,15h
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
            MOV AX,0
            MOV DX,0
            MOV SI,0
            LEA BX,LISTA
        SUBR1_MAIN:
            CMP SI,6
            JGE SUBR1_RET
            MOV CL,BX[SI]
            SHR CL,5
            JNC CONT1
            INC AL
        CONT1:
            SHR CL,2
            JNC CONT2
            INC DL
        CONT2:
            INC SI
            JMP SUBR1_MAIN     
        SUBR1_RET:
            RET        
    SUBR1 ENDP
    
CODESG ENDS
END BEGIN