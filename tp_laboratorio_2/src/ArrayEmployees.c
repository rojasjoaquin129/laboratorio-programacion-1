/*
 * employees.c
 *
 *  Created on: 28 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "utn.h"

/* \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

int findPlaceFreeEmployee(Employee *list, int len) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == STATUS_EMPTY) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */
int findEmployeeById(Employee *list, int len, int id) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == STATUS_NOT_EMPTY) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/

int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int retorno = -1;
	int index;
	if (list != NULL && len > 0) {
		index = findPlaceFreeEmployee(list, len);
		if (index >= 0) {
			strncpy(list[index].name, name, 50);
			strncpy(list[index].lastName, lastName, 50);
			list[index].id = id;
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee *list, int len, int id) {
	int retorno = -1;
	int index;
	if (list != NULL && len > 0) {
		index = findEmployeeById(list, len, id);
		if (index != -1) {
			list[index].isEmpty = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief modify a Employee by Id
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (0) if Ok
 */

int modifyEmployeeforId(Employee *list, int len, Employee item) {
	int retorno = -1;
	int index;
	if (list != NULL && len > 0) {
		index = findEmployeeById(list, len, item.id);
		if (index != -1) {
			list[index] = item;
			list[index].isEmpty = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printEmployees(Employee *list, int length) {
	int i;
	int retorno = -1;
	if (list != NULL && length > 0) {
		retorno = 0;
		printf("id     Nombre    Apellido    Salario     Sector\n");
		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == STATUS_NOT_EMPTY) {
				printf("%d -- %s -- %s -- %f -- %d \n", list[i].id,
						list[i].name, list[i].lastName, list[i].salary,
						list[i].sector);
			}

		}
	}
	return retorno;
}

int addUI(Employee *list, int len, int id) {
	Employee bList;
	int retorno = -1;
	printf("ALTA\n");
	if (findPlaceFreeEmployee(list, len) == -1) {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	} else {
		if (getString(bList.name, "Ingrese nombre\n", "Error\n", 0, 50, 3)
				!= -1) {
			if (getString(bList.lastName, "Ingrese apellido\n", "Error\n", 0,
					50, 3) == 0) {
				if (getFloat(&bList.salary,
						"Ingese salario de dicho Empleado\n", "Error\n", 1,
						10000000, 3) != -1) {
					if (getInt(&bList.sector, "Ingrese sector del Empleado\n",
							"Error\n", 1, 1000, 3) != -1) {
						id++;
						if (addEmployee(list, len, id, bList.name,
								bList.lastName, bList.salary, bList.sector)
								== 0) {
							printf("Alta exitosa\n");
							retorno = 0;
						}
					}
				}
			}
		}
	}
	if (retorno != 0) {
		printf("Error al cargar los datos\n");
	}
	return retorno;
}

int modifyUI(Employee *list, int len) {
	Employee bList;
	int idIn;
	int posicion;
	int retorno = -1;
	printf("Modificacion de Empleados\n");
	getInt(&idIn, "Ingrese el id para modificar\n", "Error\n", 0, 100000, 3);
	posicion = findEmployeeById(list, len, idIn);
	if (posicion == -1) {
		printf("Error el id no existe\n");
	} else {
		bList = list[posicion];
		printf("id     Nombre    Apellido    Salario     Sector\n");
		printf("%d -- %s -- %s -- %f -- %d \n", list[posicion].id,
				list[posicion].name, list[posicion].lastName,
				list[posicion].salary, list[posicion].sector);
		if (listForModify(bList) == 0) {
			if (modifyEmployeeforId(list, len, bList) == 0) {
				printf("Modificacion exitosa\n");
				retorno = 0;
			}
		}
	}
	if (retorno != 0) {
		printf("error al modificar los datos\n");
	}
	return retorno;
}

int listForModify(Employee item) {
	int lista;
	int retorno = -1;
	char conf;

	do {
		printf("\n"
				"1.  Modificar Nombre\n"
				"2.  Modificar Apellido\n"
				"3.  Modificar Salario\n"
				"4.  Modificar Sector\n"
				"5.  Confirmar Modificacion\n");
		getInt(&lista, "\nIngrese la opcion \n", "Error\n", 1, 5, 3);
		switch (lista) {
		case 1:
			if (getString(item.name, "Ingrese el nombre\n", "Error\n", 1, 50, 3)
					== -1) {
				printf("Error en el nombre\n");
				break;
			}

			break;
		case 2:
			if (getString(item.lastName, "Ingrese el Apellido\n", "Error", 1,
					50, 2) == -1) {
				printf("Error en el Apellido \n");
				break;
			}
			break;
		case 3:
			if (getFloat(&item.salary, "Ingrese el salario\n", "Error\n", 1,
					10000000, 3) == -1) {
				printf("Error en el salario\n");
				break;
			}
			break;
		case 4:
			if (getInt(&item.sector, "Ingrese el sector del Empleado\n",
					"Error\n", 1, 1000, 3) == -1) {
				printf("Error en el tipo\n");
				break;
			}
			break;
		case 5:
			printf("%d -- %s -- %s -- %f -- %d \n", item.id, item.name,
					item.lastName, item.salary, item.sector);
			printf("Esta seguro de la  modificacion ? S/N\n");
			getChar(&conf, "Ingrese s para confirmar la modificacion\n",
					"Error\n", 'a', 'z', 3);
			if (conf != 's' && conf != 'n') {
				printf("Error al ingresar");
			}
			if (conf == 's') {
				retorno = 0;
			}
			break;
		default:
			printf("ERROR , eleccion no corresponde \n");
			break;
		}
	} while (conf != 's' && conf != 'n');
	return retorno;
}

int removeUI(Employee *list, int len) {
	int idIn;
	int posicion;
	int retorno = -1;
	char conf;
	printf("Baja\n");
	getInt(&idIn, "Ingrese el id para dar de baja\n", "Error\n", 1, 100000, 30);
	posicion = findEmployeeById(list, len, idIn);
	if (posicion == -1) {
		printf("Error el id no existe\n");
	} else {
		printf("%d -- %s -- %s -- %f -- %d \n", list[posicion].id,
				list[posicion].name, list[posicion].lastName,
				list[posicion].salary, list[posicion].sector);
		getChar(&conf, "Ingrese s para confirmar la baja\n", "Error\n", 'a',
				'z', 2);
		if (conf == 's' || conf == 'S') {
			if (removeEmployee(list, len, idIn) == 0) {
				printf("Baja exitosa\n");
				retorno = 0;
			}
		}
	}
	if (retorno != 0) {
		printf("error  al dar el baja \n");
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee *list, int len, int order) {
	Employee swapList;
	int i;
	int retorno = -1;
	int fSwap;
	if (list != NULL && len > 0) {
		retorno = 0;
		do {
			fSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (order == 1) {
					if (strncmp(list[i].lastName, list[i + 1].lastName,
					QTY_CARACTERES) > 0) {
						fSwap = 1;
						swapList = list[i];
						list[i] = list[i + 1];
						list[i + 1] = swapList;
					} else if (strncmp(list[i].lastName, list[i + 1].lastName,
					QTY_CARACTERES) == 0
							&& list[i].sector > list[i + 1].sector) {
						fSwap = 1;
						swapList = list[i];
						list[i] = list[i + 1];
						list[i + 1] = swapList;
					}
				} else if (order == 0) {
					if (strncmp(list[i].lastName, list[i + 1].lastName,
					QTY_CARACTERES) < 0) {
						fSwap = 1;
						swapList = list[i];
						list[i] = list[i + 1];
						list[i + 1] = swapList;
					} else if (strncmp(list[i].lastName, list[i + 1].lastName,
					QTY_CARACTERES) == 0
							&& list[i].sector < list[i + 1].sector) {
						fSwap = 1;
						swapList = list[i];
						list[i] = list[i + 1];
						list[i + 1] = swapList;
					}
				}
			}
		} while (fSwap);
	}
	return retorno;
}
int averageEmployees(Employee *list, int length) {
	int i;
	float acumulador = 0;
	float promedio = 0;
	int contador = 0;
	int retorno = -1;
	int contadorSuperaPromedio = 0;
	if (list != NULL && length > 0) {
		retorno = 0;
		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == STATUS_NOT_EMPTY) {
				acumulador = list[i].salary + acumulador;
				contador++;
			}
		}
		promedio = (float) acumulador / contador;
		for (i = 0; i < length; i++) {
			if (list[i].isEmpty == STATUS_NOT_EMPTY) {
				if (promedio <= list[i].salary) {
					contadorSuperaPromedio++;
				}
			}
		}
		printf(
				"El total de todo los salarios es  %f \n El promedio de salario es %f \n",
				acumulador, promedio);
		printf(
				"La cantidad de empleados q supera el promedio de salario es de %d  personas\n",
				contadorSuperaPromedio);
	}
	return retorno;
}


int printUI(Employee* list,int len){
	int retorno=-1;
	int opcion;
	int order;
	printf("1. Listado de los empleados ordenados"
			" alfabéticamente por Apellido y Sector.\n"
			"2. Total y promedio de los salarios, y "
			"cuántos empleados superan el salario promedio.\n");
	getInt(&opcion, "Ingrese opcion (1/2)?\n", "Error\n", 1, 2, 3);
	switch (opcion) {
	case 1:
		printf("Como lo desea mostrar creciente o decreciente?\n"
				"Para decreciente ingrese 1\n"
				"Para creciente ingrese 0\n");
		if (getInt(&order, "Ingrese orden (1/0)?\n", "Error\n", 0,
				1, 3) == -1) {
			printf("opcion incorrecta\n");
			break;
		}
		sortEmployees(list, len, order);
		printEmployees(list,len);
		retorno=0;
		break;
	case 2:
		averageEmployees(list,len);
		retorno=0;
		break;
	default:
		printf("ERROR,opcion invalida\n");
		break;
	}
return retorno;
}
