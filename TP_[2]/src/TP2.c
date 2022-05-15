#include "arraypassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#define T 2000
#define X 3


int main(void)
{
	setbuf(stdout, NULL);
	int opcionElegida;
	int retorno;

	Passenger list[T];
	typePassenger lista[X] = {{100,"Ninio"}, {101, "Adolescente"}, {102, "Adulto"}};

	initPassengers(list, T);

	InicializarListaPasajeros(list);

	do
	{
		opcionElegida = MostrarMenuOpciones();
		switch(opcionElegida)
		{
			case 1:
				retorno = CargarListaPasajeros(list, T, lista, X);
				switch(retorno)
				{
					case -1:
						printf("\n|ERROR|\nNo se ha podido cargar el pasajero. No hay mas espacio\n");
					break;

					default:
						printf("\nEl pasajero ha sido cargado correctamente.\n");
					break;
				}
			break;

			case 2:
				retorno = ModificarPasajero(list, T, lista, X);
				switch(retorno)
				{
					case 0:
						printf("\n|No se han podido modificar los datos|\n");
					break;

					case 1:
						printf("\n||El pasajero se ha modificado correctamente||\n");
					break;
				}
			break;

			case 3:
				retorno = EliminarPasajero(list, T);
				switch(retorno)
				{
					case -1:
						printf("\nNo se ha podido eliminar al pasajero.");
					break;

					default:
						printf("\nEl pasajero ha sido eliminado correctamente.");
					break;
				}
			break;

			case 4:
				retorno = MostrarListaOpciones4();
				switch(retorno)
				{
					case 1:
						OrdenarListaPasajerosPorApellido(list, T);
					break;

					case 2:
						MostrarOpcionDosCuatro(list, T);
					break;

					case 3:
						OrdenarListaDePasajerosPorCodigo(list, T);
					break;
				}
			break;
		}
	}while(opcionElegida != 5);




	return EXIT_SUCCESS;
}
