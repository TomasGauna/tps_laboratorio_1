#include "parser.h"

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
	Passenger* unVuelo = NULL;
	int cantidad;
	char id[100];
	char nombre[100];
	char precio[100];
	char codigoVuelo[100];
	char apellido[100];
	char estado[100];
	char tipoPasajero[100];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estado);

		do
		{
			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estado);

			if(cantidad == 7)
			{
				unVuelo = Passenger_newParametros(id, nombre, tipoPasajero, apellido, codigoVuelo, precio, estado);

				if(unVuelo != NULL)
				{
					ll_add(pArrayListPassenger, unVuelo);
					valido = 1;
				}
				else
				{
					Passenger_delete(unVuelo);
				}
			}
			else
			{
				printf("ERROR...\n");
			}
		}while(!feof(pFile));
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
					valido = 1;
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
