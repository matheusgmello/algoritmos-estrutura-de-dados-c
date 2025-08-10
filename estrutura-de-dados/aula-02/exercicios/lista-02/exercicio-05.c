/*
Faça um algoritmo para ler os valores gastos em cheque por uma pessoa durante um
mês na função principal. Depois crie uma função para encontrar imprimir: a lista com
todos os valores, o maior valor, o menor valor e a média de todos os valores. No início
do algoritmo o usuário deve informar quantos cheques foram usados; estabeleça um
número máximo de cheques.
*/

#include <stdio.h>

void relataCheques(float *valores, int totalCheques) {
  float maior, menor, soma = 0.0, media;
  int i;
  
  maior = *valores;
  menor = *valores;

  printf("\nLista de valores:\n");
  for (i = 0; i < totalCheques; i++) {
    printf("%.2f ", *(valores + i));
    soma += *(valores + i);
    if (*(valores + i) > maior) {
      maior = *(valores + i);
    }
    if (*(valores + i) < menor) {
      menor = *(valores + i);
    }
  }

  media = soma / totalCheques;

  printf("\n\nMaior valor: %.2f\n", maior);
  printf("Menor valor: %.2f\n", menor);
  printf("Media dos valores: %.2f\n", media);
}

int main() {
  int totalCheques, i;
  float cheques[50];

  printf("Quantos cheques foram usados (max 50)? ");
  scanf("%d", &totalCheques);

  if (totalCheques > 50 || totalCheques <= 0) {
    printf("Numero invalido de cheques.\n");
    return 1;
  }

  printf("Digite os valores dos cheques:\n");
  for (i = 0; i < totalCheques; i++) {
    printf("Cheque %d: ", i + 1);
    scanf("%f", &cheques[i]);
  }

  relataCheques(cheques, totalCheques);

  return 0;
}
