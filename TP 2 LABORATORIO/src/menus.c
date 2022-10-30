#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputconvalidaciones.h"

int menuPrincipal() {
	int opcion;
	system("cls");
	printf(" ----------------------------\n");
	printf(" |  +++ ABM JUGADORES +++   |\n");
	printf(" ----------------------------\n");
	printf("1| Alta de Jugador          |\n");
	printf(" ----------------------------\n");
	printf("2| Baja de Jugador          |\n");
	printf(" ----------------------------\n");
	printf("3| Modificar Jugador        |\n");
	printf(" ----------------------------\n");
	printf("4| Mostrar Informes         |\n");
	printf(" ----------------------------\n");
	printf("5| Salir                    |\n");
	printf(" ----------------------------\n");
	fflush(stdin);
	utn_getNumero(&opcion,"Ingrese una Opcion\n", "Error !!! Ingrese una Opcion\n", 1, 5, 3);
	return opcion;
}

int mostrarSubMenu() {
	int opcion;
	system("cls");
	printf(" ----------------------------------------------\n");
	printf("     *** Seleccione opcion a modificar ***     \n");
	printf(" ----------------------------------------------\n");
	printf("1- nombre\n");
	printf("2- posicion\n");
	printf("3- numeroCamiseta\n");
	printf("4- idConfederacion\n");
	printf("5- salario\n");
	printf("6- aniosContrato\n");
	printf("7- salir\n");
	fflush(stdin);
	utn_getNumero(&opcion,"Ingrese una Opcion\n", "Error !!! Ingrese una Opcion\n", 1, 7, 3);
	return opcion;
}

int menuModificar()
{
    int opcion;
    system("cls");
    fflush(stdin);
    utn_getNumero(&opcion,"    +++ Modificar Jugador +++     \n\n1-  Nombre\n2- Posicion\n3-  Numero de camiseta\n4-  Confederacion\n5-  Salario\n6-  Anios de contrato\n7- Salir\nIngrese Opcion: \n","Error ",1,7,5);

    return opcion;
}
int menuModificarConfederacion()
{
    int opcion;
    system("cls");
    fflush(stdin);
    utn_getNumero(&opcion,"    +++ Modificar Confederacion +++    \n\n1- Modificar Nombre\n2- Modificar Region\n3- Modificar anio de creacion\nIngrese Opcion: \n","Error",1,3,5);

    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    fflush(stdin);
    utn_getNumero(&opcion,"  +++ Informes +++\n\n1- Lista de jugadores\n2- lista de jugadores por confederacion\n3- informes de salarios\n4- Confederacion con mas años de contrato\n5- Region con mas jugadores y lista de jugadores\n6- Porcentaje de jugadores por confederacion\n7- Salir\nIngrese una opcion: \n", "Error, reingrese opcion\n",1,7,5);

    return opcion;
}



void menuPosicion()
{
	printf(" ----------------------------\n");
    printf("   +++ Menu Posicion +++     \n");
    printf(" ----------------------------\n");
    printf("1 - Arquero\n");
    printf("2 - Defensor\n");
    printf("3 - Mediocampista\n");
    printf("4 - Delantero\n");

}
