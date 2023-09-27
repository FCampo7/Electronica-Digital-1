#include <stdio.h>
#include <stdint.h>

#define mask 0x1

void ImprimirBin8(int8_t num){
    for(int i=7; i>=0; i--){
        if(num&mask<<i)
            printf("1");
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

void ImprimirBin32(int32_t num){
    for(int i=31; i>=0; i--){
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
    int8_t numero=30;
    int16_t n2=256;
    int32_t n3=16500;

    ImprimirBin8(numero);
    ImprimirBin16(n2);
    ImprimirBin32(n3);

    return 0;
}
