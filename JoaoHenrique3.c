#include <stdio.h>

void calculardv() {

    int alg = 5, i, num, alla = 0, a1, a2, a3, a4, a5, soma, dv;

    printf("Digite 5 algarismos (de 0 a 9):\n");

    for(i = 1; i <= alg; i++) {
        printf("Algarismo %d: ", i);
        scanf("%d", &num);

        if (num < 0 || num > 9) {
            printf("Erro: algarismo deve ser de 0 a 9\n");
            i--; 
        } 
        else {
            alla = alla * 10 + num; 
        }
    }

    a1 = alla / 10000;
    a2 = (alla % 10000) / 1000;
    a3 = (alla % 1000) / 100;
    a4 = (alla % 100) / 10;
    a5 = alla % 10;


    soma = (a1 * 9) + (a2 * 8) + (a3 * 7) + (a4 * 6) + (a5 * 5);

    dv = (soma * 10) % 11;

    if(dv >= 10){
        dv = ((soma * 10) %  11) % 10;
    }

    printf("\nMatricula com DV (digito verificador) : %d-%d", alla, dv);

}

void mga(float m, int aprovacoes){

    float mga;
    mga = m / aprovacoes;
    printf (" > MGA = %.2f", mga);
     
}

void ida(float m, int cargahaprovado, int cargahreprovado, int cargahsemnota){

    float ida; 



}


int main(){

    calculardv();

    int cargah, i, semnota = 0, disciplinas, aprovacoes = 0, reprovacoes = 0, cargahtotal, cargahaprovado, cargahreprovado, cargahsemnota;
    float medias, m = 0;


    printf("\nInforme a quantidade de disciplinas: ");
    scanf("%d", &disciplinas);

    while(disciplinas <= 0){
        printf("\nNumero de disciplinas invalido, insira novamente: ");
        scanf("%d", &disciplinas);
    }

    for (i = 1; i <= disciplinas; i++){
        printf("\nMedia e carga horaria da disciplina %d (digite 0 0 para sair e SN X caso possua aprovacao sem nota na disciplina): ", i);
        scanf("%f %d",  &medias, &cargah);

        if(medias == 'sn'){
            semnota++;
            cargahtotal += cargah;
            cargahsemnota += cargah;
        }

        if((medias < 0 || medias > 10) || cargah < 0){
            i--;
        }

        if (medias >=  7 && cargah > 0){
            m += medias;
            aprovacoes++;
            cargahtotal += cargah;
            cargahaprovado += cargah;
        }

        else if (medias < 7 && cargah > 0){
            reprovacoes++;
            cargahtotal += cargah;
            cargahreprovado += cargah;
        }

    }


    int menu;

    printf("\n> Opcoes de calculo: ");
    printf("\n  1. Media Geral acumulada (MGA)");
    printf("\n  2. Indice de desempenho Academico (IDA)");
    printf("\n  3. Media total de Disciplinas (MTD)");
    printf("\n  4. Percentual de Aproveitamento do Aluno");
    printf("\n> Selecione uma opcao: ");
    scanf("%d", &menu);

    switch (menu){
        case 1: mga(m, aprovacoes);
            break;
        case 2: ida(m, cargahaprovado, cargahreprovado, cargahsemnota);
            break;


    }


}