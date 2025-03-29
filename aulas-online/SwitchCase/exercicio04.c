#include <stdio.h>

int main(){
	
	int opcao, quantidadeComprada;
	float valorDaCompra;
	
	printf("menu lanchonete\n");
	printf("1 - pastel (R$ 4,50)\n2 - coxinha (R$ 4,00)\n3 - hamburguer (R$ 12,00)\n");
	printf("qual sua opcao?: ");
	scanf("%d", &opcao);
	
	printf("quantidade desejada?: ");
	scanf("%d", &quantidadeComprada);
	
	switch(opcao){
		case 1:
			valorDaCompra = quantidadeComprada * 4.50;
			printf("valor a pagar: %2.f", valorDaCompra);
			break;
		case 2:
			valorDaCompra = quantidadeComprada * 4.0;
			printf("valor a pagar: %2.f", valorDaCompra);
			break;
		case 3:
			valorDaCompra = quantidadeComprada * 12.00;
			printf("valor a pagar: %2.f", valorDaCompra);
			break;
		default:
			printf("produto invalido");
	}
	
	return 0;
}