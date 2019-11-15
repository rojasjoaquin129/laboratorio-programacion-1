#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Empleado.h"


int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
	    char id[4096];
	    char nombre[4096];
	    char horasTrabajadas[4096];
	    Empleado* auxEmpleado;
	    int retorno=-1;
	    if(fileName != NULL &&  listaEmpleados != NULL )
	    {

	        fscanf(fileName,"%[^,],%[^,],%[^\n]\n",
	               id,
	               nombre,
	               horasTrabajadas);
	        while(!feof(fileName))
	        {
	            fscanf(fileName,"%[^,],%[^,],%[^\n]\n",
	                   id,
	                   nombre,
	                   horasTrabajadas)
	            auxEmpleado=Empleado_newParametros(id,nombre,horasTrabajadas);
	            if(auxEmpleado!=NULL)
	            {
	                ll_add(listaEmpleados, auxEmpleado);
	                retorno=0;

	            }
	        }

	    }
	    return retorno;
	}

