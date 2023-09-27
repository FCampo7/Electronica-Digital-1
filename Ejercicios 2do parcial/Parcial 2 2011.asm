;-------------------------------------------------------------
STACKSG SEGMENT
PILA    DW      100 DUP(0)
STACKSG ENDS
;-------------------------------------------------------------
DATASG SEGMENT
DATASG ENDS
;-------------------------------------------------------------
CODESG SEGMENT
    BEGIN PROC
        ASSUME SS:STACKSG,DS:DATASG,CS:CODESG
        MOV AX,DATASG
        MOV DS,AX
        INICIO:
            call main
        
        mov ax,4c00h
        int 21h
    BEGIN ENDP
    
    main proc
        call rutina_a
        call rutina_b
        call rutina_c
        call rutina_d
        ret
    main endp
    
    rutina_a proc
        mov ax,0
        mov bx,0
        stc
        mov al,254d ;ax=00feh
        mov bl,254d ;bx=00feh
        add al,1    ;ax=00ffh
        add bl,1    ;bx=00ffh
        return_a:
            ret
    rutina_a endp
    
    rutina_b proc
        mov ax,0
        mov bx,0
        mov al,0081h ;ax=0081h
        sar al,1     ;al=1000 0001=>1100 0000=>ax=00c0h
        mov bl,0081h ;bx=0081h
        rol bl,2     ;bl=1000 0001=>0000 0011=>0000 0110=>bx=0006h
        ret
    rutina_b endp
    
    rutina_c proc
        mov ax,0
        mov bx,0
        mov dx,0
        mov ax,24d ;ax=0018h
        mov bl,5d  ;bx=0005h
        div bl     ;ax=0404h
        mov dl,77h ;dx=0077h
        and dl,ah  ;0111 0111
        ret      ;& 0000 0100 =>0000 0100=>dx=0004h 
    rutina_c endp
    
    rutina_d proc
        mov ax,0
        mov bx,0
        mov cx,0
        mov ax,1122h ;ax=1122h
        mov bx,8866h ;bx=8866h
        push al      ;esto no funciona.
        push bl
        push al
        push ah
        pop cl       ;cx=0011h
        pop ch       ;cx=2211h
        pop ah       ;ax=6622h
        pop al       ;ax=6622h
        ret
    rutina_d endp
    
CODESG ENDS
    END BEGIN