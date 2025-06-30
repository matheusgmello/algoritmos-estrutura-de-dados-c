/**
Baseando-se no exercício anterior, acrescente no algoritmo um menu que permita ao
usuário escolher um dos seguintes tipos de relatórios:
a) Por ordem inversa de registro;
b) Por idade em ordem crescente;
c) Por idade em ordem decrescente;
d) Por sexo e por ordem de sexo;
*/

/**
Em uma pesquisa envolvendo 20 entrevistados, uma editora solicitou os seguintes
dados: sexo, idade e quantidade de livros que leu em 2020. Faça um programa que
leia os dados digitados pelo usuário e ao final, calcule e imprima: a) A
quantidade total de livros lidos pelos entrevistados menores de 10 anos; b) A
quantidade de mulheres que leram 5 livros ou mais; c) O percentual de pessoas
que não leram livros.
*/

#include <stdio.h>
#include <string.h>

#define NUM_ENTREVISTADOS 3

struct pesquisa {
    char sexo;
    int idade;
    int qtdLivros;
};

void mostrarPesquisa(struct pesquisa p) {
    printf("sexo: %c\n", p.sexo);
    printf("idade: %d\n", p.idade);
    printf("livros lidos: %d\n", p.qtdLivros);
}

int main() {
    struct pesquisa entrevista[NUM_ENTREVISTADOS];
    int qtdLivrosMenores = 0, qtdMulherLer5ouMais = 0, qtdNaoLeuLivros = 0, i, opcao, j;
    float percentual = 0;

    for (i = 0; i < NUM_ENTREVISTADOS; i++) {
        printf("qual seu sexo (M ou F): ");
        fflush(stdin);
        scanf(" %c", &entrevista[i].sexo);
        fflush(stdin);

        printf("qual sua idade: ");
        scanf("%d", &entrevista[i].idade);
        fflush(stdin);

        printf("quantos livros tu leu?: ");
        scanf("%d", &entrevista[i].qtdLivros);
        fflush(stdin);

        if (entrevista[i].idade < 10) {
            qtdLivrosMenores += entrevista[i].qtdLivros;
        }

        if ((entrevista[i].sexo == 'f' || entrevista[i].sexo == 'F') && entrevista[i].qtdLivros >= 5) {
            qtdMulherLer5ouMais++;
        }

        if (entrevista[i].qtdLivros == 0) {
            qtdNaoLeuLivros++;
        }
        printf("\n");
    }

    percentual = (qtdNaoLeuLivros * 100.0) / NUM_ENTREVISTADOS;

    printf("\n");
    printf("total de livros lidos por menores de 10 anos: %d\n", qtdLivrosMenores);
    printf("qtd de mulheres que leram 5 ou mais: %d\n", qtdMulherLer5ouMais);
    printf("percentual de quem nao leu:  %.2f%%\n", percentual);
    printf("\n");

    struct pesquisa copia[NUM_ENTREVISTADOS];
    for (i = 0; i < NUM_ENTREVISTADOS; i++) {
        copia[i] = entrevista[i];
    }

    do {
        printf("\n\nMENU\n\n");
        printf("1 - por ordem inversa de registro\n");
        printf("2 - por idade crescente\n");
        printf("3 - por idade decrescente\n");
        printf("4 - por sexo (f depois m)\n");
        printf("0 - sair\n");
        printf("escolha a opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            printf("\n\nOrdem inversa da pesquisa:\n\n");
            for (i = NUM_ENTREVISTADOS - 1; i >= 0; i--) {
                mostrarPesquisa(entrevista[i]);
            }
        }
        else if (opcao == 2) {
            struct pesquisa aux;
            for (i = 0; i < NUM_ENTREVISTADOS - 1; i++) {
                for (j = 0; j < NUM_ENTREVISTADOS - i - 1; j++) {
                    if (copia[j].idade > copia[j + 1].idade) {
                        aux = copia[j];
                        copia[j] = copia[j + 1];
                        copia[j + 1] = aux;
                    }
                }
            }
            printf("\n\nOrdem por idade crescente:\n\n");
            for (i = 0; i < NUM_ENTREVISTADOS; i++) {
                mostrarPesquisa(copia[i]);
            }
        }
        else if (opcao == 3) {
            struct pesquisa aux;
            for (i = 0; i < NUM_ENTREVISTADOS - 1; i++) {
                for (j = 0; j < NUM_ENTREVISTADOS - i - 1; j++) {
                    if (copia[j].idade < copia[j + 1].idade) {
                        aux = copia[j];
                        copia[j] = copia[j + 1];
                        copia[j + 1] = aux;
                    }
                }
            }
            printf("\n\nOrdem por idade decrescente:\n\n");
            for (i = 0; i < NUM_ENTREVISTADOS; i++) {
                mostrarPesquisa(copia[i]);
            }
        }
        else if (opcao == 4) {
            printf("\n\nPor sexo (F depois M):\n\n");
            for (i = 0; i < NUM_ENTREVISTADOS; i++) {
                if (entrevista[i].sexo == 'f' || entrevista[i].sexo == 'F') {
                    mostrarPesquisa(entrevista[i]);
                }
            }
            for (i = 0; i < NUM_ENTREVISTADOS; i++) {
                if (entrevista[i].sexo == 'm' || entrevista[i].sexo == 'M') {
                    mostrarPesquisa(entrevista[i]);
                }
            }
        }
        else if (opcao == 0) {
            printf("Encerrando programa... Até mais!\n");
        }
        else {
            printf("Opcao invalida, tente novamente\n");
        }

    } while (opcao != 0);

    return 0;
}
