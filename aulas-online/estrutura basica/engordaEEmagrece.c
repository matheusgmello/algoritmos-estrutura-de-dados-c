#include <stdio.h>

int main(){
	
	float peso, pesoEngorda, pesoEmagrece;
	
	printf("digite seu peso: ");
	scanf("%f", &peso);
	
	pesoEngorda = peso * 1.15;
	
	pesoEmagrece = peso * 0.80;
	
	printf("se tu engordar 15%% vai ficar com %2.f\n", pesoEngorda);
	printf("mas se tu emagrecer 20%% vai ficar com %2.f", pesoEmagrece);
	
	
	
	
	
	
	return 0;
}