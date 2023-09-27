#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t uvar16=0x80ff;
    uint32_t uvar32=(uint32_t)uvar16;
    int16_t var16=0x80ff;
    int32_t var32=(int32_t)var16;

    printf("sizeof sin casteo: %d\n", sizeof(uvar16)*8);
    printf("sizeof: %d\n", sizeof((uint32_t)uvar16)*8);

    printf("Hexa u16: %#x\n", uvar16);
    printf("Entero u16 con signo: %d\n", uvar16);
    printf("Entero u16 sin signo: %u\n", uvar16);
    printf("Hexa u32: %#x\n", uvar32);
    printf("Entero u32 con signo: %d\n", uvar32);
    printf("Entero u32 sin signo: %u\n", uvar32);
    printf("Hexa u16: %#x\n", var16);
    printf("Entero u16 con signo: %d\n", var16);
    printf("Entero u16 sin signo: %u\n", var16);
    printf("Hexa u32: %#x\n", var32);
    printf("Entero u32 con signo: %d\n", var32);
    printf("Entero u32 sin signo: %u\n", var32);

    return 0;
}
