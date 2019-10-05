#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define TAME 5

typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;

int menu ();
int initEmployees(sEmployee lista[], int tame);
int addEmployee(sEmployee lista[], int tame, int id);
int buscarLibre(sEmployee lista[], int tame);
sEmployee newEmployee (int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(sEmployee lista[], int tame, int id);
int modifyEmployee(sEmployee lista[], int indice);
void showEmployee(sEmployee x[], int indice);
int removeEmployee(sEmployee lista[], int tame);


int main()
{
    int id = 1000;
    char salir = 'n';
    sEmployee empleado [TAME];
    int cargoEmpleado = 0;

    initEmployees(empleado, TAME);

    do
    {
        switch ( menu())
        {
            case 1:
                if (addEmployee(empleado, TAME, id))
                {
                    id++;
                    cargoEmpleado = 1;
                }
                break;

            case 2:
                if (cargoEmpleado)
                {
                    modifyEmployee(empleado, TAME);
                }
                else
                {
                    printf("No se puede ejecutar la opcion. Cargue los datos de un empleado primero. \n");
                }
                break;

            case 3:
                if (cargoEmpleado)
                {
                    removeEmployee(empleado, TAME);
                }
                else
                {
                    printf("No se puede ejecutar la opcion. Cargue los datos de un empleado primero. \n");
                }
                break;

            case 4:
                if (cargoEmpleado)
                {
                    printEmployees();
                }
                else
                {
                    printf("No se puede ejecutar la opcion. Cargue los datos de un empleado primero. \n");
                }
                break;

            default:
                printf("Error. Ingrese una opcion valida. \n");
        }
        system("pause");
    }while (salir == 'n');

    return 0;
}

int menu ()
{
    int opcion;
    system("cls");
    printf("   ***   Bienvenido al Sistema ABM de Empleados   ***   \n\n");
    printf("Seleccione una opcion: \n\n");
    printf("1_ Alta de empleado.\n");
    printf("2_ Modificar empleado.\n");
    printf("3_ Baja de empleado.\n");
    printf("4_ Informe de empleado.\n");
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(sEmployee lista[], int tame)
{
    for (int i=0; i<tame; i++)
    {
        lista[i].isEmpty = 1;
    }

    return 0;
}

int addEmployee(sEmployee lista[], int tame, int id)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int todoOk;
    int indice;

    system("cls");

    printf("**  Alta de empleado  **\n\n");

    indice = buscarLibre(lista, tame);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre del empleado: ");
        fflush(stdin);
        gets(name);

        printf("Ingrese apellido del empleado: ");
        fflush(stdin);
        gets(lastName);

        printf("Ingrese salario del empleado: ");
        scanf("%f", &salary);

        printf("Ingrese el sector en el que trabajara: ");
        scanf("%d", &sector);

        lista[indice] = newEmployee(id, name, lastName, salary, sector);

        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

sEmployee newEmployee (int id, char name[], char lastName[], float salary, int sector)
{
    sEmployee em;
    em.id = id;
    strcpy( em.name, name);
    strcpy ( em.lastName, lastName);
    em.salary = salary;
    em.sector = sector;
    em.isEmpty = 0;

    return em;
}

int buscarLibre(sEmployee lista[], int tame)
{
    int indice = -1;

    for(int i=0; i < tame; i++)
    {
        if( lista[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(sEmployee lista[], int tame, int id)
{
    int indice = -1;

    for(int i=0; i < tame; i++)
    {
        if( lista[i].id == id && lista[i].id == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int modifyEmployee(sEmployee lista[], int tame)
{
    int todoOk = 0;
    int id;
    int indice;
    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    system("pause");
    printf("Ingrese ID del empleado: ");
    scanf("%d", &id);
    int opcion;

    indice = findEmployeeById(lista, id, tame);

    if( indice == -1)
    {
        printf("Ese ID no pertenece a ningun empleado registrado.\n\n");
    }
    else
    {
        showEmployee(lista, indice);

        printf("Seleccione el campo que desee modificar: \n");
        printf("1- Nombre \n");
        printf("2- Apellido \n");
        printf("3- Salario \n");
        printf("4- Sector \n");
        printf("5- Salir\n\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nombre: ");
            scanf("%10s", &lista[indice].name);
            break;

        case 2:
            printf("Ingrese el apellido: ");
            scanf("%10s", &lista[indice].lastName);
            break;

        case 3:
            printf("Ingrese el salaraio: \n");
            scanf("%f", &lista[indice].salary);
            break;

        case 4:
            printf("Ingrese el sector: \n");
            scanf("%d", &lista[indice].sector);
            break;

        case 5:
            printf("Se ha cancelado la mofdificacion ");
            break;
        }
    }
    return todoOk;
}

void showEmployee(sEmployee x[], int indice)
{
    printf(" %d  %10s  %10s  %f  %d \n", x[indice].id, x[indice].name, x[indice].lastName, x[indice].salary, x[indice].sector);
}

int removeEmployee(sEmployee lista[], int tame)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja de Empleado *****\n\n");
    printf("Ingrese ID del empleado: \n");
    scanf("%d", &id);

    indice = findEmployeeById(lista, id, tame);

    if( indice == -1)
    {
        printf("Ese ID no pertenece a ningun empleado registrado. \n\n");
    }
    else
    {
        showEmployee(lista, tame);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            lista[indice].isEmpty = 1;
            todoOk = 1;
            printf("El empleado se ha dado de baja con exito!! \n");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }
    return todoOk;
}

int printEmployees(sEmployee lista[], int tame)
{

    return 0;
}

int sortEmployees(Employee* list, int len, int order)
{

    return 0;
}
