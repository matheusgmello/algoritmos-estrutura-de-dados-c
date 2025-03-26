/*
Fazer um algoritmo que leia um número inteiro, verifique e escreva se ele e negativo, zero ou
positivo. Caso seja positivo diga ainda se ele e par ou impar.
*/

#include <stdio.h>
int main(){
	
	int numeroInteiro;
	
	printf("escolha um numero inteiro: ");
	scanf("%d", &numeroInteiro);
	
	if (numeroInteiro < 0){
		printf("o numero eh negativo");
	} else if (numeroInteiro == 0){
		printf("o numero eh zero");
	} else {
		printf("o numero eh positivo\n");
		
		if (numeroInteiro % 2 == 0){
			printf("alem de ser positivo eh par tbm.\n");
		} else {
			printf("alem de ser positivo eh impar tbm.\n");
		}
	}
	
	
	return 0;
}