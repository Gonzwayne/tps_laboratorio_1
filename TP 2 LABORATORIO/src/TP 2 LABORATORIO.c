
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "inputconvalidaciones.h"
#include "informes.h"
#include "menus.h"


#define TAM 20
#define TAMCONFEDERACION 6

int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    int nexId = 1;
    int nexIdConfe = 100;
    int flag = 0;
    eConfederaciones listaConfe[TAMCONFEDERACION];
    eJugador lista[TAM];

    if(!inicializarJugador(lista, TAM))
    {
        printf("Error al cargar datos ");
    }
    inicializarJugador(lista, TAM);
    harcodearJugadores(&nexId, lista, TAM, 10);
    harcodearConfederaciones(&nexIdConfe,listaConfe, TAMCONFEDERACION, 6);

    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(altaJugador(lista,listaConfe, TAMCONFEDERACION, TAM, &nexId ))
            {
            	printf("Alta Confirmada\n");

            }
            else{
            	printf("No se pudo dar de Alta\n");
            }
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                if(bajaJugador(lista, TAM, listaConfe, TAMCONFEDERACION))
                {
                	printf("Baja confirmada\n");
                }
                else
                {
                	printf("Baja cancelada \n");
                }
            }
            else
            {
                printf("Debe Dar de alta un jugador\n");
            }
            break;
        case 3:
                if(flag == 1)
                {
                    mostrarJugadoresPorId(lista,TAM,listaConfe, TAMCONFEDERACION);
                    modificarJugador(lista, TAM, listaConfe, TAMCONFEDERACION);
                }
                else
                {
                    printf("Debe Dar de alta un jugador\n");
                }

            break;
        case 4:
                if(flag == 1)
                {

                    mostrarInformes(lista, TAM, listaConfe, TAMCONFEDERACION);
                }
                else
                {
                    printf("Debe dar de alta un jugador\n");
                }

            break;
        case 5:
            printf("Salir\n");
            fflush(stdin);
            confirmarSalida(&seguir);
            fflush(stdin);
            break;
        default:
            printf("Opcion incorrecta!!!\n");
        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}

