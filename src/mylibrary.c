#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"

int confirmarSalida(char *pControl) {
	int todoOK = 0;
	char confirma;
	if (pControl != NULL) {
		printf("confirmar salir ingrese s o n?\n");
		fflush(stdin);
		scanf("%c", &confirma);
		if (confirma == 's') {
			*pControl = 's';
		}
		todoOK = 1;
	}

	return todoOK;
}

void mostrarMenu(int *pOpciones, int acumHospedaje, int acumComida,
		int acumTransporte, int contArquero, int contDefensor,
		int contMediocampista, int contDelantero) {
	printf(" +++ Menu De Opciones +++\n");
	printf("1- ingreso costo de mantenimiento \n");
	printf("costo de hospedaje $%d\n", acumHospedaje);
	printf("costo de comida $%d\n", acumComida);
	printf("costo de transporte $%d\n", acumTransporte);
	printf("2- ingrese jugadores -\n");
	printf("arqueros ->%d\n", contArquero);
	printf("defensores ->%d\n", contDefensor);
	printf("mediocampistas ->%d\n", contMediocampista);
	printf("delanteros ->%d\n", contDelantero);
	printf("3- Realizar todos los calculos \n");
	printf("4- Informar todos los resultados \n");
	printf("5- Salir \n");
	if(pOpciones != NULL){
	printf("Ingrese Una Opcion:\n");
	fflush(stdin);
	scanf("%d", pOpciones);
	}
}



int getInt(int* numero ,char* mensaje,int minimo ,int maximo)
{
	int todoOk;
	int numAuxiliar;
	if(mensaje != NULL && numero != NULL){
	do{
	printf(mensaje);
	fflush(stdin);
	todoOk = scanf("%d",&numAuxiliar);
	if(todoOk==0){
		printf("Error, no es un numero \n");
	}
		}while(todoOk ==0);
		if (numAuxiliar > minimo && numAuxiliar < maximo){
				*numero = numAuxiliar;
				return 1;
		}
	}
	return 0;
}
