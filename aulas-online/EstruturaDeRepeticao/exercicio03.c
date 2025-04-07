#include <stdio.h>

int main(){
	int numero, soma;
	
	do {	
		printf("digite um numero: ");
		scanf("%d", &numero);
		soma = soma + numero;
	} while (numero != 0);
	
	printf("a soma de todos os valores eh: %d\n", soma);
	
	
	return 0;
}