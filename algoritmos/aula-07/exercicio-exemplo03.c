/*
Desenvolver um algoritmo que leia 5 elementos de um vetor A e no final apresente o total da soma de todos os elementos ímpares.
*/
#include <stdio.h>

void somaElementosImpares(){
	
	int elementos[5];
	int i;
	int somaDosImpares;
	
	for (i=0;i<5;i++){
		scanf("%d", &elementos[i]);
	}
	
	for (i=0; i<5;i++){
		if(elementos[i] % 2 != 0){
			printf("impares: %d\n", elementos[i]);
			somaDosImpares += elementos[i];
		}
	}
	
	printf("soma eh %d", somaDosImpares);
}

int main(){
	
	somaElementosImpares();
	
	return 0;
}