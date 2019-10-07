#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;

#endif // EMPLEADOS_H_INCLUDED

int menu ();
int initEmployees(sEmployee lista[], int tame);
int addEmployee(sEmployee lista[], int tame, int id);
int buscarLibre(sEmployee lista[], int tame);
sEmployee newEmployee (int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(sEmployee lista[], int tame, int id);
int modifyEmployee(sEmployee lista[], int indice);
void showEmployee(sEmployee lista[], int indice);
void showEmployees(sEmployee lista[], int indice);
int removeEmployee(sEmployee lista[], int tame);
int menuInformar ();
int sortEmployeesByLastName(sEmployee lista[], int tame);
int sortEmployeesBySector(sEmployee lista[], int tame);
void showSalariesTotalPromedyMax (sEmployee lista[], int tame);
