#include "stdio.h"
#include "stdint.h"

/**
    El prototipo de la funci�n es el siguiente:
        int FSM_Manejo_Sensor (void);
    Se cuenta adem�s con las siguientes funciones:
        int Estado_Sensor (void);    // devuelve 0 si el sensor est� inactivo y 1 si est� activo
        void Encender_Alarma (void); // Enciende la alarma
        void Apagar_Alarma (void);  // Apaga la alarma
        int Medicion_Sensor (void); // entrega un n�mero correspondiente a la medici�n del sensor.
        int Encender_Luz (t_color luz); // Enciende la luz recibida como par�metro: ROJO o VERDE.
        int Apagar_Luz (t_color luz); // Apaga la luz recibida como par�metro: ROJO o VERDE.
    Realizar adem�s el c�digo correspondiente a la rutina de inicializaci�n.
*/

typedef enum {ESTADO_A, ESTADO_B, ESTADO_C} t_estados;

t_estados estado;
t_estados estadoInicial = ESTADO_A;

void InicializarFSM(void){
    estado=estadoInicial;
    Apagar_Alarma();
    Apagar_Luz(ROJO);
    Apagar_Luz(VERDE);
}

int FSM_Manejo_Sensor (void){
    switch(estado){
    case ESTADO_A:
        if(Estado_Sensor()==1){
            Apagar_Alarma();
            estado=ESTADO_B;
        }
        break;
    case ESTADO_B:
        if(Estado_Sensor()==0){
            Encender_Alarma();
            estado=ESTADO_A;
        }
        if(Medicion_Sensor()<100){
            Apagar_Luz(ROJO);
            Encender_Luz(VERDE);
        }
        if(Medicion_Sensor>=100){
            Apagar_Luz(VERDE);
            Encender_Luz(ROJO);
            estado=ESTADO_C;
        }
        break;
    case ESTADO_C:
        if(Estado_Sensor()==0){
            Encender_Alarma();
            estado=ESTADO_A;
        }
        if(Medicion_Sensor()>=100){
            Apagar_Luz(VERDE);
            Encender_Luz(ROJO);
        }
        if(Medicion_Sensor()<100){
            Apagar_Luz(ROJO);
            Encender_Luz(VERDE);
            estado=ESTADO_B;
        }
        break;
    default:
        inicializarFSM();
        break;
    }
    return 0;
}

int main(){
    inicializarFSM();
    while(1){
        FSM_Manejo_Sensor();
    }
    return 0;
}
