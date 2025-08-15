/*
Faça um programa para ler dois vetores A e B de 5 elementos cada. Depois construa uma
matriz C, em que a primeira coluna deve ser formada pelos elementos do vetor A e a
segunda coluna formada pelos elementos do vetor B. Apresentar a matriz C.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho = 5;

    int *A = (int *)malloc(tamanho * sizeof(int));
    int *B = (int *)malloc(tamanho * sizeof(int));

    int **C = (int **)malloc(tamanho * sizeof(int *));
    
    for(int i = 0; i < tamanho; i++){
        C[i] = (int *)malloc(2 * sizeof(int));
    }

    if (A == NULL || B == NULL || C == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    printf("Digite os 5 elementos do vetor A:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", A + i);
    }

    printf("Digite os 5 elementos do vetor B:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", B + i);
    }

    for (int i = 0; i < tamanho; i++) {
        *(*(C + i) + 0) = *(A + i);
        *(*(C + i) + 1) = *(B + i);
    }

    printf("\nMatriz C:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", *(*(C + i) + j));
        }
        printf("\n");
    }

    free(A);
    free(B);
    for (int i = 0; i < tamanho; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}