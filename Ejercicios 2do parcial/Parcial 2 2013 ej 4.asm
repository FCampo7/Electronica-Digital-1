;------------------------------------------------------------------------------
STACKSG SEGMENT 
PILA    DW      100 DUP(0)
STACKSG ENDS
;------------------------------------------------------------------------------
DATASG SEGMENT
;variables                      

FRASE DB 'La verdad se corrompe tanto con la mentira como con el silencio',0h

DATASG ENDS
;-----------------------------------------------------------------------
CODESG SEGMENT 
BEGIN   PROC 
	ASSUME 	SS:STACKSG,DS:DATASG,CS:CODESG
	MOV 	AX,DATASG	;Obtiene direcci?n de segmento de datos
	MOV	    DS,AX		;Se lo carga en DS

INICIO:                  
        CALL    MAIN
;SALIR
	MOV 	AX,4C00h
	INT 	21h
BEGIN 	ENDP       

MAIN PROC
    CALL RESUMEN      
    RET
MAIN ENDP

RESUMEN PROC
    INIT:
        MOV CX,0
        MOV DX,0
        MOV AX,0
        MOV SI,0
        LEA BX,FRASE
    RESUMEN_MAIN:
        CMP BX[SI],0h
        JE  RESUMEN_RETURN
        MOV AL,BX[SI]
        INC SI
        INC CL
        INC AH
        CMP AL,' '
        JE  CONTAR_ESPACIO
        JMP RESUMEN_MAIN
        
    CONTAR_ESPACIO:
        INC CH
        INC DL
        DEC AH
        CMP AH,DH
        JG  NLPML
        MOV AH,0
        JMP RESUMEN_MAIN
    NLPML:
        MOV DH,AH
        MOV AH,0
        JMP RESUMEN_MAIN
        
    RESUMEN_RETURN:
        CMP AL,' '
        JE RETURN_RET
        CMP AH,DH
        JG  NLPML2
        INC DL
        JMP RETURN_RET
    NLPML2:
        MOV DH,AH
        INC DL
    RETURN_RET:
        RET
RESUMEN ENDP
CODESG	ENDS

	END 	BEGIN