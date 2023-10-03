#include <stdio.h>

int main(){

    int matriz[5][5], i, j, matrizdoiscinco, matrizcincodois;

    printf("Digite uma matriz 5x5: ");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(i = 2){
                i = 5;
            }
            if(i = 5){
                i = 2;
            }

            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }





}