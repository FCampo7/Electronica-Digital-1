#include "stdio.h"
#include "stdint.h"

/** Respuestas
    a)
    int8_t x = C4h = 1100 0100 => CA2 => = -60

    CA2 de 1100 0100
    0011 1011
    +
            1
    _________
    0011 1100 = -(2^5 + 2^4 + 2^3 + 2^2) = -60

    int8_t y = 7Ah = 0111 1010 = 2^6 + 2^5 + 2^4 + 2^3 + 2^1 = +122

    b)
    x-y=x+CA2(y)
    1100 0100
    +
    1000 0110
    _________
    1|0100 1010 = 2^6 + 2^3 + 2^1 = 74 hubo overflow y carry el resultado tendria que ser -182

    c)
    x+y
    1100 0100
    +
    0111 1010
    _________
    1|0011 1110 = 2^5 + 2^4 + 2^3 + 2^2 + 2^1 = 62 hubo carry pero no overflow
*/

#define mask 0x1

void binario(int8_t num){
    for(int i=7; i>=0; i--){
        if(num&(mask<<i)) printf("1");
        else printf("0");
    }
    printf("\n");
}

int main(){
    int8_t x = 0xC4, y = 0x7A, res=x-y, res2=x+y;
    binario(x);
    printf("%d\n", x);
    binario(y);
    printf("%d\n", y);
    binario(res);
    printf("%d\n", res);
    binario(res2);
    printf("%d\n", res2);

    return 0;
}
