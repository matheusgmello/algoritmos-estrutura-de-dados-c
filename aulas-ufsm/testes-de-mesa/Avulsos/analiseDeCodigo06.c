#include <stdio.h>

int verificaImpar(int x, int y) {
    if (x % 2 != 0) {
        y = y + 1;
    }
    return y;
}

int main() {
    int N = 8;
    int menor, cont = 0, i = 0;
    int V[N];

    printf("Digite 8 numeros inteiros (um por vez):\n");
    V[0] = 1;
    V[1] = 2;
    V[2] = 3;
    V[3] = 4;
    V[4] = 5;
    V[5] = 6;
    V[6] = 7;
    V[7] = 8;
  
    // while (i < N) {
    //      printf("Digite o %dº número: ", i+1);
    //     scanf("%d", &V[i]);
    //     i++;
    // }

    menor = V[0];
    for (i = 0; i < N; i++) {
        cont = verificaImpar(V[i], cont);
        if (V[i] < menor) {
            menor = V[i];
        }
    }
    printf("\nResultado:\n");
    printf("Quantidade de numeros impares: %d\n", cont);
    printf("Menor numero digitado: %d\n", menor);
    return 0;
}