/*
Ler uma matriz A de ordem 5 e construir uma matriz B de mesma dimensão, onde cada elemento de B deve ser o
dobro de cada elemento correspondente da matriz A, com exceção para os valores situados na diagonal principal os
quais devem ser o triplo de cada elemento correspondente a A. Apresentar a matriz B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Triplica(){
	
	int MA[5][5];
	int MB[5][5];
	
	int i, j;
	
	for (i=0;i<5;i++){
		for(j=0;j<5;j++){
			MA[i][j] = rand() % 60;
		}
	}

	for (i=0;i<5;i++){
		for(j=0;j<5;j++){
			if (i == j){ // se linha for igual coluna
				MB[i][j] = MA[i][j] * 3; // multiplica por 3
			}else{
				MB[i][j] = MA[i][j] * 2; // se nao multiplica por 2
			}
		}
	}

	printf("Matriz A:\n");
	for (i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ", MA[i][j]);
		}
		printf("\n");
	}

	printf("\nMatriz B:\n");
	for (i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ", MB[i][j]);
		}
		printf("\n");
	}
	
}

int main(){

	srand(time(NULL)); 

	Triplica();
	
	return 0;
}