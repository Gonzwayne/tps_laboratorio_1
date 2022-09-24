

#ifndef MYLIBRARY_H_
#define MYLIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
/// @fn void mostrarMenu(int*, int, int, int, int, int, int, int)
/// @brief muestra un menu de opciones a elegir valida y guarda la opcion ingresada
///
/// @param pOpciones almacena la opcion ingresada
/// @param acumHospedaje acumula el gasto de hospedaje
/// @param acumComida acumula el gasto de comida
/// @param acumTransporte acumula el gasto de transporte
/// @param contArquero cuenta la cantidad de arquero
/// @param contDefensor	ciemta la cantidad de defensores
/// @param contMediocampista cuenta la cantidad de mediocampistas
/// @param contDelantero cuenta la cantidad de delanteros
void mostrarMenu(int *pOpciones, int acumHospedaje, int acumComida,
		int acumTransporte, int contArquero, int contDefensor,
		int contMediocampista, int contDelantero);
/// @fn int confirmarSalida(char*)
/// @brief pregunta al usuario si desea salir
///
/// @param pControl guarda la opcion elegida
/// @return retorna 1 si salio bien o 0 si salio mal
int confirmarSalida(char *pControl);
/// @fn int getInt(int*, char*, int, int)
/// @brief pide el ingreso de un numero al usuario y lo valida para saber si es un numero y no otra cosa y tambien valida un rango
///
/// @param numero guarda la opcion ingresada
/// @param mensaje ingreso el mensaje por parametro
/// @param minimo ingreso el minimo por parametro
/// @param maximo ingreso el maximo por parametro
/// @return retorna 1 si funciona bien y 0 si no funciono
int getInt(int* numero ,char* mensaje,int minimo ,int maximo);
#endif /* MYLIBRARY_H_ */
