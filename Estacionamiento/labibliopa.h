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

void mostrarPersonas(sPersona [],int);
void mostrarAutitos(sVehiculo [],int, sPersona[],int);

int buscarPorPatente(sVehiculo [],int);

void mostrarUnAutito(sVehiculo, sPersona[], int);
void mostrarUnaPersona(sPersona);

int buscarIndicePersona(sPersona[], int, int);

void mostrarPersonasConSusAutos(sPersona[], int, sVehiculo[], int);

