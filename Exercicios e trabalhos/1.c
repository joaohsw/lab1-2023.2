#include<stdio.h>
#include<math.h>

int main(){
    float ms;
    float kmh;

    printf("Informe uma velocidade em m/s: ");
    scanf("%f", &ms);
    kmh = ms * 3.6;
    printf("Velocidade em m/s: %.1f\nVelocidade em km/h: %.1f", ms, kmh);
}