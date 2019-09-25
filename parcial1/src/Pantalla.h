/*
 * Pantalla.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define QTY_PANTALLAS 100
#define QTY_CARACTERES 50

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sPublicidad
{
	int id;
	int status;
	//***************
	char nombre[50];
	int dias;
	int idPantalla;
	int cuit;
};
struct sPantalla
{
	int id;
	int status;
	//***************
	char nombre[50];
	char direccion[50];
	float precio;
	int tipo;
};
int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);
int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item);
int initLugarLibrePantalla(struct sPantalla *aArray, int cantidad);
int MostarPantallaPorCuit(struct sPublicidad *aArrayPublicidad, struct sPantalla *aArray,
		int cantidad,int cuit);
int imprimirArrayPantallas(struct sPantalla *aArray, int cantidad);
int ordenarArrayPantallas(struct sPantalla *aArray, int cantidad);
int buscarPublicidadPorCuit(struct sPublicidad *aArray, int cantidad,int cuit);
int buscarLugarLibrePantalla(struct sPantalla *aArray, int cantidad);
int buscarPantallaPorId(struct sPantalla *aArray, int cantidad,int id);
int altaPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla item);
int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id);
int modificarPantallaPorId(struct sPantalla *aArray, int cantidad,struct sPantalla item);


#endif /* PANTALLA_H_ */
