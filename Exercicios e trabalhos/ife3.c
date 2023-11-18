#include<stdio.h>
#include<math.h>

int main(){

    int a, b, c;
    printf("Insira a pontuacao dos 3 competidores :");
    scanf("%d %d %d", &a, &b, &c);
     
    if(a > b && c > a)
        printf("A segundo colocado");

        else if(b > a && c > b)
            printf("B segundo colocado");

            else if(c > a && b > c)
                printf("C segundo colocado");

                else if(a > c && b > a)
                    printf("A segundo colocado");

                    else if(b > c && a > b)
                        printf("B segundo colocado");

                        else if(c > b && a > c)
                            printf("C segundo colocado");

                            else
                                printf("Nao pode haver empate");
    
}