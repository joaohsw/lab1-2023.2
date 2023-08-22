#include<stdio.h>
#include<math.h>

int main(){
   int inteiro;
   printf("Digite um numero inteiro com 3 algarismos: ");
   scanf("%d", &inteiro);
   printf("Numero digitado: %d\nAlgarismo das dezenas: %d", inteiro, (inteiro % 100)/10);
}