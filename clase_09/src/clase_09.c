/*
 ============================================================================
 Name        : clase_09.c
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
#include "empleado.h"
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY -1

int buscarLugarLibreEmpleado(struct sEmpleado *aEmpleado, int cantidad);
int buscarEmpleadoPorId( struct sEmpleado *aEmpleado, int cantidad,int id);
int main(void)
{

	struct sEmpleado aEmpleados[1000];
	struct sEmpleado bEmpleado;
	int i;
	int idEmpleado = 0;

	for(i=0;i<3;i++){

		getString(bEmpleado.nombre,"Ingrese el nombre",
				"ERROR", 1, 49, 2);

		getString(bEmpleado.apellido,"Ingrese el apellido",
						"ERROR", 1, 49, 2);

		bEmpleado.idEmpleado = idEmpleado; /* el id del empleado puede variar por eso se elije un a variable */
		idEmpleado++;
		bEmpleado.status = STATUS_NOT_EMPTY; /*para saber si estan llenos o no ? */

		aEmpleados[i] = bEmpleado;
	}
	ordenarArrayString(aEmpleados,3);
	imprimirArrayEmpleados(aEmpleados,3);

	return EXIT_SUCCESS;
}

int imprimirArrayEmpleados(struct sEmpleado *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status=STATUS_NOT_EMPTY){
			printf("Id: %d - Nombre: %s - Apellido: %s \n",aArray[i].idEmpleado,aArray[i].nombre,aArray[i].apellido);
		}
	}
	return retorno;
}

int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad){
	int i;
	int retorno = -1;
	if(aNombres != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Nombre: %s \n",aNombres[i]);
		}
	}
	return retorno;
}


int buscarLugarLibreEmpleado( struct sEmpleado *aEmpleado, int cantidad)
{
	int i;
	int index = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aEmpleado[i].status == STATUS_EMPTY){
				index=i;
				break;
			}
		}
	}
	return index;
}

int buscarEmpleadoPorId( struct sEmpleado *aEmpleado, int cantidad,int id)
{
	int i;
	int index = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		for(i=0;i<cantidad;i++)
		{
			if(aEmpleado[i].idEmpleado == id ){
				index=i;
				break;
			}
		}
	}
	return index;
}






int altaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado){
	int retorno = -1;
	int indice;
	int auxiliar;
	if( cantidad>0 && aArray!=NULL ){
		auxiliar=buscarEmpleadoPorId(aArray,QTY_EMPLEADOS,empleado.idEmpleado);
		indice=buscarLugarLibreEmpleado(aArray,QTY_EMPLEADOS);
		if(indice!=-1 && auxiliar !=-1){
			retorno=0;
			aArray[indice]=empleado;
			aArray[indice].status= STATUS_NOT_EMPTY;
			}
	}
return retorno;
}


int bajaEmpleadoPorId(struct sEmpleado *aArray, int cantidad,struct sEmpleado empleado,int id )
	int retorno = -1;
	int indice;
	if( cantidad>0 && aArray!=NULL ){
		indice=buscarEmpleadoPorId(aArray,QTY_EMPLEADOS,id );
		if(indice!=-1){
			retorno=0;
			aArray[indice].status= STATUS_EMPTY;
			}
	}
return retorno;
}




int ordenarArrayString(struct sEmpleado *aEmpleado, int cantidad){
	struct sEmpleado swapEmpleado;
	int i;
	int retorno = -1;
	int fSwap;
	char pregunta;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		printf("quiere mostrarlo de menor a mayor? s/n\n");
		scanf("%s",&pregunta);
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if (pregunta=='s'){
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)>0){
						fSwap = 1;
						swapEmpleado=aEmpleado[i];
						aEmpleado[i]=aEmpleado[i+1];
						aEmpleado[i+1]=swapEmpleado;
					}else if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)==0 &&
						strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,QTY_CARACTERES)>0){
						fSwap = 1;
						swapEmpleado=aEmpleado[i];
						aEmpleado[i]=aEmpleado[i+1];
						aEmpleado[i+1]=swapEmpleado;
					}
				}else {
					if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)<0){
						fSwap = 1;
						swapEmpleado=aEmpleado[i];
						aEmpleado[i]=aEmpleado[i+1];
						aEmpleado[i+1]=swapEmpleado;
					}else if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)==0 &&
						strncmp(aEmpleado[i].nombre,aEmpleado[i+1].nombre,QTY_CARACTERES)<0){
						fSwap = 1;
						swapEmpleado=aEmpleado[i];
						aEmpleado[i]=aEmpleado[i+1];
						aEmpleado[i+1]=swapEmpleado;
					}
				}
				}
		}while(fSwap);
	}
	return retorno;
}

