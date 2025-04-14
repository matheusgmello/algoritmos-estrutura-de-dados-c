#include <stdio.h>

int main(){
	
	
	float notas[3], mediaDeNotas;
	int i;
	
	for(i =0; i< 3; i++){
		
		printf("nota 1: ");
		scanf("%f", &notas[0]);
	
		printf("nota 2: ");
		scanf("%f", &notas[1]);
		
		printf("nota 3: ");
		scanf("%f", &notas[2]);
		
		printf("notas digitadas:\n");
		printf("%f\n", notas[0]);
		printf("%f\n", notas[1]);
		printf("%f\n", notas[2]);
	
	}
	
	return 0;
}