#include "stdio.h"
#include "stdint.h"

#define mask 0x1

/** Respuestas
    a)
    int16_t num1 = 0xF1EA = 15 1 14 10 = 1111 0001 1110 1010 => CA2 => = -3606

    CA2 de 1111 0001 1110 1010
    0000 1110 0001 0101
    +
    0000 0000 0000 0001
    ___________________
    0000 1110 0001 0110 = -(2^11 + 2^10 + 2^9 + 2^4 + 2^2 + 2^1)=-3606

    int16_t num2 = 0x700F = 7 0 0 15 = 0111 0000 0000 1111 = 2^14 + 2^13 + 2^12 + 2^3 + 2^2 + 2^1 + 2^0 = +28687

    b)
    num1+num2
    1111 0001 1110 1010
    +
    0111 0000 0000 1111
    ___________________
    1|0110 0001 1111 1001 = 2^14 + 2^13 + 2^8 + 2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^0 = +25081 hubo carry pero no overflow

    c)
    num2-num1=num2+CA2(num1)
    0111 0000 0000 1111
    +
    0000 1110 0001 0110
    ___________________
    0111 1110 0010 0101 = 2^14 + 2^13 + 2^12 + 2^11 + 2^10 + 2^9 + 2^5 + 2^2 + 2^0 = +32293 no hubo carry ni overflow

    d)
    uint16_t num1 = 0xF1EA = 15 1 14 10 = 1111 0001 1110 1010 = 2^15 + 2^14 + 2^13 + 2^12 + 2^8 + 2^7 + 2^6 + 2^5 + 2^3 + 2^1 = 61930
*/

void binario(int16_t num){
    for(int i=15; i>=0; i--){
        if(num&mask<<i) printf("1");
        else printf("0");
    }
    printf("\n");
}

int main(){
    int16_t num1 = 0xF1EA, num2 = 0x700F;

    printf("Numero 1: ");
    binario(num1);
    printf("%d\n", num1);

    printf("Numero 2: ");
    binario(num2);
    printf("%d\n", num2);

    int16_t resultado = num1+num2;
    printf("suma de num1+num2=%d\n", resultado);

    resultado = num2-num1;
    printf("resta de num2-nume1=%d\n", resultado);

    uint16_t unum1 = 0xF1EA;

    printf("Numero 1 unsigned: %u\n", unum1);

    return 0;
}
