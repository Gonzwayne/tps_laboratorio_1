

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "inputconvalidaciones.h"
#include "menus.h"


int inicializarJugador(eJugador lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eJugador lista[], int tam)
{
    int posicionLibre = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}


int altaJugador(eJugador lista[], eConfederaciones listaConf[], int tamConf, int tam, int* pId)
{
    int todoOk = 0;
    int indice;
    int auxInt;
    char auxCad[50];
    float auxFloat;
    eJugador auxJugador;

    if(lista != NULL && pId != NULL && listaConf != NULL && tamConf >0 && tam > 0)
    {

        system("cls");
        printf("-----------------------------------------------\n");
        printf("   +++     +++  Alta de jugador   +++    +++   \n");
        printf("-----------------------------------------------\n");
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("esta lleno ");
        }
        else
        {
            auxJugador.id = *pId;
            (*pId)++;

            utn_getNombre(auxCad,50,"Ingrese nombre: \n","Error, reingrese nombre",5);

            strlwr(auxCad);

            auxCad[0] = toupper(auxCad[0]);

            strcpy(auxJugador.nombre, auxCad);

            fflush(stdin);

            asignarNombrePosiciones(&auxJugador);

            utn_getNumero(&auxInt,"Ingrese numero de camiseta: \n","Numero no valido\n", 1, 100, 5);

            auxJugador.numeroCamiseta = auxInt;

            fflush(stdin);

            mostrarConfederaciones(listaConf, tamConf);

            utn_getNumero(&auxInt,"Ingrese una Opcion: \n","Opcion no valida\n",100,105,5);

            fflush(stdin);

            auxJugador.idConfederacion = auxInt;

            fflush(stdin);

            input_GetFloat(&auxFloat,"Ingrese Salario\n","Error, campo invalido\n",0,2000000.000000,5);

            auxJugador.salario = auxFloat;

            fflush(stdin);

            utn_getNumero(&auxInt,"Ingrese años de contrato \n","Error, reingrese años de contrato\n", 1, 30,5);

            auxJugador.aniosContrato = auxInt;

            auxJugador.isEmpty = 0;

            lista[indice] = auxJugador;

            todoOk = 1;
        }
    }
    return todoOk;
}


void mostrarJugador(eJugador j, eJugador lista[], int tam, eConfederaciones listaConf[], int tamConferaciones)
{
    char descConfederaciones[50];

    asignarNombreConfederaciones(listaConf,tamConferaciones, j.idConfederacion,descConfederaciones);


    printf("|%4d  | %-20s|  %-15s   |   %3d      |   %10.2f   |    %-10s    | %2d años  |\n",
           j.id,
           j.nombre,
           j.posicion,
           j.numeroCamiseta,
           j.salario,
           descConfederaciones,
           j.aniosContrato);
}


int mostrarJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConferaciones)
{
    int todoOk = 0;
    int flag;

    if(lista != NULL && tam >0 && listaConf != NULL && tamConferaciones >0)
    {
        ordenarDobleCriterio(lista,tam,listaConf,tamConferaciones);
        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("                ++++                  +++    Lista De Jugadores    +++                         ++++              \n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("|  Id  |       Nombre        |      Posicion      | N° Camiseta |      Sueldo    |   Confederacion  | Contrato  |\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarJugador(lista[i], lista, tam,listaConf, tamConferaciones);
                flag = 0;
            }

        }
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        if(flag)
        {
            printf("No hay jugadores\n");
        }
        todoOk = 1;
    }
    return todoOk;
}


int bajaJugador(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConferaciones)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("                    +++              +++    Lista De Jugadores +++                         +++                   \n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("|  ID  |       Nombre        |      Posicion      | N° Camiseta |      Sueldo    |   Confederacion  | Contrato | \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarJugador(lista[i], lista, tam,listaConf, tamConferaciones);

            }
        }
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        utn_getNumero(&id,"Ingrese id: ","Error, reingrese id",1,3000,5);

        indice = buscarJugadorId(id,lista, tam);

        if(indice == -1)
        {
            printf("el id: %d no existe\n", id);
        }
        else
        {
            mostrarJugador(lista[indice], lista, tam, listaConf, tamConferaciones);
            printf("Presione S para continuar");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada \n");
            }
        }
    }
    return todoOk;
}


