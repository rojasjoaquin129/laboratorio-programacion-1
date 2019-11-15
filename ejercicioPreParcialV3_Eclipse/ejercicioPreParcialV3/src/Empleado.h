#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;
Empleado* Empleado_new();
Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void Empleado_delete(Empleado* this);

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int Empleado_setSueldo(Empleado* this,int sueldo);
int Empleado_getSueldo(Empleado* this,int* sueldo);
int compararPorNombre(void* e1, void* e2);
void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
