/*
3. Ler um vetor D de 10 elementos. Retire todos os valores nulos ou negativos do vetor D. 
Escrever o vetor após a retirada dos nulos e negativos. Exemplo:
Entrada: vetor = {10, -5, 9, -7, 2}
Saída: vetor = {10, 9, 2}
*/ 

#include <stdio.h>
#include <stdlib.h>

int removeNegativosENulos(int vetor[], int tamanho, int resultado[]);

int main() {
    int vetorD[10];
    int vetorResultado[10];
    int tamanhoResultado, i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &vetorD[i]);
    }

    tamanhoResultado = removeNegativosENulos(vetorD, 10, vetorResultado);

    printf("vetor antes:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetorD[i]);
    }

    printf("\n");

    printf("vetor dps:\n");
    for (i = 0; i < tamanhoResultado; i++) {
        printf("%d ", vetorResultado[i]);
    }

    return 0;
}

int removeNegativosENulos(int vetor[], int tamanho, int resultado[]) {
    int i, tamanhoResultado = 0;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > 0) {
            resultado[tamanhoResultado] = vetor[i];
            tamanhoResultado++;
        }
    }

    return tamanhoResultado;
}