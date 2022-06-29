#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int valido = -1;
	int cantidad = 0;

	Passenger* unVuelo = NULL;

	char id[20];
    char nombre[20];
    char apellido[20];
    char precio[20];
    char tipo[20];
    char codigo[20];
    char estado[20];

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,apellido,precio,codigo,tipo,estado);
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,apellido,precio,codigo,tipo,estado);

			if(cantidad == 7)
			{
				unVuelo = Passenger_newParametros(id, nombre, apellido, precio, tipo, codigo, estado);

				if(unVuelo != NULL)
				{
					ll_add(pArrayListPassenger, unVuelo);
					valido = 0;
				}
				else
				{
					Passenger_delete(unVuelo);
				}
			}
		}
		while(!feof(pFile));
	}

    return valido;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int valido = -1;
	Passenger* unVuelo = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			unVuelo = Passenger_new();

			if(unVuelo != NULL)
			{
				if(fread(unVuelo, sizeof(Passenger), 1, pFile))
				{
					ll_add(pArrayListPassenger, unVuelo);

					valido = 0;
				}
				else
				{
					Passenger_delete(unVuelo);
				}
			}
		}while(!feof(pFile));
	}

    return valido;
}

