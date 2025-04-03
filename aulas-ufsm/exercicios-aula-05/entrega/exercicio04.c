/*
Utilizando a função pow(), apresentar os resultados das potências de 3, variando do expoente 0
até o expoente 15.
*/

#include <stdio.h>
#include <math.h>
int main(){
	
	int valorExpoente;
	float resultadoDaConta;
	
	for (valorExpoente = 0; valorExpoente <= 15; valorExpoente++){
		resultadoDaConta = pow(3, valorExpoente);
		 printf("%d -> %.0f\n", valorExpoente, resultadoDaConta);	
	}
	
	return 0;
}