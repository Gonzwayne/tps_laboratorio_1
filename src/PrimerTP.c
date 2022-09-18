#include <stdio.h>
#include <stdlib.h>
void mostrarMenu(int *pOpciones, int acumHospedaje, int acumComida,
		int acumTransporte, int contArquero, int contDefensor,
		int contMediocampista, int contDelantero);
int confirmarSalida(char *pControl);
int main(void)

{
	setbuf(stdout, NULL);

	char salir;
	int opcion;
	int flagUno;
	int flagDos;
	int flagTres;
	int acumHospedaje;
	int acumComida;
	int acumTransporte;
	int hospedaje;
	int comida;
	int transporte;
	int opcUno;
	int opcDos;
	int opcTres;
	int camiseta;
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
	acumHospedaje = 0;
	acumComida = 0;
	acumTransporte = 0;
	flagTres = 0;
	flagDos = 0;
	flagUno = 0;
	salir = 'n';

	do {
		mostrarMenu(&opcion, acumHospedaje, acumComida, acumTransporte,
				contArquero, contDefensor, contMediocampista, contDelantero);

		switch (opcion) {
		case 1:
			printf("Ingrese una opcion\n");
			printf("1- hospedaje\n");
			printf("2- comida\n");
			printf("3- transporte\n");
			fflush(stdin);
			scanf("%d", &opcUno);

			switch (opcUno) {
			case 1:
				printf("Ingrese costo de hospedaje\n");
				fflush(stdin);
				scanf("%d", &hospedaje);
				acumHospedaje = acumHospedaje + hospedaje;
				break;
			case 2:
				printf("Ingrese costo de comida\n");
				fflush(stdin);
				scanf("%d", &comida);
				acumComida = acumComida + comida;
				break;
			case 3:
				printf("Ingrese costo de transporte\n");
				fflush(stdin);
				scanf("%d", &transporte);
				acumTransporte = acumTransporte + transporte;
				break;

			}

			flagUno = 1;
			break;
		case 2:
			if (flagUno == 1) {

				printf("Ingrese una opcion\n");
				printf("1- arquero\n");
				printf("2- defensor\n");
				printf("3- mediocampista\n");
				printf("4- delantero\n");
				fflush(stdin);
				scanf("%d", &opcDos);

				switch (opcDos) {
				case 1:

					if (contArquero > 1) {
						printf("Supero cantidad de arqueros\n");
					} else {
						contArquero++;
					}

					break;
				case 2:
					if (contDefensor > 7) {
						printf("Supero cantidad de Defensores\n");
					} else {
						contDefensor++;
					}

					break;
				case 3:
					if (contMediocampista > 7) {
						printf("Supero cantidad de mediocampistas\n");
					} else {
						contMediocampista++;
					}

					printf("Ingrese numero de camiseta");
					fflush(stdin);
					scanf("%d",&camiseta);
					printf("Ingrese confederacion");
					printf("1- AFC 2- CAF 3- CONCACAF 4- CONMEBOL 5- UEFA 6- OFC");
					fflush(stdin);
					scanf("%d",&opcTres);
					switch(opcTres)
					{
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
							contOFC++; //aca deje ayer
					break;
					}

					break;
				case 4:

					if (contDelantero > 3) {
						printf("Supero cantidad de delanteros\n");
					} else {
						contDelantero++;
					}
					break;

				}
				flagDos = 1;
			} else {
				printf("Debe completar opcion 1 primero\n");
			}
			break;
		case 3:
			if (flagDos == 1) {
				printf("Usted ingreso opcion 3\n");
				flagTres = 1;
			} else {
				printf("Primero debe completar opcion 1 y 2\n");
			}
			break;
		case 4:
			if (flagTres == 1) {
				printf("Usted ingreso opcion 4\n");
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
		}

		system("pause");
	} while (salir == 'n');

	return 0;
}

int confirmarSalida(char *pControl) {
	int todoOK = 0;
	char confirma;
	if (pControl != NULL) {
		printf("confirmar salir s o n?");
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
	printf("Ingrese Una Opcion:");
	fflush(stdin);
	scanf("%d", pOpciones);
}
