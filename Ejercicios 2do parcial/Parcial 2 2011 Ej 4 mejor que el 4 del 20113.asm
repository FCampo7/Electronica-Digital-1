STACKSG SEGMENT
    PILA DW 100 DUP(0)
STACKSG ENDS

DATASG SEGMENT
    FRASE DB 'Es el corazon el que le indica a la mente a que dedicarse',0h
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
        CALL RESUMEN
        RET
    MAIN ENDP
    
    RESUMEN PROC
        INIT:       
            MOV AX,0
            MOV CX,0
            MOV DX,0
            MOV SI,0
            LEA BX,FRASE
        RESUMEN_MAIN:
            CMP BX[SI],0
            JE  RESUMEN_FIN
            INC CL
            INC AL
            CMP BX[SI],' '
            JE  CONT_ESP
        CONTINUE:
            INC SI
            JMP RESUMEN_MAIN    
        CONT_ESP:
            DEC AL
            INC CH
            INC DL
            CMP AL,DH
            JG  NLPML
            MOV AL,0
            JMP CONTINUE
        NLPML:
            MOV DH,AL
            MOV AL,0
            JMP CONTINUE    
        RESUMEN_FIN:
            DEC SI
            CMP BX[SI],' '
            JE  RESUMEN_RET
            INC DL
            CMP DH,AL
            JG  RESUMEN_RET
            MOV DH,AL    
        RESUMEN_RET:
            RET
    RESUMEN ENDP
CODESG ENDS

END BEGIN