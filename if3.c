#include<stdio.h>
#include<math.h>

int main(){
    float a;
    printf("digite um numero: ");
    scanf("%f", &a);
    if (a > 0)
        printf("o numero eh %.1f e seu inverso e %.2f", a, 1 / a);
    else
        if (a < 0)
        printf("o numero eh negativo e seu valor absoluto eh %.2f", fabs(a));
    return 0;

}