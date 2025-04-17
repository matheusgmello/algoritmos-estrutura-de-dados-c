/*
Escreva uma função que recebe a idade de uma pessoa em anos, meses e dias e retorna essa idade
expressa em dias. Leve em consideração que todos os meses possuem 30 dias e que a pessoa já
comemorou aniversário no ano corrente.

1 ano = 360 dias

*/
#include <stdio.h>
int idadeEmDias(int anos, int meses, int dias);

int main(){
	
	int totalDias, idade, qtdMeses, qtdDias;
	
	printf("Digite sua idade, quantos meses e quantos dias: ");
	scanf("%d %d %d", &idade, &qtdMeses, &qtdDias);
		
	totalDias = idadeEmDias(idade, qtdMeses, qtdDias);
	
	printf("a idade em dias eh: %d\n", totalDias);
	return 0;
}

int idadeEmDias(int anos, int meses, int dias){
		
	int resultadoDeAnos;
	int resultadoDeMeses;
	int resultadoGeral;
	
	resultadoDeAnos = (anos * 360);
	resultadoDeMeses = (meses * 30);
	
	resultadoGeral = resultadoDeMeses + resultadoDeAnos + dias;
	
	return resultadoGeral;
	
}