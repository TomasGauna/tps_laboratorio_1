#ifndef BIBLIOTECA_CALCULOS_H_
#define BIBLIOTECA_CALCULOS_H_

#include "Biblioteca_Opciones_Menu.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief Funcion que calcula el costo con tarjeta de debito
///
/// @param precioRecibido parametro a calcular recibido desde el main.
/// @return el resultado aplicando el descuento con tarjeta de debito
float PagarConDebito(float precioRecibido);

/// @brief Funcion que calcula el costo con tarjeta de credito
///
/// @param precioRecibido parametro a calcular recibido desde el main
/// @return el resultado aplicando el interes con tarjeta de credito
float PagarConCredito(float precioRecibido);

/// @brief Funcion que convierte el peso a BITCOIN
///
/// @param precioRecibido parametro a calcular recibido desde el main
/// @return el valor del peso en BITCOIN
float PagarConBitcoin(float precioRecibido);

/// @brief Funcion que calcula el precio de un kilometro
///
/// @param precioRecibido parametro a calcular recibido desde el main
/// @param kilometrosRecibidos parametro a calcular recibido desde el main
/// @return el valor en pesos de un kilometro
float CalcularPrecioUnitario(float precioRecibido, int kilometrosRecibidos);

/// @brief Funcion que calcula la diferencia de precio
/// Se tiene en cuenta que valor es mas grande, para poder hacer la resta y no resultar en ningun numero negativo.
/// @param primerPrecioRecibido parametro a calcular recibido desde el main
/// @param segundoPrecioRecibido parametro a calcular recibido desde el main
/// @return la diferencia de precio entre un vuelo y otro
float CalcularDiferenciaPrecio(float primerPrecioRecibido, float segundoPrecioRecibido);

#endif /* BIBLIOTECA_CALCULOS_H_ */
