
#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "confederaciones.h"




typedef struct
{
    int id;
    char nombre[50];
    char posicion[50];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    short aniosContrato;
    short isEmpty;
} eJugador;
#endif /* JUGADORES_H_ */



int inicializarJugador(eJugador lista[], int tam);
int buscarLibre(eJugador lista[], int tam);
int altaJugador(eJugador lista[], eConfederaciones listaConf[], int tamConf, int tam, int* pId);
int cargarDatosJugador(eJugador* lista,eConfederaciones listaConf[], int tamConfederacion);
void mostrarJugador(eJugador j, eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion);
int mostrarJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion);
int bajaJugador(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion);
int buscarJugadorId(int id, eJugador lista[], int tam);
int modificarJugador(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion);
int harcodearJugadores(int* pjugador, eJugador vec[], int tam, int cant);
int modificarDatosJugador(eJugador* jugador);
int asignarNombrePosiciones(eJugador* jugador);
int mostrarJugadoresPorId(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion);
int ordenarDobleCriterio(eJugador lista[], int tam, eConfederaciones listaConfe[], int tamConfederacion);
