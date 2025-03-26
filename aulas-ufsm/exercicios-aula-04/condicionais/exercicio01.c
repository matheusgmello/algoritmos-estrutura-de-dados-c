/*
Desenvolva um programa para ler a temperatura de uma pessoa doente e mostrar a mensagem
“está com febre” ou “Não está com febre” considerando o valor base de 37.5ºC.
*/

#include <stdio.h>

int main()
{
	float temperatura = 0;
	
	printf("qual eh sua temperatura?: ");
	scanf("%f", &temperatura);
	
	if (temperatura >= 37.5){
		printf("esta com febre, sua temperatura eh: %2.f \n", temperatura);
	} else{
		printf("nao esta com febre, sua temperatura eh: %2.f\n", temperatura);
	}
	
	return 0;
}