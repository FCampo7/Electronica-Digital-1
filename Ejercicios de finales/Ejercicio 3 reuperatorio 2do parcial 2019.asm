stacksg segment
    pila dw 100 dup(0)
stacksg ends
datasg segment
    string db 'Hola MuNdo AggAaA',10
    array  db 10,-2,3,-4,2,-3,9,-1,-2
datasg ends
codesg segment
    begin proc
        assume ss:stacksg,ds:datasg,cs:codesg
        mov ax,datasg
        mov ds,ax
        
        call cMayus
        call cNeg
        
        mov ax,4c00h
        int 21h
    begin endp
    
    cMayus proc
        init_cMayus:
            mov ax,0
            mov si,0
            lea bx,string
        main_cMayus:
            mov ah,bx[si]
            cmp ah,10
            je ret_cMayus
            cmp ah,'Z'
            jg continue
            cmp ah,'A'
            jl continue
            inc al
        continue:
            inc si
            jmp main_cMayus    
        ret_cMayus:
            ret
    cMayus endp
    
    cNeg proc
        init_cNeg:
            mov cx,0
            mov si,0
            lea bx,array
        main_cNeg:
            cmp si,9
            jge ret_cNeg
            cmp bx[si],0
            jge continue2
            inc ch
        continue2:
            inc si
            jmp main_cNeg        
        ret_cNeg:
            ret
    cNeg endp        
    
codesg ends
end begin