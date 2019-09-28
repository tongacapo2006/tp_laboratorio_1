#include "labibliopa.h"
#define AUTOS 10
#define PERSONAS 4

/*
    1.Cada auto con el nombre de su dueño
    2.Por cada dueño los autos que tiene estacionados.
    3.Ingresar un dueño y mostrar todos sus autos.
    4.Mostrar el total de la estadia de cada auto, sabiendo que
      el valor hora es $100
    5.Mostrar cuanto debera pagar cada dueño por todos sus autos estacionados
    6.Mostrar el/los dueños con mas autos estacionados


*/
int main()
{
    int i;
    sPersona listaDePersonas[PERSONAS];
    sVehiculo listaDeVehiculos[AUTOS];

    hardcodePersonas(listaDePersonas, PERSONAS);
    hardcodeoAutos(listaDeVehiculos, AUTOS);

    printf("DUE%cOS:\n",165);
    mostrarPersonas(listaDePersonas, PERSONAS);
    printf("\n\nAUTOS CON SUS DUE%cOS:\n",165);
    mostrarAutitos(listaDeVehiculos, AUTOS, listaDePersonas, PERSONAS);

    printf("\nDUE%cOS con sus autos:\n\n", 165);
    mostrarPersonasConSusAutos(listaDePersonas,PERSONAS,listaDeVehiculos,AUTOS);
    return 0;
}



