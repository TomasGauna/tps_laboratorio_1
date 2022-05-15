#include "arraypassenger.h"
#include <string.h>
#include "auxiliar.h"

int initPassengers(Passenger list[], int len)
{
	int valido;

	valido = -1;

	if(len > 0 && len < 2001)
	{
		valido = 0;
	}

	for(int i = 0; i < len; i++)
	{
		list[i].isEmpty = LIBRE;
	}

	return valido;
}

int findPassengerById(Passenger list[], int len,int id)
{
	int index = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int removePassenger(Passenger list[], int len, int id)
{
	int valido = - 1;
	int index;

	index = findPassengerById(list, len, id);

	if(index != -1)
	{
		list[index].isEmpty = 1;
		valido = 0;
	}

	return valido;
}

int sortPassengers(Passenger list[], int len, typePassenger types[], int order)
{
	int valido = -1;
	Passenger auxiliar;

	if(order == 1)
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(strcmp(list[i].lastName, list[j].lastName) > 0)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = list[i];
				}
				else
				{
					if(strcmp(list[i].lastName, list[j].lastName) == 0)
					{
					    for(i = 0; i < len - 1; i++)
					    {
					        for(int j = i + 1; j < len; j++)
					        {
					            if(types[i].id > types[j].id)
					            {
					                auxiliar = list[i];
					                list[i] = list[j];
					                list[j] = auxiliar;
					            }
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
		if(order == 0)
		{
			for(int i = 0; i < len - 1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) > 0)
					{
						auxiliar = list[j];
						list[j] = list[i];
						list[i] = list[j];
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
						    for(i = 0; i < len - 1; i++)
						    {
						        for(int j = i + 1; j < len; j++)
						        {
						            if(types[i].id > types[j].id)
						            {
						                auxiliar = list[j];
						                list[j] = list[i];
						                list[i] = auxiliar;
						            }
						        }
						    }
						}
					}
				}
			}

			valido = 0;
		}
	}

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("\n Apellido y nombre: %s %s, Tipo de pasajero: %d", list[i].name, list[i].lastName ,list[i].idTypePassenger);
		}
	}

	return valido;
}

int printPassenger(Passenger list[], int length, typePassenger types[])
{
	int valido = -1;

	for(int i = 0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			MostrarUnPasajero(list[i]);
		}
	}

	return valido;
}

int sortPassengersByCode(Passenger list[], int len, int order)
{
	int valido = -1;
	char auxiliar[10];

	if(order == 1)
	{
		for(int i = 0; i < len; i++)
		{
			for(int j = i + 1; i < len; j++)
			{
				if(strcmp(list[i].flyCode, list[j].flyCode) > 0)
				{
					strcpy(list[i].flyCode, auxiliar);
					strcpy(list[j].flyCode, list[i].lastName);
					strcpy(auxiliar, list[j].flyCode);
				}
				else
				{
					if(strcmp(list[i].flyCode, list[j].flyCode) == 0)
					{
						if(list[i].statusFlight > list[j].statusFlight)
						{
							strcpy(list[i].flyCode, auxiliar);
							strcpy(list[j].flyCode, list[i].lastName);
							strcpy(auxiliar, list[j].flyCode);
						}
					}
				}
			}
		}
		valido = 0;
	}
	else
	{
		if(order == 0)
		{
			for(int i = 0; i < len; i++)
			{
				for(int j = i + 1; i < len; j++)
				{
					if(strcmp(list[i].flyCode, list[j].flyCode) > 0)
					{
						strcpy(list[j].flyCode, auxiliar);
						strcpy(list[i].flyCode, list[j].lastName);
						strcpy(auxiliar, list[i].flyCode);
					}
					else
					{
						if(strcmp(list[i].flyCode, list[j].flyCode) == 0)
						{
							if(list[j].statusFlight > list[i].statusFlight)
							{
								strcpy(list[j].flyCode, auxiliar);
								strcpy(list[i].flyCode, list[j].lastName);
								strcpy(auxiliar, list[i].flyCode);
							}
						}
					}
				}
			}
			valido = 0;
		}
	}

	return valido;
}
