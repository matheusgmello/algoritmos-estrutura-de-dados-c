/*
Desenvolva um algoritmo que solicite um valor positivo ou negativo para o usuário e
apresente o valor sempre positivo.
*/

#include <stdio.h>

int main(){
	
	float valorA;
    
    printf("Digite um valor (positivo ou negativo): ");
    scanf("%f", &valorA);
    
    if (valorA < 0) {
        valorA = -valorA;
    }
    
    printf("O valor positivo eh: %.2f\n", valorA); 
	
	return 0;
}