int buscarJugadorId(int id, eJugador vec[], int tam)
{
    int indice = -1;
    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


int harcodearJugadores(int* pjugador, eJugador vec[], int tam, int cant)
{
    int todoOk = 0;
    eJugador jugadores[10] =
    {
        {1, "DePaul","Delantero", 10, 100, 70000, 3, 0},
        {2, "Rivaldo","Mediocampista", 10, 101, 40000, 4, 0},
        {3, "Sorin","Defensor", 3, 100, 28000, 3, 0},
        {4, "mohamed","Delantero", 7, 103, 23000, 3, 0},
        {5, "Quinteros","Delantero", 10, 105, 21000, 3, 0},
        {6, "enzo","Mediocampista", 23, 101, 24000, 3, 0},
        {7, "Armani","Arquero", 1, 102, 27000, 3, 0},
        {8, "givanildo","Arquero",23, 103, 20000, 3, 0},
        {9, "Romero","Defensor", 2, 104, 29000, 3, 0},
        {10,"Messi","delantero", 7, 100, 22000, 3, 0},
    };
    if(pjugador != NULL && vec != NULL && tam > 0 && cant<= tam && cant <= 10)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = jugadores[i];
            (*pjugador)++;
        }
        todoOk = 1;
    }
    return todoOk;

}


int modificarJugador(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConferaciones)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma = 's';

    if(lista != NULL && listaConf != NULL && tamConferaciones > 0 && tam > 0)
    {
    	printf("-------------------------------------------------------------------\n");
        printf("|                                +++ Modificar Jugador +++        |\n");
        printf("-------------------------------------------------------------------\n");

        utn_getNumero(&id,"Ingrese id: ","Error, rengreseid valido",1,3000,5);

        indice = buscarJugadorId(id, lista, tam);

        if(indice == -1)
        {
            printf("No existe un jugador con el id: %d", id);
        }
        else
        {
            mostrarJugador(lista[indice],lista, tam, listaConf, tamConferaciones);
            printf("Presione S para continuar");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma == 's')
            {
                fflush(stdin);
                modificarDatosJugador(&lista[indice]);
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada \n");
            }
        }
    }
    return todoOk;
}

int cargarDatosJugador(eJugador* lista,eConfederaciones listaConf[], int tamConfederaciones)
{
    int todoOk = 0;
    int auxInt;
    char auxCad[50];
    float auxFloat;

    if(lista != NULL)
    {
        utn_getNombre(auxCad,50,"Ingrese nombre: \n","Error, reingrese nombre",5);

        auxCad[0] = toupper(auxCad[0]);

        strcpy(lista->nombre, auxCad);

        asignarNombrePosiciones(lista);

        utn_getNumero(&auxInt,"Ingrese numero de camiseta: \n","Numero no valido\n", 1, 100, 5);

        lista->numeroCamiseta = auxInt;

        fflush(stdin);

        mostrarConfederaciones(listaConf, tamConfederaciones);

        utn_getNumero(&auxInt,"Ingrese una Opcion: \n","Opcion no valida\n",100,105,5);

        lista->idConfederacion = auxInt;

        fflush(stdin);

        input_GetFloat(&auxFloat,"Ingrese Salario\n","Error, campo invalido\n",0,200000000,5);

        lista->salario = auxFloat;

        fflush(stdin);

        utn_getNumero(&auxInt,"Ingrese años de contrato  \n","Error,reingrese año\n", 1, 50,5);

        lista->aniosContrato = auxInt;

        todoOk = 1;
    }
    return todoOk;

}

