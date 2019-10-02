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


int findPlaceFreeEmployee(Employee *list, int len){
	int retorno = -1;
	int i;
	if(list != NULL && len > 0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == STATUS_EMPTY){
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
		index = findPlaceFreeEmployee(list, len);
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

int modifyEmployeeforId(Employee* list, int len,Employee* item){
	int retorno = -1;
	int index;
	if(list!=NULL && len>0){
		index = findEmployeeById(list, len, item.id);
		if(index!=-1){
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

int printEmployees(Employee* list, int length){
	int i;
	int retorno = -1;
	if(list != NULL && length>0)
	{
		retorno = 0;
		printf("id     Nombre    Apellido    Salario     Sector\n");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == STATUS_NOT_EMPTY){
				printf("%d -- %s -- %s -- %f -- %d \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}

		}
	}
	return retorno;
}


int altaUI(Employee *list,int len,int id)
{
	Employee bList;
	int retorno=-1;
	printf("ALTA");
	if(findPlaceFreeEmployee(list,len)==-1){
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	}else{
		if(getString(bList.name,"ingrese nombre\n","Error\n",0,50,3)!=-1){
			if(getstring(bList.lastName,"ingrese apellido","Error\n",0,50,3)!=-1){
				if(getFloat(&bList.salary,"ingese salario de dicho Empleado\n","Error\n",0,50,3)!=-1){
					if(getInt(&bList.sector,"ingrese sector del Empleado\n","Error\n",0,50,3)!=-1){
						id++;
						if(addEmployee(list,len,id,bList.name,bList.lastName,bList.salary,bList.sector)==0){
							printf("Alta exitosa");
							retorno=0;
						}
					}
				}
			}
		}
	}
	if(retorno!=0){
		printf("error al cargar los datos\n");
	}
	return retorno;
}

int modificacionUI(Employee* list,int len){
	Employee bList;
	int idIn;
	int posicion;
	int retorno=-1;
	printf("Modificacion de Empleados\n");
	getInt(&idIn,"Ingrese el id para modificar\n","Error\n",0,100000,3)
	posicion=findEmployeeById(list,len,idIn);
			if (posicion == -1) {
					printf("Error el id no existe\n");
				}else{
					bList=list[posicion];
					printf("%d -- %s -- %s -- %f -- %d \n",list[posicion].id,list[posicion].name,list[posicion].lastName,list[posicion].salary,list[posicion].sector);
					if(listForModify(bList)==0){
						if (modifyEmployeeforId(list,len, bList) == 0) {
							printf("Modificacion exitosa\n");
							retorno=0;
						}
					}
				}
	if(retorno!=0){
		printf("error al modificar los datos\n");
	}
return retorno;
}

int listForModify(Employee* item){
	int lista;
	int retorno=-1;
	char conf;

	do {
		printf("1.  Modificar Nombre\n"
			   "2.  Modificar Apellido\n"
			   "3.  Modificar Salario\n"
			   "4.  Modificar Sector\n"
			   "5.  Confirmar Modificacion\n");
		getInt(&lista, "Ingrese la opcion \n", "Error\n",1, 5, 3);
		switch(lista){
			case 1:
				if (getString(item->name,"Ingrese el nombre\n", "Error\n", 1,
												50, 2) == -1) {
					printf("Error en el nombre\n");
					break;
			}

			break;
			case 2:
				if (getString(item->lastName, "Ingrese el Apellido\n",
						"Error", 1, 50, 2) == -1) {
					printf("Error en el Apellido \n");
					break;
				}
			break;
			case 3:
				if (getFloat(&item->salary, "Ingrese el salario\n", "Error\n", 0,
						1000000, 2) == -1) {
					printf("Error en el salario\n");
					break;
				}
			break;
			case 4:
				if (getInt(&item->sector, "Ingrese el sector del Empleado\n", "Error\n",1, 1000, 3) == -1) {
					printf("Error en el tipo\n");
					break;
			}
			break;
			case 5:
				printf("%d -- %s -- %s -- %f -- %d \n",item->id,item->name,item->lastName,item->salary,item->sector);
				printf("esta seguro de la  modificacion ? S/N");
				getChar(&conf,"Ingrese s para confirmar la modificacion\n","Error\n",'a', 'z', 3);
				if(conf=='s'){
					retorno=0;
				}
				break;
			default:
				printf("ERROR , eleccion no corresponde ");
				break;
		}
	}while(conf!='s');
return retorno;
}


int bajaUI(Employee* list,int len){
	int idIn;
	int posicion;
	int retorno=-1;
	char conf;
	printf("Baja\n");
	getInt(&idIn,"Ingrese el id para dar de baja\n","Error\n",1,100000,30);
	posicion=findEmployeeById(list,len,idIn);
	if (posicion == -1) {
		printf("Error el id no existe\n");
		}else{
			printf("%d -- %s -- %s -- %f -- %d \n",list[posicion].id,list[posicion].name,list[posicion].lastName,list[posicion].salary,list[posicion].sector);
			getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
			if(conf=='s'|| conf=='S'){
				if(removeEmployee(list,len,idIn)==0){
					printf("Baja exitosa\n");
					retorno=0;
				}
			}
		}
	if(retorno!=0){
		printf("error  al dar el baja ");
	}
return retorno;
}

int sortEmployees(Employee* list, int len, int order){
	Employee swapList;
	int i;
	int retorno = -1;
	int fSwap;
	char pregunta;
	if(list != NULL && len>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if (order==1){
					if(strncmp(list[i].lastName,list[i+1].lastName,QTY_CARACTERES)>0){
						fSwap = 1;
						swapList=list[i];
						list[i]=list[i+1];
						list[i+1]=swapList;
					}else if(strncmp(list[i].lastName,list[i+1].lastName,QTY_CARACTERES)==0 &&
						strncmp(list[i].sector,list[i+1].sector,QTY_CARACTERES)>0){
						fSwap = 1;
						swapList=list[i];
						list[i]=list[i+1];
						list[i+1]=swapList;
					}
				}else if(order=0){
					if(strncmp(list[i].lastName,list[i+1].lastName,QTY_CARACTERES)<0){
						fSwap = 1;
						swapList=list[i];
						list[i]=list[i+1];
						list[i+1]=swapList;
					}else if(strncmp(list[i].lastName,list[i+1].lastName,QTY_CARACTERES)==0 &&
						strncmp(list[i].sector,list[i+1].sector,QTY_CARACTERES)<0){
						fSwap = 1;
						swapList=list[i];
						list[i]=list[i+1];
						list[i+1]=swapList;
					}
				}
				}
		}while(fSwap);
	}
	return retorno;
}
int promedioEmployees(Employee* list, int length){
	int i;
	float acumulador=0;
	float promedio=0;
	int contador=0;
	int retorno = -1;
	int contadorSuperaPromedio=0;
	if(list != NULL && length>0)
	{
		retorno = 0;
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == STATUS_NOT_EMPTY){
				acumulador=list[i].salary+acumulador;
				contador++;
			}
		}
		promedio=(float)acumulador/contador;
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty == STATUS_NOT_EMPTY){
				if (promedio<list[i].salary){
					contadorSuperaPromedio++;
				}
			}
		}
		printf("El total de todo los salarios es  %f \n El promedio de salario es %f \n",acumulador,promedio);
		printf("La cantidad de empleados q supera el promedio de salario es de %d  personas\n",contadorSuperaPromedio);
	}
	return retorno;
}
