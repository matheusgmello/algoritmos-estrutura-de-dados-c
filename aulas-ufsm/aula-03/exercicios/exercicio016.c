/*
Ler três valores numéricos inteiros e apresentar o resultado das adições e multiplicações utilizando a
propriedade distributiva para a máxima combinação possível entre as três variáveis. Por exemplo,
considerando o uso das variáveis A, B e C, devem ser feitas três adições e três multiplicações, ou seja, deve
ser combinada a variável A com B, A com C e B com C.
*/

#include <stdio.h>

#define SOMAVALORES(x, y) ((long int)(x) + (long int)(y))
#define MULTIPLICAVALORES(x, y) ((long int)(x) * (long int)(y))

int main() {
    long int valorA, valorB, valorC;

    printf("insira tres valores inteiros: ");
    scanf("%ld %ld %ld", &valorA, &valorB, &valorC);

    printf("\nresultado das somatorias\n");
    printf("valorA + valorB = %ld\n", SOMAVALORES(valorA, valorB));
    printf("valorA + valorC = %ld\n", SOMAVALORES(valorA, valorC));
    printf("valorB + valorC = %ld\n", SOMAVALORES(valorB, valorC));

    printf("\nresultados das multiplicacoes:\n");
    printf("valorA * valorB = %ld\n", MULTIPLICAVALORES(valorA, valorB));
    printf("valorA * valorC = %ld\n", MULTIPLICAVALORES(valorA, valorC));
    printf("valorB * valorC = %ld\n", MULTIPLICAVALORES(valorB, valorC));

    return 0;
}
