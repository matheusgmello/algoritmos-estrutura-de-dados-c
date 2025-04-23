/*
Fazer um algoritmo que leia diversos números e mostre quantas vezes o número 10 foi digitado.
O programa deve parar quando o usuário digitar 0.
*/

#include <stdio.h>

int main() {
    int numerosDigitados, quantasVezesN10 = 0;

    printf("digite quantos numeros quiser (0 para encerrar):\n");

    while (1) { 
        scanf("%d", &numerosDigitados);

        if (numerosDigitados == 0) {
            break;
        }

        if (numerosDigitados == 10) {
            quantasVezesN10++;
        }
    }

    printf("quantidade de 10 que tu digitou: %d\n", quantasVezesN10);

    return 0;
}