stacksg segment
    pila DW 100 DUP(0)
stacksg ends
datasg segment
    lista1 dw 0,1,30,2,40,20,30,49,21,10,34
datasg ends
codesg segment
    begin proc
        assume ss:stacksg,ds:datasg,cs:codesg
        mov ax,datasg
        mov ds,ax
        
        call main
        
        mov ax,4c00h
        int 21h
    begin endp
    
    main proc
        init_main:
            call eliminar
        return_main:
            ret
    main endp
    buscar proc
        init_buscar:
            mov si,0
            lea bx,lista1
        buscar_main:
            cmp si,22
            jge return_buscar
            cmp bx[si],al
            je  pos_buscar
            mov ah,-1
            inc si
            inc si
            inc cl
            jmp buscar_main
        pos_buscar:
            mov ah,cl    
        return_buscar:
            ret
    buscar endp
    eliminar proc
        init_eliminar:
            mov cl,0
            mov ax,0
            mov al,21
        eliminar_main:
            cmp cl,11
            jge return_eliminar
            call buscar
            cmp ah,-1
            jne eliminar_val
        continue:
            jmp eliminar_main
        eliminar_val:
            push si
            push ax
            mov al,ah
            mov ah,0
            add al,al
            mov si,ax
            mov bx[si],-1
            pop ax
            pop si
            jmp continue
        return_eliminar:
            ret
    eliminar endp
codesg ends
end begin