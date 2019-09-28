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
#include "utn.h"
#include "employees.h"

static int generarId(void){
	static int id = 0;
	id++;
	return id;
}

/* \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(Employee* list, int len){
	int i;
	int retorno = -1;
	if(list != NULL && len > 0){
		for(i=0;i<len;i++){
			list[i].isEmpty = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}


int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad){
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].status == STATUS_EMPTY){
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
int findEmployeeById(Employee* list,, int len,int id){
	int retorno = -1;
	int i;
	if(list!=NULL && len > 0 ){
		for(i=0;i<len;i++){
			if(list[i].id == id && list[i].isEmpty == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int retorno = -1;
	int index;
	if(list!=NULL && len>0){
		index = buscarLugarLibrePantalla(list, len);
		if(index>=0){
		strncpy(list[index].name,name,50);
		strncpy(list[index].lastName,lastName,50);
		list[index].id=id;
		list[index].salary=salary;
		list[index].sector=sector;
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
int removeEmployee(Employee* list, int len,int id){
	int retorno = -1;
	int index;
	if(list!=NULL && len > 0){
		index = findEmployeeById(list, len, id);
		if(index != -1){
			list[index].isEmpty = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

int modificarEmpleadoPorId(Employee* aArray, int cantidad,Employee* item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarPantallaPorId(aArray, cantidad, item.id);
		if(index!=-1){
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
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

int printEmployees(Employee* list, int length){
	int i;
	int retorno = -1;
	if(list != NULL && length>0)
	{
		retorno = 0;
		printf("id     Nombre    Direccion    Precio     Tipo\n");
		for(i=0;i<list;i++)
		{
			if(list[i].isEmpty == STATUS_NOT_EMPTY){
				printf("%d -- %s -- %s -- %f -- %d \n",list[i].id,list[i].name,list[i].lastname,list[i].precio,list[i].tipo);
			}

		}
	}
	return retorno;
}


