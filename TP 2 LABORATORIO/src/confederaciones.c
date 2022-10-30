
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "inputconvalidaciones.h"
#include "menus.h"


void mostrarConfederacion(eConfederaciones a)
{
    printf("|%4d |     %-10s   |         %-15s       |        %d       |\n",
           a.id,
           a.nombre,
           a.region,
           a.anioCreacion);
}

int mostrarConfederaciones(eConfederaciones lista[], int tamConfederaciones)
{
    int todoOk = 0;
    int flag;
    eConfederaciones auxConf;

    if(lista != NULL && tamConfederaciones >0)
    {
        system("cls");
        printf("------------------------------------------------------------------------------\n");
        printf("                               +++ Lista De Confederaciones +++               \n");
        printf("------------------------------------------------------------------------------\n");
        printf("| ID  |     Nombre       |             Region          | Año De Creacion  |   \n");
        printf("------------------------------------------------------------------------------\n");
        for(int i = 0; i <tamConfederaciones-1; i++)
        {
            for(int j = i+1; j<tamConfederaciones ; j++)
            {
                if(lista[i].id > lista[j].id)
                {
                    auxConf = lista[i];
                    lista[i]= lista[j];
                    lista[j] = auxConf;
                }
            }
        }
        for(int i = 0; i <tamConfederaciones; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarConfederacion(lista[i]);
                flag = 0;
            }
        }
        printf("------------------------------------------------------------------------------\n");
        if(flag)
        {
            printf("No hay confederacion para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}


int asignarNombreConfederaciones(eConfederaciones lista[],int tam, int idConfederacion, char descConfederaciones[])
{
    int todoOk = 0;
    if(lista != NULL && tam >0 && descConfederaciones != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].id == idConfederacion)
            {
                strcpy(descConfederaciones, lista[i].nombre);
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int harcodearConfederaciones(int* pConfederacion, eConfederaciones vec[], int tamConfederacion, int cant)
{
    int todoOk = 0;
    eConfederaciones confederaciones[6] = {{100, "AFC", "ASIA", 1954,0},
        {101, "CAF", "AFRICA", 1957,0},
        {102, "CONCACAF", "N Y C AMERICA", 1961,0},
        {103, "CONMEBOL", "SUDAMERICA", 1916,0},
        {104, "OFC", "OCEANIA", 1966,0},
        {105, "UEFA", "EUROPA", 1954,0}
    };
    if(pConfederacion != NULL && vec != NULL && tamConfederacion > 0 && cant<= tamConfederacion && cant <= 6)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = confederaciones[i];
            (*pConfederacion)++;
        }
        todoOk = 1;
    }
    return todoOk;

}

int altaConfederacion(eConfederaciones lista[], int tamConfederacion,int* pId)
{
    int todoOk = 0;
    int indice;
    int auxInt;
    char auxCad[50];
    eConfederaciones auxConf;

    if(lista != NULL && pId != NULL&& tamConfederacion >0)
    {

        system("cls");
        printf("-----------------------------------------------\n");
        printf("       +++  Alta De Confederacion  +++         \n");
        printf("-----------------------------------------------\n");
        indice = buscarLibreConfe(lista, tamConfederacion);
        if(indice == -1)
        {
            printf("No hay lugar ");
        }
        else
        {
            auxConf.id = *pId;
            (*pId)++;

            utn_getNombre(auxCad,50,"Ingrese nombre: \n","Error, reingrese nombre\n",5);

            strlwr(auxCad);

            auxCad[0] = toupper(auxCad[0]);

            strcpy(auxConf.nombre, auxCad);

            fflush(stdin);
            utn_getNombre(auxCad,50,"Ingrese region: \n","Error, reingrese Region\n",5);

            strlwr(auxCad);

            auxCad[0] = toupper(auxCad[0]);

            strcpy(auxConf.region, auxCad);

            fflush(stdin);

            utn_getNumero(&auxInt,"Ingrese año de creacion: \n","Error reingrese año\n", 1, 2022, 5);

            auxConf.anioCreacion = auxInt;

            fflush(stdin);

            auxConf.isEmpty = 0;

            lista[indice] = auxConf;

            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarLibreConfe(eConfederaciones lista[], int tam)
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

int bajaConfederacion(eConfederaciones lista[], int tamConf)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tamConf > 0)
    {
        system("cls");
        printf("------------------------------------------------------------------------------\n");
        printf("               +++       Lista De Confederaciones       +++                   \n");
        printf("------------------------------------------------------------------------------\n");
        printf("| ID  |     Nombre       |              Region           | Año De Creacion  | \n");
        printf("------------------------------------------------------------------------------\n");
        for(int i = 0; i <tamConf; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarConfederacion(lista[i]);

            }
        }
        printf("------------------------------------------------------------------------------\n");
        utn_getNumero(&id,"Ingrese id: ","Error, campo no valido",100,200,5);

        indice = buscarConfederacionId(id,lista, tamConf);

        if(indice == -1)
        {
            printf("el id: %d no esta registrado\n", id);
        }
        else
        {
            mostrarConfederacion(lista[indice]);
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
                printf("Baja cancelada\n");
            }
        }
    }
    return todoOk;
}

int buscarConfederacionId(int id, eConfederaciones lista[], int tamConf)
{
    int indice = -1;
    if(lista != NULL && tamConf > 0)
    {
        for(int i = 0; i < tamConf; i++)
        {
            if(!lista[i].isEmpty && lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int modificarConfederacion(eConfederaciones vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma = 's';
    char auxCad[50];
    int auxInt;

    eConfederaciones auxConf;

    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("------------------------------------------------------------------\n");
        printf("           +++         Modificar Confederacion          +++       \n");
        printf("------------------------------------------------------------------\n");

        for(int i = 0; i <tam; i++)
        {
            if(vec[i].isEmpty == 0)
            {
                mostrarConfederacion(vec[i]);
            }
        }
        utn_getNumero(&id,"Ingrese id: ","Error, reingrese id",1,3000,5);

        indice = buscarConfederacionId(id, vec, tam);

        if(indice == -1)
        {
            printf("No existe una confederacion con el id: %d", id);
        }
        else
        {
            mostrarConfederacion(vec[indice]);
            printf("Confirma modificacion?: s/n :");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                fflush(stdin);
                switch(menuModificarConfederacion())
                {
                case 1:
                    utn_getNombre(auxCad,50,"Ingrese nombre: \n","Error, reingrese nombre\n",5);
                    strlwr(auxCad);
                    auxCad[0] = toupper(auxCad[0]);
                    strcpy(auxConf.nombre, auxCad);
                    break;
                case 2:
                    utn_getNombre(auxCad,50,"Ingrese Region: \n","Error, reingrese Region\n",5);
                    strlwr(auxCad);
                    auxCad[0] = toupper(auxCad[0]);
                    strcpy(auxConf.region, auxCad);
                    fflush(stdin);
                    break;
                case 3:
                    utn_getNumero(&auxInt,"Ingrese anio de creacion: \n","Numero no valido\n", 1, 2022, 5);
                    auxConf.anioCreacion = auxInt;
                    fflush(stdin);
                    break;
                default:
                    printf("opcion incorrecta\n");

                }
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada\n");
            }
        }
    }
    return todoOk;
}


