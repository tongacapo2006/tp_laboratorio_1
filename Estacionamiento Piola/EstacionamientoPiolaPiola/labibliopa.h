#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int dia;
    int mes;
    int anio;

} sFecha;

typedef struct
{
    char patente[50];
    sFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
} sVehiculo;

typedef struct
{
    int id;
    char nombre[51];
    sFecha fechaNac;

} sPersona;

void hardcodePersonas(sPersona [],int);
void hardcodeoAutos(sVehiculo [],int);

void mostrarListadoPersonas(sPersona [],int);
void mostrarListadoAutitos(sVehiculo [],int, sPersona[],int);
void mostrarListadoAutitosConSusDuenios(sPersona listaPersonas[], int tp, sVehiculo listaVehiculos[], int tv);
void mostrarListadoPersonasConSusAutos(sPersona listaPersonas[], int tp, sVehiculo listaVehiculos[], int tv);

int buscarPorPatente(sVehiculo [],int);

void mostrarUnAutito(sVehiculo);
void mostrarUnAutitoConDuenio(sVehiculo, sPersona[], int);
void mostrarUnaPersona(sPersona);

int buscarIndicePersona(sPersona[], int, int);

float CalcularImportePorVehiculo(sVehiculo unAutito,float importePorHora);


