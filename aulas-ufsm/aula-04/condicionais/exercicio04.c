/*
Criar um programa que lê um número inteiro e exibe a mensagem dizendo se ele é totalmente
divisível por 7 (resto 0) ou não.
*/

#include <stdio.h>

int main()
{
	int valorUM;
	
	printf("digite um valor inteiro: ");
	scanf("%d", &valorUM);
	
	if (valorUM % 7 == 0) {
        printf("o valor inteiro %d eh divisivel totalmente por 7.\n", valorUM);
    } else {
        printf("o valor inteiro %d num eh totalmente divisivel por 7 [resto = %d].\n", valorUM, valorUM % 7);
    }
	
	return 0;
}
