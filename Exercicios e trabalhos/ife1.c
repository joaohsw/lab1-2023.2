#include<stdio.h>
#include<math.h>

int main(){

    float consumo, franquia;

    printf("Digite o consumo de agua em m3 para calcular o valor da conta: ");
    scanf("%f", &consumo);

    franquia = 7.00;

    if(consumo <= 10)
        printf("\nO valor da conta foi de %.2f", franquia);

        else
            if(consumo >= 11 && consumo <= 30)
                printf("\nO valor da conta foi de %.2f", franquia + 1);

                else
                    if(consumo >= 31 && consumo <= 100)
                        printf("\nO valor da conta foi de %.2f", franquia + 2);

                        else
                            if(consumo >= 101)
                                printf("\nO valor da conta foi de %.2f", franquia + 5);
                



}