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

int main()
{
    int id = 1000;
    char seguir = 'n';
    sEmployee empleado [TAME];

    initEmployees(empleado, TAME);

    do
    {
        switch ( menu ())
        {
            case 1:
                if (addEmployee(empleado, TAME, id))
                {
                    id++;
                }
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            default:
                printf("Error. Ingrese una opcion valida. \n");
        }
    }while (seguir == 's');

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
        scanf("%2f", &salary);

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
