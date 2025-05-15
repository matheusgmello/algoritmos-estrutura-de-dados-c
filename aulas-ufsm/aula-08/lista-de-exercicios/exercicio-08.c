/*
Faça um algoritmo para ler duas matrizes reais A e B de ordem 5, e criar uma matriz C de modo que: cij = 1, se a ij da
matriz A existe em algum lugar na matriz B; cij = 0, se a ij da matriz A não existir em B.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int MA[5][5], MB[5][5], MC[5][5];
    int i, j, k, l;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            MA[i][j] = rand() % 90 + 1;
            MB[i][j] = rand() % 90 + 1;
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                for (l = 0; l < 5; l++) {
                    if (MA[i][j] == MB[k][l]) {
                        MC[i][j] = 1;
                        break;
                    } else {
                        MC[i][j] = 0;
                    }
                }
                if (MC[i][j] == 1) break;
            }
        }
    }

    printf("matriz a:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", MA[i][j]);
        }
        printf("\n");
    }

    printf("\nmatriz b:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", MB[i][j]);
        }
        printf("\n");
    }

    printf("\nmatriz c:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", MC[i][j]);
        }
        printf("\n");
    }

    return 0;
}