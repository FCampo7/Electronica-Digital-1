#include <stdio.h>
#include <stdint.h>

#define mascara 0x1

int32_t ApagarBit(uint32_t var, uint8_t nBit){
    uint32_t cambio;
    cambio=var&(~(mascara<<nBit));
    if(cambio==var){
        return 1;
    }
    else return 0;
}

int32_t EncenderBit(uint32_t var, uint8_t nBit){
    uint32_t cambio;
    cambio=var|(mascara<<nBit);
    if(cambio==var){
        return 1;
    }
    else return 0;
}

uint8_t ConsultarBit(uint32_t var, uint8_t nBit){
    uint32_t aux=var;
    uint32_t aux2=((aux>>nBit)&mascara);
    if(aux2==1 || aux2==0)
        return aux2;
    else return 1;
}

int32_t InvertirBit(uint32_t var, uint8_t nBit){
    uint32_t cambio;
    cambio=ConsultarBit(var, nBit);
    if(cambio==0){
        EncenderBit(cambio, nBit);
        return 0;
    }
    if (cambio==1){
        ApagarBit(cambio, nBit);
        return 0;
    }
    return 1;
}

int main(){
    int32_t vari=0xfffffffc;
    uint8_t pos=29;
    int32_t p=ApagarBit(vari, pos);
    printf("%#x\n", p);
    p=EncenderBit(vari, pos);
    printf("%#x\n", p);
    p=ConsultarBit(vari, pos);
    printf("%#x\n", p);
    p=InvertirBit(vari, pos);
    printf("%#x\n", p);

    return 0;
}
