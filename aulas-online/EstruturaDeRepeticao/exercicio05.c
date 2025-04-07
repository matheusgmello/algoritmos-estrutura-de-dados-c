#include <stdio.h>

int main(){
	
	
	int opcao;
	float valorA, valorB, resultado;
	
	do {
		
		printf("digite dois numeros: ");
		scanf("%f %f", &valorA, &valorB);
		printf("qual sua opcao [1 -> somar | 2-> subtrair | 3-> sair]: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: {
				resultado = valorA + valorB;
				printf("o resultado da soma eh: %f\n", resultado);
				break;
			}
			case 2: {
				resultado = valorA - valorB;
				printf("o resultado da subtracao eh: %f\n", resultado);
				break;
			case 3: {
				printf("adios amigo");
				break;
			}
			default: {
				printf("opcao invalida");
				break;
			}
			}
		}
		
	} while (opcao != 3);
	
	return 0;
}