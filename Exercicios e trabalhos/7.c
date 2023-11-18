#include<stdio.h>
#include<math.h>

int main(){
    float b, h, casab, casah, areatotal, arealivre, porcentagem;
    printf("Digite o comprimento e a largura do terreno respectivamente: ");
    scanf("%f %f", &b, &h);
    printf("Digite o comprimento e a largura da casa respectivamente: ");
    scanf("%f %f", &casab, &casah);
    areatotal = b * h;
    arealivre = areatotal - casab * casah;
    porcentagem = areatotal * porcentagem == arealivre * 100;
    printf("Area livre em metros quadrados: %.2f\nArea livre em porcentagem: %.2f", arealivre, porcentagem);


}