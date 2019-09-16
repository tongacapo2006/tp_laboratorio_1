#include <stdio.h>
#include <stdlib.h>

void mostrarVectorChar(char* vec, int tam);

//void mostrarVectorChar(char vec[], int tam);

int main()
{
    char sexos[5];
    int contM = 0;
    int contF = 0;

    for(int i=0; i < 5; i++){

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        while(sexos[i] != 'f' && sexos[i] != 'm'){
            printf("Error. Reingrese sexo: ");
            fflush(stdin);
            scanf("%c", &sexos[i]);
        }
    }

    mostrarVectorChar(sexos, 5);

    printf("\n\n");


     for(int i=0; i < 5; i++){
           if( sexos[i] == 'f'){
            contF++;
           }
           else{
            contM++;
           }
     }

     printf("Cantidad de masculinos %d\n", contM);
     printf("Cantidad de femeninos %d\n\n", contF);


    return 0;
}


void mostrarVectorCharPuntero(char* vec, int tam){
    for(int i = 0; i < tam; i++){
        printf("%c ", *(vec + i));
    }
}

void mostrarVectorCharVectorial(char vec[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%c ", vec[i]);
    }
}
