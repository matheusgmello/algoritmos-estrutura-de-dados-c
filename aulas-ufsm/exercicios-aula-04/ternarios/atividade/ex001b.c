/*
1. Escreva um programa  para ler qualquer número de mês (1. janeiro, 2. fevereiro, ...) e exibir o nome por extenso. Ou adaptar para dias da semana.
*/

#include <stdio.h>
int main(){
	
	int numeroSemana;
	
	printf("digite qual o dia da semana (1 a 7): ");
	scanf("%d", &numeroSemana);
	
	numeroSemana == 1? printf("domingo") : numeroSemana == 2? printf("segunda") : numeroSemana == 3? printf("terca") : numeroSemana == 4? printf("quarta") :
	numeroSemana == 5? printf("quinta") :numeroSemana == 6? printf("sexta") :numeroSemana == 7? printf("sabado") : printf("esse dia da semana n existe, digite de 1 a 7");
	
	return 0;
}