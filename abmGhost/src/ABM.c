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
		index = sGen_BuscarLugarLibre(list, len);
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
		index = sGen_BuscarPorId(list, len, id);
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
		index = sGen_BuscarPorId(list, len, item.id);
		if(index!=-1)
		{
			list[index] = item;
			list[index].status = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}


