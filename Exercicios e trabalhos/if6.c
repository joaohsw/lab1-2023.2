#include<stdio.h>
#include<math.h>

int main(){

    float altura;
    char sexo;
    

    printf("informe respectivamente sua altura e seu sexo (masculino ou feminino): ");
    scanf("%f %c", &altura, &sexo);

    if(sexo == 'm')
        printf("Seu peso ideal eh: %.2f", (72.7 * altura) - 58);
    else
        if(sexo == 'f')
            printf("Seu peso ideal eh: %.2f", (62.1 * altura) - 44.7);
    
return 0;
    

}