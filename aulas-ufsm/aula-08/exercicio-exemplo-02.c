/*
Faça um algoritmo para ler uma matriz 3x3 de números reais e 
depois exibir na tela o elemento do canto superior esquerdo e o do canto inferior direito.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrizes(){
	
  float matriz[3][3];
  int i, j;

  printf("gerando valores para matriz\n");
  for (i=0;i<3;i++){
    for (j=0;j<3;j++){
      matriz[i][j] = rand() % 30;
    }
  }
  
  for (i=0;i<3;i++){
    for (j=0;j<3;j++){
		printf("%.2f\t", matriz[i][j]);
    }
    printf("\n");
  }
	
	printf("\nelementos do canto superior esquerdo\ne canto inferior direito\n");
	printf("%.2f\t", matriz[0][0]);
	printf("%.2f\t", matriz[2][2]);
}

int main(){

  srand(time(NULL)); 
  matrizes();


  return 0;
}