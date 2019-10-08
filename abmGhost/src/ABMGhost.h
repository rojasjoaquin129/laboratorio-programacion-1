/*
 * ABMGhost.h
 *
 *  Created on: 8 oct. 2019
 *      Author: joaquin
 */

#ifndef ABM_H_
#define ABM_H_
#define QTY_PANTALLAS 100
#define QTY_CARACTERES 50

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

typedef struct
{
	int id;
	int status;
	//***************
	char nombre[50];
	char direccion[50];
	float precio;
	int tipo;
} Ghost;

int InitLugarLibre(Ghost *array, int len);

int ImprimirArray(Ghost *array, int len);
int OrdenarArray(Ghost *array, int len, int orden);

int BuscarLugarLibre(Ghost *array, int len);
int BuscarPorId(Ghost *array, int len,int id);
int AltaPorId(Ghost *array, int len, Ghost item);
int BajaPorId(Ghost *array, int len,int id);
int ModificarPorId(Ghost *array, int len,Ghost item);
int GetPorId(Ghost *array, int len, Ghost *buffer);


#endif /* ABM_H_ */
