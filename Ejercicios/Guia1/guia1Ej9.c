#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define sMask 0x1
#define eMask 0xff
#define mMask 0x7fffff

void ImprimirContenidoFloat(float var){
    char s;
    int32_t *p;
    p=&var;
    uint32_t exp=0;
    uint32_t man=0;

    printf("hex del contenido del puntero al float: %#x\n", *p);

    if((*p&sMask<<31)==sMask<<31){
        s='-';
    }
    else s='+';

    exp=(*p)&eMask<<23;
    exp=exp>>23;

    man=*p & mMask;

    printf("signo: (%c)\n", s);
    printf("exponente: %#x\n", exp);
    printf("mantisa: %#x\n", man);
    printf("%u\n", exp);
    printf("%u\n", man);
}

int main(){
    float var_f=-1186.25;

    ImprimirContenidoFloat(var_f);

    return 0;
}
