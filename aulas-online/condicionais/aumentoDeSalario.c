#include <stdio.h>

int main(){
	
	float salario, aumentoDeSalario;
	
	printf("digite seu salario: ");
	scanf("%f", &salario);
	
	if (salario <= 2000){
		aumentoDeSalario = salario + 400;
	} else {
		aumentoDeSalario = salario + 200;
	}
	
	printf("seu salario antigo %.2f \n", salario);
	printf("seu novo salario %.2f \n", aumentoDeSalario);	
	
	return 0;
}