#include <stdio.h>


int main(){
	
	float altura, pesoIdeal;
	char sexo;
	
	printf("qual eh sua altura: ");
	scanf("%f", &altura);
	
	printf("qual eh seu sexo (M - F): ");
	scanf(" %c", &sexo);
	
	if (sexo == 'M' || sexo == 'm'){
		pesoIdeal = (72.7 * altura) - 58;
	} else if( sexo == 'F' || sexo == 'f'){
		pesoIdeal = (62.1 * altura) - 44.7;
	} else {
		printf("genero errado irmao! ");
	}
	
	printf("SEU PESO IDEAL EH %f ", pesoIdeal);
	
	return 0;
}