#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define TAMC 5
/*
typedef struct
{
    int id;
    char descripcion [51];

}eCategoria;

typedef struct
{
    int codigo;
    char descripcion [21];
    int importe;
    eCategoria idCategoria;

}eJuego;

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaAlquiler;

}eAlquiler;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;
*/

typedef struct
{
    int codigo;
    char nombre [51];
    char apellido [51];
    char sexo;
    char telefono [21];
    char domicilio [51];
    int isEmpty;

}eCliente;

int menu ();
int inicializarClientes(eCliente lista[], int tamC);
int altaCliente(eCliente lista[], int tamC, int codigo);
eCliente nuevoCliente (int codigo, char nombre[], char apellido[], char sexo, char telefono[], char domicilio []);
int buscarLibre(eCliente lista[], int tamC);
int buscarEmpleadoPorCodigo(eCliente lista[], int tamC, int codigo);
int modificarCliente(eCliente lista[], int tamC);
void mostrarCliente(eCliente lista[], int indice);
void mostrarClientes(eCliente lista[], int tamC);
int bajaCliente(eCliente lista[], int tamC);
int ordenarClientesPorNombre(eCliente lista[], int tamC);
int hardcodearClientes( eCliente lista[], int tamC, int cantidad);

// biblioteca Validaciones
int validarNombre(char nombre[]);
int validarApellido(char apellido[]);
int validarSexo(char sexo);
int validarTelefono(char telefono[]);

// biblioteca Alquileres

int main()
{
    int codigo = 1000;
    char salir = 'n';
    eCliente cliente [TAMC];

    inicializarClientes(cliente, TAMC);
    codigo = codigo + hardcodearClientes(cliente, TAMC, 4);

    do
    {
        switch ( menu())
        {
            case 1:
                if (altaCliente(cliente, TAMC, codigo))
                {
                    codigo++;
                }
                break;

            case 2:
                modificarCliente(cliente, TAMC);
                break;

            case 3:
                bajaCliente(cliente, TAMC);
                break;

            case 4:
                ordenarClientesPorNombre(cliente, TAMC);
                mostrarClientes(cliente, TAMC);
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
        while (validarNombre(nombre))
        {
            printf("Error. Ingrese nombre del cliente: ");
            fflush(stdin);
            gets(nombre);
        }

        printf("Ingrese apellido del cliente: ");
        fflush(stdin);
        gets(apellido);
        while (validarApellido(apellido))
        {
            printf("Error. Ingrese apellido del cliente: ");
            fflush(stdin);
            gets(apellido);
        }

        printf("Ingrese sexo del cliente: ");
        scanf("%c", &sexo);
        while (validarSexo(sexo))
        {
            printf("Error. Ingrese sexo del cliente: ");
            scanf("%c", &sexo);
        }

        printf("Ingrese el telefono del cliente: ");
        fflush(stdin);
        gets(telefono);
        while (validarTelefono(telefono))
        {
            printf("Error. Ingrese el telefono del cliente: ");
            fflush(stdin);
            gets(telefono);
        }

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
            printf("Ingrese el telefono: \n");
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
            mostrarCliente(lista, i);
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

int validarNombre(char nombre[])
{
    int nombreIncorrecto = 0;

    for (int i = 0; i < strlen(nombre); i++ )
    {
        if (nombre[i] > 'z' || nombre[i] < 'a')
        {
            nombreIncorrecto = 1;
            break;
        }
    }

    return nombreIncorrecto;
}
int validarApellido(char apellido[])
{
    int apellidoIncorrecto = 0;

    for (int i = 0; i < strlen(apellido); i++ )
    {
        if (apellido[i] > 'z' || apellido[i] < 'a')
        {
            apellidoIncorrecto = 1;
            break;
        }
    }

    return apellidoIncorrecto;
}
int validarSexo(char sexo)
{
    int sexoIncorrecto = 0;

    if (sexo != 'm' && sexo != 'f')
        {
            sexoIncorrecto = 1;
        }

    return sexoIncorrecto;
}
int validarTelefono(char telefono[])
{
    int telefonoIncorrecto = 0;

    for (int i = 0; i < strlen(telefono); i++ )
    {
        if (telefono[i] <= '/' || telefono[i] >= ':')
        {
            telefonoIncorrecto = 1;
            break;
        }
    }

    return telefonoIncorrecto;
}

int hardcodearClientes( eCliente lista[], int tamC, int cantidad)
{
    int cont = 0;

    eCliente clientesTruchos[]=
    {
        { 1000, "Juan", "Pereyra", 'm', "1544968711", "Calle Falsa 123"},
        { 1001, "Mayra", "Sofovich", 'f', "1584795569", "Araos 2064"},
        { 1002, "Esteban", "Quito", 'm', "1569696969", "Ynicaragua 1200"},
        { 1003, "Jose", "maria", 'm', "01146625988", "Jose C Paz 666"},
        { 1004, "Maria", "jose", 'f', "1520045648", "Calle Cheta 94"},
    };

    if( cantidad <= 5 && tamC >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            lista[i] = clientesTruchos[i];
            cont++;
        }
    }

    return cont;
}
