/*
Ler o valor correspondente ao salário mensal (SM) de um trabalhador e também o valor do percentual (PE)
de reajuste a ser atribuído. Apresentar o valor do novo salário (NS).
*/


#include <stdio.h>
int main(){

   	double salarioMensal = 0, percentualDeReajuste = 0, novoSalarioReajustado = 0;

 	printf("informe seu salario: ");
 	scanf("%lf", &salarioMensal); 

 	printf("informe o percentual de reajuste: ");
 	scanf("%lf", &percentualDeReajuste);
 	
	novoSalarioReajustado = salarioMensal*percentualDeReajuste/100;
	printf("esse eh seu salario reajustado: %.2f\n", salarioMensal+novoSalarioReajustado);
		
	return 0;

}
