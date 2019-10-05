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
int menuInformar ()

int main()
{
    int id = 1;
    char salir = 'n';
    sEmployee empleado [TAME];
    int cargaEmpleado = 0;

    initEmployees(empleado, TAME);

    do
    {
        switch ( menu())
        {
            case 1:
                if (addEmployee(empleado, TAME, id))
                {
                    id++;
                    cargaEmpleado = 1;
                }
                break;

            case 2:
                if (cargaEmpleado)
                {
                    modifyEmployee(empleado, TAME);
                }
                else
                {
                    printf("Aun no se ha registrado ningun empleado. Cargue los datos de al menos uno para usar esta funcion. \n");
                }

                break;

            case 3:
                if (cargaEmpleado)
                {
                    removeEmployee(empleado, TAME);
                }
                else
                {
                    printf("Aun no se ha registrado ningun empleado. Cargue los datos de al menos uno para usar esta funcion. \n");
                }

                break;

            case 4:
                if (cargaEmpleado)
                {
                    menuInformar();
                }
                else
                {
                    printf("Aun no se ha registrado ningun empleado. Cargue los datos de al menos uno para usar esta funcion. \n");
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
        if( lista[i].id == id)
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
    printf("Ingrese ID del empleado: ");
    scanf("%d", &id);
    int opcion;

    indice = findEmployeeById(lista, tame, id);

    if( lista[indice].isEmpty == 1)
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
            printf("Se ha cancelado la modificacion \n");
            break;
        }
    }
    return todoOk;
}

void showEmployee(sEmployee lista[], int indice)
{
    printf("%d",indice);
    printf(" %d \t %s \t %s \t %f \t %d \n",
           lista[indice].id, lista[indice].name, lista[indice].lastName, lista[indice].salary, lista[indice].sector);
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

    indice = findEmployeeById(lista, tame, id);

    if( lista[indice].isEmpty == 1)
    {
        printf("Ese ID no pertenece a ningun empleado registrado. \n\n");
    }
    else
    {
        showEmployee(lista, indice);

        printf("\nConfirma baja? \n");
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
            printf("Se ha cancelado la operacion. \n");
        }
    }
    return todoOk;
}

int menuInformar ()
{
    int opcion;
    system("cls");
    printf("****  Informes  **** \n");
    printf("Que desea informar? \n");
    printf("1_ Listar empleados ordenados alfabeticamente segun apellido. \n");
    printf("2_ Listar empleados ordenados por sector. \n");
    printf("3_ Listar el total de los salarios y promedio salarial. \n");
    printf("4_ Salir. \n");
    scanf("%d", &opcion);

    return opcion;
}

int printEmployees(sEmployee lista[], int tame)
{

    return 0;
}

int sortEmployees(Employee* list, int len, int order)
{
    return 0;
}
