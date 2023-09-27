#include "stdio.h"
#include "stdint.h"

/** Respuestas
    a)
    int16_t num1 = 0xE1A1 = 1110 0001 1010 0001 => CA2 => = -7775

    CA2 de 1110 0001 1010 0001
    0001 1110 0101 1110
    +
                      1
    ___________________
    0001 1110 0101 1111 = -(2^12+2^11+2^10+2^9+2^6+2^4+2^3+2^2+2^1+2^0) = -7775

    int16_t num2 = 0x121A = 0001 0010 0001 1010 = 2^12+2^9+2^4+2^3+2^1 = +4634

    b)
    num1-num2=num1+CA2(num2)

    1110 0001 1010 0001
    +
    1110 1101 1110 0110
    ___________________
    1|1100 1111 1000 0111

    0011 0000 0111 1000
    +
                      1
    ___________________
    0011 0000 0111 1001 = -(2^13+2^12+2^6+2^5+2^4+2^3+2^0) = -12409 hubo carry pero no overflow

    c)

    1111 1111 1111 1111 1110 0001 1010 0001 = 0xFFFFE1A1
    CA2 de 1111 1111 1111 1111 1110 0001 1010 0001
    0000 0000 0000 0000 0001 1110 0101 1110
    +
                                          1
    _______________________________________
    0000 0000 0000 0000 0001 1110 0101 1111 = -7775
    int32_t num1_32 = 0xFFFFE1A1;

    uint32_t unum1_32 = 0xFFFFE1A1;

*/

#define mask 0x1

void binario(int16_t num){
    for(int i=15; i>=0; i--){
        if(num&(mask<<i)) printf("1");
        else printf("0");
    }
    printf("\n");
}

int main(){
    int16_t num1 = 0xE1A1, num2 = 0x121A;

    printf("Numero 1: ");
    binario(num1);
    printf("%d\n", num1);
    printf("Numero 2: ");
    binario(num2);
    printf("%d\n", num2);

    int16_t resultado = 0x0000;
    resultado = num1-num2;
    printf("resta num1-num2=%d\n", resultado);

    int32_t num1_32=0xFFFFE1A1, num2_32=0x0000121A;
    printf("%d\n", num1_32);
    printf("%d\n", num2_32);
    uint32_t unum1_32=0xFFFFE1A1, unum2_32=0x0000121A;
    printf("%u\n", unum1_32);
    unum1_32=num1;
    printf("%u\n", unum1_32);
    printf("%u\n", unum2_32);
    unum2_32=num2;
    printf("%u\n", unum2_32);


    return 0;
}
