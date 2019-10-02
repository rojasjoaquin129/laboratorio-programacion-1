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
	Employee bList;
	int id=0;
	int idIn;
	int posicion;
	int opcion=0;
	initEmployees(list,QTY_EMPLEADOS);
	do{
		printf( "1. Alta de Empleado\n"
				"2. Modificacion de Empleado\n"
				"3. Baja de Empleado\n"
				"4. listar\n"
				"5. Modificar publicidad\n"
				"7. Mostrar costo de contrataciones de un cliente\n"
				"9. Listado de pantallas\n"
				"0. Salir\n");

		getInt(&opcion, "Ingrese la opcion\n", "Error\n", 1,5, 3);
		switch(opcion){
		case 1:
			altaUI(&list,QTY_EMPLEADOS,id);
			break;
		case 2:
			modificacionUI(&list,QTY_EMPLEADOS);
			break;
		case 3:
			bajaUI(list,QTY_EMPLEADOS);
			break;
		case 4:
			imprimirUI(list,QTY_EMPLEADOS);
			break;
		case 5:
			break;
		}
	}while (orden=5);
	return EXIT_SUCCESS;
}
