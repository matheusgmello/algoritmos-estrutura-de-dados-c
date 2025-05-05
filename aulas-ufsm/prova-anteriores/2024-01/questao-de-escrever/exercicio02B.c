/*
Escreva um programa que leia um valor monetário em reais e uma função que calcule qual o menor número possível de notas 
de 100, 50, 20, 10, 5, 2 e 1 real(is) que o valor lido pode ser decomposto. 
Escreva o valor lido e a relação de notas necessárias, bem como a quantidade de cada nota."
*/
#include <stdio.h>

#include <stdio.h>

void numeroNotas(int valorReais) {
	
    // Vetor com os valores das notas disponíveis
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    
    // Vetor para armazenar a quantidade de cada nota
    int quantidade[7] = {0}; // Inicializa todas as posições com zero

    int aux = valorReais;
    int totalNotas = 0;

    // Loop para calcular a quantidade de cada nota
    for (int i = 0; i < 7; i++) {
        if (aux >= notas[i]) {
            quantidade[i] = aux / notas[i]; // Quantas notas desse valor cabem
            aux = aux % notas[i];           // Atualiza o valor restante
        }
        totalNotas += quantidade[i]; // Soma ao total de notas
    }

    // Impressão dos resultados
    printf("O valor de entrada: %d\n", valorReais);
    for (int i = 0; i < 7; i++) {
        if (quantidade[i] > 0) {
            printf("Foram usadas %d nota(s) de %d\n", quantidade[i], notas[i]);
        }
    }
    printf("Total de notas: %d\n", totalNotas);
}

int main() {
    int valorMonetario;
    printf("Digite o valor em reais: ");
    scanf("%d", &valorMonetario);

    numeroNotas(valorMonetario);

    return 0;
}