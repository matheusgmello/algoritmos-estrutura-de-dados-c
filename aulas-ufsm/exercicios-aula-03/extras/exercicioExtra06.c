/*
Uma fábrica de camisetas produz os tamanhos pequeno, médio e grande, cada uma sendo
vendida respectivamente por 10, 12 e 15 reais. Construa um algoritmo em que o usuário
forneça a quantidade de camisetas pequenas, médias e grandes referentes a uma venda, e a
máquina informe quanto será o valor arrecadado. 
*/

#include <stdio.h>

#define PRECOP 10
#define PRECOM 12
#define PRECOG 15

int main() {
    int tamanhoP, tamanhoM, tamanhoG;
    float totalArrecadado;

    printf("quantas camisas pequenas: ");
    scanf("%d", &tamanhoP);
    
    printf("quantas camisas medias: ");
    scanf("%d", &tamanhoM);
    
    printf("quantas camisas grandes: ");
    scanf("%d", &tamanhoG);

    totalArrecadado = (tamanhoP * PRECOP) + (tamanhoM * PRECOM) + (tamanhoG * PRECOG);

    printf("valor total da venda: R$ %.2f\n", totalArrecadado);

    return 0;
}
