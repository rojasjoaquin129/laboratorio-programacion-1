#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#include "Publicidad.h"
void test(struct sPantalla p[], int cantidad);
void test(struct sPantalla p[], int cantidad);
int main(void) {

	struct sPantalla aPantallas[QTY_PANTALLAS];
	struct sPublicidad aPublicidad[QTY_PUBLICIDAD];

	struct sPantalla bPantalla;
	struct sPublicidad bPublicidad;


	int opcion;
	char conf;
	int id;
	int posicion;

	initLugarLibrePantalla(aPantallas, QTY_PANTALLAS);
	initLugarLibrePublicidad(aPublicidad, QTY_PUBLICIDAD);

	test(aPantallas,QTY_PANTALLAS);
	test2(aPublicidad, QTY_PANTALLAS);
	do {

		printf( "1. Alta de pantallas\n"
				"2. Modificacion de pantallas\n"
				"3. Baja de pantallas\n"
				"4. Alta publicidad\n"
				"5. Modificar publicidad\n"
				"9. Listado de pantallas\n"
				"0. Salir\n");

		getInt(&opcion, "Ingrese la opcion\n", "Error\n", 0, 9, 2);

		switch (opcion) {
		case 1:
			altaUI(aPantallas,QTY_PANTALLAS);
			break;
		case 2:
			printf("Modificacion de pantallas\n");
			getInt(&id,"Ingrese el id para modificar\n","Error\n",0,100000,2);
			posicion=buscarPantallaPorId(aPantallas, QTY_PANTALLAS,id);
			if (posicion == -1) {
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
			// exite el id?
			if(conf=='s')
			{
				if(bajaPantallaPorId(aPantallas,QTY_PANTALLAS,id)==0){
					printf("Baja exitosa\n");
				}else{
					printf("Error al dar baja, verifique que el id existe\n");
				}
			}
			break;
		case 4:
			printf("Alta de publicidad\n");
			if (buscarLugarLibrePublicidad(aPublicidad, QTY_PUBLICIDAD) == -1) {
				printf("Error no hay mas lugar para publicidad\n");
				break;
			}
			if (getString(bPublicidad.cuit, "Ingrese el cuit\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el cuit\n");
				break;
			}
			if (getInt(&bPublicidad.dias, "Ingrese la cantidad de dias\n", "Error",
					1, 1000, 2) == -1) {
				printf("Error en la cantidad de dias\n");
				break;
			}
			if (getString(bPantalla.direccion, "Ingrese el nombre del archivo\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en el nombre del archivo\n");
				break;
			}
			imprimirArrayPantallas(aPantallas, QTY_PANTALLAS);
			if (getInt(&bPublicidad.idPantalla, "Ingrese el id de la pantalla\n", "Error",
					1, 1000000, 2) == -1) {
				printf("Error en el id\n");
				break;
			}
			if(buscarPantallaPorId(aPantallas,QTY_PANTALLAS, bPublicidad.idPantalla)== -1){
				printf("Error id de pantalla inexistente");
				break;
			}


			if (altaPublicidadPorId(aPublicidad, QTY_PUBLICIDAD, bPublicidad) == 0) {
				printf("Alta exitosa\n");
			} else {
				printf("Error al hacer el alta\n");

			}

			break;
		case 5:
			printf("Modificacion de publicidad");
			if (getString(bPublicidad.cuit, "Ingrese el cuit\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el cuit\n");
				break;
			}
			listarPantallasPorCuit(aPantallas,QTY_PANTALLAS,aPublicidad,QTY_PUBLICIDAD, bPublicidad.cuit );
			getInt(&id,"Ingrese el id de la pantalla para modificar\n","Error\n",0,100000,2);
			posicion=verificarIdPublicidadPorcuit(aPublicidad,QTY_PUBLICIDAD ,bPublicidad,id);
			if( posicion ==-1 ) {
				printf ("Error id no valido");
				break;
			}
			bPublicidad=aPublicidad[posicion];
			if (getInt(&bPublicidad.dias, "Ingrese la cantidad de dias q quiere cambiar\n", "Error",
					1, 1000, 2) == -1) {
				printf("Error en la cantidad de dias\n");
				break;
			}
				if (modificarPublicidadPorId(aPublicidad, QTY_PUBLICIDAD, bPublicidad) == 0) {
				printf("Modificacion exitosa\n");

				} else {
					printf("Error al hacer la modificacion\n");

				}
			break;
		case 6:
			printf("baja de publicidad");
			if (getString(bPublicidad.cuit, "Ingrese el cuit\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el cuit\n");
				break;
			}
			listarPantallasPorCuit(aPantallas,QTY_PANTALLAS,aPublicidad,QTY_PUBLICIDAD, bPublicidad.cuit );
			getInt(&id,"Ingrese el id de la pantalla para dar de baja\n","Error\n",0,100000,2);
			posicion=verificarIdPublicidadPorcuit(aPublicidad,QTY_PUBLICIDAD ,bPublicidad,id);
			if (posicion==-1 ) {
				printf ("Error id no valido");
				break;
			}

			//id=aPublicidad[posicion].id;
			getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
			if(conf=='s')
			{
			if(bajaPublicidadPorId(aPublicidad,QTY_PUBLICIDAD,aPublicidad[posicion].id)==0){
				printf("Baja exitosa\n");
				}else{
				printf("Error al dar baja, verifique que el id existe\n");
				}
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

void test2(struct sPublicidad p[], int cantidad)
{
	char aCuit[][50]={"26194002","26194002","777","26194002","44434"};
	int aDias[]={5,3,7,9,5};
	char aNombreArchivo[][50]={"caballo","promo 2","propa","gato","promo3"};
	int aIdPantalla[]={4,2,4,1,2};
	struct sPublicidad bPublicidad;
	int i;
	for(i=0;i<5;i++){
		strncpy(bPublicidad.cuit,aCuit[i],50);
		bPublicidad.dias = aDias[i];
		strncpy(bPublicidad.nombreArchivo,aNombreArchivo[i],50);
		bPublicidad.idPantalla = aIdPantalla[i];

		altaPublicidadPorId(p, QTY_PUBLICIDAD, bPublicidad);
	}

}
