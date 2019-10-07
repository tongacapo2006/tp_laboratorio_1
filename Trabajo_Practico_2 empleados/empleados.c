#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Despliega las opciones del menu.
 *
 * \return int opcion opcion elegida por el usuario.
 *
 */

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

/** \brief Indica que todas las posiciones del vector estan vacias. Pone el flag isEmpty en TRUE (1) para todas las posiciones del vector.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \return int 0 si se ejecuto correctamente.
 *
 */

int initEmployees(sEmployee lista[], int tame)
{
    for (int i=0; i<tame; i++)
    {
        lista[i].isEmpty = 1;
    }

    return 0;
}

/** \brief Asigna los valores asignados por el usuario a los parametros de un vector de empleado que se encuentra vacio en todas las posiciones.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \param int id el id asignado al empleado al generarlo.
 * \return int todoOk flag para indicar si la operacion se dio con exito.
 *
 */

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

/** \brief Estructura designada para almacenar los datos introducidos por el usuario para registrar un nuevo empleado.
 *
 * \param int id el ID del empleado.
 * \param char name el nombre del empleado.
 * \param char lastName el apellido del empleado.
 * \param float salary el salario del empleado.
 * \param int sector sector en el que trabaja el empleado.
 * \return em sEmployee los datos del nuevo empleado en un vector de tipo sEmployee.
 *
 */

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

/** \brief Busca un vector de empleado cuyas posiciones se encuentren vacias.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \return int indice
 *
 */

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

/** \brief Busca un vector de empleado cuyo ID sea igual al introducido por el usuario.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \param int id el ID del empleado.
 * \return int indice
 *
 */

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

/** \brief Permite al usuario modificar los datos de una de las posiciones del vector de empleado.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \return int todoOk flag para indicar si la operacion se dio con exito.
 *
 */

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

/** \brief Muestra los datos de un empleado.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int indice indica una posicion puntual del vector.
 * \return void
 *
 */

void showEmployee(sEmployee lista[], int indice)
{
    printf(" %d \t %s \t %s \t %f \t %d \n",
    lista[indice].id, lista[indice].name, lista[indice].lastName, lista[indice].salary, lista[indice].sector);
}

/** \brief Lista todos los empleados registrados.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int indice indica una posicion puntual del vector.
 * \return void
 *
 */

void showEmployees(sEmployee lista[], int indice)
{
    system("cls");

    printf(" ID  Nombre  Apellido  Salario  Sector\n\n");

    for(int i=0; i < indice; i++)
    {
        showEmployee(lista, indice);
    }
}

/** \brief Borra los datos de un empleado, dandolo de baja.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \return int todoOk flag para indicar si la operacion se dio con exito.
 *
 */

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

/** \brief Despliega las opciones del menu de informes.
 * \return int opcion la opcion elegida por el usuario.
 *
 */

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

/** \brief Ordena los empleados por apellido.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \return int 0 si la operacion se ejecuto correctamente.
 *
 */

int sortEmployeesByLastName(sEmployee lista[], int tame)
{
    char auxiliar[51];
    int indice = 0;

    for(int i = 0; i < tame - 1 ; i++)
    {
        for(int j = i+1; j < tame; j++)
        {
            if( strcmp(lista[i].lastName,lista[j].lastName))
            {
                strcpy(auxiliar, lista[i].lastName);
                strcpy(lista[i].lastName, lista[j].lastName);
                strcpy(lista[j].lastName, auxiliar);
                indice++;
            }
        }
    }

    showEmployees(lista, indice);
    return 0;
}

/** \brief Ordena los empleados por el sector en el que trabajan.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \return int 0 si la operacion se ejecuto correctamente.
 *
 */

int sortEmployeesBySector(sEmployee lista[], int tame)
{
    int auxiliarSector;
    int indice = 0;

    for(int i = 0; i < tame - 1 ; i++)
    {
        for(int j = i+1; j < tame; j++)
        {
            if( lista[i].sector > lista[j].sector)
            {
                auxiliarSector = lista[i].sector;
                lista[i].sector = lista[j].sector;
                lista[j].sector = auxiliarSector;
                indice++;
            }
        }
    }

    showEmployees(lista, indice);
    return 0;
}

/** \brief Muestra el total de salarios sumados, el promedio de los salarios y la cantidad de empleados cuyo salario es mayor al promedio.
 *
 * \param lista sEmployee vector con los datos de un empleado.
 * \param int tame longitud del vector.
 * \return void
 *
 */

void showSalariesTotalPromedyMax (sEmployee lista[], int tame)
{
    int sumadorSalarios = 0;
    int contador = 0;
    float promedio;
    int salariosSobrePromedio = 0;

    for (int i=0; i < tame; i++)
    {
        sumadorSalarios += lista[i].salary;
        contador++;
    }

    promedio = (float) sumadorSalarios / contador;

    for (int j=0; j < tame; j++)
    {
        if (lista[j].salary > promedio)
        {
            salariosSobrePromedio++;
        }
    }
    printf("Salario Total \n");
    printf("%d \n\n", sumadorSalarios);

    printf("Promedio \n");
    printf("%.2f \n\n", promedio);

    printf("Salarios por encima del promedio \n");
    printf("%d \n", salariosSobrePromedio);

}
