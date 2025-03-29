#include <stdio.h>

int main(){
	
	char sexo;
	float peso;
	
	printf("qual teu sexo? (M ou F):");
	scanf("%c", &sexo);
	
	printf("qual teu peso?: ");
	scanf("%f", &peso);

	switch(sexo){
		case 'M':
			if (peso <= 60) {
				printf("tu eh ligeiro");
			} else if (peso <= 63){
				printf("tu eh meio-leve");
			} else {
				printf("tu eh leve");
			}
			break;
		case 'm':
			if (peso <= 60) {
				printf("tu eh ligeiro");
			} else if (peso <= 63){
				printf("tu eh meio-leve");
			} else {
				printf("tu eh leve");
			}
			break;
		case 'F':
			if (peso <= 60) {
				printf("tu eh ligeiro");
			} else if (peso <= 63){
				printf("tu eh meio-leve");
			} else {
				printf("tu eh leve");
			}
			break;
		case 'f':
			if (peso <= 48) {
				printf("tu eh ligeiro");
			} else if (peso <= 52){
				printf("tu eh meio-leve");
			} else {
				printf("tu eh leve");
			}
			break;
		default:
			printf("seu sexo digitado esta invalido");
	}	
	
	return 0;
}