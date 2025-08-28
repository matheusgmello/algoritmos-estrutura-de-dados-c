/**
 * Desenvolva um algoritmo que receba os valores das n posições de um vetor e crie uma lista encadeada
com eles.
 * 
 */
#include<stdio.h>
#include <stdlib.h>

struct lista{
	
	int info;
	struct lista *proximo;
	
};

int main(){
	
	int n, i;
	printf("digite o tamanho do vetor de n: ");
	scanf("%d", &n);
	
	int vetor[n];
	for(i=0;i<n;i++){
		printf("Digite o valor da posicao %d: ", i);
		scanf("%d", &vetor[i]);
	}
	
	struct lista *inicio = NULL, *atual = NULL;
	for(i=0;i<n;i++){
		struct lista *novo = malloc(sizeof(struct lista));
		novo->info = vetor[i];
		novo->proximo = NULL;
		if (inicio == NULL){
			inicio = novo;
		} else{
			atual->proximo = novo;
		}
		atual = novo;
	}
	
	printf("\nlista encadeada\n");
	atual = inicio;
	while(atual != NULL){
		printf("%d\n", atual->info);
		struct lista *temp = atual;
		atual = atual->proximo;
		free(temp);
	}
	printf("\n");
	
	return 0;
}