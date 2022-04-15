#include "Biblioteca_Opciones_Menu.h"
#include "Biblioteca_Calculos.h"
#include <stdio.h>
#include <stdlib.h>

int MostrarMenu(void)
{
	int opcionElegida;

	printf("\n\n1- Ingresar Kilometros del vuelo \n"
			"2- Ingresar precios del vuelo \n"
			"3- Calcular todos los costos \n"
			"4- Informar resultados \n"
			"5- Carga forzada de datos \n"
			"6- Salir \n"
			"Elija una opcion: ");
	scanf("%d", &opcionElegida);

	while(opcionElegida < 1 || opcionElegida > 6)
	{
		printf(	"1- Ingresar Kilometros del vuelo \n"
				"2- Ingresar precios del vuelo \n"
				"3- Calcular todos los costos \n"
				"4- Informar resultados \n"
				"5- Carga forzada de datos \n"
				"6- Salir \n"
				"ERROR, Elija una opcion:");
		scanf("%d", &opcionElegida);
	}

	return opcionElegida;
}

float IngresarKilometros(void)
{
	float kilometrosIngresados;

	printf("\n\nIngrese los kilometros del vuelo: ");
	scanf("%f", &kilometrosIngresados);
	while (kilometrosIngresados < 0)
	{
		printf("\n\nERROR.Ingrese los kilometros del vuelo: ");
		scanf("%f", &kilometrosIngresados);
	}

	return kilometrosIngresados;
}

char ElegirEmpresaDeVuelo(void)
{
	char empresaElegida;
	printf("\n\nLATAM -> z \n"
			"Aerolineas -> y \n"
			"\nIngrese la aerolinea con la que desea viajar:");
	fflush(stdin);
	scanf("%c", &empresaElegida);
	while (empresaElegida != 'z' && empresaElegida != 'y')
	{
		printf("\n\nLATAM -> z \n"
				"Aerolineas -> y \n"
				"\nERROR.Ingrese la aerolinea con la que desea viajar:");
		fflush(stdin);
		scanf("%c", &empresaElegida);
	}

	return empresaElegida;
}

float PedirPrecioLatam(void)
{
	float precioVueloLatam;

	printf("\n\nIngrese el precio de la empresa Latam: ");
	scanf("%f", &precioVueloLatam);
	while(precioVueloLatam < 0)
	{
		printf("\n\nERROR.Ingrese el precio de la empresa Latam: ");
		scanf("%f", &precioVueloLatam);
	}

	return precioVueloLatam;
}

float PedirPrecioAerolineas(void)
{
	float precioVueloAerolinea;

	printf("\n\nIngrese el precio de la empresa Latam: ");
	scanf("%f", &precioVueloAerolinea);
	while(precioVueloAerolinea < 0)
	{
		printf("\n\nERROR.Ingrese el precio de la empresa Latam: ");
		scanf("%f", &precioVueloAerolinea);
	}

	return precioVueloAerolinea;
}

void CargarForzadamente(void)
{
	float kilometrosDeVuelo;
	float precioVueloLatam;
	float precioVueloAerolinea;
	float diferenciaDePrecio;
	kilometrosDeVuelo = 7090;
	precioVueloLatam = 159339;
	precioVueloAerolinea = 162965;
	printf("\n\nKMs Ingresados: %.2f km"
			"\n\nPrecio Latam: $%.2f\n"
			"a)Precio con tarjeta de debito: $%.2f \n"
			"b)Precio con tarjeta de credito: $%.2f \n"
			"c)Precio pagando en bitcoins: %.6f BTC\n"
			"d)Precio unitario: $%.2f", kilometrosDeVuelo, precioVueloLatam, PagarConDebito(precioVueloLatam), PagarConCredito(precioVueloLatam), PagarConBitcoin(precioVueloLatam), CalcularPrecioUnitario(precioVueloLatam, kilometrosDeVuelo));

	printf("\n\nPrecio Aerolineas: $%.2f\n"
			"a)Precio con tarjeta de debito: $%.2f \n"
			"b)Precio con tarjeta de credito: $%.2f \n"
			"c)Precio pagando en bitcoins: %.6f BTC\n"
			"d)Precio unitario: $%.2f \n"
			"\n\nLa diferencia de precio es: $%.2f \n\n", precioVueloAerolinea, PagarConDebito(precioVueloAerolinea), PagarConCredito(precioVueloAerolinea), PagarConBitcoin(precioVueloAerolinea), CalcularPrecioUnitario(precioVueloAerolinea, kilometrosDeVuelo), diferenciaDePrecio = CalcularDiferenciaPrecio(precioVueloLatam, precioVueloAerolinea));
}


