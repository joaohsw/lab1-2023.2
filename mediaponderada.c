#include<stdio.h>
#include<math.h>

int main(){
    float x;
    float y;
    scanf("%f %f", &x, &y);
    printf("Nota 1 (peso 4): %.2f\nNota 2 (peso 2): %.2f\nMedia ponderada: %f", x, y, (x*4 + y*2)/6);
   

}