#include <stdio.h>

int main(){
	
	int idade, i, mediaIdade, pesoAcima;
	float peso;
	
	for (i = 0; i < 7; i++){
		printf("digite sua idade: ");
		scanf("%d", &idade);
		
		printf("digite seu peso: ");
		scanf("%f", &peso);
		
		if (peso > 90){
			pesoAcima++;
		}
		mediaIdade = mediaIdade + idade;
		
	}
	
	mediaIdade = mediaIdade / 7;
	
	printf("pessoas com peso acima de 90: %d\n", pesoAcima);
	printf("media de idade eh: %i\n", mediaIdade);
	
	
	
	return 0;
}