/*
1. Fazer um programa que leia uma string de caracteres maiúsculos e troque todos os
caracteres por letras minúsculas
*/
#include <stdio.h>
#include <string.h>


void transsforma(){
	
	char palavra[20];
	
	printf("digite um palavra: ");
	gets(palavra);
	
	strlwr(palavra);
	
	puts(palavra);

	
}

int main(){
	
	transsforma();
	
	return 0;
}