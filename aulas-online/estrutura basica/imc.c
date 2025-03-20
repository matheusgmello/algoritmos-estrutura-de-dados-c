#include <stdio.h>

int main(){
	
	float altura,peso,imc;
	
	printf("informe seu peso (kg): ");
	scanf("%f", &peso);
	
	printf("informe sua altura (cm): ");
	scanf("%f", &altura);
	
	imc = peso / (altura * altura); 
	
	printf("seu peso eh %f, sua altura eh %f e seu imc eh de %f", peso,altura,imc);
	
	
	
	return 0;
}