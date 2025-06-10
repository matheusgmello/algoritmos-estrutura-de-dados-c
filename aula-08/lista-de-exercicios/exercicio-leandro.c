	/*
	Desenvolva um algoritmo para simular um jogo em um tabuleiro de xadrez onde jogador
	deve preencher cada casa com o dobro de graos existentes na casa anterior.
	
	Exemplo: casa 1 = 1 grão; casa = 2 = 2 graos; casa 3 = 4 graos, etc;
	Verifique os erros que podem surgir ao executar esse codio.
	*/
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	int main(){
		
		srand(time(NULL));
		
		int MA[8][8];
		int MB[8][8];
		
		int i,j;
		
		for (i=0;i<8;i++){
			for (j=0;j<8;j++){
				MA[i][j] = rand() % 10 + 1;
			}
		}
		
		
		for (i=0;i<8;i++){
			for (j=0;j<8;j++){
				if(j ==0 ){
					MB[i][j] = MA[i][j];
				} else {
					MB[i][j] = MA[i][j-1] * 2;
				}
				
			}
		}
		
		printf("matriz a\n");
		for (i=0;i<8;i++){
			for (j=0;j<8;j++){
				printf("%d\t", MA[i][j]);
			}
			printf("\n");
		}
		
		printf("matriz b\n");
		for (i=0;i<8;i++){
			for (j=0;j<8;j++){
				printf("%d\t", MB[i][j]);
			}
			printf("\n");
		}
		
		
		
		return 0;
	}