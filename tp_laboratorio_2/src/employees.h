/*
 * employees.h
 *
 *  Created on: 28 sep. 2019
 *      Author: alumno
 */

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_
#define QTY_EMPLEADOS 1000
#define QTY_CARACTERES 51

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct
{
 int id;
 char name[QTY_CARACTERES];
 char lastName[QTY_CARACTERES];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);


#endif /* EMPLOYEES_H_ */
