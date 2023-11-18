#include <stdio.h>

int main(){

int num, i;


for (i = 0; i < 20; i++){
    printf("Digite 20 valores: ");
    scanf("%d", &num);
    printf("%d", num);
    if (num > i++)
        printf ("%d", num);

}





}