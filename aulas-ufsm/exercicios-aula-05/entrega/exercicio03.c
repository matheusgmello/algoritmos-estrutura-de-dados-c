/*
Desenvolver um programa que apresente todos os números divisíveis por 4 que sejam menores
que 200.
*/

#include <stdio.h>

int main(){
	
	int valor;
	
	for (valor = 4; valor < 200; valor += 4){
		printf("%d\n", valor);
		
	}
	
	return 0;
}