#include <stdio.h>

int main(){
	
	float saldoEmConta, valor;
	int opcao;
	
	printf("qual seu saldo bancario?: ");
	scanf("%f", &saldoEmConta);
	
	while (opcao != 4){
		
		printf("bienvido ao banco central!\n");
		printf("1 - sacar\n2 - depositar\n3 - saldo\n4 - sair\nqual sua opcao:?");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf("valor que deseja sacar?: ");
				scanf("%f", &valor);
				
				if (saldoEmConta < valor){
					printf("valor insuficiente, ta tentando roubar do banco eh\n");
				} else {
					saldoEmConta = saldoEmConta - valor;
				}
				
				break;
			case 2:
				printf("valor que deseja depositar?: ");
				scanf("%f", &valor);
				
				saldoEmConta = saldoEmConta + valor;
				
				break;
			case 3:
				printf("seu saldo bancario eh: %2.f", saldoEmConta);
				break;
			case 4:
				printf("vai embora");
				break;
			default:
				printf("opcao invalida");
		}
	}
	
	return 0;
}