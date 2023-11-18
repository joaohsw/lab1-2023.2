#include<stdio.h>
#include<math.h>

int main(){

    float a, b;
    char sinal;

    printf("Digite, respectivamente, 2 numeros e um sinal para efetuar a operacao: ");
    scanf("%f %f %c", &a, &b, &sinal);
       
            if(sinal == '+')
                printf("\nResultado da soma = %.2f", a + b);
            
                else

                    if(sinal == '-')
                        printf("\nResultado da subtracao = %.2f", a - b);
                        
                        else

                            if(sinal == '/' && b == 0)
                                printf("\nNao eh possivel dividir por 0");

                                    else

                                        if(sinal == '/')
                                        printf("\nResultado da divisao = %.2f", a / b);
                                    
                                            else
                                                if(sinal == '*')
                                                printf("\nResultado da multiplicacao = %.2f", a * b);

                                    
                                
                        
                            
                                

            
    return 0;
    

}