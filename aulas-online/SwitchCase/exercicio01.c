#include <stdio.h>

int main(){
	
	float numA, numB, resultado;
	int opcao;
	
	printf("digite o primeiro numero: ");
	scanf("%f", &numA);
	
	printf("digite o segundo numero: ");
	scanf("%f", &numB);
	
	printf("Menu\n 1 - Diferenca entre dois numeros\n 2 - Media entre dois numeros\n 3 - Divisao do primero pelo segundo\n 4 - Divisao do segundo pelo primeiro\n");
	printf("qual sua opcao?: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			resultado = numA - numB;
			printf("o resultado da diferenca entre dois numeros eh %f", resultado);
			break;
		case 2:
			resultado = (numA + numB) / 2;
			printf("o resultado da media entre dois numeros eh %f", resultado);
			break;
		case 3:
			resultado = numA / numB;
			printf("o resultado da divisao do primeiro pelo segundo eh %f", resultado);
			break;
		case 4:
			resultado = numB / numA;
			printf("o resultado da divisao do segundo pelo primeiro eh %f", resultado);
			break;
		default:
			printf("opcao invalida");
	}
	
	return 0;
}