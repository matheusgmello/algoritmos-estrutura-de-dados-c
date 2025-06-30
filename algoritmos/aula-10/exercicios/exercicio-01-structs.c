/*
Faça um algoritmo com uma função que receba os campos nome, endereço e email de
contato de uma pessoa e armazene-os em um registro. Depois, listar os dados na tela
*/

#include <stdio.h>
#include <string.h>

struct lista {
	
	char nome[20];
	char endereco[20];
	char emailDeContato[20];
	
};

struct lista preencheLista(){
	
	struct lista contato; // chama o struct original, e cria uma variavel chamado contato com as caracteristas do struct lista
	
	printf("digite seu nome: ");
	gets(contato.nome);
	
	printf("digite seu email: ");
	gets(contato.emailDeContato);
	fflush(stdin);
	
	printf("digite seu endereco: ");
	gets(contato.endereco);
	fflush(stdin);
	
	return contato; // ele devolve a variavel contato
	
}

void mostraLista(struct lista contato){

	printf("\n");
	printf("dados da lista: \n");
	
	puts(contato.nome);
	puts(contato.emailDeContato);
	puts(contato.endereco);
	
}


int main(){
	
	struct lista pessoa;
	
	pessoa = preencheLista(); // recebe o struct com os dados
	
	
	mostraLista(pessoa);
	
	return 0;
}