#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labibliopa.h"
/*
Estacionamiento: TeChocoTuCoche S.A
Estructuras a utilizar:
ePropietario
PK	IdPropietario
	nombre
	fechaNacimiento

eFecha
	dia
	mes
	anio

eVehiculo
PK	patente
	fechaIngreso
	horaEntrada
	horaSalida
FK	idPropietario

El programa deberá contar con un menú de opciones que permita:
1.	Cargar un propietario. Cargar los datos para un propietario. El Id deberá ser autoincremental.
2.	Eliminar un propietario.
3.	Modificar datos de un propietario. Desplegar un menú de opciones con los datos que se podrán modificar.
4.	Ingresar un vehículo. Se ingresa la patente, la fecha y la hora de entrada junto al propietario del vehículo.
5.	Egresar un vehículo. Se ingresa la hora de salida del vehículo.
6.	Informar:
a.	Todas las personas ordenadas por nombre y año de nacimiento.
b.	Todos los vehículos ordenados por dueño y patente.
c.	Cada auto con el nombre de su dueño.
d.	Por cada dueño los autos que tiene estacionados.
e.	Ingresar un dueño y mostrar todos sus autos.
f.	Mostrar el total de la estadía de cada auto, sabiendo que el valor hora es $100.
g.	Mostrar cuanto deberá pagar cada dueño por todos sus autos estacionados.
h.	Mostrar el/los dueños con más autos estacionados.
NOTA:
1.	Todos los datos deberán ser validados al momento del ingreso.
2.	Reutilizar código.




*/

int main()
{
    sPersona ListadoDePersonas[4];
    hardcodePersonas(ListadoDePersonas,4);

    printf("\n\n\n Personas!\n");
    mostrarListadoPersonas(ListadoDePersonas,4);

    sVehiculo ListadoDeVehiculos[8];
    hardcodeoAutos(ListadoDeVehiculos,8);

    printf("\n\n\n Personas con sus autos!\n");
    mostrarListadoPersonasConSusAutos(ListadoDePersonas,4,ListadoDeVehiculos,8);

    printf("\n\n\n Autos con sus dueños!\n");
    mostrarListadoAutitosConSusDuenios(ListadoDePersonas,4,ListadoDeVehiculos,8);

    printf("\n\n\n COBRAMOS LA SALIDA DE UN VEHICULO!\n");
    int indice=buscarPorPatente(ListadoDeVehiculos,8);
    if(indice!=-1)
    {
        float importeApagar=CalcularImportePorVehiculo(ListadoDeVehiculos[indice],100);
        printf("\n\ndebe pagar %f \n\n ", importeApagar);
    }else{
         printf("\nno existe  \n\n ");
    }

    printf("\n Estacionamiento!\n");
    return 0;
}

