#include <stdio.h>
#include <string.h>

#define MAXIMODECARACTERES 201
#define MAXIMODEPALAVRAS 10
#define TAMANHODAPALAVRA 20
#define TAMANHODONOME 50

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
funcao que remove '\n' final do comentario ou nome lido
*/
void removeQuebraDeLinha(char texto[]) {
    int tamanho = strlen(texto);
    if (tamanho > 0 && texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
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
    strlwr(comentarioMinusculo);  // deixa mais facil a comparacao

    for (i = 0; i < tamanhoDoComentario; i++) {
        for (j = 0; j < quantidadeDePalavras; j++) {
            tamanhoDaPalavra = strlen(palavrasProibidas[j]);

            // verifica se a palavra proibida esta no comentario e se ela nao eh parte de outra palavra
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
    char nome[TAMANHODONOME];
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

    printf("Por favor, digite seu nome:\n> ");
    fgets(nome, TAMANHODONOME, stdin);
    removeQuebraDeLinha(nome);

    do {
        printf("\n%s, digite seu comentario (max 200 caracteres):\n> ", nome);
        fgets(comentario, MAXIMODECARACTERES, stdin);
        removeQuebraDeLinha(comentario);

        censuraComentarios(comentario, palavrasProibidas, quantidadeDePalavras);

        printf("\nComentario filtrado do %s:\n", nome);
        puts(comentario);
        printf("----------------------------------------\n");

        printf("\n%s, deseja fazer outro comentario? (s/n): ", nome);
        scanf(" %c", &opcao);
        getchar();  // limpa o buffer

    } while (opcao == 's' || opcao == 'S');

    printf("\nObrigado por usar o sistema, %s!\n\n", nome);

    return 0;
}
