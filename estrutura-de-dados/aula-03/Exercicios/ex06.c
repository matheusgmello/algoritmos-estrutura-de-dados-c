/*
Desenvolva um algoritmo que leia os elementos de uma matriz A de ordem 4 e também
de uma matriz B de mesma ordem, gere e imprima uma matriz C com a soma dos
elementos de A com B.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho = 4;
    int **matrizA;
    int **matrizB;
    int **matrizC;
    
    matrizA = (int **)malloc(tamanho * sizeof(int *));
    matrizB = (int **)malloc(tamanho * sizeof(int *));
    matrizC = (int **)malloc(tamanho * sizeof(int *));
    
    if (matrizA == NULL || matrizB == NULL || matrizC == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }
    
    for (int i = 0; i < tamanho; i++) {
        matrizA[i] = (int *)malloc(tamanho * sizeof(int));
        matrizB[i] = (int *)malloc(tamanho * sizeof(int));
        matrizC[i] = (int *)malloc(tamanho * sizeof(int));
        
        if (matrizA[i] == NULL || matrizB[i] == NULL || matrizC[i] == NULL) {
            printf("Erro na alocacao de memoria das linhas.\n");
            return 1;
        }
    }
    
    srand(time(NULL));
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matrizA[i][j] = (rand() % 10) + 1;
            matrizB[i][j] = (rand() % 10) + 1;
        }
    }
    
    printf("Matriz A:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d\t", matrizA[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz B:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d\t", matrizB[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    printf("\nMatriz C (Soma de A e B):\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d\t", matrizC[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < tamanho; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    
    free(matrizA);
    free(matrizB);
    free(matrizC);
    
    return 0;
}