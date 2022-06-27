/*

Tomas Gauna 1B Trabajo Practico 2

*/

#include <stdio.h>
#include <stdlib.h>
#include "arraypassenger.h"
#include "utn.h"
#include "servicio.h"

#define TAM 15
#define P 3

int main(void)
{
	setbuf(stdout, NULL);
	char opcion[10];
	int opcionElegida;
	int valido;
	int retorno;
	float promedio;
	int altasHechas = 0;

	Passenger list[TAM];
	TypePassenger listType[P] = {{100, "Clase Alta"},{101, "Clase Media"},{102, "Clase Baja"}};

	valido = initPassengers(list, TAM);

	if(valido == 0)
	{
		do
		{
			getString("\n< Menu de opciones >\n1.ALTA pasajero\n2.MODIFICAR pasajero\n3.BAJA pasajero\n4.INFORMES\n5.Carga forzada\n6.Salir\nIngrese el numero de la opcion a acceder: ", opcion);
			opcionElegida = atoi(opcion);
			while(esNumerico(opcion) == 0 || (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3 && opcionElegida != 4 && opcionElegida != 5 && opcionElegida != 6))
			{
				getString("\n|ERROR|\n< Menu de opciones >\n1.ALTA pasajero\n2.MODIFICAR pasajero\n3.BAJA pasajero\n4.INFORMES\n5.Carga forzada\n6.Salir\nIngrese un numero de opcion posible: ", opcion);
				opcionElegida = atoi(opcion);
			}

			switch(opcionElegida)
			{
				case 1:
					retorno = CargarListaDeVuelos(list, TAM, listType, P);
					switch(retorno)
					{
						case -1:
							printf("\n|ERROR|\nNo se ha podido cargar el pasajero.\n");
						break;

						default:
							printf("\nEl pasajero se ha cargado correctamente\n");
							altasHechas++;
						break;
					}
				break;

				case 2:
					if(altasHechas == 0)
					{
						printf("\n|ERROR|\nSe debe realizar por lo menos un alta de servicio para ingresar a esta opcion.\n");
					}
					else
					{
						retorno = ModificarVuelo(list, TAM, listType, P);
						switch(retorno)
						{
							case -1:
								printf("\n|No se han modificado los datos|\n");
							break;

							default:
								printf("\nLos datos han sido modificados correctamente.\n");
							break;
						}
					}
				break;

				case 3:
					if(altasHechas == 0)
					{
						printf("\n|ERROR|\nSe debe realizar por lo menos un alta de servicio para ingresar a esta opcion.\n");
					}
					else
					{
						retorno = DarDeBaja(list, TAM, listType, P);
						switch(retorno)
						{
							case -1:
								printf("\n|No se ha podido dar de baja el pasajero|\n");
							break;

							default:
								printf("\nEl pasajero ha sido dado de baja con exito\n");
							break;
						}
					}
				break;

				case 4:
					if(altasHechas == 0)
					{
						printf("\n|ERROR|\nSe debe realizar por lo menos un alta de servicio para ingresar a esta opcion.\n");
					}
					else
					{
						getString("\n< Listado de INFORMES >\na)Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
								  "\nb)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
								  "\nc)Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\nd)Salir\nIngrese la letra de la opcion a acceder: ", opcion);
						while(esSoloLetras(opcion) == 0 || (strcmp(opcion, "a") != 0 && strcmp(opcion, "b") != 0 && strcmp(opcion, "c") != 0 && strcmp(opcion, "d") != 0))
						{
							getString("\n|ERROR|\n< Listado de INFORMES >\na)Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
									  "\nb)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
									  "\nc)Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\nd)Salir\nIngrese una opcion posible: ", opcion);
						}

						if(strcmp(opcion, "a") == 0)
						{
							retorno = sortPassengers(list, TAM, 1);
							printPassenger(list, TAM, listType, P);
						}
						else
						{
							if(strcmp(opcion, "b") == 0)
							{
								promedio = CalcularPromedioDePrecio(list, TAM);
								ListaPasajerosPrecioMayorPromedio(list, TAM, listType, P, promedio);
							}
							else
							{
								if(strcmp(opcion, "c") == 0)
								{
									ListaVuelosActivosOrdenados(list, TAM, listType, P);
								}
							}
						}
					}
				break;

				case 5:
					CargarForzadamenteListaPasajeros(list, &altasHechas);
					printf("\n< Carga forzada realizada con exito >\n");
				break;
			}
		}while(opcionElegida != 6);
	}

	return EXIT_SUCCESS;
}
