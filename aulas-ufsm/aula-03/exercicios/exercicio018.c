/*
Elaborar um programa que apresente o valor da conversão em real (R$) de um valor lido em dólar (US$). O
programa deve solicitar o valor da cotação do dólar e também a quantidade de dólares disponível com o
usuário.
*/

#include <stdio.h>
int main (){
	
	double cotacaoDolar = 0, quantidadeDolar = 0, quantidadeReal = 0;
	
	printf("qual a cotacao do dolar hoje: ");
	scanf("%lf", &cotacaoDolar);
	
	printf("quantos dolares tu quer converter: ");
	scanf("%lf", &quantidadeDolar);
	
	quantidadeReal = quantidadeDolar * cotacaoDolar;
	
	printf("seu valor convertido em R$ eh %.2f\n", quantidadeReal);
	
	return 0;
}