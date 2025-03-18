#include <stdio.h>

int main (){
	
	// Declarando as variaveis
	int idade;
	char sexo;
	float peso;
	
	// Atribuindo valores
	idade = 30;
	peso = 90.5;
	sexo = 'M';
	
	// %i ou %d = inteiro
	// %f = float
	// %c = char
	printf("Sua idade e: %i\n", idade);
	printf("Seu peso e: %f\n", peso);
	printf("Seu genero e: %c", sexo);
	
	return 0;
}