#include <stdio.h>
#include <stdint.h>

int main(){
    char c=65;
    printf("char: %c\n", c);
    printf("entero: %d\n", c);
    c='a';
    printf("char: %c\n", c);
    printf("entero: %d\n", c);
    c++;
    printf("char: %c\n", c);
    printf("entero: %d\n", c);
    c*=2;
    printf("char: %c\n", c);
    printf("entero: %d\n", c);

    return 0;
}
