/*
Fazer um algoritmo que leia um número inteiro e mostre uma mensagem dizendo se é primo ou
não.
*/

#include <stdio.h>

int main(){
	
	int i, numero;
	
	do{
		printf("insira um numero inteiro: ");
		scanf("%d", &numero);
		
		if (numero > 1 || numero % numero == 1){
			printf("o numero eh primo");
		} else {
			printf("o numero nao eh primo");
		}
		
		i++;
	} while (i > 2);
	
	
	return 0;
}