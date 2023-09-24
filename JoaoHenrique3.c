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

void mgaf(float m, int aprovacoes){

    float mga;
    mga = m / aprovacoes;
    printf (" > MGA = %.2f", mga);
     
}

void ida(){




}

void mtd(int MDAi, int MDRi){

    float mtd;
    mtd = MDAi - MDRi;
    printf("\n> Media Total de Disciplinas (MTD) = %.2f", mtd);

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

    int cargah, i, sna = 0, snr = 0, disciplinas, aprovacoes = 0, reprovacoes = 0, cargahtotal, cargahaprovado, cargahreprovado, cargahsemnota, cargahaprovacaosn, cargahreprovacaosn;
    float medias, mtotal = 0, maprovado = 0, mreprovado = 0, MDAi = 0, MDRi = 0;


    printf("\nInforme a quantidade de disciplinas: ");
    scanf("%d", &disciplinas);

    while(disciplinas <= 0){
        printf("\nNumero de disciplinas invalido, insira novamente: ");
        scanf("%d", &disciplinas);
    }

    for (i = 1; i <= disciplinas; i++){
        printf("\n> Digite as medias e cargas horarias no modelo X X. Caso a disciplina tenha aprovacao ou reprovacao sem nota digite SNA X e SNR X respectivamente.");
        printf("\nMedia e carga horaria da disciplina %d: ", i);
        scanf("%f %d",  &medias, &cargah);

        if(medias == 'sna' || medias == 'SNA'){
            sna++;
            cargahtotal += cargah;
            cargahsemnota += cargah;
            cargahaprovacaosn += cargah;
        }
        
        if(medias == 'snr' || medias == 'SNR'){
            snr++;
            cargahtotal += cargah;
            cargahsemnota += cargah;
            cargahreprovacaosn += cargah;
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

    printf("\n> Opcoes de calculo: ");
    printf("\n  1. Media Geral acumulada (MGA)");
    printf("\n  2. Indice de desempenho Academico (IDA)");
    printf("\n  3. Media total de Disciplinas (MTD)");
    printf("\n  4. Percentual de Aproveitamento do Aluno");
    printf("\n> Selecione uma opcao: ");
    scanf("%d", &menu);

    switch (menu){
        case 1: mgaf(maprovado, aprovacoes);
            break;
        case 2: ida();
            break;
        case 3: mtd(MDAi, MDRi);
            break;
        case 4: paa(disciplinas, aprovacoes);
            break;
    }


}