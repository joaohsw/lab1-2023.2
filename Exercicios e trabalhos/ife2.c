#include<stdio.h>
#include<math.h>

int main(){

    float b1, b2, b3, b4;

    printf("Digite o peso das 4 bolas respectivamente: ");
    scanf("%f %f %f %f", &b1, &b2, &b3, &b4);

    if(b1 == b2 + b3 + b4 && b2 + b3 == b4 && b2 == b3)
        printf("O mobile esta equilibrado");

        else
            printf("O mobile nao esta equilibrado");





}