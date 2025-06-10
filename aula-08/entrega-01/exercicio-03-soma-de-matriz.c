/**
Desenvolva um algoritmo que leia os elementos de uma matriz A de ordem 4 (4x4) e também de uma matriz B de
mesma ordem, gere e imprima uma matriz C com a soma dos elementos de A com B. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PreencheMatriz(int M[4][4]){
  
  int i,j;
  
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      M[i][j] = rand() % 60;
    }
  }
}

void ImprimeMatriz(int M[4][4]){
  
  int i,j;
  
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

int main(){

  int MA[4][4];
  int MB[4][4];
  int MC[4][4];
  
  int i, j;
  
  srand(time(NULL));
  
  PreencheMatriz(MA);
  PreencheMatriz(MB);
  
  for (i=0;i<4;i++){
    for(j=0;j<4;j++){
      MC[i][j] = MA[i][j] + MB[i][j];
    }
  }
  printf("Matriz A:\n");
  ImprimeMatriz(MA);
  printf("\nMatriz B:\n");
  ImprimeMatriz(MB);
  
  
  printf("\n");
  printf("\n");
  printf("soma das matrizes A e B:\n");
  ImprimeMatriz(MC);
  printf("\n");
  printf("\n");
  

  return 0;
}