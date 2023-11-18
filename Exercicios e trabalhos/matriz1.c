#include <stdio.h>


int main(){

    int i, j, matriz[10][10];

    printf("Digite os valores de uma matriz 10x10: ");

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if (i + j != matriz[i][j] + 1){
                printf("%4d", matriz[i][j]);
            }
        }
    }

}
