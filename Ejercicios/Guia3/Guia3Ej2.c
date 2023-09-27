#include "stdio.h"
#include "stdint.h"

/**
    Se desea realizar un sistema de port�n autom�tico para el garaje de un auto. El port�n cuenta con dos sensores que permiten detectar si el port�n est� completamente abierto, o si est� completamente
    cerrado, y con un motor que gira en un sentido para abrir, y en el sentido opuesto para cerrar. Adem�s, tiene un control remoto con una tecla �nica que permite accionar el mecanismo. Realice el
    diagrama de estados del funcionamiento del port�n autom�tico y su implementaci�n en C. Definir solo el prototipo de todas las funciones que crea necesarias para la implementaci�n, tal como manejo
    de motor, detecci�n de sensor de abierto y cerrado, y detecci�n de tecla de control remoto presionada. Implementar adem�s la rutina de inicializaci�n de la m�quina.
*/

int Estado_Sensor_Abierto(void); //devuelve 0 si el porton esta totalmente abierto y 1 en caso contrario;
int Estado_Sensor_Cerrado(void); //devuelve 0 si el porton esta totalmente cerrado y 1 en caso contrario;
void Abrir_Porton(void); //El motor gira en el sentido para abrir;
void Cerrar_Porton(void); //El motor gira en el sentido para cerrar;
void Parar_Porton(void); //El motor se para;
int Tecla_Control(void); //Devuelve 0 si no esta presionada y 1 si si lo esta;

typedef enum {ABIERTO, CERRADO, ENPROCESO, PARADO} t_Estado;

t_Estado estado;
t_Estado estadoAnterior;
t_Estado estadoInicial = PARADO;

void inicializarMDE(void){
    estado=estadoInicial;
    estadoAnterior=ABIERTO;
    Parar_Porton();
}

int portonMDE(void){
    switch(estado){
    case ABIERTO:
        if(Tecla_Control()==1 && Estado_Sensor_Abierto()==0){
            Cerrar_Porton();
            estado=ENPROCESO;
            estadoAnterior=ABIERTO;
        }
        break;
    case ENPROCESO:
        if(Estado_Sensor_Abierto()==0){
            Parar_Porton();
            estado=ABIERTO;
            estadoAnterior=CERRADO;
        }
        if(Estado_Sensor_Cerrado()==0){
            Parar_Porton();
            estado=CERRADO;
            estadoAnterior=ABIERTO;
        }
        if(Tecla_Control()==1 && Estado_Sensor_Abierto()==1 && Estado_Sensor_Cerrado()==1){
            Parar_Porton();
            estado=PARADO;
        }
        break;
    case PARADO:
        if(Tecla_Control()==1 && estadoAnterior==CERRADO){
            Cerrar_Porton();
            estado=ENPROCESO;
            estadoAnterior=ABIERTO;
        }
        if(Tecla_Control()==1 && estadoAnterior==ABIERTO){
            Abrir_Porton();
            estado=ENPROCESO;
            estadoAnterior=CERRADO;
        }
        break;
    case CERRADO:
        if(Tecla_Control()==1 && Estado_Sensor_Cerrado()==0){
            Abrir_Porton();
            estado=ENPROCESO;
            estadoAnterior=CERRADO;
        }
        break;
    default:
        inicializarMDE();
        break;
    }
    return 0;
}

int main(){
    inicializarMDE();

    while(1){
        portonMDE();
    }

    return 0;
}
