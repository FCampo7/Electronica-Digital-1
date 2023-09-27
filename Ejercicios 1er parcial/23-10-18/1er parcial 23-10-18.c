#include "stdio.h"
#include "stdint.h"

#define mask 0x1

/** Respuestas
a) expresar numeros en bianrio y tambien en decimal con signo y modulo
0xEEBF = 14 14 11 15 = 1110 1110 1011 1111 = CA2 = 0001 0001 0100 0001 = 2^12 + 2^8 + 2^6 + 2^0 = -4417
0x7FA2 = 7 15 10 2 = 0111 1111 1010 0010 = +32674

CA2 de 1110 1110 1011 1111

0001 0001 0100 0000
+                 1
___________________
0001 0001 0100 0001 = 2^12 + 2^8 + 2^6 + 2^0 = -4417

b) suma num1+num2, decir si hubo overflow y por que
1110 1110 1011 1111
+
0111 1111 1010 0010
___________________
1|0110 1110 0110 0001 = 2^14 + 2^13 + 2^11 + 2^10 + 2^9 + 2^6 + 2^5 + 2^0 =  28257 hubo carry no overflow

c) resta num2-num1, decir si hubo overflow y por que
0111 1111 1010 0010
-
1110 1110 1011 1111
___________________
CA2 al primero
1000 0000 0101 1110
+
1110 1110 1011 1111
___________________
1|0110 1111 0001 1101 = 2^14 + 2^13 + 2^11 + 2^10 + 2^9 + 2^8 + 2^4 + 2^3 + 2^2 + 2^0 = -28445 hubo overflow porque el numero se fue
rango el valor real deberia ser 37091

d) comprobar valor del 5to bit
#define mask 0x1
void bit5(int16_t num){
	if(num&mask<<5) printf("1\n");
	else printf("0\n");
}
int main(){
	int16_t num1=0xEEBF;
	printf("bit 5 de 0xEEBF = ");
	bit5(num1);

	return 0;
}

e) forzar 3er bit a 0
#define mask 0x1
void forzarTercerBit(int16_t *num){
	(*num)&=(~(mask<<3));
}
int main(){
	int16_t num2=0x7FA2;
	forzarTercerBit(&num2);

	return 0;
}
*/

void binario(int16_t num){
    for(int i=15; i>=0; i--){
        if(num&mask<<i){
            printf("1");
        }
        else printf("0");
    }
    printf("\n");
}

void bit5(int16_t num){
    if(num&mask<<5){
        printf("1\n");
    }
    else printf("0\n");
}

void forzar0(int16_t *num){
    (*num)&=(~(mask<<3));
}

int main(){
    int16_t num1=0xEEBF, num2=0x7FA2;

    printf("Numero 1: ");
    binario(num1);
    printf("%d\n", num1);
    printf("Numero 2: ");
    binario(num2);
    printf("%d\n", num2);

    int16_t resultado = num1+num2;
    printf("resultado num1+num2 = %d\n", resultado);
    resultado = num2-num1;
    printf("resultado num2-num1 = %d\n", resultado);
    printf("bit 5 de EEBF = ");
    bit5(num1);

    forzar0(&num2);
    printf("Numero 2 forzado a 0 el 3er bit: ");
    binario(num2);

    forzar0(&num1);
    printf("Numero 1 forzado a 0 el 3er bit: ");
    binario(num1);

    return 0;
}
