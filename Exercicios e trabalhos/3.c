#include<stdio.h>
#include<math.h>

int main(){
    float b, h, area;
    printf("Insira o valor da base e altura do triangulo respectivamente: ");
    scanf("%f %f", &b, &h);
    area = b*h/2;
    printf("Area do triangulo: %.2f", area);

}