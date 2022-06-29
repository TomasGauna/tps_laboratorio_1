#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/*EL PROYECTO NO COMPILA NI CORRE, NO LLEGUE CON EL TIEMPO.
 *DE TODAS FORMAS, ESTA CASI TERMINADO, ESPERO SE VALORE ALGO. EN TODO CASO
 * MUCHAS GRACIAS.
 */




int main()
{
	setbuf(stdout,NULL);

	LinkedList* list;
	char optionC[50];
	int opcionElegida;
	int retorno;
	int flagIn = 0;
	int flagOut = 0;

	list = ll_newLinkedList();

	do
	{
		retorno = getStringNumeros("\t< Menu de opciones >\n"
			   "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
			   "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
			   "3. Alta de pasajero\n"
			   "4. Modificar datos de pasajero\n"
			   "5. Baja de pasajero\n"
			   "6. Listar pasajeros\n"
			   "7. Ordenar pasajeros\n"
			   "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
			   "9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)\n"
			   "10. Salir\n"
			   "Elija una opcion: ", optionC);
		opcionElegida = atoi(optionC);
		while(opcionElegida)
		{
			retorno = getStringNumeros("\n|ERROR|\n\t< Menu de opciones >\n"
				   "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
				   "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
				   "3. Alta de pasajero\n"
				   "4. Modificar datos de pasajero\n"
				   "5. Baja de pasajero\n"
				   "6. Listar pasajeros\n"
				   "7. Ordenar pasajeros\n"
				   "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
				   "9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)\n"
				   "10. Salir\n"
				   "Elija una opcion correcta: ", optionC);
			opcionElegida = atoi(optionC);
		}

		switch(opcionElegida)
		{
			case 1:
				if(flagIn == 0)
				{
					if(controller_loadFromText("data.csv", list) == 0)
					{
						printf("Se ha cargado con exito\n");
						flagIn = 1;
					}
				}
				else
				{
					printf("El archivo ha sido abierto anterioremente\n");
				}
			break;

			case 2:
				if(flagIn == 0)
				{
					if(controller_loadFromBinary("data.bin", list) == 0)
					{
						printf("Se ha cargado con exito\n");
						flagIn = 1;
					}
				}
				else
				{
					printf("El archivo ha sido abierto anterioremente\n");
				}
			break;

			case 3:
				retorno = controller_addPassenger(list);

				if(retorno == 0)
				{
					printf("El pasajero se ha cargado con exito\n");
				}
			break;

			case 4:
				retorno = controller_editPassenger(list);

				if(retorno == 0)
				{
					printf("Se ha modificado con exito\n");
				}
				else
				{
					printf("No se han modificado los datos\n");
				}
			break;

			case 5:
				retorno = controller_removePassenger(list);

				if(retorno == 0)
				{
					printf("Se ha dado de baja exitosamente\n");
				}
			break;

			case 6:
				//ll_sort(list, retorno, 1);//hacer funcion donde dice retorno

				if(controller_ListPassenger(list) == 0)
				{
					printf("Lista cargada con exito\n");
				}
				else
				{
					printf("No hay pasajeros para mostrar\n");
				}
			break;

			case 7:
				retorno = controller_sortPassenger(list);

				if(retorno == 0)
				{
					printf("Lista cargada con exito\n");
				}
			break;

			case 8:
				retorno = controller_saveAsText("data.csv", list);

				if(retorno == 0)
				{
					printf("Guardado exitoso\n");
					flagOut = 1;
				}
			break;

			case 9:
				retorno = controller_saveAsBinary("data.bin", list);

				if(retorno == 0)
				{
					printf("Guardado exitoso\n");
					flagOut = 1;
				}
			break;

			case 10:
				if(flagOut == 1)
				{
					printf("Saliendo del programa\n");
				}
				else
				{
					printf("No puede salir sin haber realizado al menos un guardado de archivo\n");
				}
			break;
		}
	}while(opcionElegida != 10);

    return EXIT_SUCCESS;
}
