#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	char descripcion[50];
}TypePassenger;

void PrintOneType(TypePassenger oneType);
void PrintListTypes(TypePassenger list[], int len);

int FindIdType(TypePassenger list[], int len, int idRecibido);

#endif
