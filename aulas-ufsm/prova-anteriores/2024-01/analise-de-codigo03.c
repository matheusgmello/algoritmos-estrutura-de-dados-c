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

    printf("Digite 10 numeros inteiros (um por vez):\n");
    while (i < F) {
        printf("Digite o %d numero: ", i+1);
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
    printf("\nResultado:\n");
    printf("Quantidade de numeros divisiveis por 3: %d\n", b);
    printf("Menor numero digitado: %d\n", a);
    return 0;
}
// "O que faz a função 'fnc' ?"


//Ao final da execução, o que será mostrado na linha 27? Justifique sua resposta:"





