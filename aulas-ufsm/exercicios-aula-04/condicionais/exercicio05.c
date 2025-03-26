/*
Ler um número inteiro e imprimir uma mensagem informando se ele é par e divisível totalmente
divisível por 3.
*/

#include <stdio.h>

int main(){
	
	int valorInteiro;
	
	printf("insira um valor inteiro: ");
	scanf("%d", &valorInteiro);
	
	if (valorInteiro % 2 == 0 && valorInteiro % 3 == 0 ){
		printf("o numero %d eh par e divisivel por 3 \n", valorInteiro);
	} else {
		printf("o numero %d num eh par e nem divisivel por 3 \n", valorInteiro);
	}
	
	return 0;
}