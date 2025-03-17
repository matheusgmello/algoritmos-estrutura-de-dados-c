#include <stdio.h>

int main(){
	int numero1, numero2;
	
	int soma;
	int subtracao;
	int divisao;
	int multiplicao;
	
	numero1 = 20;
	numero2 = 10;
	
	// Funcao soma
	soma = numero1 + numero2;
	// Mostrando o resultado
	printf("Soma: %d \n", soma);
	
	// Funcao subtracao
	subtracao = numero1 - numero2;
	printf("Subtraindo: %d \n", subtracao);
	
	// Funcao Multiplicacao
	multiplicao = numero1 * numero2;
	printf("Multiplicando: %d \n", multiplicao);
	
	// Funcao dividindo
	divisao = numero1 / numero2;
	printf("Dividindo: %d \n", divisao);
	
	
	
	return 0;
}