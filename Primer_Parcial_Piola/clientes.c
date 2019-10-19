#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

int menu ()
{
    int opcion;
    system("cls");
    printf("   ***   Bienvenido al Sistema ABM de Clientes   ***   \n\n");
    printf("Seleccione una opcion: \n\n");
    printf("1_ Alta de cliente.\n");
    printf("2_ Modificar cliente.\n");
    printf("3_ Baja de cliente.\n");
    printf("4_ Informe de clientes.\n");
    scanf("%d", &opcion);

    return opcion;
}

int inicializarClientes(eCliente lista[], int tamC)
{
    for (int i=0; i<tamC; i++)
    {
        lista[i].isEmpty = 1;
    }

    return 0;
}

int altaCliente(eCliente lista[], int tamC, int codigo)
{
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio [21];
    int todoOk;
    int indice;

    system("cls");

    printf("**  Alta de cliente  **\n\n");

    indice = buscarLibre(lista, tamC);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre del cliente: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese apellido del cliente: ");
        fflush(stdin);
        gets(apellido);

        printf("Ingrese sexo del cliente: ");
        scanf("%c", &sexo);

        printf("Ingrese el telefono del cliente: ");
        fflush(stdin);
        gets(telefono);

        printf("Ingrese el domicilio del cliente: ");
        fflush(stdin);
        gets(domicilio);

        lista[indice] = nuevoCliente(codigo, nombre, apellido, sexo, telefono, domicilio);

        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eCliente nuevoCliente (int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio [])
{
    eCliente cl;
    cl.codigo = codigo;
    strcpy( cl.nombre, nombre);
    strcpy ( cl.apellido, apellido);
    cl.sexo = sexo;
    strcpy (cl.telefono, telefono);
    strcpy (cl.domicilio, domicilio);
    cl.isEmpty = 0;

    return cl;
}

int buscarLibre(eCliente lista[], int tamC)
{
    int indice = -1;

    for(int i=0; i < tamC; i++)
    {
        if( lista[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleadoPorCodigo(eCliente lista[], int tamC, int codigo)
{
    int indice = -1;

    for(int i=0; i < tamC; i++)
    {
        if( lista[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int modificarCliente(eCliente lista[], int tamC)
{
    int todoOk = 0;
    int codigo;
    int indice;
    system("cls");
    printf("***** Modificar Cliente *****\n\n");
    printf("Ingrese codigo del Cliente: ");
    scanf("%d", &codigo);
    int opcion;

    indice = buscarEmpleadoPorCodigo(lista, tamC, codigo);

    if( lista[indice].isEmpty == 1)
    {
        printf("Ese codigo no pertenece a ningun cliente registrado.\n\n");
    }
    else
    {
        mostrarCliente(lista, indice);

        printf("Seleccione el campo que desee modificar: \n");
        printf("1- Nombre \n");
        printf("2- Domicilio \n");
        printf("3- Telefono \n");
        printf("4- Salir\n\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nombre: ");
            scanf("%10s", &lista[indice].nombre);
            break;

        case 2:
            printf("Ingrese el domicilio: ");
            scanf("%20s", &lista[indice].domicilio);
            break;

        case 3:
            printf("Ingrese el salaraio: \n");
            scanf("%20s", &lista[indice].telefono);
            break;

        case 4:
            printf("Se ha cancelado la modificacion \n");
            break;
        }
    }
    return todoOk;
}

void mostrarCliente(eCliente lista[], int indice)
{
    printf(" %d \t %s \t %s \t %c \t %s \t %s \n",
    lista[indice].codigo, lista[indice].nombre, lista[indice].apellido, lista[indice].sexo, lista[indice].telefono, lista[indice].domicilio);
}

void mostrarClientes(eCliente lista[], int tamC)
{

    int flag = 0;
    system("cls");

    printf(" Codigo    Nombre    Apellido   Sexo  Telefono   Domicilio\n\n");

    for(int i=0; i < tamC ; i++)
    {
        if( lista[i].isEmpty == 0)
        {
            mostrarCliente(lista, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay clientes que mostrar\n");
    }

    printf("\n\n");
}

int bajaCliente(eCliente lista[], int tamC)
{
    int todoOk = 0;
    int codigo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja de Cliente *****\n\n");
    printf("Ingrese codigo del Cliente: \n");
    scanf("%d", &codigo);

    indice = buscarEmpleadoPorCodigo(lista, tamC, codigo);

    if( lista[indice].isEmpty == 1)
    {
        printf("Ese codigo no pertenece a ningun cliente registrado. \n\n");
    }
    else
    {
        mostrarCliente(lista, indice);

        printf("\nConfirma baja? \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            lista[indice].isEmpty = 1;
            todoOk = 1;

            printf("El cliente se ha dado de baja con exito!! \n");
        }
        else
        {
            printf("Se ha cancelado la operacion. \n");
        }
    }
    return todoOk;
}

int ordenarClientesPorNombre(eCliente lista[], int tamC)
{
    char auxiliar[51];

    for(int i = 0; i < tamC - 1 ; i++)
    {
        for(int j = i+1; j < tamC; j++)
        {
            if( strcmp(lista[i].nombre,lista[j].nombre))
            {
                strcpy(auxiliar, lista[i].nombre);
                strcpy(lista[i].nombre, lista[j].nombre);
                strcpy(lista[j].nombre, auxiliar);
            }
        }
    }
    return 0;
}
