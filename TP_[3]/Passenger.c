#include "Passenger.h"
#include "utn.h"
#include "string.h"

Passenger* Passenger_new()
{
	Passenger* unVuelo;

	unVuelo = (Passenger*) malloc(sizeof(Passenger)*1);

	if(unVuelo != NULL)
	    {
			unVuelo->id = 0;
	        strcpy(unVuelo->nombre, " ");
	        strcpy(unVuelo->apellido, " ");
	        unVuelo->precio = 0;
	        strcpy(unVuelo->codigoVuelo, " ");
	        strcpy(unVuelo->tipoPasajero, " ");
	        strcpy(unVuelo->estadoVuelo, " ");
	    }

	return unVuelo;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoStr, char* estadoStr)
{
	int id;
	float precio;
	Passenger* unVuelo = NULL;

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL &&
	   tipoPasajeroStr != NULL && codigoStr != NULL && estadoStr != NULL)
	{
		unVuelo = Passenger_new();
		id = atoi(idStr);
		precio = atof(precioStr);

		if(unVuelo != NULL)
		{
			if(Passenger_setId(unVuelo, id) != 0 || Passenger_setNombre(unVuelo, nombreStr) != 0 || Passenger_setApellido(unVuelo, apellidoStr) != 0 ||
			   Passenger_setPrecio(unVuelo, precio) != 0 || Passenger_setTipoPasajero(unVuelo, tipoPasajeroStr) != 0 || Passenger_setCodigoVuelo(unVuelo, codigoStr) != 0
			   || Passenger_setEstadoVuelo(unVuelo, estadoStr) != 0)
			{
				Passenger_delete(unVuelo);
			}
		}
	}

	return unVuelo;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int estado;
	estado = -1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        estado = 0;
    }

	return estado;
}

int Passenger_getId(Passenger* this,int* id)
{
	int estado;
	estado = -1;

	if(this != NULL && id != NULL)
	{
    	*id = this->id;
    	estado = 0;
	}

	return estado;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int estado = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		estado = 0;
	}

	return estado;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int estado = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
	}

	return estado;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int estado = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		estado = 0;
	}

	return estado;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int estado = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
	}

	return estado;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int estado = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		estado = 0;
	}

	return estado;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int estado = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(*codigoVuelo, this->codigoVuelo);
	}

	return estado;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int estado = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		estado = 0;
	}

	return estado;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int estado = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(*tipoPasajero, this->tipoPasajero);
	}

	return estado;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int estado;
	estado = -1;

    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        estado = 0;
    }

	return estado;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int estado;
	estado = -1;

    if(this != NULL && precio > 0)
    {
        precio = this->precio;
        estado = 0;
    }

	return estado;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int estado = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		estado = 0;
	}

	return estado;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int estado = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		estado = 0;
	}

	return estado;
}

int Passenger_CompareByName(void* p1, void* p2)
{
    int compara;

    Passenger* unPasajero;
    Passenger* otroPasajero;
    unPasajero = (Passenger*) p1;
    otroPasajero = (Passenger*) p2;

    compara = strcmp(unPasajero->nombre, otroPasajero->nombre);

    return compara;
}

int Passenger_CompareById(void* p1, void* p2)
{
    int compara;
    compara = 0;
    Passenger* unPasajero;
    Passenger* otroPasajero;
    unPasajero = (Passenger*) p1;
    otroPasajero = (Passenger*) p2;

    if(unPasajero->id > otroPasajero->id)
    {
        compara = 1;
    }
    else
    {
        if(unPasajero->id < otroPasajero->id)
        {
            compara = -1;
        }
    }
    return compara;
}

void Passenger_printOne(Passenger* unVuelo)
{
	int* id;
	float* precio;
	char* nombre;
	char* apellido;
	char* codigo;
	char* tipoPasajero;
	char* estado;

	if(unVuelo != NULL && Passenger_getId(unVuelo, id) == 0 && Passenger_getNombre(unVuelo, nombre) == 0 && Passenger_getApellido(unVuelo, apellido) == 0 &&
	   Passenger_getPrecio(unVuelo, precio) == 0 && Passenger_getCodigoVuelo(unVuelo, codigo) == 0 && Passenger_getTipoPasajero(unVuelo, tipoPasajero) == 0 &&
	   Passenger_getEstadoVuelo(unVuelo, estado) == 0)
	{
        printf("|%-5d | %-18s | %-18s | %-18s | %-8s | %-15s | %-9.2f| \n", id, nombre, apellido, precio, codigo, tipoPasajero, estado);
	}
}

int Passenger_printListPassenger(LinkedList* pArrayListPassenger)
{
	int valido = -1;
	int len;

	len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL && len > 0)
	{
		printf("|LISTADO DE PASAJEROS|\n"
			   "    ID   NOMBRE   APELLIDO   PRECIO   TIPO PASAJERO   CODIGO VUELO   ESTADO\n");
		for(int i = 0; i < len; i++)
		{
			Passenger_printOne(pArrayListPassenger + i);
		}

		valido = 0;
	}

	return valido;
}


