#ifndef BIBLIOTECA_PROPIA_H_
#define BIBLIOTECA_PROPIA_H_

#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

int DescifrarUltimoID(char* path, char* id);
int SumarID(char* idStr);
int GuardarID(char* path, char* id);
void PedirNombre(char* nombre);
void PedirApellido(char* apellido);
void PedirPrecio(char* precio);
int PedirTipo();
void DeterminarTipoPasajero(int tipo, char* tipoStr);
int PedirEstado();
void EstablecerEstado(int estado, char* estadoStr);
void PedirCodigo(char* codigo);
int PedirID();
int BuscarID(LinkedList* pArrayListPassenger, int id);
int EnlistPassenger(LinkedList* pArrayPassenger, int index);
int EliminarPasajero(LinkedList* pArrayListPassenger, int id);
int MostrarListadoOrdenado(LinkedList* pArrayListPassenger, int opcionElegida);
int DeterminarCriterio();
int CompareByID(void* p1, void* p2);
int CompareByName(void* p1, void* p2);
int CompareByLastName(void* p1, void* p2);
int CompareByCodigo(void* p1, void* p2);
int CompareByTipoPasajero(void* p1, void* p2);
int CompareByEstado(void* p1, void* p2);
int CompareByPrecio(void* p1, void* p2);
int SaveText(FILE* pArchivo , LinkedList* pArrayListPassenger);

#endif
