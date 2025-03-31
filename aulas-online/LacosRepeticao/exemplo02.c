#include <stdio.h>

int main(){
	
	float nota, acumuladoNotas;
	int indice = 0;
	
	while (indice < 5){
		printf("insira sua nota: ");
		scanf("%f", &nota);
		
		acumuladoNotas = acumuladoNotas + nota;
		
		indice++;
	}
	
	
	acumuladoNotas = acumuladoNotas / 5;
	
	printf("media de notas: %f ", acumuladoNotas);
	return 0;
}