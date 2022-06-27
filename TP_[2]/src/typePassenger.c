#include "typePassenger.h"

void PrintOneType(TypePassenger oneType)
{
	printf("%3d  %18s\n", oneType.id, oneType.descripcion);
}

void PrintListTypes(TypePassenger list[], int len)
{
	printf("\n|Listado de tipos de pasajeros|");
	printf("\n|ID|          |Nombre|\n");
	for(int i = 0; i < len; i++)
	{
		PrintOneType(list[i]);
	}
}

int FindIdType(TypePassenger list[], int len, int idRecibido)
{
	int index = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].id == idRecibido)
		{
			index = i;
			break;
		}
	}

	return index;
}
