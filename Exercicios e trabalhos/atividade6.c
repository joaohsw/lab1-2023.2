#include <stdio.h>

int main()

{
    int x;
    float y;
    double z;
    scanf("%d %f %lf", &x, &y, &z);
    printf("Valor x: %d\nValor y: %.3f\nValor z: %.4lf", x, y, z);
    
}