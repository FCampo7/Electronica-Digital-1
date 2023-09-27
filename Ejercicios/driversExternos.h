#include <stdint.h>
#include <stdbool.h>

#define ESTADO_ENCENDIDO 0
#define ESTADO_ABIERTO 1
#define ESTADO_CERRADO 2
#define ESTADO_INCIAL ESTADO_ABIERTO
#define SI 1
#define NO 0

bool hornoAbierto=SI;
bool botonInicio=NO;

int32_t estadoMde=ESTADO_INICIAL;
int32_t cuentaTiempo=0;
int32_t cuentaMax=30;

int32_t mdeHornoMicroondas (void);
int32_t InicializarMdeHornoMicroondas (void);

void ApagarHorno(void);
void EncenderHorno(void);
