/*
A partir de dois números fornecidos pelo usuário, escrever uma das seguintes mensagens:
a) Os dois são pares
b) Os dois são impares
c) O primeiro é par e o segundo é ímpar
d) O primeiro é ímpar e o segundo é par
*/

#include <stdio.h>

int main(){
	
	int valorA, valorB;
	
	printf("digite um valor inteiro: ");
	scanf("%d", &valorA);
	
	printf("digite outro valor inteiro: ");
	scanf("%d", &valorB);
	
	if (valorA % 2 == 0 && valorB % 2 == 0) {
        printf("ambos sao pares\n");
    } else if (valorA % 2 != 0 && valorB % 2 != 0) {
        printf("ambos sao impares\n");
    } else if (valorA % 2 == 0 && valorB % 2 != 0) {
        printf("O primeiro eh par e o segundo eh impar\n");
    } else {
        printf("O primeiro eh ímpar e o segundo eh par\n");
    }
	
	return 0;
}