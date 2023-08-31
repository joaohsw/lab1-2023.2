#include<stdio.h>
#include<math.h>

int main(){

    int nmax, na, nb;
    char caracter;

    printf("Digite, respectivamente, o numero maximo, numero, sinal (+ ou *), numero: ");
    scanf("%d %d %c %d", &nmax, &na, &caracter, &nb);

    if(na + nb >= nmax || na * nb >= nmax)
        printf("Overflow");

        else
            printf("OK");













}

    