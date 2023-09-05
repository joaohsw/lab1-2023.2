#include <stdio.h>
#include <math.h>

int main() {
    int dia, mes, ano;
    char op1;
    int op12, op13, op14, op15, h1, m1, h2, m2, h1h2, m1m2, mintotais1, mintotais2, mindif, hdif, minr;
    float c, f, k, r, h, comp, t6, t8, t9, area, unidadet6, unidadet8, unidadet9, valort6, valort8, valort9;

    printf("\n*****************\n*      ZOXY     *\n*****************\nMenu inicial\n a. Validacao de data\n b. Diferenca de horarios\n c. Conversao de temperatura\n d. Calculo de material\n> Selecione uma opcao: ");
    scanf(" %c", &op1);

    if (op1 == 'a' || op1 == 'A') {
    printf("\nA > Validacao de data\nInforme respectivamente: \"Dia\", \"Mes\" e \"Ano\" > ");
    scanf("%d %d %d", &dia, &mes, &ano);

    if (mes < 1 || mes > 12) {
        printf("Erro: data invalida\n");
        return 0;
    } else if (dia < 1) {
        printf("Erro: data invalida\n");
        return 0;
    } else if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31) {
        printf("Erro: data invalida\n");
        return 0;
    } else if ((mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("Erro: data invalida\n");
        return 0;
    } else if (mes == 2) {
        if ((ano % 400 != 0 && ano % 100 == 0) || (ano % 4 != 0)) {
            if (dia > 28) {
                printf("Erro: data invalida\n");
                return 0;
            }
        } else {
            if (dia > 29) {
                printf("Erro: data invalida\n");
                return 0;
            }
        }
    }

    printf("\nA > Validacao de data\n> Dia: %d\n> Mes: %d\n> Ano: %d\n 1. DD/MM/YYYY\n 2. YYYY-MM-DD\n 3. DD de [MES] de YYYY\n\n> Selecione uma opcao: ", dia, mes, ano);
    scanf("%d", &op12);

    if (op12 == 1 && mes <= 9) {
        printf("\n> Opcao 1: %d/0%d/%d\n* fim *\n", dia, mes, ano);
    } else if (op12 == 1) {
        printf("\n> Opcao 1: %d/%d/%d\n* fim *\n", dia, mes, ano);
    } else if (op12 == 2 && mes <= 9) {
        printf("\n> Opcao 2: %d-0%d-%d\n* fim *\n", ano, mes, dia);
    } else if (op12 == 2) {
        printf("\n> Opcao 2: %d-%d-%d\n* fim *\n", ano, mes, dia);
    } else if (op12 == 3 && mes == 1) {
        printf("\n> Opcao 3: %d de janeiro de %d\n* fim *\n", dia, ano);
    } else if (op12 == 3 && mes == 2) {
        printf("\n> Opcao 3: %d de fevereiro de %d\n* fim *\n", dia, ano);
    } else if (op12 == 3 && mes == 3) {
        printf("\n> Opcao 3: %d de marco de %d\n* fim *\n", dia, ano);
    } else if (op12 == 3 && mes == 4) {
        printf("\n> Opcao 3: %d de abril de %d\n* fim *\n", dia, ano);
    } else if (op12 == 3 && mes == 5) {
        printf("\n> Opcao 3: %d de maio de %d\n* fim *\n", dia, ano);
    } else if (op12 == 3 && mes == 6) {
        printf("\n> Opcao 3: %d de junho de %d\n* fim *\n", dia, ano);
    } else if (op12 == 3 && mes == 7) {
        printf("\n> Opcao 3: %d de julho de %d\n* fim *\n", dia, ano);
    }
}

    
    if (op1 == 'b' || op1 == 'B'){
        printf("\nB > Diferenca de horarios\nInforme respectivamente e em formato 24hrs os seguintes valores: \"Hora h1\", \"Minuto m1\", \"Hora h2\" e \"Minuto m2\"\n");
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        printf("\n\nB > Diferenca de horarios\n:> Hora h1: %d\n> Minuto m1: %d\n> Hora h2: %d\n> Minuto m2: %d\n 1. Padrao\n 2. Minutos\n 3. Segundos\n 4. Milisegundos\n> Selecione uma opcao: ", h1, m1, h2, m2);
        scanf("%d", &op13);

        mintotais1 = h1 * 60 + m1;
        mintotais2 = h2 * 60 + m2;
        
        if (h2 < h1 || (h2 == h1 && m2 < m1)) {
            mintotais2 += 24 * 60;
        }

        mindif = fabs(mintotais2 - mintotais1);
        hdif = mindif / 60;
        minr = mindif % 60;

        if (h1 > 24 || h2 > 24 || m1 >= 60 || m2 >= 60){
            printf("\nErro: valor invalido\n\n");
            return 0;
        } else if (op13 == 1) 
            printf("\n> Opcao 1: %d horas e %d minutos\n* fim *", hdif, minr);
        else if (op13 == 2) 
            printf("\n> Opcao 2: %d minutos\n* fim *", mindif);
        else if (op13 == 3) 
            printf("\n> Opcao 3: %d segundos\n* fim *", mindif * 60);
        else if (op13 == 4) 
            printf("\n> Opcao 4: %d milisegundos\n* fim *", mindif * 60000);
        else if (op13 > 4 || op13 < 1)
            printf("\nErro: opcao invalida");
        return 0;
    }

    if (op1 == 'c' || op1 == 'C'){
        printf("\nC > Conversao de temperatura\nInforme uma temperatura em graus celcius para ser convertida: ");
        scanf("%f", &c);
        printf("\n> Temperatura (C): %.2f\n 1. Fahrenheit\n 2. Kelvin\n 3. Rankine\n> Selecione uma opcao: ", c);
        scanf("%d", &op14);

        f = (c * 9/5) + 32;
        k = c + 273.15;
        r = (c * 9/5) + 491.67;

        if(op14 == 1){
            printf("\nOpcao 1: %.2f C <-> %.2f F\n* fim *", c, f);
        } else if(op14 == 2)
            printf("\nOpcao 2: %.2f C <-> %.2f K\n* fim *", c, k);
        else if(op14 == 3)
            printf("\nOpcao 3: %.2f C <-> %.2f R\n* fim *", c, r);
        else if(op14 > 3 || op14 < 1)
            printf("Erro: opcao invalida");
        return 0;
    }

    if (op1 == 'd' || op1 == 'D'){
        printf("\nD > Calculo de material\nInsira um valor equivalente a altura e outro ao comprimento (em metros) de um parede qualquer: ");
        scanf("%f %f", &h, &comp);
        printf("\n\nD> Calculo de material\n> Altura (m): %.2f\n> Comprimento (m): %.2f\n 1. 6 furos\n 2. 8 furos\n 3. 9 furos\n> Selecione uma opcao: ", h, comp);
        scanf("%d", &op15);

        t6 = 0.0266;
        t8 = 0.0361;
        t9 = 0.0551;
        area = h * comp;
        unidadet6 = ceil(area * t6 * 1000);
        unidadet8 = ceil(area * t8 * 1000);
        unidadet9 = ceil(area * t9 * 1000);
        valort6 = unidadet6 / 1000 * 400;
        valort8 = unidadet8 / 1000 * 400;
        valort9 = unidadet9 / 1000 * 400;

        if(op15 == 1){
            printf("\nOpcao 1: %.f unidades (R$%.2f)\n* fim *", ceil(unidadet6), valort6);
        } else if(op15 == 2)
            printf("\nOpcao 2: %.f unidades (R$%.2f)\n* fim *", ceil(unidadet8), valort8);
        else if(op15 == 3)
            printf("\nOpcao 3: %.f unidades (R$%.2f)\n* fim *", ceil(unidadet9), valort9);
        else if(op15 > 3 || op15 < 1)
            printf("\nErro: opcao invalida\n\n");
        return 0;
    }



}

