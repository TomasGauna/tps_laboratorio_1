#include "Biblioteca_Propia.h"

int DescifrarUltimoID(char* path, char* id)
{
	int valido = -1;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL && id != NULL)
	{
		fscanf(pFile, "%[^\n]\n", id);
		valido = 1;
	}

	fclose(pFile);

	return valido;
}

int SumarID(char* idStr)
{
	int valido = -1;
	int id;

	if(idStr != NULL)
	{
		id = atoi(idStr);
		id++;

		itoa(id, idStr, 10);

		valido = 1;
	}

	return valido;
}

int GuardarID(char* path, char* id)
{
	int valido = -1;
	FILE* pFile;

	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%s\n", id);
		valido = 1;
	}

	fclose(pFile);

	return valido;
}

void PedirNombre(char* nombre)
{
	int valido;
	char aux[50];

	valido = getStringLetras("\nIngrese el nombre del pasajero: ", aux);

	while(valido != 1)
	{
		valido = getStringLetras("\n|ERROR|\nIngrese el nombre del pasajero: ", aux);
	}

	strcpy(nombre, aux);
}

void PedirApellido(char* apellido)
{
	int valido;
	char aux[50];

	valido = getStringLetras("\nIngrese el apellido del pasajero: ", aux);

	while(valido != 1)
	{
		valido = getStringLetras("\n|ERROR|\nIngrese el apellido del pasajero: ", aux);
	}

	strcpy(apellido, aux);
}

void PedirPrecio(char* precio)
{
	int valido;
	char aux[50];

	valido = getStringNumerosFlotantes("\nIngrese el precio del vuelo: ", aux);

	while(valido != 1)
	{
		valido = getStringNumerosFlotantes("\n|ERROR|\nIngrese el precio del vuelo: ", aux);
	}

	strcpy(precio, aux);
}

int PedirTipo()
{
	int valido;
	char aux[50];
	int tipo;

	valido = getStringNumeros("\n< Tipos de pasajero >\n1.EconomyClass\n2.ExecutiveClass\n3.FirstClass\nElija una opcion: ", aux);
	tipo = atoi(aux);
	while(valido != 1 || (tipo != 1 && tipo != 2 && tipo != 3))
	{
		valido = getStringNumeros("\n|ERROR|\n< Tipos de pasajero >\n1.EconomyClass\n2.ExecutiveClass\n3.FirstClass\nElija una opcion: ", aux);
		tipo = atoi(aux);
	}

	return tipo;
}

void DeterminarTipoPasajero(int tipo, char* tipoStr)
{
	switch(tipo)
	{
		case 1:
			strcpy(tipoStr, "EconomyClass");
		break;

		case 2:
			strcpy(tipoStr, "ExecutiveClass");
		break;

		case 3:
			strcpy(tipoStr, "FirstClass");
		break;
	}
}

int PedirEstado()
{
	int valido;
	char aux[50];
	int estado;

	valido = getStringNumeros("\n< Estado de vuelo >\n1.En vuelo\n2.En horario\n3.Aterrizado\n4.Demorado\nElija una opcion: ", aux);
	estado = atoi(aux);

	while(valido != 1 || (estado != 1 && estado != 2 && estado != 3 && estado != 4))
	{
		valido = getStringNumeros("\n|ERROR|\n< Estado de vuelo >\n1.En vuelo\n2.En horario\n3.Aterrizado\n4.Demorado\nElija una opcion: ", aux);
		estado = atoi(aux);
	}

	return estado;
}

void EstablecerEstado(int estado, char* estadoStr)
{
	switch(estado)
	{
		case 1:
			strcpy(estadoStr, "EnVuelo");
		break;

		case 2:
			strcpy(estadoStr, "EnHorario");
		break;

		case 3:
			strcpy(estadoStr, "Aterrizado");
		break;

		case 4:
			strcpy(estadoStr, "Demorado");
		break;
	}
}

void PedirCodigo(char* codigo)
{
	int valido;
	char aux[50];
	int len;

	getString("\nIngrese el codigo de vuelo. MAXIMO 7 CARACTERES: ", aux);
	valido = esAlfaNumerico(aux);
	len = strlen(aux);

	while(valido != 1 || (len > 7 && len < 7))
	{
		getString("\n|ERROR|\nIngrese el codigo de vuelo. MAXIMO 7 CARACTERES: ", aux);
		valido = esAlfaNumerico(aux);
		len = strlen(aux);
	}

	strcpy(codigo, aux);
}

