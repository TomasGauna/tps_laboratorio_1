/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int valido = 0;
	FILE* pArchivo;

	pArchivo=fopen(path,"r");

	if(parser_PassengerFromText(pArchivo, pArrayListPassenger) == 1)
	{
		valido = 1;
	}

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
	int valido = 0;
	FILE* pArchivo;

	pArchivo = fopen(path,"rb");

	if(parser_PassengerFromBinary(pArchivo, pArrayListPassenger)==1)
	{
		valido = 1;
	}

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
	Passenger* unVuelo = NULL;
	int valido = -1;
	char id[50];
	char nombre[50];
	char apellido[50];
	float precio;
	char precioStr[50];
	int tipoPasajero;
	char tipoStr[50];
	char codigoVuelo[20];
	int estado;
	char estadoVuelo[20];

	if(pArrayListPassenger != NULL)
	{
		PedirNombre(nombre);
		PedirApellido(apellido);
		precio = PedirPrecio();
		gcvt(precio, 8, precioStr);
		tipoPasajero = PedirTipoPasajero();
		DefinirTipoPasajero(tipoPasajero, tipoStr);
		estado = PedirEstadoVuelo();
		DefinirEstadoVuelo(estado, estadoVuelo);
		PedirCodigoVuelo(codigoVuelo);

		if(DescifrarUltimoID("ID.txt", id) == 0 && CalcularID(id) == 0)
		{
			unVuelo = Passenger_newParametros(id, nombre, apellido, precioStr, tipoStr, codigoVuelo, estadoVuelo);

			if(unVuelo != NULL)
			{
				if(GuardarProximoID("ID.txt", id) == 0)
				{
					ll_add(pArrayListPassenger, unVuelo);
					valido = 0;
				}
			}
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
	int auxI;
	int index;
	Passenger* unVuelo = NULL;

	if(pArrayListPassenger != NULL)
	{
		if(controller_ListPassenger(pArrayListPassenger) == 0)
		{
			auxI = PedirId();//hacer funcion q pida
			index = BuscarId();//hacer funcion
			unVuelo = (Passenger*) ll_get(pArrayListPassenger, index);

			if(unVuelo != NULL)
			{
				Passenger_printOne(unVuelo);
				valido = ModificarVuelo();//hacer
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
	int auxI;

	if(controller_ListPassenger(pArrayListPassenger) == 0)
	{
		auxI = PedirId();//hacer
		valido = DarDeBaja();//hacer TODO EN BIBLIOTECA PROPIA
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
	int valido;
	int len;

	len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL && len > 0)
	{
		printf("|LISTADO DE PASAJEROS|\n");
		valido = Passenger_printListPassenger(pArrayListPassenger);
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

	valido = MostrarListadoOrdenamientos();//hacer

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
	int valido;
	FILE* pArchivo;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			valido = saveText(pArchivo, pArrayListPassenger) //hacer funcion
		}
		else
		{
			printf("ERROR...\n");
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
	Passenger* auxiliar = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				auxiliar = (Passenger*) ll_get(pArrayListPassenger,i);

				if(auxiliar != NULL)
				{
					fwrite(auxiliar, sizeof(Passenger), 1, pArchivo);
					valido = 0;
				}
			}
		}
		else
		{
			printf("ERROR...\n");
		}

		fclose(pArchivo);
	}


    return valido;
}
