#include "servicio.h"

int CalcularId()
{
	static int id = 1;

	return id++;
}


void PedirNombre(char nombre[])
{
	char aux[50];
	int valido;

	valido = getStringLetras("\nIngrese el nombre del pasajero: ", aux);
	while(valido != 1)
	{
		valido = getStringLetras("\n|ERROR|\nIngrese un nombre del pasajero posible: ", aux);
	}

	strcpy(nombre, aux);
}


void PedirApellido(char apellido[])
{
	char aux[50];
	int valido;

	valido = getStringLetras("\nIngrese el apellido del pasajero: ", aux);
	while(valido != 1)
	{
		valido = getStringLetras("\n|ERROR|\nIngrese un apellido del pasajero posible: ", aux);
	}

	strcpy(apellido, aux);
}


float PedirPrecio()
{
	char pidoPrecio[50];
	int valido;
	float precio;

	valido = getStringNumerosFlotantes("\nIngrese el precio del vuelo: ", pidoPrecio);
	while(valido != 1)
	{
		valido = getStringNumerosFlotantes("\n|ERROR|\nIngrese un precio de vuelo posible: ", pidoPrecio);
	}

	precio = atof(pidoPrecio);

	return precio;
}

void PedirCodigo(char codigo[])
{
	char aux[10];
	int valido;
	int len;

	getString("\nIngrese el codigo de vuelo del pasajero. CINCO(5) CARACTERES: ", aux);
	valido = esAlfaNumerico(aux);
	len = strlen(aux);
	while(valido != 1 || len > 5 || len < 5)
	{
		getString("\n|ERROR|\nIngrese un codigo de vuelo posible. CINCO(5) CARACTERES: ", aux);
		valido = esAlfaNumerico(aux);
		len = strlen(aux);
	}

	strcpy(codigo, aux);
}

int PedirTipoPasajero(TypePassenger list[], int len)
{
	char pidoTipo[50];
	int valido;
	int compruebo;
	int tipo;

	PrintListTypes(list, len);

	valido = getStringNumeros("\nIngrese el ID del tipo de pasajero: ", pidoTipo);
	compruebo = FindIdType(list, len, atoi(pidoTipo));
	while(valido != 1 || compruebo == -1)
	{
		PrintListTypes(list, len);
		valido = getStringNumeros("\n|ERROR|\nIngrese un ID de tipo de pasajero posible: ", pidoTipo);
		compruebo = FindIdType(list, len, atoi(pidoTipo));
	}

	tipo = atoi(pidoTipo);

	return tipo;
}


int PedirEstadoVuelo()
{
	char pidoEstado[50];
	int valido;
	int estado;

	valido = getStringNumeros("\nEstados de vuelo del pasajero\n1-ACTIVO\n2-DEMORADO\n3-INACTIVO\nIngrese un estado de vuelo: ", pidoEstado);
	estado = atoi(pidoEstado);
	while(valido != 1 || (estado != 1 && estado != 2 && estado != 3))
	{
		valido = getStringNumeros("\n|ERROR|\nEstados de vuelo del pasajero\n1-ACTIVO\n2-DEMORADO\n3-INACTIVO\nIngrese un estado de vuelo posible: ", pidoEstado);
		estado = atoi(pidoEstado);
	}

	return estado;
}

int CargarUnVuelo(Passenger list[], int len, TypePassenger listTypes[], int lenType)
{
	int valido;
	int id;
	char name[50];
	char lastName[50];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;

	id = CalcularId();
	PedirNombre(name);
	PedirApellido(lastName);
	price = PedirPrecio();
	PedirCodigo(flyCode);
	typePassenger = PedirTipoPasajero(listTypes, lenType);
	statusFlight = PedirEstadoVuelo();

	valido = addPassenger(list, len, id, name, lastName, price, typePassenger, flyCode, statusFlight);

	return valido;
}

int CargarListaDeVuelos(Passenger list[], int len, TypePassenger listTypes[], int lenType)
{
	int valido = -1;
	int compruebo;

	compruebo = BuscarEspacioLibre(list, len);

	if(compruebo != -1)
	{
		for(int i = 0; i < len; i++)
		{
			valido = CargarUnVuelo(list, len, listTypes, lenType);
			break;
		}
	}

	return valido;
}

int PedirId(Passenger list[], int len)
{
	int validacion;
	char pidoId[10];
	int id;

	validacion = getStringNumeros("Ingrese el ID del servicio: ", pidoId);
	while(validacion != 1)
	{
		validacion = getStringNumeros("\n|ERROR|\nIngrese un ID de servicio posible: ", pidoId);
	}

	id = atoi(pidoId);

	return id;
}

