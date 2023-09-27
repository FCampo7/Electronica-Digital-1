#include <stdio.h>
#include <stdint.h>

void ImprimirContenidoEntero(int16_t numeroRepresentar){
    uint16_t unum = numeroRepresentar;
    printf("sin h: 0x%x\n", numeroRepresentar);
    printf("signado: 0x%hx\n", numeroRepresentar);
    printf("no signado: 0x%hx\n", unum);
    printf("no signado sin h: 0x%x\n", unum);
}

int main(){
    int16_t num=0x7fff;

    printf("%d\n", num);
    ImprimirContenidoEntero(num);
    num++;
    ImprimirContenidoEntero(num);
    num=0x0000;
    ImprimirContenidoEntero(num);

    return 0;
}
