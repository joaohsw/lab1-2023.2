#include <stdio.h>

int inteirot(){

    int i, t;

    printf("Digite um valor inteiro e positivo t: ");

    for(i = 0; i < 1; i++){
        scanf("%d", &t);
        if(t > 0){
            return t;
        }
        if(t <= 0){
            printf("Numero negativo ou nulo, digite novamente: ");
            i--;
        }
    }
}

float realn(){

    float n;
    int i;

    printf("\nDigite um valor real e positivo n: ");

    for(i = 0; i < 1; i++){
        scanf("%f", &n);
        if(n > 0){
            return n;
        }
        if(n <= 0){
            printf("Numero negativo ou nulo, digite novamente: ");
            i--;
        }
    }
}

int main(){

    int t = inteirot();
    float v1[t], v2[t], v3[t * 2], v4[t * 2], v5[t], v6[t];

    int i, j, aux = 0, aux1 = 0;

    printf("\n> Vetor 1\n");

    for (i = 0; i < t; i++) {
        printf("\nV1> Insira um elemento na posicao %d: ", i);
        scanf("%f", &v1[i]);

        for (j = 0; j < i; j++) {
            if (v1[i] == v1[j]) {
                printf("\nValor repetido, digite novamente: ");
                i--;
                break;
            }
        }
    }

    printf("\n> Vetor 2\n");

    for (i = 0; i < t; i++) {
        printf("\nV2> Insira um elemento na posicao %d: ", i);
        scanf("%f", &v2[i]);

        for (j = 0; j < i; j++) {
            if (v2[i] == v2[j]) {
                printf("\nValor repetido, digite novamente: ");
                i--;
                break;
            }
        }
    }
  
    float n = realn();

    for (i = 0; i < (t * 2); i++){  
        if (i % 2 == 0 && aux == 1){
            v3[i] = v2[i/2];
            aux = 0;
        }
        else if (i % 2 == 0 && aux == 0){
            v3[i] = v1[i/2];
            aux = 1;
        }
        else if (i % 2 != 0 && aux1 == 1){
            v3[i] = v1[i/2];
            aux1 = 0;
        }
        else if (i % 2 != 0 && aux1 == 0){
            v3[i] = v2[i/2];
            aux1 = 1;
        }
    }

    printf("\n");

    int aux2 = 1;

    for(i = 0; i < (t * 2); i++){
        v4[i] = v3[(t * 2) - aux2++];
        if((int)v4[i] % 2 == 0){
            v4[i] = v4[i] + n;
        }
        else if((int)v4[i] % 2 != 0){
            v4[i] = v4[i] + (2 * n);
        }
    }

    for (i = 0; i < (t * 2); i++){
        if (i % 2 == 0 && aux == 1){
            v6[i / 2] = v4[i];
            aux = 0;
        }
        else if (i % 2 == 0 && aux == 0){
            v5[i / 2] = v4[i];
            aux = 1;
        }
        else if (i % 2 != 0 && aux1 == 1){
            v5[i / 2] = v4[i];
            aux1 = 0;
        }
        else if (i % 2 != 0 && aux1 == 0){
            v6[i / 2] = v4[i];
            aux1 = 1;
        }
    }

    for (i = 0; i < t; i++){
        if(i % 2 == 0){
            v5[i] -= 0.5; 
            v6[i] -= 0.5;
        }
        else if(i % 2 != 0){
            v5[i] -= 1; 
            v6[i] -= 1;
        }
    }

    printf("\n< t: %d", t);

    printf("\n< n: %.2f", n);

    printf("\n< v1: ");
    for(i = 0; i < t; i++){
        printf("%.2f ", v1[i]);
    }

    printf("\n< v2: ");
    for(i = 0; i < t; i++){
        printf("%.2f ", v2[i]);
    }

    printf("\n< v3: ");
    for(i = 0; i < (t * 2); i++){
        printf("%.2f ", v3[i]);
    }

    printf("\n< v4: ");
    for(i = 0; i < (t * 2); i++){
        printf("%.2f ", v4[i]);
    }

    printf("\n< v5: ");

    for(i = (t - 1); i >= 0; i--){
        printf("%.2f ", v5[i]);
    }

    printf("\n< v6: ");
    for(i = (t - 1); i >= 0; i--){
        printf("%.2f ", v6[i]);
    }

}