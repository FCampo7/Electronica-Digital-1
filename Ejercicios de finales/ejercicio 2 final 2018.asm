stacksg segment
    pila DW 100 DUP(0)
stacksg ends

datasg segment
    array DB 'Esto es un array1 de prueba','$'
    simbolos DB 0
datasg ends     

codesg segment
    begin proc
        assume ss:stacksg, ds:datasg,cs:codesg
        mov ax,datasg
        mov ds,ax
        
        inicio:
            call main
            
        mov ax,4c00h
        int 21h           
    begin endp
    
    main proc
        call buscar_simbolos
        return_main:
            ret
    main endp
    
    buscar_simbolos proc
        init_bs:
            mov si,0
            mov ax,0
            lea bx,array
        main_bs:
            mov al,bx[si]
            cmp al,'$'
            je return_bs
            cmp al,'a'
            jl cmp2_bs
            cmp al,'z'
            jg contar_bs
            incsi_bs:
                inc si
                jmp main_bs
            cmp2_bs:
                cmp al,'A'
                jl contar_bs
                cmp al,'Z'
                jg contar_bs
                jmp incsi_bs
            contar_bs:
                inc simbolos
                jmp incsi_bs
        return_bs:
            ret
    buscar_simbolos endp
    
codesg ends
    end begin