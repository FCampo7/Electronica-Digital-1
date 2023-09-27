;------------------------------------------------------------------------------
STACKSG SEGMENT 
PILA    DW      100 DUP(0)
STACKSG ENDS
;------------------------------------------------------------------------------
DATASG SEGMENT
;variables                
ARRAY2  DB      'No hay medicina que cure lo que no cura la felicidad',0
LISTA   DB      70h,8Eh,40h,3Fh,4Ah,15h                                           
ARRAY1  DB      16,31,-15,50,-7,-20,10,-9,50,-3
VAR1    DB      0
VAR2    DB      0
VAR3    DW      0
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
    ;CALL MAXIMO
    ;CALL RUT2
    ;CALL MENOR
    CALL SUBR1
    RET
MAIN ENDP

MAXIMO PROC
    INIT_MAX:
        LEA BX, ARRAY1
        MOV SI, 0
        MOV AL, BX[SI]
        MOV VAR1, AL
    MAX:
        ADD SI, 1
        CMP SI, 9
        JG RETURN
        MOV AL, BX[SI]
        CMP AL, VAR1
        JG  NUEVOMAX
        JMP MAX
    NUEVOMAX:
        MOV VAR1, AL
        JMP MAX
    RETURN:
        RET 
MAXIMO ENDP

RUT2 PROC
    INIT_RUT2:
        MOV SI, 0
        MOV DL, 0
        LEA BX, LISTA
    CANT_ELEMENTOS:
        CMP SI, 6
        JGE RETURN2
        MOV AL, BX[SI]
        ADD SI, 1
        SHR AL, 3
        JC  CONTAR
        JMP CANT_ELEMENTOS
    CONTAR:
        ADD DL, 1
        JMP CANT_ELEMENTOS
    RETURN2:
        RET
RUT2 ENDP     

MENOR PROC
    INIT_MENOR:
        MOV SI, 0
        LEA BX, LISTA
        MOV AL, BX[SI]
    MEN:
        ADD SI, 1
        CMP SI, 5
        JG RETURN3
        CMP BX[SI], AL
        JLE NUEVOMEN
        JMP MEN
    NUEVOMEN:
        MOV AL, BX[SI]
        JMP MEN        
    RETURN3:
        RET
MENOR ENDP    

SUBR1 PROC
    INIT_SUBR1:
        MOV SI, 0
        LEA BX, ARRAY2
    LONGITUD_ARRAY:
        MOV AL, BX[SI]
        CMP AL, 0
        JE  RETURNS1
        INC SI
        CMP AL, 65
        JGE MAYUS
        JMP CANTIDAD_VOCALES
    MAYUS:
        CMP AL, 90
        JNLE CANTIDAD_VOCALES
        INC VAR2
        JMP CANTIDAD_VOCALES
    CANTIDAD_VOCALES:
    CMPAM:
        CMP AL, 'A'
        JNE CMPA
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPA:
        CMP AL, 'a'
        JNE CMPEM
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPEM:
        CMP AL, 'E'
        JNE CMPE
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPE:
        CMP AL, 'e'     
        JNE CMPIM
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPIM:
        CMP AL, 'I'      
        JNE CMPI
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPI:
        CMP AL, 'i'       
        JNE CMPOM
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPOM:
        CMP AL, 'O'       
        JNE CMPO
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPO:
        CMP AL, 'o'       
        JNE CMPUM
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPUM:
        CMP AL, 'U'       
        JNE CMPU
        INC VAR1
        JMP LONGITUD_ARRAY
    CMPU:
        CMP AL, 'u'       
        JNE LONGITUD_ARRAY
        INC VAR1
        JMP LONGITUD_ARRAY
    RETURNS1:
        MOV VAR3, SI
        RET   
SUBR1 ENDP

CODESG	ENDS

	END 	BEGIN