/*
Criar um algoritmo que leia um número inteiro e diga a qual mês do ano o mesmo corresponde. Se
o valor for maior que doze ou menor que um, apresente uma mensagem informando que o valor não
corresponde a nenhum mês. Ex.: 3  mês de março.
*/

#include <stdio.h>

int main(){
	
	int numeroMes;
	
	printf("escreva um numero de 1 a 12: ");
	scanf("%d", &numeroMes);
	
	if (numeroMes == 1){
		printf("estamos em janeiro");
	} else if (numeroMes == 2) {
		printf("estamos em fevereiro");
	} else if (numeroMes == 3){
		printf("estamos em marco");
	} else if (numeroMes == 4){
		printf("estamos em abril");
	} else if (numeroMes == 5){
		printf("estamos em maio");
	} else if (numeroMes == 6) {
		printf("estamos em junho");
	} else if (numeroMes == 7) {
		printf("estamos em julho");
	} else if (numeroMes == 8){
		printf("estamos em agosto");
	} else if (numeroMes == 9){
		printf("estamos em setembro");
	} else if (numeroMes == 10){
		printf("estamos em outubro");
	} else if (numeroMes == 11){
		printf("estamos em novembro");
	} else if (numeroMes == 12){
		printf("estamos em dezembro");
	} else {
		printf("voce inseriu um valor invalido!");
	}
	
	
	return 0;
}