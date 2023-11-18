#include <stdio.h>
#include <math.h>


int main(){
    
  int r;
  int x;

  printf("Digite a razao da PA e o valor do primeiro termo: ");
  scanf("%d %d", &r, &x);
  printf("r = %d\nx = %d\n13o termo = %d ", r, x, x + r * 12);

  
}