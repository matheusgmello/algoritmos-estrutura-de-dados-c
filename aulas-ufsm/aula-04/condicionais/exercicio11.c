/*
Fazer um algoritmo que leia dois números e apresente-os em ordem crescente.
*/

#include <stdio.h>
int main(){
	
	float valorUm, valorDois;
	
	printf("fale um valor: ");
	scanf("%f", &valorUm);
	
	printf("fale outro valor: ");
	scanf("%f", &valorDois);
	
	if (valorUm > valorDois){
		printf("valores em ordem crescente\n");
		printf("valorUm eh %2.f e o valorDois eh %2.f", valorUm, valorDois);
	} else if (valorDois > valorUm){
		printf("valores em ordem crescente\n");
		printf("valorDois eh %2.f e o valorUm eh %2.f", valorDois, valorUm);
	} else {
		printf("valores iguais");
	}
	
	return 0;
}