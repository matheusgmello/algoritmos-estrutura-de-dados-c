/*
Ler duas matrizes A e B 4x5. A matriz A deve ser formada por valores que sejam divisíveis por 3 e 4, enquanto a
matriz B deve ser formada por valores que sejam divisíveis por 5 e 6. As entradas dos valores nas matrizes devem
ser validadas pelo programa e não pelo usuário. Construir e apresentar uma matriz C de mesma dimensão que
contenha a subtração dos elementos da matriz A e B.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	
	srand(time(NULL)); 

	
	int MA[4][5];
	int MB[4][5];
	int MC[4][5];
	
	int i,j;
	
	for (i=0;i<4;i++){
		for(j=0;j<5;j++){
			do {
				MA[i][j] = rand() % 20 + 1;
			} while (MA[i][j] % 3 == 0 && MA[i][j] % 4 == 0);
		}
	}
	
	for (i=0;i<4;i++){
		for(j=0;j<5;j++){
			do {
				MB[i][j] = rand() % 20 + 1;
			} while (MB[i][j] % 5 == 0 && MB[i][j] % 6 == 0);
		}
	}
	
	for (i=0;i<4;i++){
		for(j=0;j<5;j++){
			MC[i][j] = MA[i][j] - MB[i][j];
		}
	}
	
	printf("matriz a\n");
	
	for (i=0;i<4;i++){
		for(j=0;j<5;j++){
			printf("[%d]", MA[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	printf("\n");
	
	
	printf("matriz b\n");
	
	for (i=0;i<4;i++){
		for(j=0;j<5;j++){
			printf("[%d]", MB[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	printf("matriz c\n");
	
	for (i=0;i<4;i++){
		for(j=0;j<5;j++){
			printf("[%d]", MC[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	return 0;
}