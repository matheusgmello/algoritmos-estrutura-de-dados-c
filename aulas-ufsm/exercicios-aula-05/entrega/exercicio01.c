/*
Criar um programa para apresentar o quadrado dos números inteiros de 15 a 100.
*/

#include <stdio.h>
int main(){
	
	int valor;
	
	for(valor = 15;valor < 100; valor++){
		printf("%d\n", valor * valor);
	}
	
	return 0;
}

