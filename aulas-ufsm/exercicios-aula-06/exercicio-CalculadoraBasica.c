/*
Utilizando o conceito de protótipos, escreva um programa com 5 opções: 4 para realizar as
operações matemáticas básicas, e 1 para encerrar o programa. Ex:
1 – Adição
2 – Subtração
3 – Multiplicação
4 – Divisão
0 – Sair
Implemente uma função para cada operação. 
*/
#include <stdio.h>

int somarNumeros(int numeroUm, int numeroDois);
int subtrairNumeros(int numeroUm, int numeroDois);
int multiplicarNumeros(int numeroUm, int numeroDois);
float dividirNumeros(float numeroUm, float numeroDois);


int main(){
	
	int N1, N2;
	int opcao;
	
	printf("bem vindo a calculadora!!!!\n");
	printf("digite dois numeros: ");
	scanf("%d %d", &N1, &N2);
	printf("\ndigite sua opcao\n1 - para somar\n2 - para subtrair\n3 - para multiplicar\n4 - dividir\n0 - para sair\n");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1: {
			somarNumeros(N1, N2);
			break;
		}
		case 2: {
			subtrairNumeros(N1,N2);
			break;
		}
		case 3: {
			multiplicarNumeros(N1,N2);
			break;
		}
		case 4: {
			dividirNumeros(N1, N2);
			break;
		}
		case 0: {
			printf("adios amigo");
			break;
		}
		default: {
			printf("opcao invalida");
			break;
		}
	}
	
	return 0;
}


int somarNumeros(int numeroUm, int numeroDois){
	
	int resultadoDaSoma = (numeroUm + numeroDois);
	
	printf("o resultado eh: %d\n", resultadoDaSoma);
	return resultadoDaSoma;
	
}

int subtrairNumeros(int numeroUm, int numeroDois){
	
	int resultadoDaSubtracao = (numeroUm - numeroDois);
	
	printf("o resultado da subtracao eh: %d\n", resultadoDaSubtracao);
	return resultadoDaSubtracao;
}

int multiplicarNumeros(int numeroUm, int numeroDois){
	
	int resultadoDaMultiplicacao = (numeroUm * numeroDois);
	
	printf("o resultado da multiplicacao eh: %d\n", resultadoDaMultiplicacao);
	return resultadoDaMultiplicacao;
}

float dividirNumeros(float numeroUm, float numeroDois){
	
	float resultadoDaDivisao = (numeroUm / numeroDois);
	
	printf("o resultado da divisao eh: %.2f\n", resultadoDaDivisao);
	
	return resultadoDaDivisao;
}