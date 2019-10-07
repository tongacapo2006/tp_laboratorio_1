#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "clientes.h"

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


int main()
{
    int codigo = 1000;
    char salir = 'n';
    eCliente cliente [TAMC];

    inicializarClientes(cliente, TAMC);

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
