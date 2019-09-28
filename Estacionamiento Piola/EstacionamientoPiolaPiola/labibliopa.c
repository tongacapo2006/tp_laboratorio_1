#include "labibliopa.h"

void hardcodePersonas(sPersona listaPersonas[],int cant)
{
    char nombre[][51]= {"Maria","Ezequiel","German","Yanina"};
    int anio[]= {1990,1980,2000,1995};
    int mes[]= {3,4,12,11};
    int dia[]= {33,22,25,11};
    int id[]= {100,101,105,106};
    int i;

    for(i=0; i<cant; i++)
    {
        listaPersonas[i].id =id[i];
        listaPersonas[i].fechaNac.anio = anio[i];
        listaPersonas[i].fechaNac.mes = mes[i];
        listaPersonas[i].fechaNac.dia = dia[i];
        strcpy(listaPersonas[i].nombre, nombre[i]);
    }
}
void hardcodeoAutos(sVehiculo listaAutitos[], int cant)
{
    int i;
    char patente[][8]= {"AAA111", "BBB222", "AAA222", "WWW777",
                        "AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"
                       };
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int horaIngreso[] = {10,9,8,11,10,11,9,7,7,14};
    int horaSalida[] = {11,11,11,12,14,15,12,10,11,17};
    int idPersona[]= {101,106,106,106,101,101,106,105,106,106};

    for(i=0; i<cant; i++)
    {
        strcpy(listaAutitos[i].patente,patente[i]);
        listaAutitos[i].fechaIngreso.dia = dia;
        listaAutitos[i].fechaIngreso.mes = mes;
        listaAutitos[i].fechaIngreso.anio = anio;
        listaAutitos[i].horaIngreso = horaIngreso[i];
        listaAutitos[i].horaSalida = horaSalida[i];
        listaAutitos[i].idDuenio = idPersona[i];
    }

}


void mostrarListadoPersonas(sPersona listaPersonas[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("%04d %20s \t %02d/%02d/%4d\n", listaPersonas[i].id,
               listaPersonas[i].nombre,
               listaPersonas[i].fechaNac.dia,
               listaPersonas[i].fechaNac.mes,
               listaPersonas[i].fechaNac.anio);


    }
}
void mostrarListadoAutitos(sVehiculo listaAutitos[], int cant, sPersona listaPersonas[], int ca)
{
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarUnAutitoConDuenio(listaAutitos[i],listaPersonas,ca);
    }
}
void mostrarUnAutito(sVehiculo unAutito)
{
    printf("%6s %02d %02d %02d/%02d/%4d", unAutito.patente,
           unAutito.horaIngreso,
           unAutito.horaSalida,
           unAutito.fechaIngreso.dia,
           unAutito.fechaIngreso.mes,
           unAutito.fechaIngreso.anio);
}
void mostrarUnAutitoConDuenio(sVehiculo unAutito,sPersona listaPersonas[], int cp)
{
    int i;

    printf("%6s %02d %02d %02d/%02d/%4d", unAutito.patente,
           unAutito.horaIngreso,
           unAutito.horaSalida,
           unAutito.fechaIngreso.dia,
           unAutito.fechaIngreso.mes,
           unAutito.fechaIngreso.anio);

    for(i=0; i<cp; i++)
    {
        if(unAutito.idDuenio==listaPersonas[i].id)
        {
            printf(" %10s\n", listaPersonas[i].nombre);
            break;
        }
    }




}

void mostrarUnaPersona(sPersona unaPersona)
{
    printf("ID : %d \n", unaPersona.id);
    printf("Nombre : %s \n", unaPersona.nombre);
    printf("Fecha de nacimiento : %d/%d/%d \n\n", unaPersona.fechaNac.dia, unaPersona.fechaNac.mes, unaPersona.fechaNac.anio);
}
void mostrarListadoPersonasConSusAutos(sPersona listaPersonas[], int tp, sVehiculo listaVehiculos[], int tv)
{
    int i;
    int j;

    for(i=0; i<tp; i++)
    {
        printf("%s:\n", listaPersonas[i].nombre);
        for(j=0; j<tv; j++)
        {
            if(listaPersonas[i].id==listaVehiculos[j].idDuenio)
            {
                mostrarUnAutito(listaVehiculos[j]);
                printf("\n");
            }
           // printf("\n");
        }
       printf("\n");
    }

}
void mostrarListadoAutitosConSusDuenios(sPersona listaPersonas[], int tp, sVehiculo listaVehiculos[], int tv)
{
    int i;
    int j;

    for(i=0; i<tv; i++)
    {
        mostrarUnAutito(listaVehiculos[i]);
        for(j=0; j<tv; j++)
        {
            if(listaVehiculos[i].idDuenio==listaPersonas[j].id)
            {
               printf(" de: %s \n",listaPersonas[j].nombre);
            }
           // printf("\n");
        }
       printf("\n");
    }

}

float CalcularImportePorVehiculo(sVehiculo unAutito,float importePorHora)
{
    float resultado;
     printf("\n%d %d : ",unAutito.horaSalida,unAutito.horaIngreso);
    resultado=(unAutito.horaSalida-unAutito.horaIngreso  )* importePorHora;
    return resultado;
}

int buscarPorPatente(sVehiculo listaAutitos[],int cant)
{
    int i;
    char patente[51];
    int idVehiculo;
    printf("\nIngresa la patente master : ");
    fflush(stdin);
    gets(patente);
    for(i=0; i<cant; i++){
        if(strcmp(listaAutitos[i].patente, patente) == 0){
            return  i;
        }
    }
    return -1;
}

int buscarIndicePersona(sPersona unaPersona[],int cant, int id)
{
    int i;
    scanf("%d",&id);
    for(i=0; i<cant; i++)
    {
        if(id == unaPersona[i].id)
        {
            return i;
        }
    }
    return -1;
}




