/**
Faça um algoritmo que receba os valores para uma matriz 2x3, gere e imprima uma matriz transposta. A matriz
transposta é gerada trocando a linha pela coluna. Exemplo: 
Matriz 2x3  
1 9 48
2 49 658

Transposta
1 2
9 49
48 658
*/

#include <stdio.h>

int main(){

    int matriz[2][3], transposta[3][2];

    printf("digite os valores da matriz 2x3:\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Geração da matriz transposta
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            transposta[j][i] = matriz[i][j];
        }
    }

    // Impressão da matriz transposta
    printf("matriz transposta:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }


  return 0;
}