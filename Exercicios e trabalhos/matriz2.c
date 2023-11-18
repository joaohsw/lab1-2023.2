#include <stdio.h>

int main(){

    int matriz[5][5], i, j;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < 5; i++){
        for(j= 0; j < 5; j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if((i + j) % 2 == 0){
                printf("%4d", matriz[i][j]);
            }
        }
        printf("\n");
    }
}