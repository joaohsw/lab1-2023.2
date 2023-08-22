#include<stdio.h>
#include<math.h>

int main(){
   float p;
   printf("Digite o valor do produto: ");
   scanf("%f", &p);
   printf("Valor original: %.2f\nValor com desconto de 10%%: %.2f", p, p - p/100*10);
   printf("\nPreco base: %.2f\nPreco com 20%% de aumento: %.2f", p, p + p/100*20);
   
}