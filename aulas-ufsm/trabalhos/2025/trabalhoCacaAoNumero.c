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
#include <string.h>

#define TAMANHO 5
#define TENTATIVAS 10
#define NUMEROS_ESCONDIDOS 5

void iniciaMatriz(int matriz[TAMANHO][TAMANHO]);
void sorteiaPosicoes(int matriz[TAMANHO][TAMANHO]);
void mostraAMatrizVisivel(int matriz[TAMANHO][TAMANHO]);
void mostraAMatrizSecreta(int matriz[TAMANHO][TAMANHO]);
float calculaPorcentagem(int acertos, int tentativas);
int verificaInteiroDigitado(int minimo, int maximo, const char *mensagem);

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
        sorteiaPosicoes(matrizSecreta);

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

            linha = verificaInteiroDigitado(1, TAMANHO, "Informe a linha (1 a 5): ") - 1;
            coluna = verificaInteiroDigitado(1, TAMANHO, "Informe a coluna (1 a 5): ") - 1;

            if (matrizVisivel[linha][coluna] != 0) {
                printf("Posicao ja escolhida! Tente novamente.\n");
                continue;
            }

            tentativasRealizadas++;

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
        mostraAMatrizSecreta(matrizSecreta);
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
            while (getchar() != '\n');  // limpa buffer
        } while (jogarNovamente != 's' && jogarNovamente != 'S' && jogarNovamente != 'n' && jogarNovamente != 'N');

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nvaleu por ter jogado!! ate a proxima vez.\n");
    return 0;
}

// Lê um inteiro válido entre minimo e maximo (inclusive)
int verificaInteiroDigitado(int minimo, int maximo, const char *mensagem) {
    char buffer[100];
    int valor;
    int sucesso;

    do {
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("erro de leitura. tente novamente.\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';  // remove \n

        sucesso = sscanf(buffer, "%d", &valor);

        if (sucesso != 1 || valor < minimo || valor > maximo) {
            printf("entrada invalida! digite um numero inteiro entre %d e %d.\n\n", minimo, maximo);
        }

    } while (sucesso != 1 || valor < minimo || valor > maximo);

    return valor;
}

void iniciaMatriz(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = 0;
        }
    }
}

void sorteiaPosicoes(int matriz[TAMANHO][TAMANHO]) {
    int count = 0;
    while (count < NUMEROS_ESCONDIDOS) {
        int linha = rand() % TAMANHO;
        int coluna = rand() % TAMANHO;
        if (matriz[linha][coluna] != 9) {
            matriz[linha][coluna] = 9;
            count++;
        }
    }
}

void mostraAMatrizVisivel(int matriz[TAMANHO][TAMANHO]) {
    printf("\nMatriz atual:\n    ");
    for (int j = 0; j < TAMANHO; j++) printf("%d ", j + 1);
    printf("\n   ");
    for (int j = 0; j < TAMANHO; j++) printf("--");
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void mostraAMatrizSecreta(int matriz[TAMANHO][TAMANHO]) {
    printf("\nPosicoes com os numeros escondidos:\n    ");
    for (int j = 0; j < TAMANHO; j++) printf("%d ", j + 1); 
    printf("\n   ");
    for (int j = 0; j < TAMANHO; j++) printf("--"); 
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            if (matriz[i][j] == 9) {
                printf("9 ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

float calculaPorcentagem(int acertos, int tentativas) {
    return tentativas > 0 ? (acertos * 100.0) / tentativas : 0;
}
