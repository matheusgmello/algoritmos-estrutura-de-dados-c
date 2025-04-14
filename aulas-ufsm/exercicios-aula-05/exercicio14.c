/*
Fazer um algoritmo que leia números inteiros ate que seja informado zero, o qual deve ser
desconsiderado e apos escreva quantos números informados são negativos, e a média
aritmética dos números maiores que zero.
*/

#include <stdio.h>

int main(){

	int numeroDigitados, quantidadeDeNegativos = 0;
	int i;
	float somaDePositivos = 0, quantidadeDePositivos = 0, mediaDeNumeros;
	
	for (i = 1;i > 0; i++){
		printf("digite numeros inteiros (0 -> para parar): ");
		scanf("%d", &numeroDigitados);
		
		if (numeroDigitados == 0){
			break;
		}
		
		if (numeroDigitados < 0){
			quantidadeDeNegativos++;
		} else{
			somaDePositivos += numeroDigitados;
			quantidadeDePositivos++;
		}
		
		mediaDeNumeros = somaDePositivos / quantidadeDePositivos;
		
	}
	
	printf("quantidade de negativos digitados: %d\n", quantidadeDeNegativos);
	printf("a media eh %f\n", mediaDeNumeros);
	
	return 0;
}