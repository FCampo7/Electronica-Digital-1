#include <stdio.h>
#include <stdint.h>
#include <math.h>

int32_t BinarioDecimal(char* cadena_numero){
    int cont=-1;//inicia en -1 porque el primer elemento va a ser el 0.
    int numero=0;
    char* principio=cadena_numero;//Guardo la direccion de memoria del primer elemento.

    while(*cadena_numero != '\0'){
        cont++;
        cadena_numero++;
    }//obtengo el tamaño de la cadena.

    cadena_numero=principio; //vuelvo a setear la cadena al principio.

    for(int i=cont; i>=0; i--){
        if(*cadena_numero=='1'){
            numero+=pow(2, i);
        }
        cadena_numero++;
    }//construyo el numero entero.

    return numero;
}

int main(){
    char cadena[32]={"0"};
    int32_t resultado;
    printf("ingresar numero en binario: ");
    scanf("%s", cadena);

    resultado=BinarioDecimal(cadena);
    printf("decimal\t\t\t");
    printf("hexadecimal\t\t");
    printf("octal\t\t");
    printf("binario\n");
    printf("%i\t\t\t", resultado);
    printf("%x\t\t\t", resultado);
    printf("%o\t\t", resultado);
    printf("%s\n", cadena);

    return 0;
}
