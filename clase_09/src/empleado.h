/*
 * empleado.h
 *
 *  Created on: 17 sep. 2019
 *      Author: alumno
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY -1
struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
};


int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
int ordenarArrayString(struct sEmpleado *aEmpleado, int cantidad);
int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);



#endif /* EMPLEADO_H_ */
