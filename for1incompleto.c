#include <stdio.h>

int main() {
    int inicio, fim, cont, soma = 0;
    
    printf("Informe os valores do inicio e do final de um intervalo: ");
    scanf("%d %d", &inicio, &fim);
    
    for (cont = inicio; cont <= fim; cont++) {
        if (cont % 2 != 0) {
            printf("%d ", cont);
            soma += cont;
        }
    }

    printf("\nSoma dos numeros impares: %d\n", soma);

    return 0;
}
   

