#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labibliopa.h"

int main()
{
    sPersona ListadoDePersonas[4];
    hardcodePersonas(ListadoDePersonas,4);
    mostrarPersonas(ListadoDePersonas,4);

    sVehiculo ListadoDeVehiculos[4];
    hardcodeoAutos(ListadoDeVehiculos,4);

    mostrarPersonasConSusAutos(ListadoDePersonas,4,ListadoDeVehiculos,4);
    printf("\n Estacionamiento!\n");
    return 0;
}

void informesEstacionamiento (sPersona due�o [], int cantp, sVehiculo autitos [], int cantaut)
{
    char seguir == 'n';

    do
    {
        switch (menuQueQueresInformar ())
        {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;

            case 8:
                printf("Posta te queres ir?:");
                fflush(stdin);
                salir = getche();
                break;

        }
        system("pause");
    }while (seguir != 'n');
}


int menuQueQueresInformar ()
{
    int opcion;
    system("cls");

    printf("  *** BIENVENIDO AL MENU DE INFORMES!!! *** \n\n Que queres informar troesma? decime dale: \n");
    printf("1_ Tirame las personas ordenadas por nombre y nacimiento.\n");
    printf("2_ Decime los autos ordenados por due�o y patente.\n");
    printf("3_ Cada auto que tengas y sus respectivos due�os.\n");
    printf("4_ Los autos que tenga un solo due�o.\n");
    printf("5_ Te tiro un due�o y vos decime todos los autos que tenga.\n");
    printf("6_ Mostrame cuanta plata costo la estadia de cada auto.\n.");
    printf("7_ Decime cuanto tiene que garpar cada due�o por estacionar todos sus autos jaja va a quedar re pobre el logi.\n");
    printf("8_ No quiero nada sacame de aca.\n");

    return opcion;
}

/* Informar
a. Todas las personas ordenadas por nombre y a�o de nacimiento.
b. Todos los vehiculos ordenados por due�o y patente.
c. Cada auto con el nombre de su due�o.
d. Por cada due�o los autos que tiene estacionados.
e. Ingresar un due�o y mostrar todos sus autos.
f. Mostrar el total de la estadia de cada auto, sabiendo que el valor hora es $100.
g. Mostrar cuanto debera pagar cada due�o por todos sus autos estacionados.*/
