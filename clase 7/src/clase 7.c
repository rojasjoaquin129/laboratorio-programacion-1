/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h> /* libreria del purge*/
#define QTY_NOMBRES 5
#define QTY_CARACTERES 50

int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos);
int getString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos);
int imprimirArraySting(char aNombres[][QTY_CARACTERES], int cantidad,
		int aDNI[]);
void insercionArraystring(char array[][QTY_CARACTERES], int limite, int DNI[]);
int main(void) {
	int j;
	char aNombres[QTY_NOMBRES][QTY_CARACTERES];
	char nombres[QTY_CARACTERES];
	int dni[QTY_NOMBRES];

	for (j = 0; j < 5; j++) {
		getString(nombres, "\nNombre?:", "Error\n", 1, 49, 5);
		strcpy(aNombres[j], nombres);
		getInt(&dni[j], "\nDNI?", "Error\n", 0, 99999999, 5);
	}
		insercionArraystring(aNombres, QTY_NOMBRES, dni);
	if (imprimirArraySting(aNombres, QTY_NOMBRES, dni) != 0) {
		printf("error");
	}

}

void insercionArraystring(char array[][QTY_CARACTERES], int limite, int DNI[]) {
	int i;
	int j;
	int flagOrdeno;
	char swap[QTY_CARACTERES];
	int auxiliarDNI;
	for (i = 1; i < limite; i++) {
		j = i;
		flagOrdeno = 1;
		while (flagOrdeno != 0 && j != 0) {
			flagOrdeno = 0;
			if (strcmp(array[j - 1], array[j]) == 0) {
				if ((DNI[j - 1] - DNI[j]) > 0) {
					auxiliarDNI = DNI[j - 1];
					strcpy(swap, array[j - 1]);
					DNI[j - 1] = DNI[j];
					strcpy(array[j - 1], array[j]); /* array j = array j*/
					DNI[j] = auxiliarDNI;
					strcpy(array[j], swap); /* array j a swap*/
					flagOrdeno = 1;
				}

			}else if (strcmp(array[j - 1], array[j]) > 0) {
					strcpy(swap, array[j - 1]);
					auxiliarDNI = DNI[j - 1];
					strcpy(array[j - 1], array[j]); /* array j = array j*/
					DNI[j - 1] = DNI[j];
					strcpy(array[j], swap); /* array j a swap*/
					DNI[j] = auxiliarDNI;
					flagOrdeno = 1;
			}

			j--;
		}
	}
}

int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = -1;
	int buffer;
	do {
		printf("%s", pMensaje);
		__fpurge(stdin);
		if (scanf("%d", &buffer) == 1 && buffer >= minimo && buffer <= maximo) {
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s", pMensajeError);
		reintentos--;
	} while (reintentos >= 0);
	return retorno;
}



int imprimirArraySting(char aNombres[][QTY_CARACTERES], int cantidad,
		int aDNI[]) {
	int i;
	int retorno = -1;
	if (aNombres != NULL && cantidad > 0) {
		retorno = 0;
		for (i = 0; i < cantidad; i++) {
			printf("\n%s con el DNI :%d\n ", aNombres[i], aDNI[i]);
		}
	}
	return retorno;
}

int getString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = -1;
	char buffer[4096];
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			__fpurge(stdin);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer) - 1] = '\0';
			if (strlen(buffer) >= minimo && strlen(buffer) <= maximo) {
				strncpy(pResultado, buffer, maximo + 1);
				retorno = 0;
				break;
			}
			printf("%s\n", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}
