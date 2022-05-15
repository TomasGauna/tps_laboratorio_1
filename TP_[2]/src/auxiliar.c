#include "arraypassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#include "utn.h"


int MostrarMenuOpciones()
{
	int opcionElegida;

	opcionElegida = getInt("\n¡Bienvenido al menu!\n1-ALTA: Añadir nuevo pasajero.\n2-MODIFICAR: Modifica algun aspecto del pasajero."
						   "\n3-BAJA: Elimina el pasajero del sistema.\n4-INFORMAR: desplega tres informes a eleccion.\n5-Salir\nElija una opcion: ");
	while(opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3 && opcionElegida != 4 && opcionElegida != 5)
	{
		opcionElegida = getInt("\n¡Opcion Incorrecta!\n1-ALTA: Añadir nuevo pasajero.\n2-MODIFICAR: Modifica algun aspecto del pasajero."
							   "\n3-BAJA: Elimina el pasajero del sistema.\n4-INFORMAR: desplega tres informes a eleccion.\nElija una opcion valida: ");
	}

	return opcionElegida;
}

void InicializarListaPasajeros(Passenger list[])
{

	Passenger auxiliar[12] = {{1, "Pedro", "Perez", 12312.12, "AKQUEB120", 101,2, OCUPADO},
							 {2, "Juan", "Atienzo", 4332.12, "AKAUED120", 100,1, OCUPADO},
							 {3, "Maria", "Ramos", 7654.12, "AKQHUK120", 100,1, OCUPADO},
							 {4, "Octavio", "Vargas", 8122.11, "AKQUCA120", 101,2,OCUPADO},
							 {5, "German", "Ortega", 9834.3, "AKASDQR20", 102,1,OCUPADO},
							 {6, "Lucia", "Ramos", 1843.9, "AKQLUI20", 102,1,OCUPADO},
							 {7, "Paulo", "Estraneo", 5031.01, "AKYIEB120", 101,2,OCUPADO},
							 {8, "Paula", "Villegas", 8407.6, "AKAJKD120", 102,1,OCUPADO},
							 {9, "Pedro", "Alfoso", 6237.3, "AKQYT520", 102,1,OCUPADO},
							 {10, "Nazareno", "Motola", 3563.1, "AKQUGF120", 102,2,OCUPADO},
							 {11, "Juan", "Nahasapeemapetilon", 261.4, "AK2EED120", 101,1,OCUPADO},
							 {12, "Lisa", "Fuentes", 654.12, "AKSDVW120", 100,1,OCUPADO}};

	for(int i = 0; i < 12; i++)
	{
		list[i] = auxiliar[i];
	}
}
//================================================


int BuscarEspacio(Passenger list[], int len)
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

int ObtenerId(Passenger list[], int len)
{
	int contador;
	contador = 0;
	int id;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			contador++;
		}
	}

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == LIBRE)
		{
			id = contador + 1;
			break;
		}
	}

	return id;
}

void PedirNombre(Passenger newPassenger)
{
	char nombre[51];
	int retorno;

	printf("\nIngrese el nombre del pasajero: ");
	fflush(stdin);
	gets(nombre);
	retorno = esSoloLetras(nombre);

	while(retorno == 0)
	{
		printf("\n|ERROR|\nIngrese el nombre del pasajero: ");
		fflush(stdin);
		gets(nombre);
		retorno = esSoloLetras(nombre);
	}

	strcpy(newPassenger.name,nombre);

}

void PedirApellido(Passenger newPassenger)
{
	char apellido[51];
	int retorno;

	printf("\nIngrese el apellido del pasajero: ");
	fflush(stdin);
	gets(apellido);
	retorno = esSoloLetras(apellido);

	while(retorno == 0)
	{
		printf("\n|ERROR|\nIngrese el apellido del pasajero: ");
		fflush(stdin);
		gets(apellido);
		retorno = esSoloLetras(apellido);
	}

	strcpy(newPassenger.lastName, apellido);
}

float PedirPrecio()
{
	float precio;

	precio = getFloat("\nIngrese el precio del vuelo: ");//No se como verificar, ya que el esNumericoFlotante() recibe como parametro una cadena

	return precio;
}

void PedirCodigoVuelo(Passenger newPassenger)
{
	char aux[10];
	int len;
	int retorno;

	getString("\nIngrese el codigo de vuelo. MAXIMOS 9 CARACTERES: ", aux);
	retorno = esAlfaNumerico(aux);
	len = strlen(aux);

	while(len > 10 || retorno != 1)
	{
		getString("\n|ERROR|\nIngrese un codigo de vuelo correcto. MAXIMOS 9 CARACTERES: ", aux);
		retorno = esAlfaNumerico(aux);
		len = strlen(aux);
	}

	strcpy(newPassenger.flyCode, aux);
}

int PedirTipoPasajero(typePassenger list[], int len)
{
	int tipo;

	printf("\n|Lista de tipos de pasajeros|\n");
	MostrarTipos(list, len);
	tipo = getInt("Ingrese el ID del tipo de pasajero que corresponde: ");

	return tipo;
}

