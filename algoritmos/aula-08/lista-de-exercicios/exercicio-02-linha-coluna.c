/*
Ler uma matriz 4x3 com valores reais e mostrar qual é o elemento armazenado em uma linha L e coluna C
fornecidas pelo usuário.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void PreencheMatriz(float M[4][3]){
	
	int i,j;
	
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			M[i][j] = rand() % 6001 / 100.0;
		}
	}
}

void ImprimeMatriz(float M[4][3]){
	
	int i,j;
	
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			printf("%.2f\t", M[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}

int main(){
	
	srand(time(NULL)); 
	
	float M[4][3]; // 4 linhas 3 colunas
	int l,c;
	
	PreencheMatriz(M);
	
	do {
		printf("qual coluna: \n");
		scanf("%d", &c);
	} while (c < 0 || c >= 3);
	
	do {
		printf("qual linha: \n");
		scanf("%d", &l);
	} while (l < 0 || l >= 4);
	
	printf("\nC0      C1      C2\n");
	ImprimeMatriz(M);
	
	printf("\n");
	printf("\nvalor na posicao [linha %d][coluna %d]: %.2f\n", l, c, M[l][c]);
	
	return 0;
}