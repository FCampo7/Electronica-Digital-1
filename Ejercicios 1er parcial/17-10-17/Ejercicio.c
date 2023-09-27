#include "stdio.h"
#include "stdint.h"

/** Respuestas
    a)
    int16_t num1 = 0xAE01 = 10 14 0 1 = 1010 1110 0000 0001 => CA2 => = -20991
    CA2 de 1010 1110 0000 0001
    0101 0001 1111 1110
    +
                      1
    ___________________
    0101 0001 1111 1111 = -(2^14 + 2^12 + 2^8 + 2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0) = -20991

    int16_t num2 = 0x7112 = 0111 0001 0001 0010 = 2^14 + 2^13 + 2^12 + 2^8 + 2^4 + 2^1 = +28946

    b)
    num1+num2

    1010 1110 0000 0001
    +
    0111 0001 0001 0010
    ___________________
    1|0001 1111 0001 0011 = 2^12+2^11+2^10+2^9+2^8+2^4+2^1+2^0 = +7955 hubo carry pero no overflow

    c)
    num2-num1=num2+CA2(num1)

    0111 0001 0001 0010
    +
    0101 0001 1111 1111
    ___________________
    1100 0011 0001 0001 = 2^15+2^14+2^9+2^8+2^4+2^0 = 49947

    CA2 de 1100 0011 0001 0001
    0011 1100 1110 1110
    +
                      1
    ___________________
    0011 1100 1110 1111 = 2^13+2^12+2^11+2^10+2^7+2^6+2^5+2^3+2^2+2^1+2^0 = -15599 hubo overflow porque el numero se fue del rango permitido para los positivos en un entero de 16 bits

    d)
    #define mask 0x1
    void verifTercerBit(int16_t num){
        if(num&(mask<<3)) printf("1\n");
        else printf("0\n");
    }
    int main(){
        int16_t num1 = 0xAE01;
        verifTercerBit(num1);
        return 0;
    }

    e)
    #define mask 0x1
    void forzarSeptimoBit(int16_t *num){
        (*num)&=(~(mask<<7));
    }
    int main(){
        int16_t num2 = 0x7112;
        forzarSeptimoBit(&num2);
        return 0;
    }

*/

#define mask 0x1

void binario(int16_t num){
    for(int i=15; i>=0; i--){
        if(num&(mask<<i)) printf("1");
        else printf("0");
    }
    printf("\n");
}

void verifTercerBit(int16_t num){
    if(num&(mask<<3)) printf("1\n");
    else printf("0\n");
}

void forzarSeptimoBitA0(int16_t *num){
    (*num)&=(~(mask<<7));
}

void forzarSeptimoBitA1(int16_t *num){
    (*num)|=(mask<<7);
}

int main(){
    int16_t num1 = 0xAE01, num2 = 0x7112;

    printf("Numero 1: ");
    binario(num1);
    printf("%d\n", num1);
    printf("Numero 2: ");
    binario(num2);
    printf("%d\n", num2);

    int16_t resultado = 0x0000;
    resultado = num1+num2;
    printf("suma num1+num2=%d\n", resultado);

    resultado = num2-num1;
    printf("resta num2-num1=%d\n", resultado);

    printf("Tercer Bit de 0xAE01: ");
    verifTercerBit(num1);


    forzarSeptimoBitA1(&num2);
    binario(num2);

    forzarSeptimoBitA0(&num2);
    binario(num2);

    return 0;
}
