/*
Faça um programa com uma função que recebe por parâmetro um número inteiro e retorna 1 caso
seja maior que um valor inserido pelo usuário dentro da função e 0 em caso contrário.
*/
#include <stdio.h>
int retornaZeroOuUm(int numero){
	int numeroDigitado;
	
	printf("digite um numero: ");
	scanf("%d", &numeroDigitado);
	
	if (numeroDigitado > numero){
		return 1;
	}else{
		return 0;
	}
	
}

int main(){
	
	int resultado;

	resultado = retornaZeroOuUm(10);
	
	printf("%d", resultado);
	
	return 0;
}