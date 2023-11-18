#include <stdio.h>

int main(){

    int matriz[2][3], matriztransposta[3][2], i, j;

    printf("Leia uma matriz 2x3: ");

    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(j = 0; j < 3; j++){
        for(i = 0; i < 2; i++){
            matriztransposta[j][i] = matriz[i][j];
            printf("%4d", matriztransposta[j][i]);
        }
        printf("\n");
    }


}