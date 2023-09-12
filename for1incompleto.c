#include <stdio.h>

int main(){

    int inicio, fim, cont;
    printf("Informe os valores do inicio e do final de um intervalo: ");
    scanf("%d %d", &inicio, &fim);
    for (cont = inicio; cont <= fim; cont++){
        if (cont++ % 2 != 0){
            printf("%d ", cont - 1);
        }    
    }   
    for (cont++ % 2 != 0; cont <= fim; cont + cont) 
        printf ("\n%d", cont);
}
        
    
   