int ModificarVuelo(Passenger list[], int len, TypePassenger listTypes[], int lenType)
{
	int valido = -1;
	int retorno;
	char pidoOpcion[20];
	int opcionElegida;
	int id;
	int index;
	char auxC[50];
	float auxF;
	int auxI;

	printPassenger(list, len, listTypes, lenType);
	id = PedirId(list, len);
	index = findPassengerById(list, len, id);

	if(index != -1)
	{
		retorno = getStringNumeros("< Modificaciones disponibles >\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de pasajero\n5.Codigo de vuelo\n6.Volver al menu\nIngrese el numero de la opcion: ", pidoOpcion);
		opcionElegida = atoi(pidoOpcion);
		while(retorno != 1 || (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3 && opcionElegida != 4 && opcionElegida != 5 && opcionElegida != 6))
		{
			retorno = getStringNumeros("\n|ERROR|\n< Modificaciones disponibles >\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de pasajero\n5.Codigo de vuelo\n6.Volver al menu\nIngrese un numero de opcion posible: ", pidoOpcion);
			opcionElegida = atoi(pidoOpcion);
		}

		switch(opcionElegida)
		{
			case 1:
				PedirNombre(auxC);

				retorno = getStringNumeros("El nombre esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese el numero de la opcion: ", pidoOpcion);
				opcionElegida = atoi(pidoOpcion);
				while(retorno != 1 || (opcionElegida != 1 && opcionElegida != 2))
				{
					retorno = getStringNumeros("\n|ERROR|\nEl nombre esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese un numero de opcion posible: ", pidoOpcion);
					opcionElegida = atoi(pidoOpcion);
				}

				if(opcionElegida == 1)
				{
					strcpy(list[index].name, auxC);
					valido = 0;
				}
				else
				{
					printf("\n|Volviendo al menu|\n");
				}
			break;

			case 2:
				PedirApellido(auxC);

				retorno = getStringNumeros("El apellido esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese el numero de la opcion: ", pidoOpcion);
				opcionElegida = atoi(pidoOpcion);
				while(retorno != 1 || (opcionElegida != 1 && opcionElegida != 2))
				{
					retorno = getStringNumeros("\n|ERROR|\nEl apellido esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese un numero de opcion posible: ", pidoOpcion);
					opcionElegida = atoi(pidoOpcion);
				}

				if(opcionElegida == 1)
				{
					strcpy(list[index].lastName, auxC);
					valido = 0;
				}
				else
				{
					printf("\n|Volviendo al menu|\n");
				}
			break;

			case 3:
				auxF = PedirPrecio();

				retorno = getStringNumeros("El precio esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese el numero de la opcion: ", pidoOpcion);
				opcionElegida = atoi(pidoOpcion);
				while(retorno != 1 || (opcionElegida != 1 && opcionElegida != 2))
				{
					retorno = getStringNumeros("\n|ERROR|\nEl precio esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese un numero de opcion posible: ", pidoOpcion);
					opcionElegida = atoi(pidoOpcion);
				}

				if(opcionElegida == 1)
				{
					list[index].price = auxF;
					valido = 0;
				}
				else
				{
					printf("\n|Volviendo al menu|\n");
				}
			break;

			case 4:
				auxI = PedirTipoPasajero(listTypes, lenType);

				retorno = getStringNumeros("El tipo de pasajero esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese el numero de la opcion: ", pidoOpcion);
				opcionElegida = atoi(pidoOpcion);
				while(retorno != 1 || (opcionElegida != 1 && opcionElegida != 2))
				{
					retorno = getStringNumeros("\n|ERROR|\nEl tipo de pasajero esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese un numero de opcion posible: ", pidoOpcion);
					opcionElegida = atoi(pidoOpcion);
				}

				if(opcionElegida == 1)
				{
					list[index].idTypePassenger = auxI;
					valido = 0;
				}
				else
				{
					printf("\n|Volviendo al menu|\n");
				}
			break;

			case 5:
				auxI = PedirEstadoVuelo();

				retorno = getStringNumeros("El estado de vuelo esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese el numero de la opcion: ", pidoOpcion);
				opcionElegida = atoi(pidoOpcion);
				while(retorno != 1 || (opcionElegida != 1 && opcionElegida != 2))
				{
					retorno = getStringNumeros("\n|ERROR|\nEl estado de vuelo esta por ser modificado, esta segurx de hacerlo?\n1.Si\n2.No\nIngrese un numero de opcion posible: ", pidoOpcion);
					opcionElegida = atoi(pidoOpcion);
				}

				if(opcionElegida == 1)
				{
					list[index].statusFlight = auxI;
					valido = 0;
				}
				else
				{
					printf("\n|Volviendo al menu|\n");
				}
			break;

			case 6:
				printf("\n|Volviendo al menu|\n");
			break;
		}
	}
	else
	{
		printf("\n|No se ha encontrado el ID|\n");
	}


	return valido;
}

