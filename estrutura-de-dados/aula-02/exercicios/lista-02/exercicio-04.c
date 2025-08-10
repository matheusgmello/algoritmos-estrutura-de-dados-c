/*
Faça um algoritmo que leia um vetor de 10 elementos na função principal. Depois,
chame uma função para modificar o vetor de modo que o primeiro elemento passe
para a última posição, e desloque todos os outros para uma posição a esquerda.
Imprima o vetor modificado na função main.
Exemplo:
Antes: 12 35 25 14 1 85 10 110 44 996
Depois: 35 25 14 1 85 10 110 44 996 12
*/

#include <stdio.h>

void mudaVetor(int *v, int tamanho) {
  int primeiroElemento = *v;
  for (int i = 0; i < tamanho - 1; i++) {
    *(v + i) = *(v + i + 1);
  }
  *(v + tamanho - 1) = primeiroElemento;
}

int main() {
  int vetor[10] = {12, 35, 25, 14, 1, 85, 10, 110, 44, 996};
  int i;
  
  printf("Vetor antes da modificacao:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  
  mudaVetor(vetor, 10);
  
  printf("Vetor depois da modificacao:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  
  return 0;
}