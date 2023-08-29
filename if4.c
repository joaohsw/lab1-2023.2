#include<stdio.h>
#include<math.h>

int main(){
    int a;
    printf("digite um numero: ");
    scanf("%d", &a);
    if (a % 7 == 0 && a % 3 == 0)
        printf("divisivel por 3 e 7");
    else 
        printf("nao divisivel por 3 e 7");
    return 0;

}