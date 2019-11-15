
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "LinkedList.h"

static int isValidNombre(char* nombre);
static int isValidHorasTrabajadas(int horasTrabajadas);
static int isValidSueldo(int sueldo);



/** \brief Crea un nuevo empleado
 *
 * \return Empleado*
 *
 */
Empleado* Empleado_new()
{
	return (Empleado*)malloc(sizeof(Empleado));
}

/** \brief Crea un nuevo empleado con los parametros recibidos
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Empleado*
 *
 */
Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Empleado* retorno = NULL;
	Empleado* this;
	this = Empleado_new();
	if(		this!=NULL &&
			Empleado_setId(this, atoi(idStr))!=-1 &&
			Empleado_setNombre(this, nombreStr)!=-1 &&
			Empleado_setHorasTrabajadas(this, atoi(horasTrabajadasStr))!=-1){
		retorno = this;
	}else{
		Empleado_delete(this);
	}
	return retorno;
}

/** \brief Elimina un empleado
 *
 * \param this Empleado*
 *
 */
void Empleado_delete(Empleado* this)
{
	free(this);
}

/** \brief asigna el id, lleva cuenta del id maximo y si se ingresa un numero negativo devuelve maximo+1
 *
 * \param this Empleado*
 * \param id int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_setId(Empleado* this, int id)
{
	int retorno = -1;
	static int maximoId = -1;
	if(this != NULL)
	{
		retorno = 0;
		if(id < 0)
		{
			maximoId++;
			this->id = maximoId;
		}
		else
		{
			if(id > maximoId)
			{
				maximoId = id;
			}
			this->id = id;
		}
	}
	return retorno;
}


/** \brief devuelve el id de un empleado en parametro id
 *
 * \param this Empleado*
 * \param id int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_getId(Empleado* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/** \brief asigna el nombre de un empleado
 *
 * \param this Empleado*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_setNombre(Empleado* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && isValidNombre(nombre)){
		retorno = 0;
		strncpy(this->nombre, nombre,128);
	}
	return retorno;
}

/** \brief devuelve el nombre de un empleado en parametro nombre
 *
 * \param this Empleado*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_getNombre(Empleado* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno = 0;
		strncpy(nombre, this->nombre,128);
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidNombre(char* nombre)
{
	int retorno = 0;
	//if(chequear(nombre, 1, 0, " ") && strlen(nombre)<127)
	{
		retorno = 1;
	}
	return retorno;
}

/** \brief asigna las horas trabajadas de un empleado
 *
 * \param this Empleado*
 * \param horasTrabajadas int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && isValidHorasTrabajadas(horasTrabajadas)){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/** \brief devuelve las horas trabajadas de un empleado
 *
 * \param this Empleado*
 * \param horasTrabajadas int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

/** \brief verifica si horas trabajadas es valido
 *
 * \param horasTrabajadas int
 * \return retorna 0 si no es valido y 1 si lo es
 *
 */
static int isValidHorasTrabajadas(int horasTrabajadas)
{
	int retorno = 0;
	if(horasTrabajadas >= 0){
		retorno = 1;
	}
	return retorno;
}

/** \brief asigna el sueldo de un empleado
 *
 * \param this Empleado*
 * \param sueldo int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_setSueldo(Empleado* this,int sueldo)
{
	int retorno = -1;
	if(this!=NULL && isValidSueldo(sueldo)){
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

/** \brief devuelve el sueldo de un empleado
 *
 * \param this Empleado*
 * \param sueldo int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int Empleado_getSueldo(Empleado* this,int* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo!=NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

/** \brief verifica si sueldo es valido
 *
 * \param sueldo int
 * \return retorna 0 si no es valido y 1 si lo es
 *
 */
static int isValidSueldo(int sueldo)
{
	int retorno = 0;
	if(sueldo >= 0){
		retorno = 1;
	}
	return retorno;
}

void em_calcularSueldo(void* p)
{
	int horasTrabajadas;
 Empleado*aux
 aux=p;
 horasTrabajadas=aux->horasTrabajadas

	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
}
