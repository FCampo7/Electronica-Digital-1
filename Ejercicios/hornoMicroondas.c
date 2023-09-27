#include <stdio.h>
#include "driversExternos.h"

int32_t mdeHornoMicroondas(void){
    switch(estadoMde){
    case ESTADO_ENCENDIDO:
        if(hornoAbierto==SI){
            ApagarHorno();
            estadoMde = ESTADO_ABIERTO;
        }
        if(hornoAbierto==NO && cuentaTiempo==cuentaMax){
            ApagarHorno();
            estadoMde=ESTADO_CERRADO;
        }
        break;
    case ESTADO_ABIERTO:
        if(hornoAbierto==NO){
            estadoMde=ESTADO_CERRADO;
        }
        break;
    case ESTADO_CERRADO:
        if(hornoAbierto==SI){
            estadoMde=ESTADO_ABIERTO;
        }
        if(hornoAbierto==NO && botonInicio==SI){
            cuentaTiempo=0;
            EncenderHorno();///En EncenderHorno se prende y comienza a contar el tiempo;
            estadoMde=ESTADO_ENCENDIDO;
        }
        break;
    default:
    }
    return 0;
}

int32_t InicializarMdeHornoMicroondas(void){
    estadoMde=ESTADO_INCIAL;
    ApagarHorno();
    cuentaTiempo=0;
    cuentaMax=30;
    botonInicio=NO;
    hornoAbierto=SI;
    return 0;
}

int main(){
    InicializarMdeHornoMicroondas();
    while(1){
        mdeHornoMicroondas();
    }
    return 0;
}
