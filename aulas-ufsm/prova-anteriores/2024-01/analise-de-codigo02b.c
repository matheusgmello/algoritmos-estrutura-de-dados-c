#include <stdio.h>

int fnc(int p, int s, int c)
{
    int h, a;
    a = c % 2;
    switch (a) {
        case 0: h = s / p; break;
        case 1: h = (a + 1) % 2; break;
    }
    return (h);
}

int main()
{
    int E, F, G, H;
    scanf("%d %d", &E, &F);
    G = (E / 3) + (2 * F);
    H = fnc(E, F, G);
    E = E + 3;
    printf("Valores: %d %d %d\n", G, H, E);
    return 0;
} 

/*
"I. (V) No código 1, dados os valores 6 e 4 para E e F (na linha 14), respectivamente, o valor de G ao final da execução será 10.

II. (F) Os códigos 1 e 2 em linguagem de programação C não apresentam desvios condicionais.

III. (F) No código 2, dados os valores 3 e 6 para E e F (na linha 17), respectivamente, o texto apresentado ao usuário no final da execução será: Valores: 1 3

IV. (V) Os códigos 1 e 2 em linguagem de programação C não apresentam estruturas de repetição.

V. (F) Os códigos 1 e 2 são algoritmos para problemas diferentes."

*/