int PedirID()
{
	int valido;
	int id;
	char aux[50];

	valido = getStringNumeros("\nIngrese el ID del vuelo: ", aux);
	while(valido != 1)
	{
		valido = getStringNumeros("\n|ERROR|\nIngrese un ID de vuelo correcto: ", aux);
	}

	id = atoi(aux);

	return id;
}

int BuscarID(LinkedList* pArrayListPassenger, int id)
{
	int index = -1;
	int len;
	int idAux;
	Passenger* unVuelo = NULL;

	if(pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				unVuelo = (Passenger*) ll_get(pArrayListPassenger, i);
				if(Passenger_getId(unVuelo, &idAux) == 1)
				{
					if(idAux == id)
					{
						index = i;
						break;
					}
				}
			}
		}
	}

	return index;
}

int EnlistPassenger(LinkedList* pArrayPassenger, int index)
{
	Passenger* unVuelo = NULL;
	int valido = -1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[50];
	char estadoVuelo[50];

	unVuelo = (Passenger*) ll_get(pArrayPassenger, index);
	if(unVuelo != NULL)
	{
		if(Passenger_getId(unVuelo, &id) == 1 && Passenger_getNombre(unVuelo, nombre) == 1 && Passenger_getApellido(unVuelo, apellido) == 1 &&
		   Passenger_getCodigoVuelo(unVuelo, codigoVuelo) == 1 && Passenger_getPrecio(unVuelo, &precio) == 1
		   && Passenger_getEstadoVuelo(unVuelo, estadoVuelo) == 1 && Passenger_getTipoPasajero(unVuelo, tipoPasajero) == 1)
		{
			printf("|%-5d | %-18s | %-18s | %-9.2f | %-18s | %-18s | %-8s|\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			valido = 1;
		}
	}

	return valido;
}

int EliminarPasajero(LinkedList* pArrayListPassenger, int id)
{
	int valido = -1;
	char pedirOpcion[50];
	int opcionElegida;
	int compruebo;
	int index = -1;

	if(pArrayListPassenger != NULL)
	{
		index = BuscarID(pArrayListPassenger, id);
		if(index != -1)
		{
			EnlistPassenger(pArrayListPassenger, index);

			compruebo = getStringNumeros("\nEl pasajero que ha sido mostrado por pantalla esta por ser eliminado, desea continuar?\n1.Si\n2.No\nElija una opcion: ", pedirOpcion);
			opcionElegida = atoi(pedirOpcion);
			while(compruebo != 1 || (opcionElegida != 1 && opcionElegida != 2))
			{
				compruebo = getStringNumeros("\n|ERROR|\nEl pasajero que ha sido mostrado por pantalla esta por ser eliminado, desea continuar?\n1.Si\n2.No\nElija una opcion correcta: ", pedirOpcion);
				opcionElegida = atoi(pedirOpcion);
			}

			switch(opcionElegida)
			{
				case 1:
					ll_remove(pArrayListPassenger, index);
					printf("\nSe ha realizado la baja con exito\n");
					valido = 1;
				break;

				case 2:
					printf("\nSe ha cancelado la baja\n");
				break;
			}
		}
		else
		{
			printf("\nEl ID no ha sido encontrado");
		}
	}

	return valido;
}

int MostrarListadoOrdenado(LinkedList* pArrayListPassenger, int opcionElegida)
{
	int valido = -1;
	int criterio;
	LinkedList* aux;

	aux = ll_clone(pArrayListPassenger);

	switch(opcionElegida)
	{
	 	case 1:
	 		aux = ll_clone(pArrayListPassenger);
	 		if(controller_ListPassenger(aux) == 1)
	 		{
	 			printf("\nEl listado ha sido mostrado con exito.");
	 		}
	 		else
	 		{
	 			printf("\nNo se han encontrado pasajeros para mostrar\n");
	 		}
		break;

	 	case 2:
	 		criterio = DeterminarCriterio();
	 		ll_sort(pArrayListPassenger, CompareByID, criterio);
	 		if(criterio == 1)
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma descendente\n");
	 		}
	 		else
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma ascendente\n");
	 		}
	 	break;

	 	case 3:
	 		criterio = DeterminarCriterio();
	 		ll_sort(aux, CompareByName, criterio);
	 		if(!criterio)
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma descendente\n");
	 		}
	 		else
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma ascendente\n");
	 		}
	 	break;

	 	case 4:
	 		criterio = DeterminarCriterio();
	 		ll_sort(aux, CompareByLastName, criterio);
	 		if(!criterio)
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma descendente\n");
	 		}
	 		else
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma ascendente\n");
	 		}
	 	break;

	 	case 5:
	 		criterio = DeterminarCriterio();
	 		ll_sort(aux, CompareByTipoPasajero, criterio);
	 		if(!criterio)
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("Se ordeno el listado por ID de forma descendente");
	 		}
	 		else
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma ascendente\n");
	 		}
	 	break;

	 	case 6:
	 		criterio = DeterminarCriterio();

	 		if(!ll_sort(aux, CompareByPrecio, criterio))
	 		{
		 		if(!criterio)
		 		{
		 			if(controller_ListPassenger(aux) == 1)
		 			{
		 				ll_deleteLinkedList(aux);
		 				printf("\nLista mostrada con exito\n");
		 			}
		 			printf("\nSe ordeno el listado por ID de forma descendente\n");
		 		}
		 		else
		 		{
		 			if(controller_ListPassenger(aux) == 1)
		 			{
		 				ll_deleteLinkedList(aux);
		 				printf("\nLista mostrada con exito\n");
		 			}
		 			printf("\nSe ordeno el listado por ID de forma ascendente\n");
		 		}
	 		}
	 	break;

	 	case 7:
	 		criterio = DeterminarCriterio();
	 		ll_sort(aux, CompareByEstado, criterio);
	 		if(!criterio)
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma descendente\n");
	 		}
	 		else
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma ascendente\n");
	 		}
	 	break;

	 	case 8:
	 		criterio = DeterminarCriterio();
	 		ll_sort(aux, CompareByCodigo, criterio);
	 		if(!criterio)
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma descendente\n");
	 		}
	 		else
	 		{
	 			if(controller_ListPassenger(aux) == 1)
	 			{
	 				ll_deleteLinkedList(aux);
	 				printf("\nLista mostrada con exito\n");
	 			}
	 			printf("\nSe ordeno el listado por ID de forma ascendente\n");
	 		}
	 	break;

	 	case 9:
	 		printf("\nVolviendo al menu\n");
	 	break;
	}

	return valido;
}

