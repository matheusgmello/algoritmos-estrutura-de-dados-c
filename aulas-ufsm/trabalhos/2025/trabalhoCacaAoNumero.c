/*
Trabalho 1: caca ao numero
Implemente um jogo em que o jogador deve descobrir as posicoes de valores especiais escondidos
em uma matriz 5x5. O programa gera aleatoriamente 5 posicoes secretas, marcadas com o valor 9,
mas que o jogador nao ve. O jogador tem 10 tentativas para acertar o maior numero possivel de
posicoes corretas.
Regras do Jogo:
- A matriz comeca com todos os valores como 0 (oculta).
- O programa insere cinco valores 9 em posicoes aleatorias da matriz.
- O jogador, em cada rodada:
- Informa as coordenadas da tentativa (linha e coluna).
- Se acertar uma posicao com 9, ganha 1 ponto.
- Se errar, a posicao e marcada como -1.
- O jogo termina apos 10 tentativas ou quando o jogador encontra todas as posicoes com 9.

O que exibir ao final:
- Matriz final com acertos (9), erros (-1) e posicoes nao reveladas (0);
- Numero de acertos do jogador;
- Uma funcao que calcule a eficiencia: (acertos / tentativas) * 100%
- Casos omissos ao enunciado devem ser tratados pelo aluno e fazem parte da avaliacao.

Matheus Gabriel e Isaac - 2025 - 1 semestre
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5
#define TENTATIVAS 10
#define NUMEROS_ESCONDIDOS 5

void iniciaMatriz(int matriz[TAMANHO][TAMANHO]);
void sorteiaPosicoes(int matriz[TAMANHO][TAMANHO]);
void mostraAMatrizVisivel(int matriz[TAMANHO][TAMANHO]);
void mostraAMatrizSecreta(int matriz[TAMANHO][TAMANHO]);
float calculaPorcentagem(int acertos, int tentativas);

int main() {
    srand(time(NULL));
    char jogarNovamente;

    do {
        int matrizSecreta[TAMANHO][TAMANHO];
        int matrizVisivel[TAMANHO][TAMANHO];
        int linha, coluna;
        int acertos = 0;
        int tentativasRealizadas = 0;

        iniciaMatriz(matrizSecreta);
        iniciaMatriz(matrizVisivel);
        sorteiaPosicoes(matrizSecreta);  // Preenche com os números escondidos (9)

        printf("============================\n");
        printf("======= Bem vindo ao =======\n");
        printf("=== Jogo: Caca ao Numero ===\n");
        printf("============================\n");
        printf("Encontre os %d numeros escondidos (9).\n", NUMEROS_ESCONDIDOS);
        printf("Voce tem %d tentativas. Buena suerte!\n", TENTATIVAS);

        while (tentativasRealizadas < TENTATIVAS && acertos < NUMEROS_ESCONDIDOS) {
            printf("\nTentativa %d/%d | Acertos: %d/%d\n", 
            tentativasRealizadas + 1, TENTATIVAS, acertos, NUMEROS_ESCONDIDOS);
            mostraAMatrizVisivel(matrizVisivel);

            // pede uma linha valida (de 1 a TAMANHO)
            do {
                printf("Informe a linha (1 a %d): ", TAMANHO);
                scanf("%d", &linha);

                // verifica se a linha eh valida, caso o usuario digite algo fora do intervalo
                if (linha < 1 || linha > TAMANHO) {
                    printf("linha invalida, tente novamente por favor.\n\n");
                }

            } while (linha < 1 || linha > TAMANHO);
            linha--;  // ajuste do vetor pro indice ficar correto (de 0 a 4)

            // pede uma coluna valida (de 1 a TAMANHO)
            do {
                printf("Informe a coluna (1 a %d): ", TAMANHO);
                scanf("%d", &coluna);

                // verifica se a coluna eh valida, caso o usuario digite algo fora do intervalo
                if (coluna < 1 || coluna > TAMANHO) {
                    printf("coluna invalida, tente novamente por favor.\n\n");
                }

            } while (coluna < 1 || coluna > TAMANHO);
            coluna--;  // ajuste do vetor pro indice ficar correto (de 0 a 4)

            // verificacao se a posicao ja foi escolhida
            if (matrizVisivel[linha][coluna] != 0) {
                printf("Posicao ja escolhida! Tente novamente.\n");
                continue;  // nao conta como tentativa
            }

            tentativasRealizadas++;

            // faz a verificacao se o jogador encontrou o 9 ou nao
            if (matrizSecreta[linha][coluna] == 9) {
                printf("Acertou! Encontrou um 9!!!\n");
                matrizVisivel[linha][coluna] = 9;
                acertos++;
            } else {
                printf("Errou feio. nao ha nada aqui.\n");
                matrizVisivel[linha][coluna] = -1;
            }
        }

		printf("============================");
        printf("\n====== FIM DE JOGO =========\n");
        mostraAMatrizVisivel(matrizVisivel);
        mostraAMatrizSecreta(matrizSecreta);  // chama a funcao pra mostrar onde que tava os 9
        printf("\n====== RESULTADOS =========\n");
        printf("\nTotal de acertos: %d/%d\n", acertos, NUMEROS_ESCONDIDOS);
        printf("Tentativas usadas: %d/%d\n", tentativasRealizadas, TENTATIVAS);
        printf("Porcentagem dos acertos: %.2f%%\n", calculaPorcentagem(acertos, tentativasRealizadas));

        if (acertos == NUMEROS_ESCONDIDOS) {
            printf("Parabens!!!!! tu encontrou todos os numeros escondidos!! é dificil mas aconteceu\n");
        } else if (tentativasRealizadas == TENTATIVAS) {
            printf("Suas tentativas esgotaram! Tente novamente.\n");
        }

        do {
            printf("\nDeseja tentar novamente? (s/n): ");
            scanf(" %c", &jogarNovamente);
        } while (jogarNovamente != 's' && jogarNovamente != 'S' && jogarNovamente != 'n' && jogarNovamente != 'N');

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nvaleu por ter jogado!! ate a proxima vez.\n");
    return 0;
}

// bota zero em todas as posicoes da matriz e inicializa a matriz
void iniciaMatriz(int matriz[TAMANHO][TAMANHO]) {
	int i;
	int j;
	
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            matriz[i][j] = 0;
        }
    }
}

// sorteia as posicoes que o 9 vai ficar (numeros escondidos)
void sorteiaPosicoes(int matriz[TAMANHO][TAMANHO]) {
    int count = 0;
    while (count < NUMEROS_ESCONDIDOS) {
        int linha = rand() % TAMANHO;
        int coluna = rand() % TAMANHO;
        if (matriz[linha][coluna] != 9) {  // aqui garante que nao vai repetir
            matriz[linha][coluna] = 9;
            count++;
        }
    }
}

/** 
funcao pra mostrar a matriz visivel (com os numeros que o jogador escolheu)
e os que ele errou (-1)
*/
void mostraAMatrizVisivel(int matriz[TAMANHO][TAMANHO]) {
	int i;
	int j;
	
    printf("\nMatriz atual:\n    ");
    for (j = 0; j < TAMANHO; j++) printf("%d ", j + 1);
    printf("\n   ");
    for (j = 0; j < TAMANHO; j++) printf("--");
    printf("\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("%d | ", i + 1);
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// funcao pra mostrar onde tava os numeros escondidos (9)
void mostraAMatrizSecreta(int matriz[TAMANHO][TAMANHO]) {
	int i;
	int j;
	
    printf("\nPosicoes com os numeros escondidos:\n    ");
    for (j = 0; j < TAMANHO; j++) printf("%d ", j + 1); 
    printf("\n   ");
    for (j = 0; j < TAMANHO; j++) printf("--"); 
    printf("\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("%d | ", i + 1);
        for (j = 0; j < TAMANHO; j++) {
            if (matriz[i][j] == 9) {
                printf("9 ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// calcula a porcentagem final de acertos do jogador
float calculaPorcentagem(int acertos, int tentativas) {
    return tentativas > 0 ? (acertos * 100.0) / tentativas : 0;
}
