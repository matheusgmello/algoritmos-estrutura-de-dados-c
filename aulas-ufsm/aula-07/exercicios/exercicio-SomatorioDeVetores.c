/*
Criar um programa com uma função que leia os N valores de um vetor do tipo inteiro e, então, construir
um segundo vetor de mesma dimensão, sendo que cada elemento do segundo vetor é o somatório do
elemento correspondente no primeiro. Ex.: VetA[0] = 5; logo, VetB[0] = 15 (1 + 2 + 3 + 4 + 5 = 15).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void somatorioDeVetores(){
	
	int vetorA[10];
	int vetorB[10];
	int i;
	
	for (i=0;i<10;i++){
		scanf("%d", &vetorA[i]);
	}
	
	for (i=0;i<10;i++){
		vetorB[i] = (vetorA[i] * (vetorA[i] + 1)) / 2;
	}
	
	printf("\n");
	
	for (i=0;i<10;i++){
		printf("%d\t", vetorA[i]);
	}
	
	printf("\n");
	
	for (i=0;i<10;i++){
		printf("%d\t", vetorB[i]);
	}
}

int main(){
	
	srand(time(NULL)); 

	
	somatorioDeVetores();
	
	return 0;
}