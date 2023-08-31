#include<stdio.h>
#include<math.h>

int main(){

    int a, b, c;
    printf("Jogo 2 ou 1 - digite 3 valores de 2 ou 1 para Ana, Bob e Caren respectivamente: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a > 2 || b > 2 || c > 2)
        printf("O numero precisa ser 1 ou 2");

        else if(a == b == c)
            printf("*");

            else if(a > b && a > c)
                printf("Ana ganhou");

                else if(a < b && a < c)
                    printf ("Ana ganhou");

                    else if(b > a && b > c)
                        printf("Bob ganhou");

                        else if(b < a && b < c)
                            printf("Bob ganhou");

                            else if(c > a && c > b)
                                printf("Caren ganhou");

                                else if(c < a && c < b)
                                    printf("Caren ganhou");



}