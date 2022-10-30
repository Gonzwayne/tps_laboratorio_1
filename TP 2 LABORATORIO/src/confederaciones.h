
#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
    int isEmpty;

} eConfederaciones;

#endif /* CONFEDERACIONES_H_ */

int mostrarConfederaciones(eConfederaciones lista[], int tam);
void mostrarConfederacion(eConfederaciones a);
int asignarNombreConfederaciones(eConfederaciones lista[],int tam,int idConfederacion,char descConfederaciones[]);
int harcodearConfederaciones(int* pConfederacion, eConfederaciones vec[], int tamConfederacion, int cant);
int buscarLibreConfe(eConfederaciones lista[], int tam);
int altaConfederacion(eConfederaciones lista[], int tamConfederacion,int* pId);
int bajaConfederacion(eConfederaciones lista[], int tamConfederacion);
int buscarConfederacionId(int id, eConfederaciones lista[], int tamConfederacion);
int modificarConfederacion(eConfederaciones vec[], int tam);
