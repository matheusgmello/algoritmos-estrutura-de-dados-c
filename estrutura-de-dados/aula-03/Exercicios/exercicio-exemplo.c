#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *vetor = NULL;
	int n;
	
	printf("digite o tamanho: ");
	scanf("%d", &n);
	
	vetor = (int*) malloc (n* sizeof(int));
	
	for(int i = 0; i< n;i++){
		printf("\n\ntaca os valores: ");
		scanf("%d", &vetor[i]);
	}
	
	for(int i = 0; i< n;i++){
		printf("%d", vetor[i]);
	}
	
	
	free(vetor);
	return 0;
}