/*
Desenvolva um algoritmo que faça a leitura de dois números inteiros e chame uma
função para verificar se são valores primos. Caso não sejam, altere os valores das
variáveis para armazenar os próximos primos a partir dos valores lidos. Exemplo:
valores lidos: x = 4 e y = 9. (Não são primos)
x = 5 e y = 11 (as variáveis recebem estes valores, pois 5 é o próximo primo
depois de 4 e 11 é o próximo primo depois de 9)
*/

#include <stdio.h>

int ehPrimo(int n) {
  if (n <= 1) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int proximoPrimo(int n) {
  int proximo = n + 1;
  while (ehPrimo(proximo) == 0) { 
    proximo++;
  }
  return proximo;
}

void verificaEAlteraPrimos(int *x, int *y) {
  if (ehPrimo(*x) == 0) {
    *x = proximoPrimo(*x);
  }
  if (ehPrimo(*y) == 0) {
    *y = proximoPrimo(*y);
  }
}

int main() {
  int x, y;

  scanf("%d", &x);

  scanf("%d", &y);

  printf("\nNum Iniciais: x = %d, y = %d\n", x, y);

  verificaEAlteraPrimos(&x, &y);

  printf("Num finais: x = %d, y = %d\n", x, y);

  return 0;
}