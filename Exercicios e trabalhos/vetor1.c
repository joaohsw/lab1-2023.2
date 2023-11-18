#include <stdio.h>

int main(){

    int x, i, valores[10], cont = 0;


    printf("Digite 10 valores inteiros: ");

    for(i = 0; i < 10; i++){
        scanf("%d", &valores[i]);
    }

    printf("Digite 1 valor inteiro para verificar quantas vezes aparece no intervalo: ");
    scanf("%d", &x);

    for(i = 0; i < 10; i++){
        if (valores[i] == x){
            cont++;
        }
    }

    printf("Quantidade de vezes que x aparece no intervalo: %d", cont);
    
}
