#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"

int main(void)

{
	setbuf(stdout, NULL);

	//banderas
	char salir;
	int flagUno;
	int flagDos;
	int flagTres;
	//acumuladores
	int acumHospedaje;
	int acumComida;
	int acumTransporte;

	//
	int costoMantenimiento;
	int aumentoDeCosto;
	int costoMasAumento;

	int hospedaje;
	int comida;
	int transporte;
	//menu de opciones
	int opcion;
	int opcGasto;
	int opcPosicion;
	int opcConfederacion;
	int camiseta;
	//contadores
	int contArquero;
	int contDefensor;
	int contMediocampista;
	int contDelantero;
	int contAFC;
	int contCAF;
	int contCONCACAF;
	int contCONMEBOL;
	int contUEFA;
	int contOFC;
	int contJugadores;
	//promedios
	float promedioAFC;
	float promedioCAF;
	float promedioCONCACAF;
	float promedioCONMEBOL;
	float promedioUEFA;
	float promedioOFC;

	//contadores
	contAFC = 0;
	contCAF = 0;
	contCONCACAF = 0;
	contCONMEBOL = 0;
	contUEFA = 0;
	contOFC = 0;
	contArquero = 0;
	contDefensor = 0;
	contMediocampista = 0;
	contDelantero = 0;
	contJugadores = 0;
	//acumuladores
	acumHospedaje = 0;
	acumComida = 0;
	acumTransporte = 0;

	//banderas
	flagTres = 0;
	flagDos = 0;
	flagUno = 0;
	salir = 'n';

	do {
		system("cls");
		mostrarMenu(&opcion, acumHospedaje, acumComida, acumTransporte,
				contArquero, contDefensor, contMediocampista, contDelantero);
		system("cls");
		switch (opcion) {
		case 1:
			getInt(&opcGasto,"Ingrese una opcion de gasto\n1- hospedaje\n2- comida\n3- transporte\n",0, 4);
			system("cls");
			switch (opcGasto) {
			case 1:
				getInt(&hospedaje,"ingrese costo de hospedaje\n", 0,999999999);
				fflush(stdin);
				acumHospedaje = acumHospedaje + hospedaje;
				break;
			case 2:
				getInt(&comida,"ingrese costo de comida\n", 0,999999999);
				fflush(stdin);
				acumComida = acumComida + comida;
				break;
			case 3:
				getInt(&transporte,"ingrese costo de transporte\n", 0,99999999);
				fflush(stdin);
				acumTransporte = acumTransporte + transporte;
				break;
			default:
				printf("No es una opcion valida\n");
				break;

			}

			flagUno = 1;
			break;
		case 2:
			if (flagUno == 1) {
				contJugadores++;
				getInt(&opcPosicion,"Ingrese la posicion del jugador\n1- arquero\n2- defensor\n3- mediocampista\n4- delantero\n",0, 4);
				system("cls");
				switch (opcPosicion) {
				case 1:
					if (contArquero == 2) {
						printf("Supero cantidad de arqueros\n");
					} else {
						contArquero++;
						getInt(&camiseta,
								"Ingrese numero de camiseta del jugador \n", 0,99);
						getInt(&opcConfederacion,"Ingrese confederacion del jugador \n1- AFC\n 2- CAF\n 3- CONCACAF\n 4- CONMEBOL\n 5- UEFA\n 6- OFC\n,",0, 6);
						system("cls");
					}
					break;
				case 2:
					if (contDefensor == 8) {
						printf("Supero cantidad de Defensores\n");
					} else {
						contDefensor++;
						getInt(&camiseta,
								"Ingrese numero de camiseta del jugador \n", 0,99);
						getInt(&opcConfederacion,"Ingrese confederacion del jugador \n1- AFC\n 2- CAF\n 3- CONCACAF\n 4- CONMEBOL\n 5- UEFA\n 6- OFC\n,",0, 6);
						system("cls");
					}
					break;
				case 3:
					if (contMediocampista == 8) {
						printf("Supero cantidad de mediocampistas\n");
					} else {
						contMediocampista++;
						getInt(&camiseta,
								"Ingrese numero de camiseta del jugador \n", 0,99);
						getInt(&opcConfederacion,"Ingrese confederacion del jugador \n1- AFC\n 2- CAF\n 3- CONCACAF\n 4- CONMEBOL\n 5- UEFA\n 6- OFC\n,",0, 6);
						system("cls");
					}
					break;
				case 4:
					if (contDelantero == 4) {
						printf("Supero cantidad de delanteros\n");
					} else {
						contDelantero++;
						getInt(&camiseta,
								"Ingrese numero de camiseta del jugador \n", 0,99);
						getInt(&opcConfederacion,
								"Ingrese confederacion del jugador \n1- AFC\n 2- CAF\n 3- CONCACAF\n 4- CONMEBOL\n 5- UEFA\n 6- OFC\n,",0, 6);
						system("cls");
					}
					break;
				default:
					printf("No es una opcion valida\n");
					break;
				}
				flagDos = 1;
				switch (opcConfederacion) {
				case 1:
					contAFC++;
					break;
				case 2:
					contCAF++;
					break;
				case 3:
					contCONCACAF++;
					break;
				case 4:
					contCONMEBOL++;
					break;
				case 5:
					contUEFA++;
					break;
				case 6:
					contOFC++;
					break;
				default:
					printf("No es una opcion valida\n");
					break;
				}
			} else {
				printf("Debe completar opcion 1 primero\n");
			}
			break;
		case 3:
			if (flagDos == 1) {
				printf("Usted ingreso opcion 3 realizar calculos \n");
				promedioAFC = (float) contAFC / contJugadores;
				promedioCAF = (float) contCAF / contJugadores;
				promedioCONCACAF = (float) contCONCACAF / contJugadores;
				promedioCONMEBOL = (float) contCONMEBOL / contJugadores;
				promedioUEFA = (float) contUEFA / contJugadores;
				promedioOFC = (float) contOFC / contJugadores;
				costoMantenimiento = acumHospedaje + acumComida
						+ acumTransporte;
				printf("Los calculos se realizaron correctamente\n Ingrese a la opcion 4 para ver los resultados\n");
				flagTres = 1;
			} else {
				printf("Primero debe completar opcion 1 y 2\n");
			}
			break;
		case 4:
			if (flagTres == 1) {
				printf("Usted ingreso opcion 4 mostrar resultados \n");
				printf("Promedio = AFC %.2f\n", promedioAFC);
				printf("Promedio = CAF %.2f\n", promedioCAF);
				printf("Promedio = CONCACAF %.2f\n", promedioCONCACAF);
				printf("Promedio = CONMEBOL %.2f\n", promedioCONMEBOL);
				printf("Promedio = UEFA %.2f\n", promedioUEFA);
				printf("Promedio = OFC %.2f\n", promedioOFC);

				if (contUEFA > contJugadores / 2) {
					aumentoDeCosto = costoMantenimiento * 0.35;
					costoMasAumento = costoMantenimiento + aumentoDeCosto;
					printf(
							"El costo de mantenimiento era de %d y recibio un aumento de %d, su nuevo valor es de %d\n",
							costoMantenimiento, aumentoDeCosto,
							costoMasAumento);
				} else {
					printf(
							"El costo de mantenimiento es de %d y no recibio ningun aumento\n",
							costoMantenimiento);
				}
				flagUno = 0;
				flagDos = 0;
				flagTres = 0;
			} else {
				printf("Primero debe completar opcion 1 2 y 3\n");
			}
			break;
		case 5:
			printf("Usted ingreso opcion 5 salir\n");
			confirmarSalida(&salir);
			if (salir == 's') {
				printf("Usted salio del programa, Hasta pronto\n");
			}
			break;
		default:
			printf("No es una opcion valida\n");
			break;
		}
		system("pause");
	} while (salir == 'n');
	return 0;
}

