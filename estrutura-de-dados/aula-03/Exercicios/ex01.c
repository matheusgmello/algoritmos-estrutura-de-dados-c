/*
Escrever um programa com uma função que leia N números reais, 
armazene-os em um vetor e imprima-os na ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

void funcao(float *p){
	
	int n;
	
	printf("digite o tamanho: ");
	scanf("%d", &n);
	
	p = (float*) malloc (n* sizeof(float));
	
	if (p != NULL){
		
		printf("\n\ntaca os valores:\n");
		for(int i = 0; i< n;i++){
		scanf("%f", &p[i]);
		}
	
		for(int i = n - 1; i >= 0;i--){
			printf("%.2f\t", p[i]);
		}
		
	} else{
		printf("memoria insuficiente");
	}
	
}

int main(){
	
	float *vetor = NULL;
	
	funcao(vetor);
	
	free(vetor);
	return 0;
}