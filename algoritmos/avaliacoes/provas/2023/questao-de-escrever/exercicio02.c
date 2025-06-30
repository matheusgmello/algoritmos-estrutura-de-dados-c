/*
4. (2,0) Desenvolva uma função que leia N valores inteiros e insira-os em um vetor em ordem crescente. A cada valor capturado, o programa deve 
encontrar sua posição correta no vetor e ajustar os demais elementos. Exemplo:

Valor lido: 10

vetor | 10 |   |   |
       0   1   2

Valor lido: 30

vetor | 10 | 30 |   |
       0   1   2

Valor lido: 20

vetor | 10 | 20 | 30 |
       0   1   2

Observação: a ordenação deve ser feita no momento da inserção. Não é permitida a inserção de todos os elementos para depois realizar a ordenação.
*/

#include <stdio.h>

void funcaoProva() {
    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    int vet[N];

    int qtd = 0;  // quantidade de elementos já inseridos
    int valor, pos, i, j;

    for (i = 0; i < N; i++) {
        printf("digite o valor %d: ", i + 1);
        scanf("%d", &valor);

        // 1. Encontrar a posição correta para inserir
        pos = 0;
        while (pos < qtd && vet[pos] < valor) {
            pos++;
        }

        // 2. Deslocar os elementos para abrir espaço
        for (j = qtd; j > pos; j--) {
            vet[j] = vet[j - 1];
        }

        // 3. Inserir o valor na posição correta
        vet[pos] = valor;

        // 4. Atualizar a quantidade de elementos inseridos
        qtd++;
    }

    // Exibir o vetor ordenado
    printf("Vetor ordenado: ");
    for (i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    funcaoProva();
    return 0;
}