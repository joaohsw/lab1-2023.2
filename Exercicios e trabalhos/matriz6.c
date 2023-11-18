#include <stdio.h>

int main(){

    int vetor[3], matriz[3][3], i, j, a, matrizvetor[3][3];

    printf("Digite 3 numeros: ");
    
    for(a = 0; a < 3; a++){
        scanf("%d", &vetor[a]);
    }

    printf("Digite uma matriz 3x3: ");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

     for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
     }


    printf("\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(i = 0){
                i = i * vetor[0];
            }
            if(i = 1){
                i = i * vetor[1];
            }
            if(i = 2){
                i = i * vetor[2];
            }

            printf("%4d", matrizvetor[i][j]);
        }
        printf("\n");
    }


}