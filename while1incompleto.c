#include <stdio.h>

int main(){
    int num, primo, cont, p, i;
    cont = 0;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    for (i = primo; i <= 99; i++)

    while(num > 0){
        if (num % i != 0 && num % 1 == 0 && num % num == 0){
            cont++;
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);
        }
    }

    printf("Numeros primos: %d", cont);
    return 0;
}
