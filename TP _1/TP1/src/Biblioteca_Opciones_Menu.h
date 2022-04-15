#ifndef BIBLIOTECA_OPCIONES_MENU_H_
#define BIBLIOTECA_OPCIONES_MENU_H_
#include <stdio.h>
#include <stdlib.h>
/// @brief Funcion que muestra un menu de opciones y permite ingresar un entero
///
/// @return Retorna un numero entero que ingreso, el cual responde a una opcion del menu
int MostrarMenu(void);

/// @brief Funcion que permite el ingreso de un flotante
///
/// @return retorna el mismo flotante ingresado.
float IngresarKilometros(void);

/// @brief Funcion que permite ingresar un char
///
/// @return retorna el char ingresado.
char ElegirEmpresaDeVuelo(void);

/// @brief Funcion que permite el ingreso de un flotante
///
/// @return retorna el mismo flotante ingresado
float PedirPrecioLatam(void);

/// @brief Funcion que permite el ingreso de un flotante
///
/// @return retorna el mismo flotante ingresado
float PedirPrecioAerolineas(void);

/// @brief Funcion que muestra datos harcodeados
///
void CargarForzadamente(void);

#endif /* BIBLIOTECA_OPCIONES_MENU_H_ */
