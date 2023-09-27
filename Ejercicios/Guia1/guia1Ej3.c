#include <stdio.h>
#include <stdint.h>
#include <math.h>

void ImprimirBin8(int8_t num){
    int8_t aux=num;
    int8_t bin[8]={0};
    for(int i=7; i>=0; i--){
        bin[i]=aux%2;
        aux=aux/2;
    }
    for(int i=0; i<8; i++){
        if(i!=7){
            printf("%d", bin[i]);
        }
        else printf("%d\n", bin[i]);
    }
}
void ImprimirBin16(int16_t num){
    int16_t aux=num;
    int16_t bin[16]={0};
    for(int i=15; i>=0; i--){
        bin[i]=aux%2;
        aux=aux/2;
    }
    for(int i=0; i<16; i++){
        if(i!=15){
            printf("%d", bin[i]);
        }
        else printf("%d\n", bin[i]);
    }
}
void ImprimirBin32(int32_t num){
    int32_t aux=num;
    int32_t bin[32]={0};
    for(int i=31; i>=0; i--){
        bin[i]=aux%2;
        aux=aux/2;
    }
    for(int i=0; i<32; i++){
        if(i!=31){
            printf("%d", bin[i]);
        }
        else printf("%d\n", bin[i]);
    }
}

int main(){
    int32_t A, B, aux;

    printf("inserte el valor de A: ");
    scanf("%d", &A);
    printf("inserte el valor de B: ");
    scanf("%d", &B);

    if(A>B){
        aux=A;
        A=B;
        B=aux;
    }

    printf("decimal\t\t\t");
    printf("hexadecimal\t\t");
    printf("octal\t\t");
    printf("binario\n");

    for(int i=A; i<=B; i++){
        printf("%i\t\t\t", i);
        printf("%x\t\t", i);
        printf("%o\t\t", i);
        if(i<pow(2, 8)){
            ImprimirBin8(i);
        }
        else if(i<pow(2, 16)){
            ImprimirBin16(i);
        }
        else if(i<pow(2, 32)){
            ImprimirBin32(i);
        }
    }

    system("PAUSE");

    return 0;
}

