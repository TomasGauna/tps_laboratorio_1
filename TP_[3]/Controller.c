#include "Controller.h"
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int valido;
	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	valido = parser_PassengerFromText(pArchivo, pArrayListPassenger);

	fclose(pArchivo);

	return valido;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int valido;
	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	valido = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);

	fclose(pArchivo);

    return valido;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int valido = -1;
	Passenger* unVuelo = NULL;
	char idStr[10];
	char nombre[50];
	char apellido[50];
	char precio[50];
	int tipo;
	char tipoStr[20];
	char codigoVuelo[20];
	int estado;
	char estadoVuelo[20];

	PedirNombre(nombre);
	PedirApellido(apellido);
	PedirPrecio(precio);
	tipo = PedirTipo();
	DeterminarTipoPasajero(tipo, tipoStr);
	PedirCodigo(codigoVuelo);
	estado = PedirEstado();
	EstablecerEstado(estado, estadoVuelo);

	if(DescifrarUltimoID("ID.txt", idStr) == 1 && SumarID(idStr) == 1)
	{
		unVuelo = Passenger_newParametros(idStr, nombre, tipoStr, apellido, estadoVuelo, precio, estadoVuelo);
	}

	if(unVuelo != NULL)
	{
		if(GuardarID("ID.txt", idStr) == 1)
		{
			ll_add(pArrayListPassenger, unVuelo);
			valido = 1;
		}
	}

    return valido;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int valido;
	int index;
	int id;
	Passenger* unVuelo = NULL;

	if(pArrayListPassenger != NULL)
	{
		if(controller_ListPassenger(pArrayListPassenger) == 1)
		{
			id = PedirID();
			index = BuscarID(pArrayListPassenger, id);
			if(index != -1)
			{
				unVuelo = (Passenger*) ll_get(pArrayListPassenger, index);
				EnlistPassenger(pArrayListPassenger, index);
				valido = Passenger_EditPassenger(unVuelo);
			}
		}
	}

    return valido;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int valido;
	int id;

	if(controller_ListPassenger(pArrayListPassenger) == 1)
	{
		id = PedirID();
		valido = EliminarPasajero(pArrayListPassenger, id);
	}

    return valido;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int valido = -1;
	int cantidad;

	if(pArrayListPassenger != NULL)
	{
		cantidad = ll_len(pArrayListPassenger);

		if(cantidad > 0)
		{
			printf("\n< LISTADO DE PASAJEROS >");
			printf("\n ID	 Nombre		      Apellido	           Precio      Tipo de pasajero     Codigo               Estado\n");
			for(int i = 0; i < cantidad; i++)
			{
				valido = EnlistPassenger(pArrayListPassenger, i);
			}
		}
	}

    return valido;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int valido;
	int compruebo;
	char pedirOpcion[50];
	int opcionElegida;

	compruebo = getStringNumeros("\n< LISTADO DE ORDENAMIENTOS >\n1.Lista de pasajeros\n2.Lista ordenada por ID\n3.Lista ordenada por nombre\n4.Lista ordenada por apellido\n"
			                     "5.Lista ordenada por tipo de pasajeros\n6.Lista ordenada por precio\n7.Lista ordenada por estado de vuelo\n"
			                     "8.Lista ordenada por codigo de vuelo\n9.Salir\nElija una opcion: ", pedirOpcion);
	opcionElegida = atoi(pedirOpcion);
	while(compruebo != 1 || (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3 && opcionElegida != 4 && opcionElegida != 5
		  && opcionElegida != 6 && opcionElegida != 7 && opcionElegida != 8 && opcionElegida != 9))
	{
		compruebo = getStringNumeros("\n|ERROR|\n< LISTADO DE ORDENAMIENTOS >\n1.Lista de pasajeros\n2.Lista ordenada por ID\n3.Lista ordenada por nombre\n4.Lista ordenada por apellido\n"
				                     "5.Lista ordenada por tipo de pasajeros\n6.Lista ordenada por precio\n7.Lista ordenada por estado de vuelo\n"
				                     "8.Lista ordenada por codigo de vuelo\n9.Salir\nElija una opcion correcta: ", pedirOpcion);
		opcionElegida = atoi(pedirOpcion);
	}

	valido = MostrarListadoOrdenado(pArrayListPassenger, opcionElegida);

    return valido;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int valido = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			valido = SaveText(pArchivo, pArrayListPassenger);
		}
		else
		{
			printf("\nError al intentar abrir el archivo\n");
		}

		fclose(pArchivo);
	}

    return valido;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int valido = -1;
	int len;
	FILE* pArchivo;
	Passenger* unVuelo = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				unVuelo = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unVuelo != NULL)
				{
					fwrite(unVuelo, sizeof(Passenger), 1, pArchivo);
					valido = 1;
				}
			}
		}
		else
		{
			printf("\nError al intentar abrir el archivo\n");
		}

		fclose(pArchivo);
	}

    return valido;
}

