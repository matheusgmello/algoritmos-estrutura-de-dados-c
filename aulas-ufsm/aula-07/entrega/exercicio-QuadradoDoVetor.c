/*
Crie um programa com uma função que leia 5 elementos de um vetor A. Construir um vetor B de mesmo
tipo, observando a seguinte lei de formação: Todo elemento de B deve ser o quadrado do elemento de A
correspondente. Apresentar os 2 vetores.

vetor * vetor
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quadradoDoVetor() {
    int vetorA[5];
    int vetorB[5];
    int i;

    for (i = 0; i < 5; i++) {
        vetorA[i] = rand() % 10;
        vetorB[i] = vetorA[i] * vetorA[i];
    }

    printf("vetor A:\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t", vetorA[i]);
    }
    printf("\n");

    printf("vetor B (quadrado de A):\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t", vetorB[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); 

    quadradoDoVetor();

    return 0;
}