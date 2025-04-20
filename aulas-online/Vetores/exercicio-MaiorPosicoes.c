#include <stdio.h>

void maiorPosicoes(){
	int valores[5];
	int i, maior =0, menor =0;
	
	for (i=0; i < 5; i++){
		printf("[%d] = ",i );
		scanf("%d", &valores[i]);
	}
	
	for (i=1; i < 5; i++){
		// se valores na posicao 1 > valores na posicao 0
		if (valores[i] > valores[maior]){
			printf("maior alterado. POSICAO: %i VALOR: %d \n", i, valores[i]);
			maior = i;
		}
		
		if (valores[i] < valores[menor]){
			menor = i;
		}
	}
	
	printf("posicao do maior: %d\n", maior);
	printf("posicao do menro: %d\n", menor);
}

int main(){
	
	maiorPosicoes();
	
	return 0;
}