int DarDeBaja(Passenger list[], int len, TypePassenger listTypes[], int lenType)
{
	int valido = -1;
	int retorno;
	char pidoOpcion[10];
	int opcionElegida;
	int id;
	int index;

	printPassenger(list, len, listTypes, lenType);
	id = PedirId(list, len);
	index = findPassengerById(list, len, id);

	if(index != -1)
	{
		printf("\nEl pasajero con ID: %d, nombre y apellido: %s %s y tipo de pasajero: %d, esta por ser eliminado.", list[index].id, list[index].name, list[index].lastName, list[index].idTypePassenger);
		retorno = getStringNumeros("Esta segurx de hacerlo?\n1.Si\n2.No\nIngrese un numero de opcion: ", pidoOpcion);
		opcionElegida = atoi(pidoOpcion);
		while(retorno != 1 || (opcionElegida != 1 && opcionElegida != 2))
		{
			printf("\n|ERROR|\nEl pasajero con ID: %d, nombre y apellido: %s %s y tipo de pasajero: %d, esta por ser eliminado.", list[index].id, list[index].name, list[index].lastName, list[index].idTypePassenger);
			retorno = getStringNumeros("\nEsta segurx de hacerlo?\n1.Si\n2.No\nIngrese un numero de opcion posible: ", pidoOpcion);
			opcionElegida = atoi(pidoOpcion);
		}

		if(opcionElegida == 1)
		{
			list[index].isEmpty = LIBRE;
			valido = 0;
		}
		else
		{
			printf("\n|Volviendo al menu|\n");
		}
	}
	else
	{
		printf("\n|No se ha encontrado el ID|\n");
	}

	return valido;
}

float CalcularPromedioDePrecio(Passenger list[], int len)
{
	float sumaTotal = 0;
	int contador = 0;
	float promedio;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			sumaTotal += list[i].price;
			contador++;
		}
	}

	promedio = sumaTotal / contador;

	return promedio;
}

void ListaPasajerosPrecioMayorPromedio(Passenger list[], int len, TypePassenger listTypes[], int lenType, float promedio)
{
	printf("\n|Listado de pasajeros que superan el precio de vuelo promedio de %.2f|\n", promedio);
	printf("|ID|       |Nombre|   |Apellido|     |Precio|    |Codigo vuelo|   |Tipo pasajero|   |Estado vuelo|\n");

	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < lenType; j++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].idTypePassenger == listTypes[j].id && list[i].price > promedio)
			{
				printOnePassenger(list[i], listTypes[j]);
			}
		}
	}
}

void ListaVuelosActivosOrdenados(Passenger list[], int len, TypePassenger listTypes[], int lenType)
{
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			sortPassengersByCode(list, len, 1);
		}
	}

	printf("|ID|       |Nombre|   |Apellido|     |Precio|    |Codigo vuelo|   |Tipo pasajero|   |Estado vuelo|\n");
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < lenType; j++)
		{
			if(list[i].statusFlight == 1 && list[i].idTypePassenger == listTypes[j].id)
			{
				printOnePassenger(list[i], listTypes[j]);
			}
		}
	}
}

void CargarForzadamenteListaPasajeros(Passenger list[], int* altasHechas)
{
	Passenger aux[10] = {{1, "Juan", "Cruz", 2156.40, "H5NK1", 100, 1, 1},
						 {2, "Marina", "Aguero", 3401.25, "H5NA3", 102, 3, 1},
						 {3, "Noelia", "Pascual", 2410.50, "LMO12", 102, 1, 1},
						 {4, "Octavio", "Fernandez", 1263.54, "AMW2L", 100, 2, 1},
						 {5, "Esteban", "Cardozo", 900.21, "NO23K", 101, 3, 1},
						 {6, "Americo", "Vespucio", 1920.87, "NE9WK", 101, 1, 1},
						 {7, "Lucas", "Pereyra", 7934.12, "PQW82", 100, 2, 1},
						 {8, "Joey", "Tribbiani", 5439.12, "BW1J3", 102, 3, 1},
						 {9, "Ross", "Geller", 6923.65, "C9IWJ", 101, 1, 1},
						 {10, "Rachel", "Green", 8192.43, "C1IWJ", 101, 2, 1}};

	*altasHechas = 10;

	for(int i = 0; i < 10; i++)
	{
		list[i] = aux[i];
	}
}
