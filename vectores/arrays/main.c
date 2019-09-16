#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numeros[5];
    int indice;
    int mayor;
    int flag = 0;

    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &numeros[i]);

        while( numeros[i] <= 0)
        {
            printf("Error. Ingrese un numero positivo: ");
            scanf("%d", &numeros[i]);
        }
    }

     for(int i = 0; i < 5; i++)
    {
        printf("%d ", numeros[i]);
    }


     for(int i = 0; i < 5; i++)
    {
        if( numeros[i] > mayor || flag == 0){
            mayor = numeros[i];
            flag = 1;
        }
    }

    printf("El mayor numero ingresa es %d\n y esta en el indice ", mayor);

     for(int i = 0; i < 5; i++)
    {
        if( numeros[i] == mayor){
            printf("%d ", i);
        }

    }







    return 0;
}
