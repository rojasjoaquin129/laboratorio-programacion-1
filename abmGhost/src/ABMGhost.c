/*
 * ABM.c
 *
 *  Created on: 8 oct. 2019
 *      Author: joaquin
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ABMGhost.h"

/** \brief Genera un id autoincremental
* \return int
*
*/
static int generarId(void){
	static int id = 0;
	id++;
	return id;
}



/** \brief Ordena los elementos en el array, el argumento order indica
* ascendente o descendente
*
* \param list dGen*
* \param len int
* \param order int [1] ascendente - [0] descendente
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL o order distinto de 1 o 0] - (0) si Ok
*
*/
int OrdenarArray(Ghost* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	int flagOrdeno;
	Ghost swap;

	if(list!=NULL && len>0 && (order == 1 || order == 0))
	{
		retorno = 0;
		for(i=1; i<len; i++){
			j=i;
			flagOrdeno = 1;
			while(flagOrdeno != 0 && j!=0){
				flagOrdeno = 0;
				if((order && ((list[j-1].status == STATUS_EMPTY && list[j].status == STATUS_NOT_EMPTY) ||
							(strncmp(list[j-1].nombre, list[j].nombre,51)>0) ||
							(strncmp(list[j-1].nombre, list[j].nombre,51)==0 && list[j-1].precio > list[j].precio)))
						||
				   (!order && ((list[j-1].status == STATUS_EMPTY && list[j].status == STATUS_NOT_EMPTY) ||
							(strncmp(list[j-1].nombre, list[j].nombre,51)<0) ||
							(strncmp(list[j-1].nombre, list[j].nombre,51)==0 && list[j-1].precio < list[j].precio)))
				){
					swap = list[j-1];
					list[j-1] = list[j];
					list[j] = swap;
					flagOrdeno = 1;
				}
				j--;
			}
		}
	}
	return retorno;
}

