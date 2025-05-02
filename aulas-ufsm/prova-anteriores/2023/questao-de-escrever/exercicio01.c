/*
Desenvolva uma função para ler os elementos inteiros de um vetor de N posições. 
Depois o algoritmo deve solicitar uma posição do vetor e 
alterar os valores armazenados até ali. Os novos valores devem ser escolhidos pelo usuário. 
Por fim, o vetor com a formação alterada deve ser apresentado.
*/
#include <stdio.h>

void funcaoProva(){
	
	int N;
	int i;
	
	int p,v;
	
	printf("qual o tamanho do vetor:");
	scanf("%d", &N);
	
	int vet[N];
	
	printf("\n");
	
	printf("digite os valores do vetor:");
	for(i=0;i<N;i++){
		scanf("%d", &vet[i]);
	}
	
	do{
		printf("digite qual posicao do vetor: ");
		scanf("%d", &p);
	} while(p > N);
	
	printf("\n");
	
	printf("digite qual valor: ");
	scanf("%d", &v);	
	
	
	
	for (i=0; i <= p; i++){
		vet[i] = v;
	}
	
	for (i=0; i < N; i++){
		printf("%d\t", vet[i]);
	}
	
}

int main(){
	
	funcaoProva();
	
	return 0;
}