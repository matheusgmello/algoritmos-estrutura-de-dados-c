/** 
Criar um programa que possa armazenar as alturas de dez atletas de 5 delegações que participarão das olimpíadas
e imprima a maior altura de cada delegação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float atletas[5][10];
    float maiorAltura[5];
    int i, j;

    srand(time(NULL)); 

    for(i = 0; i < 5; i++) {
        printf("altuaas dos atletas da delegacao %d:\n", i + 1);
        for(j = 0; j < 10; j++) {
            atletas[i][j] = 1.50 + (rand() % 71) / 100.0;
            printf("atleta %d: %.2f\n", j + 1, atletas[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 5; i++) {
        maiorAltura[i] = atletas[i][0];
        for(j = 1; j < 10; j++) {
            if(atletas[i][j] > maiorAltura[i]) {
                maiorAltura[i] = atletas[i][j];
            }
        }
    }

    printf("maior altura de cada delegacao:\n");
    for(i = 0; i < 5; i++) {
        printf("delegacao %d: %.2f\n", i + 1, maiorAltura[i]);
    }

    return 0;
}
