#include<stdio.h>
#include<math.h>

int main(){
    float altura;
    int sexo;

    printf("informe respectivamente sua altura e seu sexo (masculino ou feminino): ");
    scanf("%f %c", &altura, &sexo);
    if (sexo == 1)
        printf("Peso ideal: %.2f", (72.7 * altura) - 58);
    else
        if (sexo == 2)
        printf("Pesoa ideal: %.2f", (62.1 * altura) - 44.7);

return 0;
    


    

}