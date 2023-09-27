;------------------------------------------------------------------------------
STACKSG SEGMENT 
PILA    DW      100 DUP(0)
STACKSG ENDS
;------------------------------------------------------------------------------
DATASG SEGMENT
;variables
DATO8   DB      0
DATO16  DW      0
CAR     DB      'f'
CONT    DW      0
ARRAY   DB      0,55,0,-8,4,-5,56,0,2,54,-2,-1,100,-4
TEXTO   DB      'marca' 
DATASG ENDS
;-----------------------------------------------------------------------
CODESG SEGMENT 
BEGIN   PROC 
	ASSUME 	SS:STACKSG,DS:DATASG,CS:CODESG
	MOV 	AX,DATASG	;Obtiene direcci?n de segmento de datos
	MOV	DS,AX		;Se lo carga en DS

INICIO:
        CALL    MAIN

;SALIR
	MOV 	AX,4C00H
	INT 	21H
BEGIN 	ENDP

MAIN PROC
;PROGRAMA PRINCIPAL

        MOV     CONT,0          ;CONT=CONTADOR DE NUMEROS NEGATIVOS
        MOV     SI,0            ;PONGO EN CERO EL REGISTRO INDICE
        LEA     BX,ARRAY        ;CARGA LA DIRECCION DE ARRAY EN BX
BUCLE1:
        MOV     AL,BX[SI]       ;LEO EL ARRAY[INDICE]                           
        INC     SI              ;INCREMENTO EL INDICE PARA LA PROX LECTURA
        CMP     SI,1           ;LLEGUE AL FINAL?
        JE      INIT_CONT       ;SI! ME VOY, SINO CONTINUO

        CMP     AL,0            ;EL NRO LEIDO ES NEGATIVO?
        JG      BUCLE1          ;SI NO VUELVO ARRIBA BUSCO EL PR?XIMO
        INC     CONT            ;SI ERA NEGATIVO INCREMENTO EL CONTADOT
        JMP     BUCLE1          ;BUSCO EL PR?XIMO   

INIT_CONT:
        MOV     CONT,0
        MOV     SI,0
        LEA     BX,ARRAY
BUCLE2: 
        MOV     AL,BX[SI]       ;LEO EL ARRAY[INDICE]                           
        INC     SI              ;INCREMENTO EL INDICE PARA LA PROX LECTURA
        CMP     SI,1           ;LLEGUE AL FINAL?
        JE      INIT_ACUMULAR
        
        CMP     AL,0
        JE      CONT_CEROS
        JMP     BUCLE2
        
CONT_CEROS:
        INC     CONT
        JMP     BUCLE2
        
INIT_ACUMULAR:
        MOV     DATO16,0
        MOV     SI,0
        LEA     BX,ARRAY
ACUMULAR:
        MOV     AL,BX[SI]
        CBW
        INC     SI
        CMP     SI,15
        JE      FINMAIN
        
        ADD     DATO16,AX
        JMP     ACUMULAR

FINMAIN:
        RET
MAIN ENDP

CODESG	ENDS

	END 	BEGIN

