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

El programa deber� contar con un men� de opciones que permita:
1.	Cargar un propietario. Cargar los datos para un propietario. El Id deber� ser autoincremental.
2.	Eliminar un propietario.
3.	Modificar datos de un propietario. Desplegar un men� de opciones con los datos que se podr�n modificar.
4.	Ingresar un veh�culo. Se ingresa la patente, la fecha y la hora de entrada junto al propietario del veh�culo.
5.	Egresar un veh�culo. Se ingresa la hora de salida del veh�culo.
6.	Informar:
a.	Todas las personas ordenadas por nombre y a�o de nacimiento.
b.	Todos los veh�culos ordenados por due�o y patente.
c.	Cada auto con el nombre de su due�o.
d.	Por cada due�o los autos que tiene estacionados.
e.	Ingresar un due�o y mostrar todos sus autos.
f.	Mostrar el total de la estad�a de cada auto, sabiendo que el valor hora es $100.
g.	Mostrar cuanto deber� pagar cada due�o por todos sus autos estacionados.
h.	Mostrar el/los due�os con m�s autos estacionados.
NOTA:
1.	Todos los datos deber�n ser validados al momento del ingreso.
2.	Reutilizar c�digo.




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

    printf("\n\n\n Autos con sus due�os!\n");
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

