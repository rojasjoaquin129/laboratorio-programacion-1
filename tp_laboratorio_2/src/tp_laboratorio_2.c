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
#include "employees.h"

int main(void) {
	Employee list [QTY_EMPLEADOS];
	int salir=0;
	int id=0;
	int alta=-1;
	int opcion=0;
	initEmployees(list,QTY_EMPLEADOS);
	do{
		printf( "1. Alta de Empleado\n"
				"2. Modificacion de Empleado\n"
				"3. Baja de Empleado\n"
				"4. lista de Empleados\n"
				"5. Salir\n");

		getInt(&opcion, "Ingrese la opcion\n", "Error\n", 1,5, 3);
		switch(opcion){
		case 1:
			if (altaUI(&list,QTY_EMPLEADOS,id)==0){
				alta=0;
				break;
			}
			break;
		case 2:
			if(alta==0){
				modificacionUI(&list,QTY_EMPLEADOS);
			} else {
				printf("no existe ningun empleado para modificar\n");
			}
			break;
		case 3:
			if(alta==0){
				bajaUI(&list,QTY_EMPLEADOS);
			} else {
				printf("no existe ningun empleado para eliminar\n");
			}
			break;
		case 4:
			if(alta==0){
				ordenarEmployee(list,QTY_EMPLEADOS);
				printEmployee(list,QTY_EMPLEADOS);
				promedioEmployee(list,QTY_EMPLEADOS);
			} else {
				printf("no existe ningun empleado para mostar ni ordenar\n");
			}

			break;
		case 5:
			salir=1;
			print("que tenga un buen dia\n");
			break;
		default:
			print("ERROR, la opcion invalida\n");
			break;
		}
	}while (salir);
	return EXIT_SUCCESS;
}
