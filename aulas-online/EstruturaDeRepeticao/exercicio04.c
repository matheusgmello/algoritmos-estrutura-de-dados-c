#include <stdio.h>

int main(){
	
	int opc;
	float valorA, valorB, resultado;
	
	do{
		
		printf("digite dois numeros:\n");
		scanf("%f %f", &valorA, &valorB);
		
		printf("digite qual opcao (1 -> soma | 2 -> subtrai | 3 -> sair):");
		scanf("%d", &opc);
		
		
		switch(opc){
			case 1:{
				resultado = valorA + valorB;
				printf("resultado eh %f", resultado);
				break;
			}
			case 2: {
				resultado = valorA - valorB;
				printf("resultado eh %f", resultado);
				break;
			}	default: {
				break;
			}
		}
		
	}while(opc != 3);
	
	return 0;
}