#include <stdio.h>
#include <stdint.h>

#define mask 0x1

void ImprimirBin8(int8_t num){
    for(int i=7; i>=0; i--){
        if(num&mask<<i){
            printf("1");
        }
        else
            printf("0");
        if((i+1)%4==1)
            printf(" ");
    }
    printf("\n");
}

void ImprimirBin16(int16_t num){
    for(int i=15; i>=0; i--){
        if(num&mask<<i)
            printf("1");
        else
            printf("0");
        if((i+1)%4==1)
            printf(" ");
    }
    printf("\n");
}

int main(){
    int8_t var1=53;
    int8_t var2=-var1;
    int8_t var3=~var1;

    int16_t mascara=0xf0f0;
    int16_t varr1=0x5a5a;
    int16_t resultado=varr1&mascara;

    int16_t varr2=0xa0a0;
    int16_t mascara2=0x00ff;
    int16_t resultado2=varr2|mascara2;

    int16_t varr3=0xff00;
    int16_t mascara3=0x6060;
    int16_t resultado3=varr3^mascara3;

    printf(" var1\n Hex: %#x\n Decimal: %d\n Binario: ", var1, var1);
    ImprimirBin8(var1);
    printf("\n var2\n Hex: %#x\n Decimal: %d\n Binario: ", var2, var2);
    ImprimirBin8(var2);
    printf("\n var3\n Hex: %#x\n Decimal: %d\n Binario: ", var3, var3);
    ImprimirBin8(var3);

    printf("\n varr1\n Hex: %#x\n Decimal: %d\n Binario: ", varr1, varr1);
    ImprimirBin16(varr1);
    printf("\n mascara\n Hex: %#x\n Decimal: %d\n Binario: ", mascara, mascara);
    ImprimirBin16(mascara);
    printf("\n resultado &\n Hex: %#x\n Decimal: %d\n Binario: ", resultado, resultado);
    ImprimirBin16(resultado);

    printf("\n varr2\n Hex: %#x\n Decimal: %d\n Binario: ", varr2, varr2);
    ImprimirBin16(varr2);
    printf("\n mascara2\n Hex: %#x\n Decimal: %d\n Binario: ", mascara2, mascara2);
    ImprimirBin16(mascara2);
    printf("\n resultado2 |\n Hex: %#x\n Decimal: %d\n Binario: ", resultado2, resultado2);
    ImprimirBin16(resultado2);

    printf("\n varr3\n Hex: %#x\n Decimal: %d\n Binario: ", varr3, varr3);
    ImprimirBin16(varr3);
    printf("\n mascara3\n Hex: %#x\n Decimal: %d\n Binario: ", mascara3, mascara3);
    ImprimirBin16(mascara3);
    printf("\n resultado3 ^\n Hex: %#x\n Decimal: %d\n Binario: ", resultado3, resultado3);
    ImprimirBin16(resultado3);


    return 0;
}
