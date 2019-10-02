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

int generarId(void);

int altaUI(Employee *list,int len,int id);
int modificacionUI(Employee* list,int len);
int listForModify(Employee* bList);

int initEmployees(Employee* list, int len);
int findPlaceFreeEmployee(Employee *list, int len);
int findEmployeeById(Employee* list,, int len,int id);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int removeEmployee(Employee* list, int len,int id);
int modifyEmployeeforId(Employee* list, int len,Employee* item);
int printEmployees(Employee* list, int length);


#endif /* EMPLOYEES_H_ */
