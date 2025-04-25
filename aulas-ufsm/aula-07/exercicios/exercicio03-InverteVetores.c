/*
Escrever um programa com uma função que leia N números reais, armazene-os em um vetor e imprimaos na ordem inversa.
*/
#include <stdio.h>

void inverteArray(){
	
	int n, i;

	printf("digite o tamanho do vetor: ");
	scanf("%d", &n);

	float vetorN[n];
	
	
	for(i=0;i<n;i++){
		scanf("%f", &vetorN[i]);
	}
	
	printf("\n");
	
	for(i=n-1; i>=0; i--){
		printf("%.2f\t", vetorN[i]);
	}
	
	
}

int main(){
	
	inverteArray();
	
	return 0;
}