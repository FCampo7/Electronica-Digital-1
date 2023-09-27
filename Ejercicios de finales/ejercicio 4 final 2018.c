typedef enum {estado_a, estado_b, estado_c} t_estado;
typedef enum {verde, rojo} t_color;

int Estado_Sensor(void);
void Encender_Alarma(void);
void Apagar_Alarma(void);
int Medicion_Sensor(void);
int Enceder_Luz(t_color luz);
int Apagar_Luz(t_color luz);

t_estado estadoInit=estado_a;
t_estado estadoAct;

void inicializarMDE(){
    estadoAct=estadoInit;
    Apagar_Luz(verde);
    Enceder_Luz(rojo);
    Encender_Alarma();
}

void MDE(){
    switch(estadoAct){
    case estado_a:
        if(Estado_Sensor()==1){
            Apagar_Alarma();
            estadoAct=estado_b;
        }
        break;
    case estado_b:
        if(Estado_Sensor()==0){
            Apagar_Luz(verde);
            Encender_Luz(rojo);
            Encender_Alarma();
            estadoAct=estado_a;
        }
        if(Medicion_Sensor()<100){
            Apagar_Luz(rojo);
            Encender_Luz(verde);
        }
        if(Medicion_Sensor()>=100){
            Apagar_Luz(verde);
            Encender_Luz(rojo);
            estadoAct=estado_c;
        }
        break;
    case estado_c:
        if(Estado_Sensor()==0){
            Apagar_Luz(verde);
            Encender_Luz(rojo);
            Encender_Alarma();
            estadoAct=estado_a;
        }
        if(Medicion_Sensor()<100){
            Apagar_Luz(rojo);
            Enceder_Luz(verde);
            estadoAct=estado_b;
        }
        if(Medicion_Sensor()>=100){
            Apagar_Luz(verde);
            Encender_Luz(rojo);
        }
        break;
    default:
        inicializarMDE();
    }
}

int main(){
    inicializarMDE();
    while(1){
        MDE();
    }
    return 0;
}
