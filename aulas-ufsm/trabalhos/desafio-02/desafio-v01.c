#include <stdio.h>
#include <string.h>

#define MAXIMODECARACTERES 201
#define MAXIMODEPALAVRAS 10
#define TAMANHODAPALAVRA 20

/**
funcao que evita que a palavra proibida seja parte de outra palavra
exemplo: "burro" não pode ser parte de chaburros.
*/
int comentarioSeparado(char c) {
    return c == ' ' || c == '\0' || c == '.' || c == ',' || c == '!' ||
           c == '?' || c == '\n' || c == ';' || c == ':' || c == '(' ||
           c == ')' || c == '[' || c == ']' || c == '{' || c == '}' ||
           c == '"' || c == '\'' || c == '-' || c == '_';
}

/**
funcao que remove '\n' final do comentario lido
*/
void removeQuebraDeLinha(char comentario[]) {
    int tamanho = strlen(comentario);
    if (comentario[tamanho - 1] == '\n') {
        comentario[tamanho - 1] = '\0';
    }
}

/**
funcao que censura os comentarios, substituindo as palavras proibidas por '*'
*/
void censuraComentarios(char comentario[], char palavrasProibidas[][TAMANHODAPALAVRA], int quantidadeDePalavras) {
    char comentarioMinusculo[MAXIMODECARACTERES];
    int i, j, k;
    int tamanhoDoComentario = strlen(comentario);
    int tamanhoDaPalavra;

    strcpy(comentarioMinusculo, comentario);
    strlwr(comentarioMinusculo);  // deixa mais facil a comparacao, colocando tudo em minusculo

    for (i = 0; i < tamanhoDoComentario; i++) {
        for (j = 0; j < quantidadeDePalavras; j++) {
            tamanhoDaPalavra = strlen(palavrasProibidas[j]);

            /*
            verifica se a palavra proibida esta no comentario
            e se ela nao eh parte de outra palavra
            */
            if (i + tamanhoDaPalavra <= tamanhoDoComentario) {
                if (strncmp(&comentarioMinusculo[i], palavrasProibidas[j], tamanhoDaPalavra) == 0) {
                    if ((i == 0 || comentarioSeparado(comentarioMinusculo[i - 1])) &&
                        comentarioSeparado(comentarioMinusculo[i + tamanhoDaPalavra])) {

                        for (k = 0; k < tamanhoDaPalavra; k++) {
                            comentario[i + k] = '*';
                        }
                    }
                }
            }
        }
    }
}

int main() {
    char comentario[MAXIMODECARACTERES];
    char palavrasProibidas[MAXIMODEPALAVRAS][TAMANHODAPALAVRA] = {
        "burro", 
        "feio", 
        "idiota", 
        "otario", 
        "boboca", 
        "chato", 
        "babaca", 
        "bosta", 
        "gordo", 
        "merda"
    };
    int quantidadeDePalavras = MAXIMODEPALAVRAS;
    char opcao;

    printf("========================================\n");
    printf("   SISTEMA DE FILTRO DE COMENTARIOS\n");
    printf("========================================\n\n");

    do {
        printf("digite seu comentario (max 200 caracteres):\n> ");
        fgets(comentario, MAXIMODECARACTERES, stdin);
        removeQuebraDeLinha(comentario);

        censuraComentarios(comentario, palavrasProibidas, quantidadeDePalavras);

        printf("\n");
        printf("comentario filtrado pelo sistema:\n");
        puts(comentario);
        printf("----------------------------------------\n");

        printf("\ndeseja fazer outro comentario? (s/n): ");
        scanf(" %c", &opcao);
        getchar();  // limpa o buffer

        printf("\n");

    } while (opcao == 's' || opcao == 'S');

    printf("obrigado por usar o sistema!\n\n");

    return 0;
}
