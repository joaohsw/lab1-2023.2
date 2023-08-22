#include<stdio.h>
#include<math.h>

int main(){
    float ht, qh, sb, sl;
    printf("Insira, respectivamente o valor da hora de trabalho e a quantidade de horas trabalhadas: ");
    scanf("%f %f", &ht, &qh);
    sb = ht * qh;
    sl = sb - (sb * 0.11) - (sb * 0.08) - (sb * 0.05);
    printf("Valor hora de trabalho: %.2f\nHoras trabalhadas: %.2f\nSalario bruto: %.2f\nSalario liquid: %.2f\nIR: %.2f\nINSS: %.2f\nContribuicao sindical: %.2f", ht, qh, sb, sl, sb * 0.11, sb * 0.08, sb * 0.05);
    

}