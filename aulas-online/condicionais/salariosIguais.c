#include <stdio.h>

int main(){
	
	float salarioP1, salarioP2;
	
	printf("insira o salario da primeira pessoa: ");
	scanf("%f", &salarioP1);
	
	printf("insira o salario da segunda pessoa: ");
	scanf("%f", &salarioP2);
	
	if (salarioP1 > salarioP2){
		printf("salario da pessoa 1 eh maior que o da segunda pessoa");
	} else if (salarioP2 > salarioP1){
		printf("salario da pessoa 2 eh maior que o da primeira pesoa");
	} else{
		printf("o salarios sao iguais");
	}
		
	return 0;
}