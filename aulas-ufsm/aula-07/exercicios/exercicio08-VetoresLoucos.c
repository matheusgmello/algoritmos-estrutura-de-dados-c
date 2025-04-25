/*
Construa um algoritmo para ler 2 vetores reais de N posições e enviá-los por parâmetro para uma função.
Depois esta função deve criar 

um terceiro vetor cujo conteúdo de cada posição é: 1, se o número
armazenado em uma posição do 1º vetor é o mesmo armazenado na posição respectiva do 2º vetor, e 0,
se não for o mesmo.
*/

#include <stdio.h>

void comparaVetores(float vetor1[], float vetor2[], int N, int resultado[]) {
    for (int i = 0; i < N; i++) {
        resultado[i] = (vetor1[i] == vetor2[i]) ? 1 : 0;
    }
}

int main() {
    int N;
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &N);

    float vetor1[N], vetor2[N];
    int resultado[N];

    printf("Digite os valores do primeiro vetor:\n");
    for (int i = 0; i < N; i++) {
        scanf("%f", &vetor1[i]);
    }

    printf("Digite os valores do segundo vetor:\n");
    for (int i = 0; i < N; i++) {
        scanf("%f", &vetor2[i]);
    }

    comparaVetores(vetor1, vetor2, N, resultado);

    printf("Vetor resultado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }

    return 0;
}