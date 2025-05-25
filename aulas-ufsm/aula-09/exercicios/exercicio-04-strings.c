/*
Fazer um programa para ler uma string e contar quantas vezes um determinado caractere
aparece na string. O caractere deverá ser informado pelo usuário.
*/
#include <stdio.h>
#include <string.h>

int main() {

    char palavra[20];
    char letra;
    int i;
    int qtdLetras = 0;
    int tamanhoPalavra;

    printf("digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = 0;

    printf("digite a letra para ser analisada: ");
    scanf("%c", & letra);
    getchar();

    tamanhoPalavra = strlen(palavra);

    for (i = 0; i < tamanhoPalavra; i++) {
        if (palavra[i] == letra) {
            qtdLetras++;
        }
    }

    printf("a letra %c apareceu %d na palavra %s\n", letra, qtdLetras, palavra);

    return 0;
}