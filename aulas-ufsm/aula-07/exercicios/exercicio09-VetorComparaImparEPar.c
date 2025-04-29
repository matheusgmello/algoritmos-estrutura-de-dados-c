/*
Desenvolva um algoritmo com uma função que contenha um vetor de N elementos. O conteúdo das
posições pares deve ser ‘P’ e das posições ímpares deve ser ‘I’. A inserção dos elementos deve ser feita
automaticamente. Depois, apresente o resultado na tela.
*/
#include <stdio.h>

void preencherVetor(int n);

int main() {
    int n;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &n);

    preencherVetor(n);

    return 0;
}

void preencherVetor(int n) {
    char vetor[n];

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            vetor[i] = 'P';
        } else {
            vetor[i] = 'I';
        }
    }

    printf("vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", vetor[i]);
    }
    printf("\n");
}