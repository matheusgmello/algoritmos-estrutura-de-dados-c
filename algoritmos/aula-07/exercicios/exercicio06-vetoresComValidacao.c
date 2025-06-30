/*
6. Crie um programa com uma função que leia 8 valores dos vetores A e B. O Vetor A deve aceitar apenas a
entrada de valores que sejam divisíveis por 2 e 3, e o vetor B deve aceitar apenas valores múltiplos de 5.
Esta validação não deve ser feita pelo usuário, mas sim pelo programa. Depois, crie um terceiro vetor que
armazene todos os elementos dos dois vetores (16 posições) e apresente esses valores na tela.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vetoresComValidacao(){
	
	int vetorA[8];
	int vetorB[8];
	int vetorC[16];
	int i;
	
	//Percorre o primeiro vetor
	for(i=0;i<8;i++){
		int numero = 0;
		numero = rand() % 100;
		while ((numero % 2 != 0 || numero % 3 != 0) || numero == 0){
			//printf("numero invalido. digite outro: ");
    		numero = rand() % 100;
		}
		vetorA[i] = numero;
	}
	
	printf("\n");
	
	//Percorre o segundo vetor
	for(i=0;i<8;i++){
		int numero = 0;
		numero = rand() % 100;
		while (numero % 5 != 0 || numero == 0){
			//printf("numero invalido. digite outro: ");
    		numero = rand() % 100;
		}
		vetorB[i] = numero;
	}
	
	//Printa os dois primeiros vetores
	printf("primeiro vetor\n");
	for (i=0; i<8; i++){
		printf("%d\t", vetorA[i]);
		
	}
	
	printf("\n");
	
	printf("segundo vetor\n");
	for (i=0; i<8; i++){
		printf("%d\t", vetorB[i]);
		
	}
	
	// PREENCHE O VETOR COM 8 ELEMENTOS
	for (i = 0; i < 8; i++) {
    	vetorC[i] = vetorA[i];
	}
	
	// PREENCHE O RESTANTE DO VETOR COM MAIS 8 ELEMENTOS
	for (i = 0; i < 8; i++) {
    	vetorC[i + 8] = vetorB[i];
	}
	
	printf("\n");
	
	printf("ultimo vetor\n");
	for (i=0; i<16; i++){
		printf("%d\t", vetorC[i]);
		
	}
}

int main(){
	srand(time(NULL)); 
	
	vetoresComValidacao();
	
	return 0;
}