;------------------------------------------------------------------------------
STACKSG SEGMENT 
PILA    DW      100 DUP(0)
STACKSG ENDS
;------------------------------------------------------------------------------
DATASG SEGMENT
;variables                                             
ARRAY2  DB      -4,3,5,12,-5,8,8,6,0,1
ARRAY3  DB      00001111b,00000000b,11111111b,01010101b
MAXIMO  DB      0
DATASG ENDS
;-----------------------------------------------------------------------
CODESG SEGMENT 
BEGIN   PROC 
	ASSUME 	SS:STACKSG,DS:DATASG,CS:CODESG
	MOV 	AX,DATASG	;Obtiene direcci?n de segmento de datos
	MOV	    DS,AX		;Se lo carga en DS

INICIO:                  
        CALL    MAIN
        ;CALL    BUSCAR_MAX

;SALIR
	MOV 	AX,4C00h
	INT 	21h
BEGIN 	ENDP       

MAIN PROC
        CALL    BUSCAR_MAX
        LEA     BX,ARRAY3
        MOV     SI,0
BUCLE3:          
        MOV     DL,[BX+SI]
        PUSH    SI
        JMP     CANTUNOS
RESSI:
        POP     SI
        INC     SI
        CMP     SI,4
        JE      FINMAIN
        JMP     BUCLE3    
CANTUNOS:   
        MOV CL,0
        MOV AL,DL
        MOV SI,0
INIT_CANTUNOS:
        INC SI
        CMP SI,8
        JG  RESSI
        
        SHR AL,1
        JC  CONTARUNOS
        JMP INIT_CANTUNOS   
        
CONTARUNOS:
        INC CL   
        JMP INIT_CANTUNOS
        
FINMAIN:
        RET
MAIN ENDP     

BUSCAR_MAX PROC  
        MOV     MAXIMO,0
        MOV     SI,0
        LEA     BX,ARRAY2
        
MAXIM:               
        MOV     AL,BX[SI]
        INC     SI
        CMP     SI,11
        JE      FINMAXIM
        
        CMP     AL,MAXIMO
        JG      MAXIMO_F
        JMP     MAXIM
MAXIMO_F:        
        MOV     MAXIMO,AL
        JMP     MAXIM
FINMAXIM:        
        RET
BUSCAR_MAX ENDP

CODESG	ENDS

	END 	BEGIN

