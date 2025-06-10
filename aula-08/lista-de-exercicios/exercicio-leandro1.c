#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main() {
    long long tabuleiro[8][8];

    long long graos = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = graos;
            graos *= 2;
        }
    }

    printf("tabuleiro de xadrez com o dobro de graos:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%lld\t", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}