int PedirEstadoDeVuelo()
{
	int estadoVuelo;

	estadoVuelo = getInt("\nEstados de vuelo:\n1-Activo\n2-Demorado\n3-Inactivo\nElija una opcion: ");

	while(estadoVuelo != 1 && estadoVuelo != 2 && estadoVuelo != 3)
	{
		estadoVuelo = getInt("\nERROR.\nEstados de vuelo:\n1-Activo\n2-Demorado\n3-Inactivo\nElija una opcion correcta: ");
	}

	return estadoVuelo;
}

Passenger PedirUnPasajero(Passenger list[], int len,typePassenger types[], int lenTypes)
{
	Passenger unPasajero;

	unPasajero.id = ObtenerId(list, len);
	PedirNombre(unPasajero);
	PedirApellido(unPasajero);
	unPasajero.price = PedirPrecio();
	PedirCodigoVuelo(unPasajero);
	unPasajero.idTypePassenger = PedirTipoPasajero(types, lenTypes);
	unPasajero.statusFlight = PedirEstadoDeVuelo();
	unPasajero.isEmpty = OCUPADO;

	return unPasajero;
}

int CargarListaPasajeros(Passenger list[], int len, typePassenger types[], int lenType)
{
	int index;

	index = BuscarEspacio(list, len);
	if(index != -1)
	{
		list[index] = PedirUnPasajero(list, len, types, lenType);
	}

	return index;
}

void MostrarPasajerosResumido(Passenger list[], int len)
{
	printf("\nLista de pasajeros.");
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("\nID: %d  Apellido: %s   Nombre:  %s", list[i].id, list[i].lastName, list[i].name);
		}
	}
}

void MostrarTipos(typePassenger list[], int len)
{
	for(int i = 0; i < len; i++)
	{
		printf(" ID: %d       Nombre: %s\n", list[i].id, list[i].description);
	}
}

void MostrarUnPasajero(Passenger pasajero)
{
	printf("\nID:%4d || Apellido y nombre:%5s   %s  || Precio:%.2f || Codigo:%5s || Tipo:%d || Estado: %d",
			pasajero.id, pasajero.lastName,pasajero.name, pasajero.price,
			pasajero.flyCode, pasajero.idTypePassenger, pasajero.statusFlight);
}

int MostrarMenuModificacion(int modificar, Passenger list[], int len, typePassenger types[], int lenType, int index)
{
	char aux[50];
	int seguro;
	float precioNuevo;
	int nuevoTipo;

	switch(modificar)
	{
		case 1:
			getString("\nIngrese el nuevo nombre del pasajero: ", aux);
			seguro = getInt("\nEl nombre esta por ser modificado. Para confirmar indique 1. Para volver presione 0: ");
			while(seguro != 1 && seguro != 0)
			{
				seguro = getInt("\n|ERROR|\nEl nombre esta por ser modificado. Para confirmar indique 1. Para volver presione 0.\nIndique una opcion correcta: ");
			}
			if(seguro == 1)
			{
				strcpy(list[index].name, aux);
			}
		break;

		case 2:
			getString("\nIngrese el nuevo apellido del pasajero: ", aux);
			seguro = getInt("\nEl apellido esta por ser modificado. Para confirmar indique 1. Para volver presione 0: ");
			while(seguro != 1 && seguro != 0)
			{
				seguro = getInt("\n|ERROR|\nEl apellido esta por ser modificado. Para confirmar indique 1. Para volver presione 0.\nIndique una opcion correcta: ");
			}
			if(seguro == 1)
			{
				strcpy(list[index].lastName, aux);
			}
		break;

		case 3:
			precioNuevo = getFloat("\nIndique el nuevo precio del vuelo: ");
			seguro = getInt("\nEl precio esta por ser modificado. Para confirmar indique 1. Para volver presione 0: ");
			while(seguro != 1 && seguro != 0)
			{
				seguro = getInt("\n|ERROR|\nEl precio esta por ser modificado. Para confirmar indique 1. Para volver presione 0.\nIndique una opcion correcta: ");
			}
			if(seguro == 1)
			{
				list[index].price = precioNuevo;
			}
		break;

		case 4:
			MostrarTipos(types, lenType);
			nuevoTipo = getInt("\nIngrese el ID del nuevo tipo de pasajero: ");
			seguro = getInt("\nEl tipo de pasajero esta por ser modificado. Para confirmar indique 1. Para volver presione 0: ");
			while(seguro != 1 && seguro != 0)
			{
				seguro = getInt("\n|ERROR|\nEl tipo de pasajero esta por ser modificado. Para confirmar indique 1. Para volver presione 0.\nIndique una opcion correcta: ");
			}
			if(seguro == 1)
			{
				list[index].idTypePassenger = nuevoTipo;
			}
		break;

		case 5:
			getString("\nIngrese el nuevo codigo de vuelo. MAXIMO 9 CARACTERES: ", aux);
			seguro = getInt("\nEl codigo de vuelo esta por ser modificado. Para confirmar indique 1. Para volver presione 0: ");
			while(seguro != 1 && seguro != 0)
			{
				seguro = getInt("\n|ERROR|\nEl codigo de vuelo esta por ser modificado. Para confirmar indique 1. Para volver presione 0.\nIndique una opcion correcta: ");
			}
			if(seguro == 1)
			{
				strcpy(list[index].flyCode, aux);
			}
		break;
	}

	return seguro;
}

