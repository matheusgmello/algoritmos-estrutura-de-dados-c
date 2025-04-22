#include <stdio.h>
#include <string.h>

void mostraNomeDigitado(){
	char nome[30];
	
	printf("digite seu nome: ");
	// scanf("%s", &nome); // %S, utilizar somnete quando quiser ler uma palavra.
	
	fgets(nome, 30, stdin);
	
	printf("nome digitado foi: %s \n", nome);
		
}

int main(){
	
	mostraNomeDigitado();
	
	return 0; 
}