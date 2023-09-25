#include <stdio.h>


void calculardv() {

    int alg = 5, i, num, alla = 0, a1, a2, a3, a4, a5, soma, dv;

    printf("\n> Digite os 5 ultimos algarismos (de 0 a 9) do numero de matricula:\n");

    for(i = 1; i <= alg; i++) {
        printf("  Algarismo %d: ", i);
        scanf("%d", &num);

        if (num < 0 || num > 9) {
            printf("\nErro: algarismo deve ser de 0 a 9\n");
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

    printf("\n> Matricula com DV (digito verificador) : %d-%d", alla, dv);

}

void mgaf(float m, int aprovacoes){

    float mga;
    mga = m / aprovacoes;
    
    if (aprovacoes <= 0){
        printf("\nImpossivel calcular, nenhuma aprovacao");
    }
    else if (aprovacoes > 0){
    printf (" > Media Geral Acumulada (MGA) = %.2f", mga);
    }
     
}

void ida(float maprovado, float cargahaprovado, float cargahaprovacaosn, float cargahreprovacaosn, float cargahreprovado, int aprovacoescomnota) {
    float ida;

    ida = ((maprovado / aprovacoescomnota) * cargahaprovado) + (7 * cargahaprovacaosn) - (7 * cargahreprovado) - (7 * cargahreprovacaosn); // como calcular a media quando se tem valores sem nota 

    printf("\n> Indice de desempenho Academico (IDA) = %.2f", ida);
}


void mtd(int MDAi, int MDRi, int cargahsemnota, int reprovacoes){

    float mtd;
    mtd = MDAi - MDRi;

    if((MDAi == 0 || MDRi ==0) && cargahsemnota > 0){
        printf("Erro: calculo nao pode ser realizado");
    }
    else{
        printf("\n> Media Total de Disciplinas (MTD) = %.2f\nReprovacoes = %d", mtd, reprovacoes);
    }

}

void paa(int disciplinas, int aprovacoes){
    
    int paa;

    paa = (aprovacoes * 100) / disciplinas;

    if (paa == 100){
        printf("\nPercentual de Aproveitamento do aluno (PAA) = %d%%\nParabens! Aprovado em todas as disciplinas!", paa);
    }
    else{
        printf("\nPercentual de Aproveitamento do Aluno (PAA) = %d%%", paa);
    }

}


int main(){

    calculardv();

    int cargah, i, sna = 0, snr = 0, disciplinas, aprovacoes = 0, reprovacoes = 0, aprovacoescomnota = 0, cargahtotal, cargahaprovado, cargahreprovado, cargahsemnota, cargahaprovacaosn, cargahreprovacaosn;
    float medias, mtotal = 0, maprovado = 0, mreprovado = 0, MDAi = 0, MDRi = 0;
    char yesorno, aour;


    printf("\n\n> Informe a quantidade de disciplinas: ");
    scanf("%d", &disciplinas);

    while(disciplinas <= 0){
        printf("\n> Numero de disciplinas invalido, insira novamente: ");
        scanf("%d", &disciplinas);
    }

    for (i = 1; i <= disciplinas; i++){

        printf("\n> Disciplina %d possui nota? (Y ou N): ", i);
        scanf(" %c", &yesorno);

        if (yesorno == 'y' || yesorno == 'Y'){
            printf("\n> Digite as medias e cargas horarias no modelo X X.");
            printf("\n\nMedia e carga horaria da disciplina %d: ", i);
            scanf("%f %d",  &medias, &cargah);

        }
        
        else if (yesorno == 'n' || yesorno == 'N'){
            printf("\n> Informe se houve aprovacao ou reprovacao (a ou r) na disciplina %d e sua carga horaria: ", i);
            scanf(" %c %d", &aour, &cargah);

            if(aour == 'a' || aour == 'A'){
                sna++;
                cargahtotal += cargah;
                cargahaprovacaosn += cargah;
                cargahsemnota += cargah;
                aprovacoes++;
            }
            else if (aour == 'r' || aour == 'R'){
                snr++;
                cargahtotal += cargah;
                cargahreprovacaosn += cargah;
                cargahsemnota += cargah;
                reprovacoes++;
            }
        }

        if((medias < 0 || medias > 10) || cargah < 0){
            printf ("\nErro: Insira os dados novamente");
            i--;
        }
        
        if (medias >=  7 && cargah > 0){
            mtotal += medias;
            maprovado += medias;
            aprovacoes++;
            cargahtotal += cargah;
            cargahaprovado += cargah;
            MDAi += medias * cargah;
            aprovacoescomnota++;
        }

        else if (medias < 7 && cargah > 0){
            mtotal += medias;
            mreprovado += medias;
            reprovacoes++;
            cargahtotal += cargah;
            cargahreprovado += cargah;
            MDRi += medias * cargah;
        }

    }

    int menu;

    while (1) {

        printf("\n\n> Opcoes de calculo: ");
        printf("\n  1. Media Geral acumulada (MGA)");
        printf("\n  2. Indice de desempenho Academico (IDA)");
        printf("\n  3. Media total de Disciplinas (MTD)");
        printf("\n  4. Percentual de Aproveitamento do Aluno (PAA)");
        printf("\n  5. Sair");
        printf("\n\n> Selecione uma opcao: ");
        scanf("%d", &menu);

        switch (menu){
            case 1: mgaf(maprovado, aprovacoescomnota);
                break;
            case 2: ida(maprovado, cargahaprovado, cargahaprovacaosn, cargahreprovacaosn, cargahreprovado, aprovacoescomnota);
                break;
            case 3: mtd(MDAi, MDRi, cargahsemnota, reprovacoes);
                break;
            case 4: paa(disciplinas, aprovacoes);
                break;
            case 5: 
                return 0;
                break;
            default: printf("\nOpcao invalida");
        }
    }
}