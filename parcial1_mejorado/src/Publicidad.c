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
#include "Publicidad.h"

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
/*
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
*/
int verificarIdPublicidadPorcuit(struct sPublicidad *aArray, int cantidad,struct sPublicidad item,int id){
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].status == STATUS_EMPTY && aArray[i].idPantalla==id && strncmp(aArray[i].cuit,item.cuit,50)==0 ){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad){
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

int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad){
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



int buscarPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id){
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

int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarLugarLibrePublicidad(aArray, cantidad);
		if(index>=0){
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
			aArray[index].id = generarId();
			retorno = 0;
		}
	}
	return retorno;
}


int listarPantallasPorCuit(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad, char *cuit )
{
	int retorno = -1;
	int i;
	if(aPantallas != NULL && cantidadPantallas>0 && aPublicidad != NULL && cantidadPublicidad >0 && cuit != NULL){
		for(i=0;i<cantidadPublicidad;i++){

			if(aPublicidad[i].status == STATUS_NOT_EMPTY && strncmp(aPublicidad[i].cuit, cuit, 50) == 0 ){
				retorno=0;
				imprimirPantallaConCuit(aPantallas, cantidadPantallas, aPublicidad[i].idPantalla, cuit);
			}
		}

	}
return retorno;
}

int imprimirPantallaConCuit(struct sPantalla *aPantallas, int cantidadPantallas,int idPantalla,char *cuit){
	int index;
	int retorno = -1;
	index=buscarPantallaPorId(aPantallas, cantidadPantallas, idPantalla);
	if(index != -1){
		printf("id - %d - nombre - %s - direccion - %s - precio - %f - tipo - %d- cuit - %s \n"
				,aPantallas[index].id,aPantallas[index].nombre,aPantallas[index].direccion,aPantallas[index].precio,aPantallas[index].tipo,cuit );
	}

	return retorno;
}

/*Anulado
int listarPantallasPorCuit(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad, char *cuit )
{
	int retorno = -1;
	if(aPantallas != NULL && cantidadPantallas>0 && aPublicidad != NULL && cantidadPublicidad >0 && cuit != NULL){
		int posicionActual=-1;
		int incremento=0;
		retorno = 0;
		do{
			incremento = buscarPublicidadPorCuit(aPublicidad+posicionActual+1, cantidadPublicidad-posicionActual-1, cuit);
			if(incremento == -1){
				break;
			}
			posicionActual += incremento+1;
			printf("%d\n",posicionActual);
			imprimirPantallaConCuit(aPantallas, cantidadPantallas, aPublicidad[posicionActual].idPantalla, cuit);

		}while(1);
	}
	return retorno;
}

int buscarPublicidadPorCuit(struct sPublicidad *aArray, int cantidad,char *cuit){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad > 0 ){
		for(i=0;i<cantidad;i++){
			if(strncmp(aArray[i].cuit, cuit, 50) == 0 && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
*/

int bajaPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad > 0){
		index = buscarPublicidadPorId(aArray, cantidad, id);
		if(index != -1){
			aArray[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

int modificarPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarPublicidadPorId(aArray, cantidad, item.id);
		if(index!=-1){
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}


