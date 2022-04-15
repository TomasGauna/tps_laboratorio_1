#include "Biblioteca_Opciones_Menu.h"
#include "Biblioteca_Calculos.h"
#include <stdio.h>
#include <stdlib.h>

float PagarConDebito(float precioRecibido)
{
	float precioDebito;
	float descuento;

	descuento = precioRecibido * 10 / 100;
	precioDebito = precioRecibido - descuento;

	return precioDebito;
}

float PagarConCredito(float precioRecibido)
{
	float precioCredito;
	float interes;

	interes = precioRecibido * 25 / 100;
	precioCredito = precioRecibido + interes;

	return precioCredito;
}

float PagarConBitcoin(float precioRecibido)
{
	float precioBitcoin;
	float unBitcoin;

	unBitcoin = 4606954.55;
	precioBitcoin = precioRecibido / unBitcoin;

	return precioBitcoin;
}

float CalcularPrecioUnitario(float precioRecibido, int kilometrosRecibidos)
{
	float precioUnitario;

	precioUnitario = precioRecibido / kilometrosRecibidos;

	return precioUnitario;
}

float CalcularDiferenciaPrecio(float primerPrecioRecibido, float segundoPrecioRecibido)
{
	float diferenciaDePrecio;

	if (primerPrecioRecibido > segundoPrecioRecibido)
	{
		diferenciaDePrecio = primerPrecioRecibido - segundoPrecioRecibido;
	}
	else
	{
		diferenciaDePrecio = segundoPrecioRecibido - primerPrecioRecibido;
	}

	return diferenciaDePrecio;
}
