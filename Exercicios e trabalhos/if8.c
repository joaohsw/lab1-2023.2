#include<stdio.h>
#include<math.h>

int main(){

    float a, b, c, s, area;

    printf("Digite 3 valores correspondentes as medidas dos lados de uma figura geometrica: ");
    scanf("%f %f %f", &a, &b, &c);

    s = (a + b +c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));

    if(a < (b + c) && a > fabs(b - c))
        printf("Area do triangulo = %.2f", area);

            else
                printf("Nao formam um triangulo");



}
