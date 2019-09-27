/*
 * Empleado.c
 *
 *  Created on: 17 sep. 2019
 *      Author: profesor
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"

static int generarId(void){
	static int id = 0;
	id++;
	return id;
}


/*
int ordenarArrayPantallas(struct sPantalla *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct sPantalla buffer;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aArray[i].nombre,aArray[i+1].nombre,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					buffer = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=buffer;
				}
				else if(strncmp(aArray[i].nombre,aArray[i+1].nombre,QTY_CARACTERES)==0)
				{
					if(strncmp(aArray[i].apellido,aArray[i+1].apellido,QTY_CARACTERES)>0)
					{
						fSwap = 1;
						buffer = aArray[i];
						aArray[i]=aArray[i+1];
						aArray[i+1]=buffer;
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}
*/

int imprimirArrayPantallas(struct sPantalla *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		printf("id     Nombre    Direccion    Precio     Tipo\n");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY){
				printf("%d -- %s -- %s -- %f -- %d \n",aArray[i].id,aArray[i].nombre,aArray[i].direccion,aArray[i].precio,aArray[i].tipo);
			}

		}
	}
	return retorno;
}

int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			aArray[i].status = STATUS_EMPTY;
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



int buscarPantallaPorId(struct sPantalla *aArray, int cantidad,int id){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad > 0 ){
		for(i=0;i<cantidad;i++){
			if(aArray[i].id == id && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarLugarLibrePantalla(aArray, cantidad);
		if(index>=0){
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
			aArray[index].id = generarId();
			retorno = 0;
		}
	}
	return retorno;
}

int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad > 0){
		index = buscarPantallaPorId(aArray, cantidad, id);
		if(index != -1){
			aArray[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

int modificarPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla item){
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

