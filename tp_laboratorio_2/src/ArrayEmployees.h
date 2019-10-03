/*
 * ArrayEmployees.h
 *
 *  Created on: 28 sep. 2019
 *      Author: alumno
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define QTY_EMPLEADOS 1000
#define QTY_CARACTERES 51

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct {
	int id;
	char name[QTY_CARACTERES];
	char lastName[QTY_CARACTERES];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int generarId(void);

int initEmployees(Employee *list, int len);
int findPlaceFreeEmployee(Employee *list, int len);
int findEmployeeById(Employee *list, int len, int id);
int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector);
int removeEmployee(Employee *list, int len, int id);
int modifyEmployeeforId(Employee *list, int len, Employee item);
int printEmployees(Employee *list, int length);
int sortEmployees(Employee *list, int len, int order);
int printUI(Employee* list,int len);
int addUI(Employee *list, int len, int id);
int modifyUI(Employee *list, int len);
int listForModify(Employee item);
int removeUI(Employee *list, int len);
int averageEmployees(Employee *list, int length);

#endif /* ARRAYEMPLOYEES_H_ */
