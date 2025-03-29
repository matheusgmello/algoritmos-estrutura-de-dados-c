#include <stdio.h>

int main(){
	
	float N1, N2, resultado;
	int operacao;
	
	printf("qual o valor de N1: ");
	scanf("%f", &N1);
	
	printf("qual o valor de N2: ");
	scanf("%f", &N2);
	
	printf("escolha qual operacao: \n ");
	printf("1 - soma\n 2 - subtracao\n 3 - divisao\n 4 - multiplicacao\n");
	printf("opcao: ");
	scanf("%d", &operacao);
	
	switch(operacao){
		case 1:
			resultado = N1 + N2;
			printf("o resultado eh %2.f", resultado);
			break;
		case 2:
			resultado = N1 - N2;
			printf("o resultado eh %2.f", resultado);
			break;
		case 3:
			resultado = N1 / N2;
			printf("o resultado eh %2.f", resultado);
			break;
		case 4:
			resultado = N1 * N2;
			printf("o resultado eh %2.f", resultado);
			break;
		default:
			printf("operacao escolhida invalida\n");
	}
	
	
	
	return 0;
}