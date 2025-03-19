/*
Ler dois valores para as variáveis A e B, e efetuar a troca dos valores de forma que a variável A passe a
possuir o valor da variável B e a variável B passe a possuir o valor da variável A. Apresentar os valores
trocados.
*/

#include <stdio.h>

int main() {
    /*
    long int valorA, valorB;

    printf("insira o valor de A: ");
    scanf("%ld", &valorA);
    printf("insira o valor de B: ");
    scanf("%ld", &valorB);

    valorA = valorA + valorB;
    valorB = valorA - valorB;
    valorA = valorA - valorB;

    printf("\ncomo ficou apos a troca:\n");
    printf("valorA = %ld\n", valorA);
    printf("valorB = %ld\n", valorB);

    return 0;
	*/
	
	// testando com bitwise
	
	long int valorA, valorB;
	
    printf("insira o valor de A: ");
    scanf("%ld", &valorA);
    printf("insira o valor de B: ");
    scanf("%ld", &valorB);

    valorA = valorA ^ valorB;
    valorB = valorA ^ valorB;
    valorA = valorA ^ valorB;

    printf("\ncomo ficou apos a troca:\n");
    printf("valorA = %d\n", valorA);
    printf("valorB = %d\n", valorB);

    return 0;

}
