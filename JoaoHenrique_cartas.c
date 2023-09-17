#include <stdio.h>
#include <time.h>

int estrategia1(int cartaescolhida, int cartamudada) {

    int i;
    int resultado1;

    for  (i = 1; i <= 3; i++){
        cartaescolhida = rand(i) % 3; // as de espadas = 1, as de bastos = 2, sete de espadas = 3
        for  (i = 1; i <= 3 && i != cartaescolhida; i++){
            cartamudada = rand(i) % 3;
            if(cartaescolhida == 1){
                printf("\nL");
                resultado1 == 5; // 5 representa que perdeu o jogo e 10 que ganhou
                return 0;
            }
                else if (cartamudada == 1)
                    printf("\nW");
                    resultado1 == 10;
                
        }
    }
    return resultado1;

}

int estrategia2(int cartadefinida){

    int i;
    int resultado2;

    for (i = 1; i <= 3; i++){
        cartadefinida = rand(i) % 3;
        if (cartadefinida == 1){
            printf("\nW");
            resultado2 == 10;
        }
            else 
                printf("\nL");
                resultado2 == 5;
            
    }

    return resultado2;

}

int main() {

    srand(time(NULL));
    char w, l;
    int i, simulacao, derrotas = 0, vitorias = 0, i2, derrotas2 = 0, vitorias2 = 0;
    float porcentagemv, porcentagemd, porcentagemv2, porcentagemd2;
    

    simulacao = 1000000;

    for (i = 1; i <= simulacao; i++){
        estrategia1;
            if (i == 5){
                derrotas++;
            }
            if (i == 10){
                vitorias++;
            }
                porcentagemv == vitorias / 10000;
                porcentagemd == derrotas / 10000;
    }

    for (i2 = 1; i <= simulacao; i2++){
        estrategia2;
            if (i2 == 5){
                derrotas2++;
            }
            if (i2 == 10){
                vitorias2++;
            }

                porcentagemv2 == vitorias2 / 10000;
                porcentagemd2 == derrotas2 / 10000;
    }

    printf("> Estrategia 1 (sem mudanca de carta):\n  Partidas jogadas: 1000000");
    printf("\n  Partidas ganhas: %d", vitorias2);
    printf("\n  Partidas perdidas: %d", derrotas2);
    printf("\n  Porcentagem de derrotas: %.2f%%", porcentagemd2);
    printf("\n  Porcentagem de vitorias: %.2f%%\n", porcentagemv2);

    printf("\n> Estrategia 2 (com mudanca de carta):\n  Partidas jogadas: 1000000");
    printf("\n  Partidas ganhas: %d", vitorias);
    printf("\n  Partidas perdidas: %d", derrotas);
    printf("\n  Porcentagem de derrotas: %.2f%%", porcentagemd);
    printf("\n  Porcentagem de vitorias: %.2f%%\n", porcentagemv);

    printf("\n> Recomendacao: ");

    }
                





   






