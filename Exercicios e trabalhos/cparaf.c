#include<stdio.h>
#include<math.h>

int main(){
   float C;
   printf("Digite uma temperatura em Celcius para conversao:");
   scanf("%f", &C);
   printf("Valor em Celcius: %.2f\nValor convertido para Fahrenheit: %.2f", C, C * 1.8 + 32);
   
}