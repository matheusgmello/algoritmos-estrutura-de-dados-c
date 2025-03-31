#include <stdio.h>

int main(){
	int numero, qtdDez = 0;
	
	
	while (numero != 0 ){
		printf("digite um numero: ");
		scanf("%d", &numero);
		if (numero == 10){
			qtdDez++;
		}
	}
	
	printf("total de vezes que foi digitado 10, foram:  %d vezes", qtdDez);
	
	return 0;
}