#include<stdio.h>
#include<math.h>

int main(){
    float a, b, c, delta, x1, x2;

    printf("defina valores para a, b e c respectivamente: ");
    scanf("%f %f %f", &a, &b, &c);

    delta = b*b - 4 * a * c;

    if(delta < 0){
        printf("\nDelta = %.2f\nNao possui raizes reais!\n", delta);
    }

    else{

        if(delta == 0){

            x1 = -b / (2 * a);
            printf("Delta = %.2f\nX = %.2f", delta, x1);
        }

            else{

            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("\nDELTA = %8.2f \nx'   = %8.2f\nx''  = %8.2f\n\n", delta, x1, x2);




            }
            
        }

    
    
        
    }
   
    
    
