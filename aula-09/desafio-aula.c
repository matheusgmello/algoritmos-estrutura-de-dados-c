#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para usar tolower() e isalpha()

// Função auxiliar para normalizar um caractere (para minúscula)
char normalizarCaractere(char c) {
    return tolower(c);
}

// Função para verificar se a frase é um palíndromo
int ehPalindromo(char frase[]) {
    int inicio = 0;
    int fim = strlen(frase) - 1;

    while (inicio < fim) {
        // Ignora espaços no início
        while (inicio < fim && frase[inicio] == ' ') {
            inicio++;
        }
        // Ignora espaços no fim
        while (inicio < fim && frase[fim] == ' ') {
            fim--;
        }

        // Converte para minúscula para comparação case-insensitive
        char charInicio = normalizarCaractere(frase[inicio]);
        char charFim = normalizarCaractere(frase[fim]);

        if (charInicio != charFim) {
            return 0; // Não é um palíndromo
        }
        inicio++;
        fim--;
    }
    return 1; // É um palíndromo
}

// Função para contar vogais e consoantes
void contarVogaisConsoantes(char frase[], int *vogais, int *consoantes) {
    *vogais = 0;
    *consoantes = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = normalizarCaractere(frase[i]);
        if (isalpha(c)) { // Verifica se é uma letra
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                (*vogais)++;
            } else {
                (*consoantes)++;
            }
        }
    }
}

// Função para contar palavras
int contarPalavras(char frase[]) {
    int contador = 0;
    int dentroPalavra = 0; // Flag para indicar se estamos dentro de uma palavra
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ' && frase[i] != '\t' && frase[i] != '\n') { // Considera outros espaços em branco
            if (!dentroPalavra) {
                dentroPalavra = 1;
                contador++;
            }
        } else {
            dentroPalavra = 0;
        }
    }
    return contador;
}

int main() {
    char frase[100];
    int opcao;

    do {
        printf("Digite uma frase: ");
        fgets(frase, sizeof(frase), stdin);
        // Remove o '\n' adicionado pelo fgets, se presente
        frase[strcspn(frase, "\n")] = '\0';

        printf("\nEscolha uma opcao:\n");
        printf("1. Validar palíndromo\n");
        printf("2. Contar vogais e consoantes\n");
        printf("3. Contar palavras\n");
        printf("4. Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Consome o '\n' restante após o scanf

        switch (opcao) {
            case 1:
                if (ehPalindromo(frase)) {
                    printf("A frase eh um palindromo.\n");
                } else {
                    printf("A frase nao eh um palindromo.\n");
                }
                break;
            case 2: { // Bloco para declarar variáveis dentro do case
                int numVogais, numConsoantes;
                contarVogaisConsoantes(frase, &numVogais, &numConsoantes);
                printf("Vogais: %d\n", numVogais);
                printf("Consoantes: %d\n", numConsoantes);
                break;
            }
            case 3:
                printf("Palavras: %d\n", contarPalavras(frase));
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
        }
        printf("\n");
    } while (opcao != 4);

    return 0;
}