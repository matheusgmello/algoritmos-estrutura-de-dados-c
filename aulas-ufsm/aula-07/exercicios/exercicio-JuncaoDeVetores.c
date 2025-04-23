/*
Desenvolver um algoritmo com uma função que leia dois vetores, sendo a primeiro com 5 elementos e o
segundo com 8 elementos. Construir um terceiro vetor que armazene a junção dos dois primeiros vetores
e mostre os valores na tela. Assim, o terceiro vetor deve ter 13 posições. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void juntaVetores(){
	
	int vetorA[5];
	int vetorB[8];
	int vetorC[13];
	int i;


	// PERCORRE O PRIMEIRO VETOR COM 5 POSICOES
	for (i=0;i<5;i++){
		scanf("%d", &vetorA[i]);
		vetorC[i] = vetorA[i];
		//vetorA[i] = rand() % 10;
	}
	
	// PERCORRE O SEGUNDO VETOR COM 8 POSICOES
	for (i=0;i<8;i++){
		vetorB[i] = rand() % 10;
	}
	
	// Printa os valores do primeiro vetor
	for (i=0; i<5; i++){
		printf("%d\t", vetorA[i]);
	}
	
	printf("\n");
	
	// Printa os valores do segundo vetor
	for (i=0; i<8; i++){
		printf("%d\t", vetorB[i]);
	}
	
	for (i = 0; i < 8; i++) {
    	vetorC[i + 5] = vetorB[i];
	}
	
	printf("\n");
	
	// Printa os valores do ultimo vetor
	for (i=0; i<13; i++){
	    printf("%d\t", vetorC[i]);
	}
	
}

int main(){
	
	srand(time(NULL)); 
	
	juntaVetores();
	
	return 0;
}