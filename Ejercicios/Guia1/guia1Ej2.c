#include <stdio.h>
#include <stdint.h>

int main(){
    uint8_t var_c;
    int16_t var_si;
    int32_t var_i;
    int32_t var_li;
    int64_t var_lli;
    float var_f;
    double var_d;

    scanf("%c", &var_c);
    printf("%c\n", var_c);
    printf("tam char %d\n", sizeof(var_c)*8);
    printf("tam short int %d\n", sizeof(var_si)*8);
    printf("tam int %d\n", sizeof(var_i)*8);
    printf("tam long int %d\n", sizeof(var_li)*8);
    printf("tam long long int %d\n", sizeof(var_lli)*8);
    printf("tam float %d\n", sizeof(var_f)*8);
    printf("tam double %d\n", sizeof(var_d)*8);

    system("PAUSE");

    return 0;
}
