/*
Elaborar um programa que calcule o volume de uma caixa retangular.
*/

#include <stdio.h>
int main (){
	
	float largura, altura, comprimento, volumeDaCaixa;
	
	printf("insira a largura da caixa: ");
	scanf("%f", &largura);
	
	printf("insira a altura da caixa: ");
	scanf("%f", &altura);
	
	printf("insira a comprimento da caixa: ");
	scanf("%f", &comprimento);
	
	volumeDaCaixa = (largura * altura * comprimento);
	
	printf("o volume da caixa eh: %f metros cubicos", volumeDaCaixa);
	
	return 0;
}