int ModificarPasajero(Passenger list[], int len, typePassenger types[], int lenType)
{
	int id;
	int valido = -1;
	int index;
	int modificar;

	MostrarPasajerosResumido(list, len);

	id = getInt("\nIngese el ID del pasajero a modificar: ");

	index = findPassengerById(list, len, id);

	if(index != -1)
	{
		modificar = getInt("¿Que desea modificar?\n1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero"
						   "\n5-Codigo de vuelo\n6-Salir\nIngrese el numero de la opcion: ");
		while(modificar != 1 && modificar != 2 && modificar != 3 && modificar != 4 && modificar != 5 && modificar != 6)
		{
			modificar = getInt("ERROR\n1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero"
							   "\n5-Codigo de vuelo\nIngrese un numero de opcion correcto: ");
		}

		valido = MostrarMenuModificacion(modificar, list, len, types, lenType, index);
	}
	else
	{
		printf("\nNo se ha encontrado el ID.");
	}

	return valido;
}

int EliminarPasajero(Passenger list[], int len)
{
	int eliminado = -1;
	int id;
	int index;
	int seguro;

	MostrarPasajerosResumido(list, len);

	id = getInt("\nIngrese el ID del pasajero a eliminar: ");

	index = findPassengerById(list, len, id);

	printf("\nEl pasajero con ID: %d, nombre y apellido: %s %s y codigo de vuelo: %s, esta por ser eliminado.\n",
					list[index].id, list[index].name, list[index].lastName, list[index].flyCode);
	seguro = getInt("¿Esta seguro de esta accion? 1-SI  2-NO\nElija una opcion: ");
	if(seguro == 1)
	{
		list[index].isEmpty = LIBRE;
		eliminado = 0;
	}
	return eliminado;
}

void MostrarListaDePasajeros(Passenger list[], int len)
{
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			MostrarUnPasajero(list[i]);
		}
	}
}

int MostrarListaOpciones4()
{
	int retorno;

	retorno = getInt("\nMenu de informes: \n1-Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
					 "\n2-Promedio de precio de vuelo. Y cuantos pasajeros superal el promedio."
					 "\n3-Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
					 "4-Volver al menu.\nElija una opcion: ");
	while(retorno != 1 && retorno != 2 && retorno != 3 && retorno != 4)
	{
		retorno = getInt("\nOpcion incorrecta. \n1-Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
						 "\n2-Promedio de precio de vuelo. Y cuantos pasajeros superal el promedio."
						 "\n3-Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
						 "4-Volver al menu.\nElija una opcion: ");
	}
	return retorno;
}

void OrdenarListaPasajerosPorApellido(Passenger list[], int len)
{
	Passenger aux;

	for(int i = 0; i < len - 1; i++)
	{
		for(int j = i + 1; j < len; j++)
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

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("\nApellido Y Nombre: %s %s       Tipo de pasajero: %d", list[i].lastName, list[i].name, list[i].idTypePassenger);
		}
	}
}

float SumarPreciosDeVuelo(Passenger list[], int len)
{
	float sumaTotal;
	sumaTotal = 0;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			sumaTotal += list[i].price;
		}
	}

	return sumaTotal;
}

float CalcularPromedio(Passenger list[], int len, float sumaTotal)
{
	float promedio;
	int contador = 0;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			contador++;
		}
	}

	promedio = sumaTotal / contador;

	return promedio;
}

void MostrarListaMayorAPromedio(Passenger list[], int len, float promedio)
{
	printf("\nEl precio promedio de vuelo es de: %.2f\n", promedio);

	printf("\n||Lista de pasajeros con precio de vuelo mayor al promedio||\n");
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].price > promedio)
		{
			printf("\nApellido Y Nombre: %s %s, precio de vuelo: %.2f", list[i].lastName, list[i].name, list[i].price);
		}
	}
}

void MostrarOpcionDosCuatro(Passenger list[], int len)
{
	float sumaTotal;
	float promedio;

	sumaTotal = SumarPreciosDeVuelo(list, len);
	promedio = CalcularPromedio(list, len, sumaTotal);

	MostrarListaMayorAPromedio(list, len, promedio);
}

void OrdenarListaDePasajerosPorCodigo(Passenger list[], int len)
{
	Passenger aux;
	printf("\n||Lista de pasajeros activos, ordenado por codigo de vuelo||");
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO )
		{
			for(int i = 0; i < len - 1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if(strcmp(list[i].flyCode, list[j].flyCode) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
	}

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].statusFlight == 1)
		{
			printf("\nApellido Y Nombre: %s %s     Codigo De Vuelo: %s     Estado de vuelo: %d", list[i].lastName,
							list[i].name, list[i].flyCode, list[i].statusFlight);
		}
	}
}
