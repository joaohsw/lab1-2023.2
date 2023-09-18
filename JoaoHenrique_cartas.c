#include <stdio.h>
#include <time.h>


int estrategia1(){ // as de espadas = 1 as de bastos = 2 sete de espadas = 3

    int cartadefinida = 1 + rand() % 3;

        if (cartadefinida == 1) {
            return 10;  // 5 representa que perdeu o jogo e 10 que ganhou
        }
            else { 
                return 5;
            }
            
    }

int estrategia2() {

    int cartaescolhida = 1 + rand() % 3;

        if(cartaescolhida == 1) {
            return 5;
            }
            else {
                return 10;         
        }
    }


int main() {

    srand(time(NULL));
    int simulacao = 1000000, derrotas1 = 0, vitorias1 = 0, derrotas2 = 0, vitorias2 = 0;
    float porcentagemv1, porcentagemd1, porcentagemv2, porcentagemd2;
    
    simulacao = 1000000;

    for (int i = 1; i <= simulacao; i++) {

        int resultado1 = estrategia1();

        if (resultado1 == 5) {
            derrotas1++;
        }
        if (resultado1 == 10) {
            vitorias1++;
        }
    }

    for (int i = 1; i <= simulacao; i++) {

        int resultado2 = estrategia2();

        if (resultado2 == 5){
            derrotas2++;
        }
        if (resultado2 == 10){
            vitorias2++;
        }      
    }

    porcentagemv1 = (float)vitorias1 / simulacao * 100;
    porcentagemd1 = (float)derrotas1 / simulacao * 100;
    porcentagemv2 = (float)vitorias2 / simulacao * 100;
    porcentagemd2 = (float)derrotas2 / simulacao * 100;
    

    printf("> Estrategia 1 (sem mudanca de carta):\n  Partidas jogadas: 1000000");
    printf("\n  Partidas ganhas: %d", vitorias1);
    printf("\n  Partidas perdidas: %d", derrotas1);
    printf("\n  Porcentagem de derrotas: %.2f%%", porcentagemd1);
    printf("\n  Porcentagem de vitorias: %.2f%%\n", porcentagemv1);

    printf("\n> Estrategia 2 (com mudanca de carta):\n  Partidas jogadas: 1000000");
    printf("\n  Partidas ganhas: %d", vitorias2);
    printf("\n  Partidas perdidas: %d", derrotas2);
    printf("\n  Porcentagem de derrotas: %.2f%%", porcentagemd2);
    printf("\n  Porcentagem de vitorias: %.2f%%\n", porcentagemv2);

    if (porcentagemv1 > porcentagemv2) {
        printf("\n> Recomendacao: estrategia 1 com %.2f%% de vitorias", porcentagemv1);
    }
    else if (porcentagemv2 > porcentagemv1) {
        printf("\n> Recomendacao: estrategia 2 com %.2f%% de vitorias", porcentagemv2);
    }
    else {
        return 0;
    }

    return 0;
    
    }
                





   






