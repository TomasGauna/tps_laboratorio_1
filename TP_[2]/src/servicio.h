#ifndef SERVICIO_H_
#define SERVICIO_H_

#include <stdio.h>
#include <stdlib.h>
#include "arraypassenger.h"
#include "typePassenger.h"
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1

int CalcularId();
void PedirNombre(char nombre[]);
void PedirApellido(char apellido[]);
float PedirPrecio();
void PedirCodigo(char codigo[]);
int PedirTipoPasajero(TypePassenger list[], int len);
int PedirEstadoVuelo();
int CargarUnVuelo(Passenger list[], int len, TypePassenger listTypes[], int lenType);
int CargarListaDeVuelos(Passenger list[], int len, TypePassenger listTypes[], int lenType);
int ModificarVuelo(Passenger list[], int len, TypePassenger listTypes[], int lenType);
int DarDeBaja(Passenger list[], int len, TypePassenger listTypes[], int lenType);
float CalcularPromedioDePrecio(Passenger list[], int len);
void ListaPasajerosPrecioMayorPromedio(Passenger list[], int len, TypePassenger listTypes[], int lenType, float promedio);
void ListaVuelosActivosOrdenados(Passenger list[], int len, TypePassenger listTypes[], int lenType);
void CargarForzadamenteListaPasajeros(Passenger list[], int* altasHechas);

#endif
