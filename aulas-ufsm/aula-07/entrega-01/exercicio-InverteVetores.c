/*
Escrever um programa com uma função que leia N números reais, armazene-os em um vetor e imprimaos na ordem inversa.
*/
#include <stdio.h>

void inverteArray(){
		
	float vetorN[10];
	
	int i;
	
	for(i=0;i<10;i++){
		scanf("%f", &vetorN[i]);
	}
	
	for(i=9; i>=0; i--){
		printf("%.2f\n", vetorN[i]);
	}
	
	
}

int main(){
	
	inverteArray();
	
	return 0;
}