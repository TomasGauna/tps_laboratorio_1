#include "mia.h"

int DescifrarUltimoID(char* path, char* id)
{
	int valido = -1;
	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArchivo != NULL && id != NULL)
	{
		fscanf(pArchivo, "%[^\n]\n", id);
		valido = 0;
	}

	fclose(pArchivo);

	return valido;
}

int CalcularID(char* id)
{
	int valido = -1;
	int proximoID;

	if(id != NULL)
	{
		proximoID = atoi(id);
		proximoID++;

		itoa(proximoID, id, 10);

		valido = 0;
	}

	return valido;
}

int GuardarProximoID(char* path, char* id)
{
	int valido = -1;
	FILE* pArchivo;

	pArchivo = fopen(path, "w");

	if(pArchivo != NULL)
	{
		fprintf(pArchivo, "%s\n", id);
		valido = 0;
	}

	fclose(pArchivo);

	return valido;
}

void PedirNombre(char* nombre)
{
	char aux[50];
	int retorno;

	retorno = getStringLetras("\nIngrese el nombre del pasajero: ", aux);

	while(retorno != 1)
	{
		retorno = getStringLetras("\nERROR\nIngrese el nombre del pasajero: ", aux);
	}

	strcpy(nombre, aux);
}

void PedirApellido(char* apellido)
{
	char aux[50];
	int retorno;

	retorno = getStringLetras("\nIngrese el apellido del pasajero: ", aux);

	while(retorno != 1)
	{
		retorno = getStringLetras("\n|ERROR|\nIngrese el apellido del pasajero: ", aux);
	}

	strcpy(apellido, aux);
}

float PedirPrecio()
{
	char pedir[50];
	float precio;
	int retorno;

	retorno = getStringNumerosFlotantes("\nIngrese el precio del vuelo: ", pedir);
	while(retorno != 1)
	{
		retorno = getStringNumerosFlotantes("\n|ERROR|\nIngrese el precio del vuelo: ", pedir);
	}

	precio = atof(pedir);

	return precio;
}

int PedirTipoPasajero()
{
	char pedir[50];
	int retorno;
	int tipo;

	retorno = getStringNumeros("\nTipos de pasajero\n1-FirstClass\n2-ExecutiveClass\n3-EconomyClass\nIngrese una opcion: ", pedir);
	tipo = atoi(pedir);
	while(retorno != 1 || (tipo != 1 && tipo != 2 && tipo != 3))
	{
		retorno = getStringNumeros("\n|ERROR|\nTipos de pasajero\n1-FirstClass\n2-ExecutiveClass\n3-EconomyClass\nIngrese una opcion: ", pedir);
		tipo = atoi(pedir);
	}

	return tipo;
}

void DefinirTipoPasajero(int tipo, char* tipoStr)
{
	switch(tipo)
	{
		case 1:
			strcpy(tipoStr, "FirstClass");
		break;

		case 2:
			strcpy(tipoStr, "ExecutiveClass");
		break;

		case 3:
			strcpy(tipoStr, "EconomyClass");
		break;
	}
}

void PedirCodigoVuelo(char* codigo)//7
{
	int retorno;
	int len;
	char aux[50];

	getString("\nIngrese su codigo de vuelo. 7 CARACTERES: ", aux);
	len = strlen(aux);
	retorno = esAlfaNumerico(aux);
	while(retorno != 1 && len > 7 && len < 7)
	{
		getString("\n|ERROR|\nIngrese su codigo de vuelo. 7 CARACTERES: ", aux);
		len = strlen(aux);
		retorno = esAlfaNumerico(aux);
	}

	strcpy(codigo, aux);
}

int PedirEstadoVuelo()
{
	char pedir[50];
	int estado;
	int retorno;

	retorno = getStringNumeros("\nEstados del vuelo.\n1-En vuelo\n2-En horario\n3-Aterrizado\n4-Demorado\nIngrese una opcion: ", pedir);
	estado = atoi(pedir);
	while(retorno != 1 || (estado != 1 && estado != 2 && estado != 3 && estado != 4))
	{
		retorno = getStringNumeros("\nEstados del vuelo.\n1-En vuelo\n2-En horario\n3-Aterrizado\n4-Demorado\nIngrese una opcion: ", pedir);
		estado = atoi(pedir);
	}

	return estado;
}

void DefinirEstadoVuelo(int estado, char* estadoStr)
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
