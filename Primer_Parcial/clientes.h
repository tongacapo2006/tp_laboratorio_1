#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

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

#endif // CLIENTES_H_INCLUDED

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
