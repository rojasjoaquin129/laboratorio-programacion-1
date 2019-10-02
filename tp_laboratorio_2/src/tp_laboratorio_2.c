/*
 ============================================================================
 Name        : tp_laboratorio_2.c
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
#include "arrayEmployees.h"

int main(void) {
	Employee list [QTY_EMPLEADOS];
	int out=0;
	int id=0;
	int auxAdd=-1;
	int order=0;
	int opcion=0;
	initEmployees(list,QTY_EMPLEADOS);
	do{
		printf( "1. Alta de Empleado\n"
				"2. Modificación de Empleado\n"
				"3. Baja de Empleado\n"
				"4. Lista de Empleados\n"
				"5. Salir\n");

		getInt(&opcion, "Ingrese la opción\n", "Error\n", 1,5, 3);
		switch(opcion){
		case 1:
			if (AddUI(&list,QTY_EMPLEADOS,id)==0){
				auxAdd=0;
				break;
			}
			break;
		case 2:
			if(auxAdd==0){
				modificationUI(&list,QTY_EMPLEADOS);
			} else {
				printf("No existe ningún empleado para modificar\n");
			}
			break;
		case 3:
			if(auxAdd==0){
				removeUI(&list,QTY_EMPLEADOS);
			} else {
				printf("No existe ningún empleado para eliminar\n");
			}
			break;
		case 4:
			if(auxAdd==0){
				printf("¿Cómo lo desea mostrar creciente o decreciente?\n"
						"Para decreciente ingrese 1\n"
						"Para creciente ingrese 0\n");
				if (getInt(&order,"Ingrese orden (1/0)?\n","Error\n",0,1,3)==0){
					sortEmployees(list,QTY_EMPLEADOS,order);
					printEmployee(list,QTY_EMPLEADOS);
					promedioEmployee(list,QTY_EMPLEADOS);
				}else {
					printf("ERROR,dato inválido");
				}
			} else {
				printf("No existe ningún empleado para mostar ni ordenar\n");
			}

			break;
		case 5:
			out=1;
			print("Que tenga un buen día\n");
			break;
		default:
			print("ERROR, la opción es inválida\n");
			break;
		}
	}while (out);
	return EXIT_SUCCESS;
}
