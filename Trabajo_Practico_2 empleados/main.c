#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "empleados.h"

#define TAME 5

int main()
{
    int id = 1;
    char salir = 'n';
    sEmployee empleado [TAME];
    int cargaEmpleado = 0;

    initEmployees(empleado, TAME);

    do
    {
        switch ( menu())
        {
            case 1:
                if (addEmployee(empleado, TAME, id))
                {
                    id++;
                    cargaEmpleado = 1;
                }
                break;

            case 2:
                if (cargaEmpleado)
                {
                    modifyEmployee(empleado, TAME);
                }
                else
                {
                    printf("Aun no se ha registrado ningun empleado. Cargue los datos de al menos uno para usar esta funcion. \n");
                }

                break;

            case 3:
                if (cargaEmpleado)
                {
                    removeEmployee(empleado, TAME);
                }
                else
                {
                    printf("Aun no se ha registrado ningun empleado. Cargue los datos de al menos uno para usar esta funcion. \n");
                }

                break;

            case 4:
                if (cargaEmpleado)
                {
                    switch (menuInformar())
                        {
                            case 1:
                                sortEmployeesByLastName(empleado, TAME);
                                break;

                            case 2:
                                sortEmployeesBySector(empleado, TAME);
                                break;

                            case 3:
                                showSalariesTotalPromedyMax(empleado, TAME);
                                break;

                            case 4:
                                printf("Seguro que desea salir? \n");
                                fflush(stdin);
                                salir = getche();
                                break;
                    }
                }
                else
                {
                    printf("Aun no se ha registrado ningun empleado. Cargue los datos de al menos uno para usar esta funcion. \n");
                }
                break;

            default:
                printf("Error. Ingrese una opcion valida. \n");
        }
        system("pause");
    }while (salir == 'n');

    return 0;
}