int DeterminarCriterio()
{
	int criterio;
	char aux[50];
	int valido;

	valido = getStringNumeros("\n< CRITERIOS DE ORDENAMIENTO >\n0.Ascendente\n1.Descendente\nElija una opcion: ", aux);
	criterio = atoi(aux);
	while(valido != 1 || (criterio != 1 && criterio != 0))
	{
		valido = getStringNumeros("\n|ERROR|\n< CRITERIOS DE ORDENAMIENTO >\n0.Ascendente\n1.Descendente\nElija una opcion correcta: ", aux);
		criterio = atoi(aux);
	}

	return criterio;
}

int CompareByID(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* unAuxiliar = NULL;
	Passenger* otroAuxiliar = NULL;
	int unID;
	int otroID;

	if(p1 != NULL && p2 != NULL)
	{
		unAuxiliar = (Passenger*) p1;
		otroAuxiliar = (Passenger*) p2;

		if(Passenger_getId(unAuxiliar, &unID) == 1 && Passenger_getId(otroAuxiliar, &otroID) == 1)
		{
			if(unID > otroID)
			{
				retorno = 1;
			}
			else
			{
				if(unID < otroID)
				{
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

int CompareByName(void* p1, void* p2)
{
	int retorno;
	Passenger* unAuxiliar = NULL;
	Passenger* otroAuxiliar = NULL;
	char unNombre[50];
	char otroNombre[50];

	if(p1 != NULL && p2 != NULL)
	{
		unAuxiliar = (Passenger*) p1;
		otroAuxiliar = (Passenger*) p2;

		if(Passenger_getNombre(unAuxiliar, unNombre) == 1 && Passenger_getNombre(otroAuxiliar, otroNombre) == 1)
		{
			retorno = strcmp(unNombre, otroNombre);
		}
	}

	return retorno;
}

int CompareByLastName(void* p1, void* p2)
{
	int retorno;
	Passenger* unAuxiliar = NULL;
	Passenger* otroAuxiliar = NULL;
	char unApellido[50];
	char otroApellido[50];

	if(p1 != NULL && p2 != NULL)
	{
		unAuxiliar = (Passenger*) p1;
		otroAuxiliar = (Passenger*) p2;

		if(Passenger_getApellido(unAuxiliar, unApellido) == 1 && Passenger_getApellido(otroAuxiliar, otroApellido) == 1)
		{
			retorno = strcmp(unApellido, otroApellido);
		}
	}

	return retorno;
}

int CompareByCodigo(void* p1, void* p2)
{
	int retorno;
	Passenger* unAuxiliar = NULL;
	Passenger* otroAuxiliar = NULL;
	char unCodigo[50];
	char otroCodigo[50];

	if(p1 != NULL && p2 != NULL)
	{
		unAuxiliar = (Passenger*) p1;
		otroAuxiliar = (Passenger*) p2;

		if(Passenger_getCodigoVuelo(unAuxiliar, unCodigo) == 1 && Passenger_getCodigoVuelo(otroAuxiliar, otroCodigo) == 1)
		{
			retorno = strcmp(unCodigo, otroCodigo);
		}
	}

	return retorno;
}

int CompareByTipoPasajero(void* p1, void* p2)
{
	int retorno;
	Passenger* unAuxiliar = NULL;
	Passenger* otroAuxiliar = NULL;
	char unTipoStr[50];
	char otroTipoStr[50];

	if(p1 != NULL && p2 != NULL)
	{
		unAuxiliar = (Passenger*) p1;
		otroAuxiliar = (Passenger*) p2;

		if(Passenger_getTipoPasajero(unAuxiliar, unTipoStr) == 1 && Passenger_getTipoPasajero(otroAuxiliar, otroTipoStr) == 1)
		{
			retorno = strcmp(unTipoStr, otroTipoStr);
		}
	}

	return retorno;
}

int CompareByEstado(void* p1, void* p2)
{
	int retorno;
	Passenger* unAuxiliar = NULL;
	Passenger* otroAuxiliar = NULL;
	char unEstado[50];
	char otroEstado[50];

	if(p1 != NULL && p2 != NULL)
	{
		unAuxiliar = (Passenger*) p1;
		otroAuxiliar = (Passenger*) p2;

		if(Passenger_getEstadoVuelo(unAuxiliar, unEstado) == 1 && Passenger_getEstadoVuelo(otroAuxiliar, otroEstado) == 1)
		{
			retorno = strcmp(unEstado, otroEstado);
		}
	}

	return retorno;
}

int CompareByPrecio(void* p1, void* p2)
{
	int retorno = 0;
	Passenger* unAuxiliar = NULL;
	Passenger* otroAuxiliar = NULL;
	float unPrecio;
	float otroPrecio;

	if(p1 != NULL && p2 != NULL)
	{
		unAuxiliar = (Passenger*) p1;
		otroAuxiliar = (Passenger*) p2;

		if(Passenger_getPrecio(unAuxiliar,&unPrecio) == 1 && Passenger_getPrecio(otroAuxiliar,&otroPrecio) == 1)
		{
			if(unPrecio > otroPrecio)
			{
				retorno = 1;
			}
			else
			{
				if(unPrecio < otroPrecio)
				{
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

int SaveText(FILE* pArchivo , LinkedList* pArrayListPassenger)
{
	Passenger* unVuelo = NULL;
	int valido = 0;
	int len;
	int id;
	float precio;
	char nombre[50];
	char apellido[50];
	char codigo[50];
	char estado[50];
	char tipoStr[50];

	if(pArrayListPassenger != NULL && pArchivo != NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				unVuelo = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unVuelo != NULL)
				{
					if(Passenger_getNombre(unVuelo, nombre) == 1 && Passenger_getApellido(unVuelo, apellido) == 1 && Passenger_getId(unVuelo, &id) == 1
					   && Passenger_getEstadoVuelo(unVuelo, estado) == 1 && Passenger_getCodigoVuelo(unVuelo, codigo) == 1 && Passenger_getPrecio(unVuelo, &precio) == 1
					   && Passenger_getTipoPasajero(unVuelo, tipoStr) == 1)
					{
						fprintf(pArchivo,"%d,%s,%s,%f,%s,%s,%s\n",id, nombre, apellido, precio, tipoStr, codigo, estado);
						valido = 1;
					}
				}
			}
		}
	}

	return valido;
}
