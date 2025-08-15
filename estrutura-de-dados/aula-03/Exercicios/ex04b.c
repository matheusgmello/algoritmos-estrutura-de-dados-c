#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tamanho = 3;
    int **matrizA = (int **)malloc(tamanho * sizeof(int *));
    int **matrizB = (int **)malloc(tamanho * sizeof(int *));

    if (!matrizA || !matrizB) {
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        matrizA[i] = (int *)malloc(tamanho * sizeof(int));
        matrizB[i] = (int *)malloc(tamanho * sizeof(int));
        if (!matrizA[i] || !matrizB[i]) {
            return 1;
        }
    }
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matrizA[i][j] = (rand() % 10) + 1;
        }
    }

    printf("Matriz A:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == j) {
                matrizB[i][j] = 3 * matrizA[i][j];
            } else {
                matrizB[i][j] = 2 * matrizA[i][j];
            }
        }
    }

    printf("\nMatriz B:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d\t", matrizB[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < tamanho; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
    }
    free(matrizA);
    free(matrizB);

    return 0;
}