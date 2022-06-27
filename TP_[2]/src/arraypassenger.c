#include "arraypassenger.h"

int BuscarEspacioLibre(Passenger list[], int len)
{
	int index;

	index = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == LIBRE)
		{
			index = i;
			break;
		}
	}

	return index;
}

//====================================================================================

int initPassengers(Passenger list[], int len)
{
	int valido = -1;

	if(len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = LIBRE;
		}

		valido = 0;
	}

	return valido;
}


int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight)
{
	int valido = -1;
	int index;

	index = BuscarEspacioLibre(list, len);

	if(index != -1)
	{
		list[index].id = id;
		strcpy(list[index].name, name);

		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		strcpy(list[index].flyCode, flyCode);
		list[index].idTypePassenger = typePassenger;
		list[index].statusFlight = statusFlight;
		list[index].isEmpty = OCUPADO;

		valido = 0;
	}

	return valido;
}


int findPassengerById(Passenger list[], int len,int id)
{
	int index = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].id == id && list[i].isEmpty == OCUPADO)
		{
			index = i;
			break;
		}
	}

	return index;
}


int removePassenger(Passenger list[], int len, int id)
{
	int valido = -1;
	int index;

	index = findPassengerById(list, len, id);

	if(index != -1)
	{
		list[index].isEmpty = LIBRE;
		valido = 0;
	}

	return valido;
}


int sortPassengers(Passenger list[], int len, int order)
{
	int valido = -1;
	Passenger aux;

	if(order == 1)
	{
		for(int i = 0; i < len; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].idTypePassenger > list[j].idTypePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}
		valido = 0;
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[j].lastName, list[i].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].idTypePassenger < list[j].idTypePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}

		valido = 0;
	}

	return valido;
}


void printOnePassenger(Passenger onePassenger, TypePassenger oneType)
{
	printf("%2d  %14s %11s  %12.2f  %12s  %19s  %11d\n", onePassenger.id, onePassenger.name, onePassenger.lastName, onePassenger.price, onePassenger.flyCode, oneType.descripcion, onePassenger.statusFlight);
}


int printPassenger(Passenger list[], int length, TypePassenger listTypes[], int lenType)
{
	int valido = -1;

	printf("< Lista de pasajeros >\n");
	printf("|ID|       |Nombre|    |Apellido|     |Precio|    |Codigo vuelo|   |Tipo pasajero|   |Estado vuelo|\n");
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < lenType; j++)
		{
			if(list[i].isEmpty == OCUPADO && listTypes[j].id == list[i].idTypePassenger)
			{
				printOnePassenger(list[i], listTypes[j]);
				valido = 0;
			}
		}
	}
	printf("\n**Estados de vuelo: 1 = ACTIVO, 2 = DEMORADO, 3 = INACTIVO**\n");

	return valido;
}


int sortPassengersByCode(Passenger list[], int len, int order)
{
	int valido = -1;
	Passenger aux;

	if(order == 1)
	{
		for(int i = 0; i < len; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[i].flyCode, list[j].flyCode) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].flyCode, list[j].flyCode) == 0)
						{
							if(list[i].statusFlight > list[j].statusFlight)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}
		valido = 0;
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[j].flyCode, list[i].flyCode) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else
					{
						if(strcmp(list[i].flyCode, list[j].flyCode) == 0)
						{
							if(list[i].statusFlight < list[j].statusFlight)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}

		valido = 0;
	}

	return valido;
}
