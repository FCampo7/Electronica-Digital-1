;------------------------------------------------------------------------------
STACKSG SEGMENT 
PILA    DW      100 DUP(0)
STACKSG ENDS
;------------------------------------------------------------------------------
DATASG SEGMENT
;variables
ARRAY1 DB 16,31,-15,50,-7,-20,10,-9,50,-3                
VAR1 DW 0
VAR2 DB 0
VAR3 DB 0
LISTA DB 70h,8Eh,40h,3Fh,4Ah,15h
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
    ;CALL RUTINA_A
    ;CALL RUTINA_B
    ;CALL RUTINA_C
    ;CALL SUBR1
    CALL SUBR2      
    RET
MAIN ENDP

SUBR2 PROC
    INIT:
        MOV SI,0
        MOV AX,0
        MOV DX,0
        MOV CX,0
        LEA BX,LISTA
    SUBR2_MAIN:
        CMP SI,6
        JGE SUBR2_RETURN
        MOV CL,BX[SI]
        SHR CL,5
        JC  INC_AL
    CONT:
        SHR CL,2
        JC  INC_DL
    CONT2:
        INC SI
        JMP SUBR2_MAIN
    INC_AL:
        INC AL
        JMP CONT
    INC_DL:
        INC DL
        JMP CONT2
    SUBR2_RETURN:    
    RET
SUBR2 ENDP

SUBR1 PROC
    INIT_CANTPAR:
        MOV AX,0
        MOV DL,2
        MOV SI,0
        LEA BX,ARRAY1
    CANTPAR_MAIN:
        CMP SI,9
        JG  RETURN
        MOV AL,BX[SI]
        CMP AL,0
        JG  AUMENTARV2
    CONTINUAR:
        CMP AL,-5
        JGE AUMENTARV3
    CONTINUAR2:
        DIV DL
        CMP AH,0
        JE  AUMENTARV1
        INC SI
        JMP CANTPAR_MAIN
    AUMENTARV1:
        INC VAR1
        INC SI
        JMP CANTPAR_MAIN
    AUMENTARV2:
        INC VAR2
        JMP CONTINUAR
    AUMENTARV3:
        CMP AL,45
        JG  CONTINUAR2
        INC VAR3
        JMP CONTINUAR2    
    RETURN:    
        RET
SUBR1 ENDP

RUTINA_A PROC
    MOV BL,50 ;BX=00h 32h
    MOV BH,0x45h ;BX=45h 32h
    MOV DX,0     ;DX=00h 00h
    MOV AH,0x6Eh ;AX=6Eh 00h
    MOV AL,0x4Ch ;AX=6Eh 4Ch
    MOV CL,AH    ;CX=00h 6Eh
    ADD CL,AL    ;CX=00h BAh
    ADC DH,AH    ;DX=6Eh 00h
    MOV CH,BH    ;CX=45h BAh
    ADD CH,BL    ;CX=77h BAh
    ADC DL,BH    ;DX=6Eh 45h
    RET
RUTINA_A ENDP

RUTINA_B PROC
    MOV DX,0C36Fh ;DX=C36Fh
    MOV AX,55DAh  ;AX=55DA
    MOV BX,0D96Ah  ;BX=D96A
    MOV CX,0EAA6h  ;CX=EAA6
    SAR AH,4 ;AH=55h=SAR4 0101 0101=05h=>AX=05DA
    ADC AH,2 ;AX=07DAh
    SAL CL,4 ;CL=A6h=SAL4 1010 0110=60h=>CX=EA60
    ROR BL,4 ;BL=6Ah=ROR4 0110 1010=A6h=>BX=D9A6
    RCL DH,4 ;DH=C3h=RCL4 1100 0011=3Eh=>DX=3E6F
    AND AL,DH ;DA&3E=1101 1010              
              ;    & 0011 1110=0001 1010=1Ah
              ;AX=071Ah
    OR  BH,CL ;D9|60=1101 1001
              ;    | 0110 0000=1111 1001=F9h
              ;BX=F9A6h
    XOR CH,AH ;EA^07=1110 1010
              ;    ^ 0000 0111=1110 1101=EDh
              ;CX=ED60h
    NEG DL    ;~6F=~0110 1111=1001 0001=91h
              ;DX=3E91h
    RET
RUTINA_B ENDP

RUTINA_C PROC
    MOV AX,0FC38h ;AX=FC38h
    MOV BX,0D5Ch  ;BX=0D5Ch
    MOV CX,0ACE7h ;CX=ACE7h
    MOV DX,9DAEh  ;DX=9DAEh
    PUSH AX       ;AX==
    PUSH BX       ;BX==
    PUSH CX       ;CX==
    PUSH DX       ;DX==
    POP BX        ;BX=9DAE
    POP AX        ;AX=ACE7
    POP CX        ;CX=0D5C
    POP DX        ;DX=FC38
    RET
RUTINA_C ENDP

CODESG	ENDS

	END 	BEGIN