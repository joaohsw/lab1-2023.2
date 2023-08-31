#include<stdio.h>
#include<math.h>

int main(){

    int brat, mazel, salek, tak, blip, anot, seg, min, hora, dia, mes;
    char op1, op2;

    printf("Insira as informacoes no formato 'dia' 'mes' 'hora' 'min' 'seg': ");
    scanf("%d %d %d %d %d", &dia, &mes, &hora, &min, &seg);
    printf("Informe qual a ordem da conversao (terrestre extraterrestre || extraterrestre terrestre): ");
    scanf("%c %c", &op1, &op2);

    blip = seg * 3;
    tak = 40 * blip;
    salek = 15 * tak;
    mazel = 15 * salek;
    brat = 8 * mazel;
    anot = 73 * brat;

    if(op1 == 't')
        printf("Terrestre para extraterreste \nblip: %d \ntak: %d \nsalek: %d \nmazel: %d \nbrat: %d \nano: %d", blip, tak, salek, mazel, brat, anot);

    
    
}