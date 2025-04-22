#include <stdio.h>
#include <string.h>

void contadorDeLetras(){
	
	char nome[30];
	int qntdLetras;
	
	printf("digite um nome: ");
	scanf(" %s", nome);
	
	
	qntdLetras = strlen(nome);
	
	printf("total de letras no nome: %i", qntdLetras);
}

int main(){
	
	contadorDeLetras();
	
	return 0;
}