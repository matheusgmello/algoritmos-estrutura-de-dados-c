/*
Faça um algoritmo com uma função para criar um vetor de 20 posições. As primeiras 10 posições são
valores informados pelo usuário, as últimas 10 posições deverão ter valores que obedecem a seguinte
regra: os valores de posições ímpares da primeira metade deverão ser acrescidos de 5 % na segunda
metade. E, os valores pares da primeira metade deverão ser acrescidos de 2% na segunda metade. Ex.:
Vet[0] = 10, logo, Vet[10] = 10 + 2%
*/
#include <stdio.h>

void vetoresComAcrescimo() {
    float vetorMessi[20];
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%f", &vetorMessi[i]);
    }

    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) { 
            vetorMessi[i + 10] = vetorMessi[i] + (vetorMessi[i] * 0.02);
        } else { 
            vetorMessi[i + 10] = vetorMessi[i] + (vetorMessi[i] * 0.05);
        }
    }

    
    printf("\vetor completo:\n");
    for (i = 0; i < 20; i++) {
        printf("%.2f\t", vetorMessi[i]);
    }
    printf("\n");
}

int main() {
    vetoresComAcrescimo();
    return 0;
}