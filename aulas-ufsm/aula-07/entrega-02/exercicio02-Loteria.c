/*
Ler um vetor R de 5 elementos contendo o gabarito da loteria. A seguir ler um vetor A de 10 elementos contendo uma aposta. 
A seguir imprima quantos pontos fez o apostador. Pesquise sobre geração de valores aleatórios em C (funções rand() e srand()) para gerar o gabarito.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loteria();

int main(){
  
  srand(time(NULL)); 
  loteria();
  
  return 0;
}

void loteria(){
	
	int vetorR[5];
	int vetorA[10];
	
	int i,j;
	int pontos=0;
	
	for(i=0;i<5;i++){
		vetorR[i] =  rand() % 60 + 1;
	}
	
	for (i=0;i<10;i++){
		vetorA[i] =  rand() % 60 + 1;
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			if (vetorA[i] == vetorR[j]) {
			    pontos++;
			    break;
			}
		}
	}
	
	printf("gabarito\n");
	for(i=0;i<5;i++){
		printf("%d\t", vetorR[i]);
	}
	
	printf("\n");
	
	printf("cartela do apostador\n");
	for(i=0;i<10;i++){
		printf("%d\t", vetorA[i]);
	}
	
	printf("\n");
	
	printf("voce fez %d pontos.\n", pontos);
	
}