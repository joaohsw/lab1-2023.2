#include<stdio.h>
#include<math.h>

int main(){
    int a, b, c, delta, eq2;
    printf("defina valores para a, b e c respectivamente: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0)
        printf ("a equacao eh de primeiro grau");
    else
        delta = b^2 - 4*a*c;
        eq2 = ((b - b*2) + (sqrt(delta))) /2*a;
        printf("a raiz da equacao eh igual a: %d", delta);

}