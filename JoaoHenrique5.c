#include <stdio.h>

int main() {
    int l, c;

    printf("> Digite a quantidade de linhas: ");
    scanf("%d", &l);
    printf("> Digite a quantidade de colunas: ");
    scanf("%d", &c);

    while (l <= 0 || c <= 0 || l >= 100 || c >= 100) {
        printf("Valor nulo, negativo ou maior que 100");
        printf("\n> Digite a quantidade linhas novamente: ");
        scanf("%d", &l);
        printf("> Digite a quantidade de colunas novamente: ");
        scanf("%d", &c);
    }

    int matriz[l][c], med[l][c], i, j, k, novalinha, novacoluna, temp, vcont;

    printf("> Digite os valores da matriz M: ");

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz M:\n");

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    int vizinhos[9];
    int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}; // deslocamento do i
    int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1}; // deslocamento do j

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            vcont = 0;
            printf("\n> Valores adjacentes de %d:\n", matriz[i][j]);

            for (k = 0; k < 9; k++) {
                novalinha = i + di[k];
                novacoluna = j + dj[k];

                if (novalinha >= 0 && novalinha < l && novacoluna >= 0 && novacoluna < c) {
                    vizinhos[vcont] = matriz[novalinha][novacoluna];
                    vcont++;
                }
            }

            for (int k = 0; k < vcont; k++) {
                printf(" %d", vizinhos[k]);
            }
        }
    }

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            vcont = 0;

            for (k = 0; k < 9; k++) {
                novalinha = i + di[k];
                novacoluna = j + dj[k];

                if (novalinha >= 0 && novalinha < l && novacoluna >= 0 && novacoluna < c) {
                    vizinhos[vcont] = matriz[novalinha][novacoluna];
                    vcont++;
                }
            }

            for (int k = 0; k < vcont - 1; k++) {
                for (int m = k + 1; m < vcont; m++) {
                    if (vizinhos[k] > vizinhos[m]) {
                        temp = vizinhos[k];
                        vizinhos[k] = vizinhos[m];
                        vizinhos[m] = temp;
                    }
                }
            }

            printf("\n> Valores adjacentes (ordenados) de %d:\n", matriz[i][j]);

            for (int k = 0; k < vcont; k++) {
                printf(" %d", vizinhos[k]);
            }
        }
    }

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            vcont = 0;

            for (k = 0; k < 9; k++) {
                novalinha = i + di[k];
                novacoluna = j + dj[k];

                if (novalinha >= 0 && novalinha < l && novacoluna >= 0 && novacoluna < c) {
                    vizinhos[vcont] = matriz[novalinha][novacoluna];
                    vcont++;
                }
            }

            int mediana;

            for (int k = 0; k < vcont - 1; k++) {
                for (int m = k + 1; m < vcont; m++) {
                    if (vizinhos[k] > vizinhos[m]) {
                        temp = vizinhos[k];
                        vizinhos[k] = vizinhos[m];
                        vizinhos[m] = temp;
                    }
                }
            }

            if (vcont % 2 == 0) {
                mediana = (vizinhos[vcont / 2 - 1] + vizinhos[vcont / 2]) / 2;
            } 
            else {
                mediana = vizinhos[vcont / 2];
            }

            med[i][j] = mediana;

            printf("\n> Mediana de %d: %d\n", matriz[i][j], mediana);
        }
    }

    printf("\n> Matriz Med:\n");

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%4d ", med[i][j]);
        }
        printf("\n");
    }

    printf("\n(Scrolle para cima para ver o resto dos resultados)");

}
