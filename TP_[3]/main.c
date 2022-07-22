#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n
     3. Alta de pasajero\n
     4. Modificar datos de pasajero\n
     5. Baja de pasajero\n
     6. Listar pasajeros\n
     7. Ordenar pasajeros\n
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n
    10. Salir\n
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	char pidoOpcion[50];
    int opcionElegida;
    int valido;
    int flagIn = 0;
    int flagOut = 0;
    int aux;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do
    {
    	valido = getStringNumeros("MENU DE OPCIONES\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    							  "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    							  "3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n"
    							  "7. Ordenar pasajeros\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    							  "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10. Salir\nElija una opcion: ", pidoOpcion);
    	opcionElegida = atoi(pidoOpcion);

    	while(valido != 1 || (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3 && opcionElegida != 4 && opcionElegida != 5 && opcionElegida != 6
    		  && opcionElegida != 7 && opcionElegida != 8 && opcionElegida != 9 && opcionElegida != 10))
    	{
        	valido = getStringNumeros("\n|ERROR|\nMENU DE OPCIONES\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
        							  "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
        							  "3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n"
        							  "7. Ordenar pasajeros\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
        							  "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10. Salir\nElija una opcion correcta: ", pidoOpcion);
        	opcionElegida = atoi(pidoOpcion);
    	}

    	switch(opcionElegida)
        {
            case 1:
                if(flagIn == 0)
                {
                	if(controller_loadFromText("data.csv",listaPasajeros) == 1)
                	{
                		printf("\nCarga realizada con exito\n");
                		flagIn = 1;
                	}
                }
                else
                {
                	printf("\nYa se realizo una carga con anterioridad\n");
                }
            break;

            case 2:
                if(flagIn == 0)
                {
                	if(controller_loadFromBinary("data.bin",listaPasajeros) == 1)
                	{
                		printf("\nCarga realizada con exito\n");
                		flagIn = 1;
                	}
                }
                else
                {
                	printf("\nYa se realizo una carga con anterioridad\n");
                }
            break;

            case 3:
            	aux = controller_addPassenger(listaPasajeros);

            	if(aux == 1)
            	{
            		printf("\nVuelo cargado con exito\n");
            	}
            break;

            case 4:
            	aux = controller_editPassenger(listaPasajeros);

            	if(aux == 1)
            	{
            		printf("\nEl vuelo se ha modificado correctamente\n");
            	}
            	else
            	{
            		printf("\nNo se han modificado los datos\n");
            	}
            break;

            case 5:
            	aux = controller_removePassenger(listaPasajeros);
            break;

            case 6:
            	ll_sort(listaPasajeros, CompareByID, 1);
            	if(controller_ListPassenger(listaPasajeros) == 1)
            	{
            		printf("\nLista cargada con exito\n");
            	}
            	else
            	{
            		printf("\nNo se han podido mostrar los pasajeros\n");
            	}
            break;

            case 7:
            	aux = controller_sortPassenger(listaPasajeros);
            break;

            case 8:
            	aux = controller_saveAsText("data.csv", listaPasajeros);

            	if(aux == 1)
            	{
            		printf("\nSe ha guardado la lista con exito\n");
            		flagOut = 1;
            	}
            break;

            case 9:
            	aux = controller_saveAsBinary("data.bin", listaPasajeros);

            	if(aux == 1)
            	{
            		printf("\nSe ha guardado la lista con exito\n");
            		flagOut = 1;
            	}
            break;

            case 10:
            	if(flagOut == 1)
            	{
            		printf("\nTerminando el programa..\n");
            		opcionElegida = 11;
            	}
            	else
            	{
            		printf("\nNo se puede terminar el programa sin haber guardado el archivo aunque sea una vez...\n");
            	}
            break;
        }
    }while(opcionElegida != 11);

    return 0;
}

