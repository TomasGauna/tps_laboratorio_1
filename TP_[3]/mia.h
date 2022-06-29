#ifndef MIA_H_
#define MIA_H_

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DescifrarUltimoID(char* path, char* id);
int CalcularID(char* id);
int GuardarProximoID(char* path, char* id);
void PedirNombre(char* nombre);
void PedirApellido(char* apellido);
float PedirPrecio();
int PedirTipoPasajero();
void DefinirTipoPasajero(int tipo, char* tipoStr);
void PedirCodigoVuelo(char* codigo);
int PedirEstadoVuelo();
void DefinirEstadoVuelo(int estado, char* estadoStr);

#endif
