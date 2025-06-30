/*
Desenvolva um algoritmo com uma função que recebe as três notas de um aluno por parâmetro e
uma letra. Se a letra for A, deve-se calcular a média aritmética das três notas, se for P, calcula-se a
média ponderada (pesos: 5, 3 e 2). O resultado deve ser apresentado na função principal. Se
necessário, pesquise como encontrar a média ponderada de um conjunto de valores para resolver a
questão.
*/
#include <stdio.h>

float calculaMedia(char opcao){
	
	float nota1, nota2, nota3;
	float resultado;
	float somaDosProdutos;
	printf("insira sua primeira nota: ");
	scanf("%f", &nota1);
	
	printf("insira sua segunda nota: ");
	scanf("%f", &nota2);
	
	printf("insira sua terceira nota: ");
	scanf("%f", &nota3);
	
	if (opcao == 'A' || opcao == 'a'){
		return (nota1 + nota2  + nota3) / 3;
	} else if (opcao == 'P' || opcao == 'p'){
		
		somaDosProdutos = ((nota1 * 5) + (nota2 * 3) + (nota3 * 2)) / 10;
		return somaDosProdutos;
		
	} else {
		printf("opcao invalida\n");
		return -1;
	}
	
}

int main(){
	char opcao;
	float resultado;
	
	printf("escolha sua opcao (A para aritmetic, P para ponderada): ");
	scanf(" %c", &opcao);
	
	resultado = calculaMedia(opcao);
	
	printf("%.2f\n", resultado);
	
	return 0;
}