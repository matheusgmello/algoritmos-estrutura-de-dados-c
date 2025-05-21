/*
Desenvolva um algoritmo com uma função para ler seu nome e armazená-lo na variável nome e seu sobrenome armazenando-o na variável sobrenome. 
Depois mostrar o valor das duas variáveis para o usuário.
*/

#include <stdio.h>
#include <string.h>

void stringCacete(){
	
	char nome[20], sobreNome[20];
	
	printf("digite seu nome: ");
	gets(nome);
	
	printf("digite seu sobrenome: ");
	gets(sobreNome);
	
	char nomeCompleto[60];
	
	strcpy(nomeCompleto, nome);
	
	strcat(nomeCompleto, " ");
	strcat(nomeCompleto, sobreNome);
	
	puts(nomeCompleto);
	
}

int main(){
	
	stringCacete();
	
	return 0;
}