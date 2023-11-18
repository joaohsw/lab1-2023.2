#include<stdio.h>
#include<math.h>

int main(){

    float alitro, glitro, kmla, kmlg;

    printf("Digite respectivamente o preco do litro do alcool, da gasolina e os km/l do alcool e da gasolina: ");
    scanf("%f %f %f %f", &alitro, &glitro, &kmla, &kmlg);

    if(alitro / kmla == glitro / kmlg)
        printf("Abastecer com gasolina");

        else if(glitro / kmlg > alitro / kmla)
            printf("Abastecer com alcool");

            else if(glitro / kmlg < alitro / kmla)
                printf("Abastecer com gasolina");












}