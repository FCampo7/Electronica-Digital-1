#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t num1=0x8000;
    uint16_t num2=0x0001;
    uint16_t resultado=num1-num2;
    printf("num1 hexa: %x\n", num1);
    printf("num1 no signada %u\n", num1);
    printf("num1 signada %d\n", num1);
    printf("num2 hexa: %x\n", num2);
    printf("num2 no signada %u\n", num2);
    printf("num2 signada %d\n", num2);
    printf("resultado hexa: %x\n", resultado);
    printf("resultado no signada %u\n", resultado);
    printf("resultado signada %d\n", resultado);
    printf("\n");

    num1=0x7fff;
    num2=0x0001;
    resultado=num1+num2;
    printf("num1 hexa: %x\n", num1);
    printf("num1 no signada %u\n", num1);
    printf("num1 signada %d\n", num1);
    printf("num2 hexa: %x\n", num2);
    printf("num2 no signada %u\n", num2);
    printf("num2 signada %d\n", num2);
    printf("resultado hexa: %x\n", resultado);
    printf("resultado no signada %u\n", resultado);
    printf("resultado signada %d\n", resultado);
    printf("\n");

    num1=0xf000;
    num2=0xff01;
    resultado=num1+num2;
    printf("num1 hexa: %x\n", num1);
    printf("num1 no signada %u\n", num1);
    printf("num1 signada %d\n", num1);
    printf("num2 hexa: %x\n", num2);
    printf("num2 no signada %u\n", num2);
    printf("num2 signada %d\n", num2);
    printf("resultado hexa: %x\n", resultado);
    printf("resultado no signada %u\n", resultado);
    printf("resultado signada %d\n", resultado);
    printf("\n");

    num1=0x0011;
    num2=0xff01;
    resultado=num1+num2;
    printf("num1 hexa: %x\n", num1);
    printf("num1 no signada %u\n", num1);
    printf("num1 signada %d\n", num1);
    printf("num2 hexa: %x\n", num2);
    printf("num2 no signada %u\n", num2);
    printf("num2 signada %d\n", num2);
    printf("resultado hexa: %x\n", resultado);
    printf("resultado no signada %u\n", resultado);
    printf("resultado signada %d\n", resultado);
    printf("\n");


    return 0;
}
