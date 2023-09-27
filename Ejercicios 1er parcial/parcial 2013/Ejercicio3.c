#include "stdio.h"
#include "stdint.h"

/** Respuestas
    a)
    a => 75/2=37/2=18/2=9/2=4/2=2/2=1 => a=01001011
    b => 98/2=49/2=24/2=12/2=6/2=3/2=1 => b=01100010

    c=a+b
    0100 1011
    +
    0110 0010
    _________
    1010 1101
    CA2 de 1010 1101
    0101 0010
    +
            1
    _________
    0101 0011 = -(2^6+2^4+2^1+2^0) = -83 hay overflow porque el resultado se fue de rango

    d=a-b=a+CA2(b)
    0100 1011
    +
    1001 1110
    _________
    1110 1001
    CA2 de 1110 1001
    0001 0110
    +
            1
    _________
    0001 0111 = -(2^4+2^2+2^1+2^0) = -23 no hay overflow porque el resultado se encuentra dentro del rango

    b)
    las variables de tipo entero signado se alojan usando el complemento a 2 es decir si el numero es negativo se conjuga el binario y se suma 1
    los numeros flotantes se almacenan mediante la forma de punto flotante, el bit n° 31 representa el signo, los siguientes 8 bits son el exponente y el restp es la mantisa
    hexa de a = 0x4B
    hexa de b = 0x62
    hexa de c = 0xAD
    hexa de d = 0xE9
*/

int main(){
    int8_t a=75, b=98, c=a+b, d=a-b;
    float f=1529.35;

    printf("%d\n", c);
    printf("%d\n", d);

    printf("%#x\n", a);
    printf("%#x\n", b);
    printf("%#x\n", c);
    printf("%#x\n", d);

    return 0;
}
