#include <stdio.h>
#include <stdint.h>

#define sMask 0x1
#define eMask 0xff
#define mMask 0x7fffff

struct camposFloat_t{
    uint32_t signo;
    uint32_t exponente;
    uint32_t mantisa;
};

struct camposFloat_t ImprimirCamposFloat(float num){
    struct camposFloat_t campoF;
    int32_t *pi = &num;
    uint32_t signo;
    uint32_t exponente;
    uint32_t mantisa;

    signo = *pi&sMask<<31;
    signo = signo>>31;

    exponente = *pi&eMask<<23;
    exponente = exponente>>23;

    mantisa = *pi&mMask;

    campoF.signo=signo;
    campoF.exponente=exponente;
    campoF.mantisa=mantisa;

    printf(" Signo: %#x\n exponente: %#x\n mantisa: %#x\n", campoF.signo, campoF.exponente, campoF.mantisa);

    return campoF;
}

float ArmarImprimirFloat(struct camposFloat_t camposFloat){
    float numero;
    float mantisaGen=1;

    for(int i=0; i<23; i++){
        if(camposFloat.mantisa&sMask<<23-i)
            mantisaGen+=pow(2, -i);
    }

    numero=mantisaGen*pow(2, camposFloat.exponente-127)*pow(-1, camposFloat.signo);

    printf("Numero float: %f", numero);

    return numero;
}

int main(){
    struct camposFloat_t cF;
    float num=-5.0205;
    float numero;

    cF=ImprimirCamposFloat(num);
    numero=ArmarImprimirFloat(cF);

    return 0;
}
