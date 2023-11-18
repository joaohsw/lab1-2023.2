#include <stdio.h>

int main(){
    int m, n, aux;
    printf("Informe o valor de m e n: ");
    scanf("%d %d", &m, &n);

    while(m > 0 && n > 0){
        while(m < n){
            aux = m++;
            }

        printf("A soma dos n inteiros consecutivos a partir de m: %d", m + aux + n + n++);
        printf("\nInforme o valor de m e n: ");
        scanf("%d %d", &m, &n);       

    }

    return 0;
    




    
        
}
