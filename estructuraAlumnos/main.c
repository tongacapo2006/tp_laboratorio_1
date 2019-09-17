#include <stdio.h>
#include <stdlib.h>

#define TAM 5
// Las estructuras funcionan como variables que almacenan otras variables dentro de ellas.
// Pueden ser declaradas como un tipo de variable "personalizada".

typedef struct
{ //Definis que la estructura es un nuevo tipo de variable

    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int notaParcial1;
    int notaParcial2;
    float promedio;

}eAlumno; // tipo de variable de la estructura ( lo define uno mismo).

void mostrarAlumno (eAlumno al); //al es el nombre de la variable/estructura de tipo eAlumno.
void mostrarAlumnos (eAlumno vec[], int tam); // Defino veç como vector de tipo eAlumno, de tamaño tam.


int main()
{
    eAlumno alumno1;

    for (i = 0; i < TAM; i++)
    {
        printf("Introduzca numero de legajo: ");
        scanf("%d", &legajo);

        printf("Introduzca nombre del alumno: ");
        scanf("%s", nombre);

        printf("Introduzca la edad: ");
        scanf("%d", &edad);

        printf("Introduzca el sexo: ");
        scanf("%c", &sexo);

        printf("Introduzca nota del primer parcial: ");
        scanf("%d", &notaParcial1);

        printf("Introduzca nota del segundo parcial: ");
        scanf("%d", &notaParcial2);

        promedio = (float) (notaParcial1 + notaParcial2) / 2;

    }
    return 0;
}

void mostrarAlumno(eAlumno al)
{
    printf(" %d  %s  %d  %c  %2d  %2d  %2f\n",
            al.legajo,
            al.nombre,
            al.edad,
            al.sexo,
            al.notaParcial1,
            al.notaParcial2,
            al.promedio);
}