int modificarDatosJugador(eJugador* jugador)
{
    int todoOk = 0;
    int auxInt;
    float auxFloat;
    switch(mostrarSubMenu())
    {
    case 1:
        utn_getNombre(jugador->nombre,50,"Ingrese nuevo nombre: \n","Error, reingrese nuevo nombre: ",5);
        strlwr(jugador->nombre);
        jugador->nombre[0] = toupper(jugador->nombre[0]);
        break;
    case 2:
        asignarNombrePosiciones(jugador);
        break;
    case 3:
        utn_getNumero(&auxInt,"Ingrese numero de camiseta: \n","Numero no valido\n", 1, 100, 5);
        jugador->numeroCamiseta = auxInt;
        break;
    case 4:
        utn_getNumero(&auxInt,"Ingrese id de la Confederacion: \n100 - AFC\n101 - CAF\n102 - CONCACAF\n103 - CONMEBOL\n104 - OFC\n105 - UEFA\nIngrese una Opcion: \n","Opcion no valida\n",100,105,99);
        jugador->idConfederacion = auxInt;
        break;
    case 5:
        fflush(stdin);
        input_GetFloat(&auxFloat,"Ingrese Salario\n","Error, campo invalido\n",0,200000000,5);
        break;
    case 6:
        utn_getNumero(&auxInt,"Ingrese años de contrato  \n", "Error, reingrese años\n", 1,50,5);
        jugador->aniosContrato = auxInt;
        break;
    default:
        printf("opcion incorrecta");

    }
    return todoOk;
}


int asignarNombrePosiciones(eJugador* jugador)
{
    int todoOk = 0;
    int auxInt;

    if(jugador != NULL)
    {
        menuPosicion();
        utn_getNumero(&auxInt,"Ingrese una opcion\n","Error, reingrese opcion\n",1,4,5);
        switch(auxInt)
            {
            case 1:
                strcpy(jugador->posicion,"Arquero");
                break;
            case 2:
                strcpy(jugador->posicion,"Defensor");
                break;
            case 3:
                strcpy(jugador->posicion,"Mediocampista");
                break;
            case 4:
                strcpy(jugador->posicion,"Delantero");
                break;
            }
        todoOk = 1;
    }

    return todoOk;
}

int mostrarJugadoresPorId(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion)
{
    int todoOk = 0;
    int flag;

    if(lista != NULL && tam >0)
    {
        system("cls");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("                                         +++ Lista De Jugadores +++                                             \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("|  ID  |       Nombre        |      Posicion      | N° Camiseta |      Sueldo   |   Confederacion  | Contrato  |\n");
        printf("----------------------------------------------------------------------------------------------------------------\n");

        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarJugador(lista[i], lista, tam,listaConf, tamConfederacion);
                flag = 0;
            }

        }
        printf("----------------------------------------------------------------------------------------------------------------\n");
        if(flag)
        {
            printf("No hay jugadores para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}


int ordenarDobleCriterio(eJugador lista[], int tam, eConfederaciones listaConfe[], int tamConfederacion)
{
	int todoOk = 0;
	eJugador auxJugador;

	if(lista != NULL && tam > 0 && listaConfe != NULL && tamConfederacion >0){
		for(int i = 0; i <tam-1; i++)
        {
            for(int j = i+1; j<tam ; j++)
            {
                if(lista[i].idConfederacion > lista[j].idConfederacion)
                {
                    auxJugador = lista[i];
                    lista[i]= lista[j];
                    lista[j] = auxJugador;
                }
                else
                {
                    if(lista[i].idConfederacion == lista[j].idConfederacion)
                    {
                        if(strcmp(lista[i].nombre,lista[j].nombre) >0)
                        {
                            auxJugador = lista[i];
                            lista[i]= lista[j];
                            lista[j] = auxJugador;
                        }
                    }
                }
            }
        }
		todoOk = 1;
	}
	return todoOk;
}
