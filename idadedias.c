#include<stdio.h>
#include<math.h>

int main(){
   int idade;
   printf("Digite sua idade: ");
   scanf("%d", &idade);
   printf("Sua idade em anos: %d\nSua idade em dias: %d", idade, idade * 365);
   
}