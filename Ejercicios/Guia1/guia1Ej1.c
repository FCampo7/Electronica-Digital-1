#include <stdio.h>

int main(){
    char var_c;
    short int var_si;
    int var_i;
    long int var_li;
    long long int var_lli;
    float var_f;
    double var_d;

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
