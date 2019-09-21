#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 3


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{

    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int notaParcial1;
    int notaParcial2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty; //Inicializo el en 1 para la primer carga de alumno, de manera que sea que el struct no tiene ningun alumno cargado.

} eAlumno;

void mostrarAlumno( eAlumno al);
void mostrarAlumnos( eAlumno vec[], int tam);
void ordenarAlumnosLeg( eAlumno vec[], int tam);
void ordenarAlumnosNombre( eAlumno vec[], int tam);
void inicializarAlumnos (eAlumno vec[], int tam);
int buscarLibre (eAlumno vec[], int tam);
int buscarAlumno (int legajo, eAlumno vec[], int tam);
int altaAlumno (eAlumno vec [], int tam);

int menu();

int main()
{
    //eAlumno alumno1;
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos(lista, TAM);

    do
    {
        switch ( menu())
        {
        case 1:
            printf("Alta alumno\n");
            break;

        case 2:
            printf("Baja alumno\n");
            break;

        case 3:
            printf("Modificar alumno\n");
            break;

        case 4:
            printf("Listar alumno\n");
            mostrarAlumno(eAlumno);
            break;

        case 5:
            printf("Ordenar alumno\n");
            break;

        case 6:
            printf("Informe alumno\n");
            break;

        case 7:
            printf("Confirma salir?: \n");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("Opcion invalida!");
            break;
    }
    }while (salir == 'n');

    /*
        for(int i=0; i < TAM; i++){

        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);

        printf("Ingrese edad: ");
        scanf("%d", &lista[i].edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);

        printf("Ingrese nota parcial 1: ");
        scanf("%d", &lista[i].notaParcial1);

        printf("Ingrese nota parcial 2: ");
        scanf("%d", &lista[i].notaParcial2);

        printf("Ingrese dia ingreso: ");
        scanf("%d", &lista[i].fechaIngreso.dia);

        printf("Ingrese mes ingreso: ");
        scanf("%d", &lista[i].fechaIngreso.mes);

        printf("Ingrese anio ingreso: ");
        scanf("%d", &lista[i].fechaIngreso.anio);

        printf("Ingrese fecha ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &lista[i].fechaIngreso.dia, &lista[i].fechaIngreso.mes, &lista[i].fechaIngreso.anio );

        lista[i].promedio = (float) (lista[i].notaParcial1 + lista[i].notaParcial2) / 2;

        }*/
    mostrarAlumnos(lista, TAM);

    ordenarAlumnosLeg(lista, TAM);

    mostrarAlumnos(lista, TAM);

    ordenarAlumnosNombre(lista, TAM);

    mostrarAlumnos(lista, TAM);

    return 0;
}


int menu ()
{
    system("cls"); // Limpio pantalla
    printf("------- ABM ALUMNOS -------\n\n");
    printf("1. Alta de alumno\n");
    printf("2. Baja de alumno\n");
    printf("3. Modificar alumno\n");
    printf("4. Listar alumnos\n");
    printf("5. Ordenar alumno\n");
    printf("6. Informar alumno\n");
    printf("7. Salir\n");


}


void mostrarAlumno(eAlumno al)
{

    printf("%d %10s  %d  %c  %2d  %2d  %.2f %02d/%02d/%d\n",
           al.legajo,
           al.nombre,
           al.edad,
           al.sexo,
           al.notaParcial1,
           al.notaParcial2,
           al.promedio,
           al.fechaIngreso.dia,
           al.fechaIngreso.mes,
           al.fechaIngreso.anio
          );
}

void mostrarAlumnos( eAlumno vec[], int tam)
{
    int flag = 0;
    system("cls");

    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio fechaIngreso\n");
    for(int i= 0; i < tam; i++)
    {
        if (vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag = 1;
        }

        if (flag == 0)
        {
            printf("\nNo hay alumnos que mostrar.\n");
        }
    }
    printf("\n\n");
}

void ordenarAlumnosLeg( eAlumno vec[], int tam)
{
    eAlumno auxAlumno;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if( vec[i].legajo > vec[j].legajo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

    void ordenarAlumnosNombre( eAlumno vec[], int tam)
    {
        eAlumno auxAlumno;

        for(int i=0; i < tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if( strcmp(vec[i].nombre, vec[j].nombre) > 0)
                {
                    auxAlumno = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxAlumno;
                }
            }
        }
    }

void inicializarAlumnos (eAlumno vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int buscarLibre (eAlumno vec[], int tam)
{
    int indice = -1; //inicializo que no hay lugar en ningun del vector.

    for (int i = 0; i < tam; i++)
    {
        if (vec[i].isEmpty == 1) // Si en el indice i isEmpty es verdadero (es decir, hay lugar en ese indice del vector)...
        {
            indice = i; // el indice pasa a ser el indice en el que hay lugar.
            break; // corto el for para que no siga iterando luego de encontrar lugar.
        }
    }

    return indice;
}

int buscarAlumno (int legajo, eAlumno vec[], int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (vec[i].legajo = legajo && vec[i].isEmpty == 0) //si el legajo que existe en eAlumno (si existe) es igual al legajo introducido y no hay espacio en ese indice del vector (porque el nro de legajo haya existido antes pero haya sido dado de baja)...
        {
            indice = i;
            break;
        }

    return indice;
}

int altaAlumno (eAlumno vec [], int tam) // chequeo si esta todo disponible para la carga de un nuevo alumno.
{
    int todoOk = 0;
    int indice;
    int legajoYaExistente;
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int n1;
    int n2;
    eFecha fecha;
    int promedio;

    system("cls");

    printf("----Alta de Alumno----\n\n");

    indice = buscarLibre(vec, tam);

    if (indice == -1)
    {
        printf("Sistema completo.\n");
    }

    else
    {
        printf("Ingrese nro de legajo: \n");
        scanf("%d", &legajo);

        legajoYaExistente = buscarAlumno(legajo, vec, tam);
        if (legajoYaExistente != -1)
        {
            printf("El legajo ingresado pertenece a un alumno existente.\n");
            mostrarAlumno(vec[indice]);
        }

        printf("Ingrese nombre del alumno: \n");
        scanf("%s", &nombre);

        printf("Ingrese la edad: \n");
        scanf("%d", &edad);

        printf("Ingrese el sexo: n");
        scanf("%c", &sexo);

        printf("Ingrese nota del primer parcial: \n");
        scanf("&d", &n1);

        printf("Ingrese nota del segundo parcial: \n");
        scanf("%d", &n2);

        printf("Ingrese la fecha: \n");
        scanf("%d %d %d", eFecha.dia, eFecha.mes, eFecha.anio);

        promedio = (float) (vec.notaParcial1 + vec.notaParcial2) / 2;

        todoOk = 1;
        printf("Alta dada con exito!!\n");
    }

    return todoOk;
}
