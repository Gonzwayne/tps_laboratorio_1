
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "inputconvalidaciones.h"
#include "informes.h"
#include "menus.h"




int mostrarJugadoresConfederaciones(eJugador vec[], int tam, eConfederaciones listaConf[], int tamConfederacion)
{
    int todoOk = 0;
    int idConfederacion;
    if(vec != NULL && tam > 0 && listaConf != NULL && tamConfederacion > 0)
    {
        system("cls");
        printf("    *** Informacion de Confederaciones ***\n");
        mostrarConfederaciones(listaConf, tamConfederacion);
        utn_getNumero(&idConfederacion,"Ingrese una Opcion: \n","Error, reingrese id confe\n",100,110,5);

        mostrarJugadoresIdConfederaciones(idConfederacion, vec, tam, listaConf, tamConfederacion);

        todoOk = 1;
    }
    return todoOk;
}

int mostrarPromedioDeSalarios(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion)
{
    int todoOk = 0;
    int contador = 0;
    float AcumSalario  = 0;
    float promedio;
    int masDelPromedio = 0;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConfederacion >0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 )
            {
                AcumSalario+=lista[i].salario;
                contador++;
            }
        }
        promedio = AcumSalario / contador;

        if(contador == 0)
        {
            printf("No hay salarios para mostrar\n");
        }
        else
        {
            promedio = AcumSalario / contador;
            printf("El promedio de salarios es: $%.2f\n", promedio);
        }
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].salario > promedio)
            {
                masDelPromedio++;
            }
        }
        printf("La cantidad de jugadores que superan el salario promedio son: %d\n", masDelPromedio);

        todoOk = 1;
    }
    return todoOk;
}


int mostrarTotalDeSalarios(eJugador lista[], int tam)
{
    int todoOk = 0;
    float AcumSalario  = 0;
    int contador = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                AcumSalario+=lista[i].salario;
                contador++;
            }
        }
        if(contador == 0)
        {
            printf("No hay salarios para mostrar\n");
        }
        else
        {
            printf("El total de salarios es: $%.2f\n", AcumSalario);
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarJugadoresIdConfederaciones(int idConfe, eJugador vec[], int tam, eConfederaciones listaConf[], int tamConfederacion)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && listaConf != NULL && tamConfederacion > 0)
    {
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("|  ID  |       Nombre        |      Posicion      | N° Camiseta |      Sueldo    |   Confederacion  | Contrato | \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i <tam; i++)
        {
            if(vec[i].isEmpty == 0 && vec[i].idConfederacion == idConfe)
            {
                mostrarJugador(vec[i], vec, tam, listaConf, tamConfederacion);
            }
        }
        printf("----------------------------------------------------------------------------------------------------------------\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarInformes(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConfederacion > 0)
    {
        switch(menuInformes())
        {
        case 1:
            mostrarJugadores(lista, tam, listaConf, tamConfederacion);
            break;
        case 2:
            mostrarJugadoresConfederaciones(lista, tam,listaConf,tamConfederacion);
            break;
        case 3:
            mostrarTotalDeSalarios(lista,tam);
            mostrarPromedioDeSalarios(lista, tam, listaConf, tamConfederacion);
            break;
        case 4:
            mostrarConfederacionMayorContratos(lista, tam, listaConf, tamConfederacion);
            break;
        case 5:
            mostrarRegionMayorJugadores(lista, tam,listaConf,tamConfederacion);
            break;
        case 6:
            porcentajeJugadoresPorConf(lista,tam,listaConf,tamConfederacion);
            break;
        case 7:
            break;
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarConfederacionMayorContratos(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion)
{
    int todoOk = 0;
    int maximo;
    int contadores[] = {0,0,0,0,0,0};
    int flag = 0;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConfederacion > 0)
    {
        system("cls");
        printf("    *** confederacion con mas contratos ***\n");
        for(int i = 0; i < tamConfederacion; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idConfederacion == listaConf[i].id)
                {
                    contadores[i]+= lista[j].aniosContrato;
                }
            }
        }
        for(int i = 0; i < tamConfederacion; i++)
        {
            if(flag == 0 || contadores[i] > maximo)
            {
                maximo = contadores[i];
                flag = 1;
            }
        }
        for(int i = 0; i < tamConfederacion; i++)
        {
            if(contadores[i] == maximo)
            {
                printf("%s\n", listaConf[i].nombre);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarRegionMayorJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConfederacion)
{
    int todoOk = 0;
    int maximo;
    int contadores[] = {0,0,0,0,0,0};
    int flag = 0;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConfederacion > 0)
    {
        system("cls");
        printf("    *** Region con mas jugadores ***\n");
        for(int i = 0; i < tamConfederacion; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idConfederacion == listaConf[i].id)
                {
                    contadores[i]++;
                }
            }
        }
        for(int i = 0; i < tamConfederacion; i++)
        {
            if(flag == 0 || contadores[i] > maximo)
            {
                maximo = contadores[i];
                flag = 1;
            }
        }
        for(int i = 0; i < tamConfederacion; i++)
        {
            if(contadores[i] == maximo)
            {
                printf("%s\n", listaConf[i].region);
                mostrarJugadoresIdConfederaciones(listaConf[i].id,lista,tam,listaConf,tamConfederacion);

            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int porcentajeJugadoresPorConf(eJugador lista[],int tam,eConfederaciones listaConf[],int tamConfederacion)
{
	int todoOk = 0;
	int contador = 0;
	int jugadoresConmebol = 0;
	int jugadoresUefa = 0;
	int jugadoresConcacaf = 0;
	int jugadoresOfc = 0;
	int jugadoresCaf = 0;
	int jugadoresAfc = 0;
	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeConcacaf;
	float porcentajeOfc;
	float porcentajeCaf;
	float porcentajeAfc;

	if(lista != NULL && tam > 0 && listaConf != NULL&& tamConfederacion > 0)
        {
            for(int i = 0; i < tam; i++)
            {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].idConfederacion == 103)
                {
                    jugadoresConmebol++;
                }
                if(lista[i].idConfederacion == 105)
                {
                    jugadoresUefa++;
                }
                if(lista[i].idConfederacion == 100)
                {
                    jugadoresAfc++;
                }
                if(lista[i].idConfederacion == 101)
                {
                    jugadoresCaf++;
                }
                if(lista[i].idConfederacion == 102)
                {
                    jugadoresConcacaf++;
                }
                if(lista[i].idConfederacion == 104)
                {
                    jugadoresOfc++;
                }
                contador++;
                }
		}
    porcentajeConmebol = (float) jugadoresConmebol*100/contador;
	porcentajeUefa =(float) jugadoresUefa*100/contador;
	porcentajeConcacaf =(float) jugadoresConcacaf*100/contador;
	porcentajeOfc =(float) jugadoresOfc*100/contador;
	porcentajeCaf =(float) jugadoresCaf*100/contador;
	porcentajeAfc =(float) jugadoresAfc*100/contador;

    printf("----------------------------------------\n");
    printf("Confederacion| Porcentaje Dd Jugadores |\n");
    printf("----------------------------------------\n");
	printf("CONMEBOL      |%5.2f\n", porcentajeConmebol);
	printf("UEFA          |%5.2f\n", porcentajeUefa);
	printf("AFC           |%5.2f\n", porcentajeAfc);
	printf("CAF           |%5.2f\n", porcentajeCaf);
	printf("CONCACAF      |%5.2f\n", porcentajeConcacaf);
	printf("OFC           |%5.2f\n", porcentajeOfc);
	printf("----------------------------------------\n");
	}

	return todoOk;
}
