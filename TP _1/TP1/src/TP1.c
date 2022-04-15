#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca_Opciones_Menu.h"
#include "Biblioteca_Calculos.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcionElegida;
	float kilometrosDeVuelo;
	char empresaElegida;
	float precioVueloAerolinea;
	float precioVueloLatam;
	float precioTarjetaDeDebitoAerolinea;
	float precioTarjetaDeCreditoAerolinea;
	float precioBitcoinAerolinea;
	float precioUnitarioAerolinea;
	float precioTarjetaDeDebitoLatam;
	float precioTarjetaDeCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaDePrecio;

	kilometrosDeVuelo = -1;
	precioVueloAerolinea = -1;
	precioVueloLatam = -1;

	do
	{
		opcionElegida = MostrarMenu();

		switch(opcionElegida)
			{
				case 1:
					kilometrosDeVuelo = IngresarKilometros();
				break;

				case 2:
					empresaElegida = ElegirEmpresaDeVuelo();
					switch (empresaElegida)
					{
						case 'z':
							precioVueloLatam = PedirPrecioLatam();
						break;
						default:
							precioVueloAerolinea = PedirPrecioAerolineas();
						break;
					}
				break;

				case 3:
					if (kilometrosDeVuelo == -1 || precioVueloLatam == -1 || precioVueloAerolinea == -1)
					{
						printf("\n\n~~ERROR. Faltan datos por completar~~\n\n");
					}
					else
					{
						precioTarjetaDeDebitoAerolinea = PagarConDebito(precioVueloAerolinea);
						precioTarjetaDeCreditoAerolinea = PagarConCredito(precioVueloAerolinea);
						precioBitcoinAerolinea = PagarConBitcoin(precioVueloAerolinea);
						precioUnitarioAerolinea = CalcularPrecioUnitario(precioVueloAerolinea, kilometrosDeVuelo);

						precioTarjetaDeDebitoLatam = PagarConDebito(precioVueloLatam);
						precioTarjetaDeCreditoLatam = PagarConCredito(precioVueloLatam);
						precioBitcoinLatam = PagarConBitcoin(precioVueloLatam);
						precioUnitarioLatam = CalcularPrecioUnitario(precioVueloLatam, kilometrosDeVuelo);

						diferenciaDePrecio = CalcularDiferenciaPrecio(precioVueloLatam, precioVueloAerolinea);

						printf("\n\n~~Los costos han sido calculados. Opcion 4 para obtenerlos~~\n");
					}
				break;

				case 4:
					if (kilometrosDeVuelo == -1 || precioVueloLatam == -1 || precioVueloAerolinea == -1)
					{
						printf("\n\n~~ERROR. Faltan datos por completar~~\n\n");
					}
					else
					{
						printf("\n\nKMs Ingresados: %.2f km"
								"\n\nPrecio Latam: $%.2f\n"
								"a)Precio con tarjeta de debito: $%.2f \n"
								"b)Precio con tarjeta de credito: $%.2f \n"
								"c)Precio pagando en bitcoins: %.6f BTC\n"
								"d)Precio unitario: $%.2f", kilometrosDeVuelo, precioVueloLatam, precioTarjetaDeDebitoLatam, precioTarjetaDeCreditoLatam, precioBitcoinLatam, precioUnitarioLatam);

						printf("\n\nPrecio Aerolineas: $%.2f\n"
								"a)Precio con tarjeta de debito: $%.2f \n"
								"b)Precio con tarjeta de credito: $%.2f \n"
								"c)Precio pagando en bitcoins: %.6f BTC\n"
								"d)Precio unitario: $%.2f \n"
								"\n\nLa diferencia de precio es : $%.2f \n\n", precioVueloAerolinea, precioTarjetaDeDebitoAerolinea, precioTarjetaDeCreditoAerolinea, precioBitcoinAerolinea, precioUnitarioAerolinea, diferenciaDePrecio);
					}

				break;

				case 5:
					CargarForzadamente();
				break;
			}
	}while(opcionElegida != 6);


	return 0;
}