/** \brief Imprime los elementos en el array.
*
* \param list dGen*
* \param len int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int ImprimirArray(Ghost *list, int len)
{
	int i;
	int retorno = -1;
	if(list != NULL && len>0)
	{
		retorno = 0;
		printf("id     Nombre    Direccion    Precio     Tipo\n");
		for(i=0;i<len;i++)
		{
			if(list[i].status == STATUS_NOT_EMPTY){
				printf("%d -- %s -- %s -- %f -- %d \n",list[i].id,list[i].nombre,list[i].direccion,list[i].precio,list[i].tipo);
			}

		}
	}
	return retorno;
}

/** \brief inicializa con espacio vacio los elementos en el array.
*
* \param list dGen*
* \param len int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int InitLugarLibre(Ghost *list, int len)
{
	int i;
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].status = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Busca espacio vacio entre los elementos del array.
*
* \param list dGen*
* \param len int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (primer espacio libre) si Ok
*
*/
int BuscarLugarLibre(Ghost *list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].status == STATUS_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Busca por id entre los elementos en el array.
*
* \param list dGen*
* \param len int
* \param id int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (posicion del id) si Ok
*
*/
int BuscarPorId(Ghost *list, int len,int id)
{
	int retorno = -1;
	int i;
	if(list!=NULL && len > 0 )
	{
		for(i=0;i<len;i++){
			if(list[i].id == id && list[i].status == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Genera un alta con un id automatico.
*
* \param list dGen*
* \param len int
* \param item dGen
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int AltaPorId(Ghost *list, int len, Ghost item)
{
	int retorno = -1;
	int index;
	if(list!=NULL && len>0)
	{
		index =BuscarLugarLibre(list, len);
		if(index>=0)
		{
			list[index] = item;
			list[index].status = STATUS_NOT_EMPTY;
			list[index].id = generarId();
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Da una baja logica por id.
*
* \param list dGen*
* \param len int
* \param id int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int BajaPorId(Ghost *list, int len,int id)
{
	int retorno = -1;
	int index;
	if(list!=NULL && len > 0)
	{
		index =BuscarPorId(list, len, id);
		if(index != -1){
			list[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Hace una modificacion por id.
*
* \param list dGen*
* \param len int
* \param item dGen
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int ModificarPorId(Ghost *list, int len,Ghost item)
{
	int retorno = -1;
	int index;
	if(list!=NULL && len>0)
	{
		index = BuscarPorId(list, len, item.id);
		if(index!=-1)
		{
			list[index] = item;
			list[index].status = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/*
int printEmployees(Ghost *list, int length) {
	int i;
	int retorno = -1;
	if (list != NULL && length > 0) {
		retorno = 0;
		printf("id     Nombre    Apellido    Salario     Sector\n");
		for (i = 0; i < length; i++) {
			if (list[i].status == STATUS_NOT_EMPTY) {
				printf("%d -- %s -- %s -- %f -- %d \n", list[i].id,
						list[i].nombre, list[i].direccion, list[i].precio,
						list[i].tipo);
			}

		}
	}
	return retorno;
}
*/
int addUI(Ghost *list, int len, int id) {
	Ghost bList;
	int retorno = -1;
	printf("ALTA\n");
	if (buscarLugarLibre(list, len) == -1) {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	} else {
		if (getString(bList.nombre, "Ingrese nombre\n", "Error\n", 0, 50, 3)
				!= -1) {
			if (getString(bList.direccion, "Ingrese apellido\n", "Error\n", 0,
					50, 3) == 0) {
				if (getFloat(&bList.precio,
						"Ingese salario de dicho Empleado\n", "Error\n", 1,
						10000000, 3) != -1) {
					if (getInt(&bList.tipo, "Ingrese sector del Empleado\n",
							"Error\n", 1, 1000, 3) != -1) {
						id++;
						if (altaPorId(list,len,bList)== 0) {
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

int modificarUI(Ghost *list, int len) {
	Ghost bList;
	int idIn;
	int posicion;
	int retorno = -1;
	printf("Modificacion de Empleados\n");
	getInt(&idIn, "Ingrese el id para modificar\n", "Error\n", 0, 100000, 3);
	posicion = BuscarPorId(list, len, idIn);
	if (posicion == -1) {
		printf("Error el id no existe\n");
	} else {
		bList = list[posicion];
		printf("id     Nombre    Apellido    Salario     Sector\n");
		printf("%d -- %s -- %s -- %f -- %d \n", list[posicion].id,
				list[posicion].nombre, list[posicion].direccion,
				list[posicion].precio, list[posicion].tipo);
		if (listaDeModificacion(bList) == 0) {
			if (ModificarPorId(list, len, bList) == 0) {
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

int listaDeModificacion(Ghost item) {
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
			if (getString(item.nombre, "Ingrese el nombre\n", "Error\n", 1, 50, 3)
					== -1) {
				printf("Error en el nombre\n");
				break;
			}

			break;
		case 2:
			if (getString(item.direccion, "Ingrese el Apellido\n", "Error", 1,
					50, 2) == -1) {
				printf("Error en el Apellido \n");
				break;
			}
			break;
		case 3:
			if (getFloat(&item.precio, "Ingrese el salario\n", "Error\n", 1,
					10000000, 3) == -1) {
				printf("Error en el salario\n");
				break;
			}
			break;
		case 4:
			if (getInt(&item.tipo, "Ingrese el sector del Empleado\n",
					"Error\n", 1, 1000, 3) == -1) {
				printf("Error en el tipo\n");
				break;
			}
			break;
		case 5:
			printf("%d -- %s -- %s -- %f -- %d \n", item.id, item.nombre,
					item.direccion, item.precio, item.tipo);
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

int EliminarUI(Ghost *list, int len) {
	int idIn;
	int posicion;
	int retorno = -1;
	char conf;
	printf("Baja\n");
	getInt(&idIn, "Ingrese el id para dar de baja\n", "Error\n", 1, 100000, 30);
	posicion = BuscarPorId(list, len, idIn);
	if (posicion == -1) {
		printf("Error el id no existe\n");
	} else {
		printf("%d -- %s -- %s -- %f -- %d \n", list[posicion].id,
				list[posicion].nombre, list[posicion].direccion,
				list[posicion].precio, list[posicion].tipo);
		getChar(&conf, "Ingrese s para confirmar la baja\n", "Error\n", 'a',
				'z', 2);
		if (conf == 's' || conf == 'S') {
			if (BajaPorId(list, len, idIn) == 0) {
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
int sortEmployees(Ghost *list, int len, int order) {
	Ghost swapList;
	int i;
	int retorno = -1;
	int fSwap;
	if (list != NULL && len > 0) {
		retorno = 0;
		do {
			fSwap = 0;
			for (i = 0; i < len - 1; i++) {
				if (order == 1) {
					if (strncmp(list[i].direccion, list[i + 1].direccion,
					QTY_CARACTERES) > 0) {
						fSwap = 1;
						swapList = list[i];
						list[i] = list[i + 1];
						list[i + 1] = swapList;
					} else if (strncmp(list[i].direccion, list[i + 1].direccion,
					QTY_CARACTERES) == 0
							&& list[i].tipo > list[i + 1].tipo) {
						fSwap = 1;
						swapList = list[i];
						list[i] = list[i + 1];
						list[i + 1] = swapList;
					}
				} else if (order == 0) {
					if (strncmp(list[i].direccion, list[i + 1].direccion,
					QTY_CARACTERES) < 0) {
						fSwap = 1;
						swapList = list[i];
						list[i] = list[i + 1];
						list[i + 1] = swapList;
					} else if (strncmp(list[i].direccion, list[i + 1].direccion,
					QTY_CARACTERES) == 0
							&& list[i].tipo < list[i + 1].tipo) {
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


int printUI(Ghost* list,int len){
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


