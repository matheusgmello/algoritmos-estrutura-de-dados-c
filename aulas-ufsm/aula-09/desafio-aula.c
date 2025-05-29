#include <stdio.h>
#include <string.h>

int ehPalindromo(char frase[]) {
    int inicio = 0, fim = strlen(frase) - 1;
    while (inicio < fim) {
        while (inicio < fim && frase[inicio] == ' ') inicio++;
        while (inicio < fim && frase[fim] == ' ') fim--;
        
        char charInicio = (frase[inicio] >= 'A' && frase[inicio] <= 'Z') ? frase[inicio] + 32 : frase[inicio];
        char charFim = (frase[fim] >= 'A' && frase[fim] <= 'Z') ? frase[fim] + 32 : frase[fim];
        
        if (charInicio != charFim) return 0;
        inicio++;
        fim--;
    }
    return 1;
}

int contarVogais(char frase[]) {
    int contador = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = (frase[i] >= 'A' && frase[i] <= 'Z') ? frase[i] + 32 : frase[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') contador++;
    }
    return contador;
}

int contarConsoantes(char frase[]) {
    int contador = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = (frase[i] >= 'A' && frase[i] <= 'Z') ? frase[i] + 32 : frase[i];
        if ((c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) contador++;
    }
    return contador;
}

int ehArtigo(char frase[]);

int contarPalavras(char frase[]) {
    int contador = 0, dentroPalavra = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ') {
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
        printf("digite uma frase: ");
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0';

        printf("\escolha uma opcao:\n");
        printf("1. valida palindromo\n");
        printf("2. contar vogais e consoantes\n");
        printf("3. contar palavras\n");
        printf("4. sair do programa\n");
        printf("opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (ehPalindromo(frase)) {
                    printf("a frase eh um palindromo.\n");
                } else {
                    printf("a frase nao eh um palindromo.\n");
                }
                break;
            case 2:
                printf("vogais: %d\n", contarVogais(frase));
                printf("consoantes: %d\n", contarConsoantes(frase));
                break;
            case 3:
                printf("palavras: %d\n", contarPalavras(frase));
                break;
            case 4:
                printf("encerrando o programa.\n");
                break;
            default:
                printf("opcao invalida.\n");
        }
        printf("\n");
    } while (opcao != 4);

    return 0;
}