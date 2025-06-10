/*
Ler diversos números e mostrar quantos deles são ímpares. O valor -999 é o código para fim de
entrada.
*/

#include <stdio.h>

int main() {
    int numeroInteiro, contadorDeImpares = 0;

    printf("digite quantos numeros inteiros quiser (-999 para encerrar):\n");

    while (1) { 
        scanf("%d", &numeroInteiro);

        if (numeroInteiro == -999) {
            break;
        }

        if (numeroInteiro % 2 != 0) {
            contadorDeImpares++;
        }
    }

    printf("quantidade de impares que tu digitou: %d\n", contadorDeImpares);

    return 0;
}