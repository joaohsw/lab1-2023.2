#include <stdio.h>

int main(){

    int matriz[2][2], i, j, determinante;

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    determinante = matriz[0][0] * matriz [1][1] - matriz[1][0] * matriz[0][1];

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nDeterminante = %d", determinante);


}