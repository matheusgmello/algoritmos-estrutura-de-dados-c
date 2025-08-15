/*
Criar um programa com uma função que leia os N valores de um vetor do tipo inteiro e, então, construir um segundo vetor de mesma dimensão, 
sendo que cada elemento do segundo vetor é o somatório do elemento correspondente no primeiro. 
Ex.: VetA[0] = 5; logo, VetB[0] = 15 (1 + 2 + 3 + 4 + 5 = 15).
*/

#include <stdio.h>
#include <stdlib.h>


void funcao(int **a, int **b, int n) {
	
    *a = malloc(n * sizeof(int));
    *b = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &(*a)[i]);
        int soma = 0;
        for (int j = 1; j <= (*a)[i]; j++) soma += j;
        (*b)[i] = soma;
    }
    for (int i = 0; i < n; i++) printf("%d\t", (*b)[i]);
}

int main() {
    int *vetA = NULL, *vetB = NULL;
    int n;
    scanf("%d", &n);
    funcao(&vetA, &vetB, n);
    free(vetA);
    free(vetB);
    return 0;
}
