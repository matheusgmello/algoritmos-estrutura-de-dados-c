/*
Construa um programa para solicitar o sexo da pessoa e depois apresentar a mensagem:
“Prezado Senhor”, para homens e a mensagem “Prezada Senhora”, para mulheres.
Juntamente com isso, apresente uma mensagem de boas-vindas.
*/
#include <stdio.h>

int main(){
	
	char sexo;
	
	printf("qual eh seu sexo? (H ou M): ");
	scanf(" %c", &sexo);
	
	if (sexo == 'M' || sexo == 'm'){
		printf("boas vinda, prezado senhora\n");
	} else if (sexo == 'H' || sexo == 'h'){
		printf("boas vinda, prezado senhor\n");
	} else {
		printf("digite novamente ai seu mula");
	}
	
	
	return 0;
}