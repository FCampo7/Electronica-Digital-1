#include "stdio.h"

int main(){
    char cadena[]="La verdad se corrompe tanto con la mentira como con el silencio";
    int cl=0, ce=0, cp=0, clm=0, aux=0, i=0;
    while(cadena[i]!='\0'){
        cl++;
        aux++;
        if(cadena[i]==' '){
            aux--;
            ce++;
            cp++;
            if(clm<aux) clm=aux;
            aux=0;
        }
        i++;
    }
    if(cadena[i-1]!=' '){
        cp++;
        if(clm<aux) clm=aux;
    }
    printf("Cantidad de letras: %d\nCantidad de espacios: %d\nCantidad de palabras: %d\nCantidad de letras de la palabra mas larga: %d\n", cl, ce, cp, clm);
    return 0;
}
