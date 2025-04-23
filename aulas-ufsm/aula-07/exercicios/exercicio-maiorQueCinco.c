/*
Desenvolver um programa com uma função para ler 15 números, armazená-los em um vetor e mostrar o
total de números digitados maiores que 5.
*/
#include <stdio.h>
#include <time.h>
void maiorQueCinco(){
	
	srand(time(NULL));
	
	int elementos[15];
	int i;
	int maiorQueCinco;
	
	for (i=0;i<15;i++){
		elementos[i] = rand() % 10;
	}
	
	for (i=0;i<15;i++){
		if(elementos[i] > 5){
			printf("maior > 5: %d\n", elementos[i]);
			maiorQueCinco++;
			
		}
	}
	printf("qntd de numeros maior que 5: %d\n", maiorQueCinco);
	
}

int main(){
	
	maiorQueCinco();
	
	return 0;
}