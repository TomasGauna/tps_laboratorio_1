#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* unVuelo = NULL;

	unVuelo = (Passenger*) malloc(sizeof(Passenger) * 1);

	if(unVuelo != NULL)
	{
		unVuelo->id = 0;
		strcpy(unVuelo->nombre, " ");
		strcpy(unVuelo->apellido, " ");
		unVuelo->precio = 0;
		strcpy(unVuelo->tipoPasajero, " ");
		strcpy(unVuelo->codigoVuelo, " ");
		strcpy(unVuelo->estadoVuelo, " ");
	}

	return unVuelo;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* codigoStr, char* precioStr, char* estadoStr)
{
	Passenger* unVuelo = NULL;
	int id;
	float precio;

	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL && apellidoStr != NULL && codigoStr != NULL && precioStr != NULL && estadoStr != NULL)
	{
		unVuelo = Passenger_new();

		id = atoi(idStr);
		precio = atof(precioStr);

		if(unVuelo != NULL)
		{
			if(Passenger_setId(unVuelo, id) == -1 || Passenger_setNombre(unVuelo, nombreStr) == -1 || Passenger_setApellido(unVuelo, apellidoStr) == -1 || Passenger_setPrecio(unVuelo, precio) == -1
			   || Passenger_setTipoPasajero(unVuelo, tipoPasajeroStr) == -1 || Passenger_setCodigoVuelo(unVuelo, codigoStr) == -1 || Passenger_setEstadoVuelo(unVuelo, estadoStr) == -1)
			{
				Passenger_delete(unVuelo);
			}
		}
	}

	return unVuelo;
}

void Passenger_delete(Passenger* unVuelo)
{
	if(unVuelo != NULL)
	{
		free(unVuelo);
		unVuelo = NULL;
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int valido = -1;

	if(this != NULL)
	{
		this->id = id;
		valido = 1;
	}

	return valido;
}

int Passenger_getId(Passenger* this,int* id)
{
	int valido = -1;

	if(this != NULL)
	{
		*id = this->id;
		valido = 1;
	}

	return valido;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int valido = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		valido = 1;
	}

	return valido;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int valido = -1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		valido = 1;
	}

	return valido;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int valido = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		valido = 1;
	}

	return valido;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int valido = -1;

	if(this != NULL)
	{
		strcpy(apellido, this->apellido);
		valido = 1;
	}

	return valido;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int valido = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		valido = 1;
	}

	return valido;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int valido = -1;

	if(this != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		valido = 1;
	}

	return valido;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int valido = -1;

	if(this != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		valido = 1;
	}

	return valido;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int valido = -1;

	if(this != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		valido = 1;
	}

	return valido;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int valido = -1;

	if(this != NULL)
	{
		this->precio = precio;
		valido = 1;
	}

	return valido;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int valido = -1;

	if(this != NULL)
	{
		*precio = this->precio;
		valido = 1;
	}

	return valido;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int valido = -1;

	if(this != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		valido = 1;
	}

	return valido;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int valido = -1;

	if(this != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		valido = 1;
	}

	return valido;
}

int Passenger_EditPassenger(Passenger* this)
{
	int valido = -1;
	char pedirOpcion[50];
	int opcionElegida;
	int compruebo;
	char nombre[50];
	char apellido[50];
	char precioStr[50];
	float precio;
	int tipoPasajero;
	char tipoStr[50];
	char codigoVuelo[20];
	int estado;
	char estadoVuelo[20];

	compruebo = getStringNumeros("\n < LISTADO DE MODIFICACIONES >\n1)Nombre\n2)Apellido\n3)Tipo de pasajero\n4)Codigo de vuelo\n5)Estado de vuelo"
			                     "\n6)Precio\n7)Volver al menu\nElija una opcion: ", pedirOpcion);
	opcionElegida = atoi(pedirOpcion);
	while(compruebo != 1 || (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3 && opcionElegida != 4 && opcionElegida != 5 && opcionElegida != 6 && opcionElegida != 7))
	{
		compruebo = getStringNumeros("\n|ERROR|\n < LISTADO DE MODIFICACIONES >\n1)Nombre\n2)Apellido\n3)Tipo de pasajero\n4)Codigo de vuelo\n5)Estado de vuelo"
				                     "\n6)Precio\n7)Volver al menu\nElija una opcion correcta: ", pedirOpcion);
		opcionElegida = atoi(pedirOpcion);
	}

	switch(opcionElegida)
	{
		case 1:
			PedirNombre(nombre);
			valido = Passenger_setNombre(this, nombre);
		break;

		case 2:
			PedirApellido(apellido);
			valido = Passenger_setApellido(this, apellido);
		break;

		case 6:
			PedirPrecio(precioStr);
			precio = atof(precioStr);
			valido = Passenger_setPrecio(this, precio);
		break;

		case 3:
			tipoPasajero = PedirTipo();
			DeterminarTipoPasajero(tipoPasajero, tipoStr);
			valido = Passenger_setTipoPasajero(this, tipoStr);
		break;

		case 5:
			estado = PedirEstado();
			EstablecerEstado(estado, estadoVuelo);
			valido = Passenger_setEstadoVuelo(this, estadoVuelo);
		break;

		case 4:
			PedirCodigo(codigoVuelo);
			valido = Passenger_setCodigoVuelo(this, codigoVuelo);
		break;
	}

	return valido;
}
