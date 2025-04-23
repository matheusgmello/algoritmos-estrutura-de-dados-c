/*
Desenvolver um programa que leia 5 elementos de um vetor A. 
Construir um vetor B de mesmo tipo e copiar os valores do vetor A para o B, 
mantendo-os nas posições originais.
*/
#include <stdio.h>

void copiaVetores(){
	
	int vetorA[5];
	int vetorB[5];
	
	int i;
	
	for (i=0;i<5;i++){
		scanf("%d", &vetorA[i]);
	}
	
	for (i=0;i<5;i++){
		vetorB[i] = vetorA[i];
	}
	
		
	for (i=0;i<5;i++){
		printf("%d\n", vetorB[i]);
	}
	
}

int main(){
	
	copiaVetores();
	
	return 0;
}