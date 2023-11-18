#include<stdio.h>
#include<math.h>

int main(){

    int x, y;

    printf("Digite uma coordenada x e uma y para decidir se a bola caiu dentro ou fora da quadra: ");
    scanf("%d %d", &x, &y);

    if(x <= 468 && x >= 0 && y <= 432 && y >= 0)
        printf("Bola dentro");

        else if(x > 468 || x < 0 || y > 432 || y < 0)
            printf("Bola fora");

    



}