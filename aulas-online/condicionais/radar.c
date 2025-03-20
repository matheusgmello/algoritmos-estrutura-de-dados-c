#include <stdio.h>

int main(){
	
	int velocidade;
	
	printf("digite a velocidade (km): ");
	scanf("%d", &velocidade);
	
	if (velocidade > 80){
		printf("voce foi muultado");
	} else{
		printf("voce nao foi multado");
	}
	
	
	return 0;
}