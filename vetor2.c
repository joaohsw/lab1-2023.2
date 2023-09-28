#include <stdio.h>

#define tamanho 5


int main(){

    int i;

    int reais[tamanho];

    printf("\nDigite valores positivos ou nulos para inserir no intervalo: ");
    
    for(i = 0; i < tamanho; i++){

        scanf("%d", &reais[i]);

        if(reais[i] < 0){
            i--;
            printf("Apenas numeros positivos ou nulos");
        }
    }

    for(i = 0; i < tamanho; i++){

        if(reais[i] == 0){
            reais[i] = -99;
        }

    }

    for(i = 0; i < tamanho; i++){
        printf("%d, ", reais[i]);
    }
    
}