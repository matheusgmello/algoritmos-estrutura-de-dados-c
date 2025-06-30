/*
Escreva um programa que leia um valor monetário em reais e uma função que calcule qual o menor número possível de notas 
de 100, 50, 20, 10, 5, 2 e 1 real(is) que o valor lido pode ser decomposto. 
Escreva o valor lido e a relação de notas necessárias, bem como a quantidade de cada nota."
*/
#include <stdio.h>

void numeroNotas(int valorReais){
	
	int notas_100=0,notas_50=0,notas_20=0,notas_10=0,notas_5=0,notas_2=0, moedas=0;
	int aux = valorReais;
	int totalNotas;
	
	while (aux > 0){
		if (aux >= 100){
			notas_100++;
			aux = aux - 100;
		} else if (aux >= 50){
			notas_50++;
			aux = aux - 50;
		} else if (aux >= 20){
			notas_20++;
			aux = aux - 20;
		} else if (aux >= 10){
			notas_10++;
			aux = aux - 10;
		} else if (aux >= 5){
			notas_5++;
			aux = aux - 5;
		} else if (aux >= 2){
			notas_2++;
			aux = aux - 2;
		} else if(aux >= 1){
			moedas++;
			aux = aux - 1;
		}
	}
	
	totalNotas = notas_100 + notas_50 + notas_20 + notas_10 + notas_5 + notas_2 + moedas;
	
	printf("o valor de entrada: %d\n", valorReais);
	printf("foram usadas %d notas de 100\nforam usadas %d notas de 50\n foram usadas %d notas de 20\nforam usadas %d notas de 10\n foram usadas %d de 5\nforam usadas %d de 2\nforam usadas moedas %d de 1\n", notas_100 , notas_50 , notas_20 , notas_10 , notas_5 , notas_2 , moedas);
	printf("total de notas %d", totalNotas);
		
}

int main(){
	
	int valorMonetario = 10.0;
	
	numeroNotas(valorMonetario);
	
	return 0;
}