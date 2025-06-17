#include <stdio.h>
#include <string.h>

// Funcao que gera as iniciais com pontos
void gerarIniciais(char nome[51], char iniciais[51]) {
    int i, j = 0;

    // Se o primeiro caractere for uma letra, e uma inicial
    if (nome[0] != ' ') {
        iniciais[j++] = nome[0];
        iniciais[j++] = '.';
    }

    // Verifica os espacos e pega a proxima letra como inicial
    for (i = 1; i < 51 && nome[i] != '\0'; i++) {
        if (nome[i] == ' ' && nome[i+1] != '\0' && nome[i+1] != ' ') {
            iniciais[j++] = nome[i+1];
            iniciais[j++] = '.';
        }
    }

    iniciais[j] = '\0'; // Finaliza a string
}

int main() {
    char nome[51];
    char iniciais[51];

    printf("Digite seu nome completo (ate 50 caracteres): ");
    gets(nome); 
    fflush(stdin); // Limpa o buffer de entrada

    gerarIniciais(nome, iniciais);

    printf("Iniciais: %s\n", iniciais);

    return 0;
}
