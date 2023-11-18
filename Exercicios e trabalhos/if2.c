#include<stdio.h>
#include<math.h>

int main(){
    int a;
    printf("digite o valor de a: ");
    scanf("%d", &a);
    if (a > 0)
        printf("o numero eh positivo");
    else 
        if (a < 0)
        printf("o numero eh negativo");
    else 
        printf("o numero eh nulo");
    return 0;   

}