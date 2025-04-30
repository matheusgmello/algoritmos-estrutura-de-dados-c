#include <stdio.h>

int fnc(int c, int d) {
    if (c % 3 == 0) {
        d = d + 1;
    }
    return d;
}

int main() {
    int F = 10;
    int a, b = 0, i = 0;
    int G[F]; 
    while (i < F) {
        scanf("%d", &G[i]); 
        i++;
    }
    a = G[0]; 
    for (i = 0; i < F; i++) {
        b = fnc(G[i], b);
        if (G[i] < a) {
            a = G[i];
        }
    }
    printf("Saida: %d, %d\n", b, a);
    return 0;
}

// "O que faz a função 'fnc' ?"


//Ao final da execução, o que será mostrado na linha 27? Justifique sua resposta:"





