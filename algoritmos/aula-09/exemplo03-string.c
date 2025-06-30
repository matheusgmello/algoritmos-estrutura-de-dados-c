/*
Crie um algoritmo com uma função que contenha dois vetores do tipo char, chamados palavra1 e palavra2. 
Utilizando a função gets, atribua valores (texto) para elas e depois faça o seguinte:
Descubra o tamanho de cada uma delas.
Se e, somente, se tiverem o mesmo tamanho, verifique se as duas palavras são iguais e informe ao usuário sobre isso.
*/
#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

void slaonome(){

	char palavra1[20], palavra2[20]; // Correção aqui

	printf("digite a palavra: ");
	gets(palavra1);

	printf("digite a segunda palavra: ");
	gets(palavra2);

	int tamanho1, tamanho2;

	tamanho1 = strlen(palavra1);
	tamanho2 = strlen(palavra2);


	if (tamanho1 == tamanho2){
		int verifica = strcmp(palavra1, palavra2);
		if (verifica == 0){
			printf("sao iguais");
		} else {
			printf("diferentes");
		}
	}


}

int main(){

	slaonome();

	return 0;
}