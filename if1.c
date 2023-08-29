#include<stdio.h>
#include<math.h>

int main(){
    int a, b;
    printf("digite um valor para a e um valor para b: ");
    scanf("%d %d", &a, &b);
    if (a % b == 0 || b % a == 0)
        printf("sao multiplos");
    else 
        printf("nao sao multiplos");
    return 0;

}