/*
1. Escreva um programa  para ler qualquer número de mês (1. janeiro, 2. fevereiro, ...) e exibir o nome por extenso. Ou adaptar para dias da semana.
*/

#include <stdio.h>
int main(){
	
	int numeroMes;
	
	printf("qual mes vc nasceu (escreva em numero): ");
	scanf("%d", &numeroMes);
	
	numeroMes == 1? printf("janeiro") : numeroMes == 2? printf("fevereiro") : numeroMes == 3? printf("marco") : numeroMes == 4? printf("abril") :
	numeroMes == 5? printf("maio") :numeroMes == 6? printf("junho") :numeroMes == 7? printf("julho") :numeroMes == 8? printf("agosto") :
	numeroMes == 9? printf("setembro") :numeroMes == 10? printf("outubro") : numeroMes == 11? printf("novembro") : numeroMes == 12? printf("dezembro") :
	printf("este mes n existe, digite de 1 a 12");
	
	return 0;
}