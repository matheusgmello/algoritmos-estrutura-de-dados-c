/*
O número 3025 possui a seguinte característica:
a) 30 + 25 = 55.
b) 55 * 55 = 3025.
Desenvolva um algoritmo que verifica, através de uma função, e imprime todos os números de quatro
algarismos (de 1000 até 9999) que apresentam tal característica.

QUE CODIGO CHATO PQP
*/

#include <stdio.h>
void verificaMaluquice();

int main() {
  verificaMaluquice();
  return 0;
}

void verificaMaluquice() {
  for (int num = 1000; num <= 9999; num++) {
    int parte1 = num / 100; 
    int parte2 = num % 100; 
    int soma = parte1 + parte2;
    if (soma * soma == num) {
      printf("%d\n", num);
    }
  }
}