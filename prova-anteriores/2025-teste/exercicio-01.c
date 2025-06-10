#include <stdio.h>
#include <string.h>

// Função que gera as iniciais com pontos
void gerarIniciais(char nome[51], char iniciais[51]) {
    int i, j = 0;

    // Se o primeiro caractere for uma letra, é uma inicial
    if (nome[0] != ' ') {
        iniciais[j++] = nome[0];
        iniciais[j++] = '.';
    }

    // Verifica os espaços e pega a próxima letra como inicial
    for (i = 1; i < 51 && nome[i] != '\0'; i++) {
        if (nome[i] == ' ' && nome[i+1] != '\0' && nome[i+1] != ' ') {
            iniciais[j++] = nome[i+1];
            iniciais[j++] = '.';
        }
    }

    iniciais[j] = '\0'; // Finaliza a string
}

int main() {
    char nome[51] = "Joao Pedro da Silva"; // Nome digitado no main
    char iniciais[51];

    gerarIniciais(nome, iniciais);

    printf("Iniciais: %s\n", iniciais);

    return 0;
}
