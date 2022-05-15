#ifndef AUXILIAR_H_
#define AUXILIAR_H_
#define OCUPADO 0
#define LIBRE 1

/// @brief Muestra un menu de opciones
///
/// @return opcion elegida
int MostrarMenuOpciones();


/// @brief coloca el campo de estado(isEmpty) de cada
/// posicion del array en LIBRE
/// @param list array de pasajeros
void InicializarListaPasajeros(Passenger list[]);


/// @brief Muestra un pasajero
///
/// @param pasajero variable de tipo Passenger
void MostrarUnPasajero(Passenger pasajero);


/// @brief Muestra los tipos de pasajeros
///
/// @param list array de tipos de pasajeros
/// @param len logintud del array
void MostrarTipos(typePassenger list[], int len);


/// @brief Carga una lista de pasajeros
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @param types array de tipos de pasajeros
/// @param lenType logintud del array
/// @return int Return (-1) si no hay espacio en el array (!= 1) si esta ok
int CargarListaPasajeros(Passenger list[], int len, typePassenger types[], int lenType);


/// @brief Muestra un menu con opciones a elegir
///
/// @param modificar del 1 al 5 la opcion elegida
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @param types arrays de tipos de pasajeros
/// @param lenType longitud del array de tipos de pasajeros
/// @param index en que posicion del array se va a modificar
/// @return int (1) para confirmar (0) para volver
int MostrarMenuModificacion(int modificar, Passenger list[], int len, typePassenger types[], int lenType, int index);


/// @brief Modifica un pasajero
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @param types arrays de tipos de pasajeros
/// @param lenType longitud del array de tipos de pasajeros
/// @return (-1) si no se encotro el id  (1 o 0) si esta ok
int ModificarPasajero(Passenger list[], int len, typePassenger types[], int lenType);


/// @brief Elimina un pasajero
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @return (-1) si no se elimina (0) si esta ok
int EliminarPasajero(Passenger list[], int len);


/// @brief Muestra una lista de pasajeros con solo el Id, nombre y apellido
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
void MostrarPasajerosResumido(Passenger list[], int len);


/// @brief Pide informacion de un pasajero
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @param types arrays de tipos de pasajeros
/// @param lenType longitud del array de tipos de pasajeros
/// @return el pasajero
Passenger PedirUnPasajero(Passenger list[], int len,typePassenger types[], int lenTypes);


/// @brief Muestra una lista de todos los pasajeros
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
void MostrarListaDePasajeros(Passenger list[], int len);


/// @brief Ordena la lista alfabeticamente por apellido
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
void OrdenarListaPasajerosPorApellido(Passenger list[], int len);


/// @brief Muestra un menu de opciones de la opcion 4 del main
///
/// @return int opcion elegida
int MostrarListaOpciones4();


/// @brief Suma todos los precios de vuelo
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @return float la suma de todos los precios
float SumarPreciosDeVuelo(Passenger list[], int len);


/// @brief Calcula el promedio entre todos los precios ingresados
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @param sumaTotal suma de todos los precios
/// @return float el promedio de todos los precios
float CalcularPromedio(Passenger list[], int len, float sumaTotal);


/// @brief muestra una lista de pasajeros que superan el promedio de precio
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @param promedio
void MostrarListaMayorAPromedio(Passenger list[], int len, float promedio);


/// @brief Muestra el resultado de la opcion 4.2 del menu principal
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
void MostrarOpcionDosCuatro(Passenger list[], int len);


/// @brief ordena la lista de pasajeros por su codigo de vuelo
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
void OrdenarListaDePasajerosPorCodigo(Passenger list[], int len);


/// @brief Busca el primer espacio libre en el array
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @return int indice del array
int BuscarEspacio(Passenger list[], int len);


/// @brief Calcula el id automaticamente
///
/// @param list array de pasajeros
/// @param len logintud del array de pasajeros
/// @return int el id calculado
int ObtenerId(Passenger list[], int len);


/// @brief Le pide al usuario el nombre del pasajero
///
/// @param newPassenger variable del tipo passenger
void PedirNombre(Passenger newPassenger);


/// @brief Le pide al usuario el apellido del pasajero
///
/// @param newPassenger variable del tipo passenger
void PedirApellido(Passenger newPassenger);


/// @brief pide al usuario el precio de vuelo del pasajero
///
/// @return float precio ingresado
float PedirPrecio();


/// @brief pide al usuario el codigo de vuelo del pasajero
///
/// @param newPassenger variable del tipo passenger
void PedirCodigoVuelo(Passenger newPassenger);


/// @brief pide al usuario el tipo de pasajero
///
/// @param list array de tipos de pasajeros
/// @param len longitud del array de tipos de pasajeros
/// @return int tipo elegido
int PedirTipoPasajero(typePassenger list[], int len);


/// @brief pide al usuario el estado del vuelo
///
/// @return int estado del vuelo
int PedirEstadoDeVuelo();

#endif /* AUXILIAR_H_ */
