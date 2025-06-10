/*
Desenvolva um programa que leia e imprima os valores pares armazenados em uma matriz 2x3.
*/
#include <stdio.h>
void matrizes(){
	
  int matriz[2][3];
  int i, j;

  printf("digite os valores para matriz\n");
  for (i=0;i<2;i++){
    for (j=0;j<3;j++){
      scanf("%d", &matriz[i][j]);
    }
  }

  for (i=0;i<2;i++){
    for (j=0;j<3;j++){
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(){

  matrizes();


  return 0;
}