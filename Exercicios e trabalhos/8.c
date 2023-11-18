#include<stdio.h>
#include<math.h>

int main(){
    int a, b;
    printf("Determine valores para A e B respectivamente: ");
    scanf("%d %d", &a, &b);
    printf("A = %d B = %d", a, b);
    printf("\nValor invertido de a = %d\nValor invertido de b = %d", a - a + b, b - b + a);

}