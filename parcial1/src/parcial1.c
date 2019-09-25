#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"

#define QTY_PUBLICIDAD 1000

int main(void) {

	struct sPantalla aPantallas[QTY_PANTALLAS];
	struct sPantalla bPantalla;

	struct sPublicidad aPublicidad [QTY_PANTALLAS];
	struct sPublicidad bPublicidad;
	int opcion;
	char conf;
	int id;
	int auxiliar;
	int cuit;
	intLugarLibrePantalla(aPublicidad,QTY_PANTALLAS);
	initLugarLibrePantalla(aPantallas, QTY_PANTALLAS);
	test(aPantallas,QTY_PANTALLAS);
	do {

		printf( "1. Alta de pantallas\n"
				"2. Modificacion de pantallas\n"
				"3. Baja de pantallas\n"
				"4. Contratar una publicidad\n"
				"5. "
				"9. Listado de pantallas\n"
				"0. Salir\n");

		getInt(&opcion, "Ingrese la opcion\n", "Error\n", 0, 9, 2);

		switch (opcion) {
		case 1:
			printf("Alta de pantallas\n");
			if (buscarLugarLibrePantalla(aPantallas, QTY_PANTALLAS) == -1) {
				printf("Error no hay mas lugar para pantallas\n");
				break;
			}
			if (getString(bPantalla.nombre, "Ingrese el nombre\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el nombre\n");
				break;
			}
			if (getString(bPantalla.direccion, "Ingrese la direccion\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en la direccion\n");
				break;
			}
			if (getFloat(&bPantalla.precio, "Ingrese el precio\n", "Error", 0,
					1000000, 2) == -1) {
				printf("Error en el precio\n");
				break;
			}
			if (getInt(&bPantalla.tipo, "Ingrese el tipo 1-lcd 2-led\n", "Error",
					1, 2, 2) == -1) {
				printf("Error en el tipo\n");
				break;
			}
			if (altaPantallaPorId(aPantallas, QTY_PANTALLAS, bPantalla) == 0) {
				printf("Alta exitosa\n");
			} else {
				printf("Error al hacer el alta\n");

			}

			break;
		case 2:
			printf("Modificacion de pantallas\n");
			getInt(&id,"Ingrese el id para modificar\n","Error\n",0,100000,2);
			if (buscarPantallaPorId(aPantallas, QTY_PANTALLAS,id) == -1) {
				printf("Error el id no existe\n");
				break;
			}
			bPantalla.id = id;
			if (getString(bPantalla.nombre, "Ingrese el nombre\n", "Error\n", 1,
					49, 2) == -1) {
				printf("Error en el nombre\n");
				break;
			}
			if (getString(bPantalla.direccion, "Ingrese la direccion\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en la direccion\n");
				break;
			}
			if (getFloat(&bPantalla.precio, "Ingrese el precio\n", "Error\n", 0,
					1000000, 2) == -1) {
				printf("Error en el precio\n");
				break;
			}
			if (getInt(&bPantalla.tipo, "Ingrese el tipo 1-lcd 2-led\n", "Error\n",
					1, 2, 2) == -1) {
				printf("Error en el tipo\n");
				break;
			}
			if (modificarPantallaPorId(aPantallas, QTY_PANTALLAS, bPantalla) == 0) {
				printf("Modificacion exitosa\n");
			} else {
				printf("Error al hacer la modificacion\n");

			}

			break;
		case 3:
			printf("Baja\n");
			getInt(&id,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);
			getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
			if(bajaPantallaPorId(aPantallas,QTY_PANTALLAS,id)==0){
				printf("Baja exitosa\n");
			}else{
				printf("Error al dar baja, verifique que el id existe\n");
			}
			break;

		case 4:
			printf("Contratar una publicidad\n");
			if (buscarLugarLibrePantalla(aPublicidad, QTY_PUBLICIDAD) == -1) {
				printf("Error no hay mas lugar para la publicidad\n");
				break;
			}
			imprimirArrayPantallas(aPantallas, QTY_PANTALLAS);
			getInt(&id,"Ingrese el id de la pantalla q desea contratar\n","Error\n",0,100000,2);
			if (buscarPantallaPorId(aPantallas, QTY_PANTALLAS,id) == -1) {
				printf("Error el id no existe\n");
				break;
				}
			bPublicidad.idPantalla = id;
			if (getString(bPublicidad.nombre, "Ingrese el nombre del archivo\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el nombre\n");
				break;
			}

			if (getInt(&bPublicidad.cuit, "Ingrese el Cuit del cliente\n", "Error", 0,
					1000000, 2) == -1) {
				printf("Error en el precio\n");
				break;
			}
			if (getInt(&bPublicidad.dias, "Ingrese cantidad por dia\n", "Error",
					1, 100000, 2) == -1) {
				printf("Error en el tipo\n");
				break;
			}
			if (altaPublicidadPorId(aPublicidad, QTY_PUBLICIDAD, bPublicidad) == 0) {
				printf("contratacion exitosa\n");
			} else {
				printf("Error al hacer la contratacion\n");

			}
			break;
		case 5:
			printf("Modificacion de publicidad\n");
			getInt(&cuit,"Ingrese el cuit del cliente para modificar\n","Error\n",0,100000,2);
			auxiliar=buscarPublicidadPorCuit(aPublicidad, QTY_PANTALLAS,cuit);
			if (auxiliar == -1) {
				printf("Error el cuit no existe\n");
				break;
			}
			if (MostarPantallaPorCuit(aPublicidad,aPantallas,QTY_PANTALLAS,cuit)==-1){
				printf("Error en la compilacion\n");
				break;
			}


			break;
		case 9:
			imprimirArrayPantallas(aPantallas, QTY_PANTALLAS);
			break;
		}

	} while (opcion != 0);

	return EXIT_SUCCESS;
}



void test(struct sPantalla p[], int cantidad)
{
	char aNombre[][50]={"Florida","Lavalle","Cabildo","Entre Rios","Callao"};
	char aDireccion[][50]={"Florida 300","Lavalle 500","Diagonal norte 499","Entre Rios 387","Callao 361"};
	float aPrecio[]={3000,2900,2589,1900,8000};
	float aTipo[]={1,1,2,1,2};
	struct sPantalla bPantalla;
	int i;
	for(i=0;i<5;i++){
		strncpy(bPantalla.nombre,aNombre[i],50);
		strncpy(bPantalla.direccion,aDireccion[i],50);
		bPantalla.precio = aPrecio[i];
		bPantalla.tipo = aTipo[i];

		altaPantallaPorId(p, QTY_PANTALLAS, bPantalla);
	}

}

