/*
 ============================================================================
 Name        : abmGhost.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ABMGhost.h"

#define QTY_EMPLEADOS 1000


int main(void) {
	Ghost list[QTY_EMPLEADOS];
	int out = 1;
	int id = 0;
	int assistantAdd = -1;
	int opcion = 0;
	initLugarLibre(list, QTY_EMPLEADOS);
	do {
		printf("\n"
				"1. Alta de Empleado\n"
				"2. Modificacion de Empleado\n"
				"3. Baja de Empleado\n"
				"4. Lista de Empleados\n"
				"5. Salir\n");

		getInt(&opcion, "\nIngrese la opcion\n", "\n Error\n", 1, 5, 3);
		switch (opcion) {
		case 1:
			if (addUI(list, QTY_EMPLEADOS, id) == 0) {
				assistantAdd = 0;
				break;
			}
			break;
		case 2:
			if (assistantAdd == 0) {
				modificarUI(list, QTY_EMPLEADOS);
			} else {
				printf("No existe ningun empleado para modificar\n");
			}
			break;
		case 3:
			if (assistantAdd == 0) {
				eliminarUI(list, QTY_EMPLEADOS);
			} else {
				printf("No existe ningun empleado para eliminar\n");
			}
			break;
		case 4:
			if (assistantAdd == 0) {
				//printUI(list,QTY_EMPLEADOS);
			} else {
				printf("No existe ningun empleado para mostar ni ordenar\n");
			}

			break;
		case 5:
			out = 0;
			printf("Que tenga un buen dia\n");
			break;
		default:
			printf("ERROR, la opcion es invalida\n");
			break;
		}
	} while (out);
	return EXIT_SUCCESS;
}
