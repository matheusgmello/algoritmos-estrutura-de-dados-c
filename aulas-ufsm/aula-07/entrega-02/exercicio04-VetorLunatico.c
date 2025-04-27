/*
Desenvolver um algoritmo que tenha um vetor de N posições, onde N é definido pelo usuário. 
Fazer a leitura de N-1 valores para preencher o vetor. A última posição não é preenchida. 
Depois ler dois valores P (posição) e V (valor). O conteúdo de V deve ser armazenado na posição P. 
Se a posição P estiver ocupada, deslocar os elementos existentes para adiante e só então preencher com o novo valor.
*/ 
#include <stdio.h>
#include <stdlib.h>

void deslocaVetor();

int main() {
    deslocaVetor();
    return 0;
}

void deslocaVetor() {
    int lim, i, p, v;

    printf("digite o tamanho do vetor: ");
    scanf("%d", &lim);

    int vetor[lim]; 

    printf("preencha o vetor com %d valores:\n", lim - 1);
    for (i = 0; i < lim - 1; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("digite o valor de p (posicao) e v (valor): ");
    scanf("%d %d", &p, &v);

    for (i = lim - 1; i > p; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[p] = v;

    printf("vetor resultante:\n");
    for (i = 0; i < lim; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}