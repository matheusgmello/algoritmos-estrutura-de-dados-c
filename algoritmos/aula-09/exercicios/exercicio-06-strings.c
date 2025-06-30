/**
6. Fazer um programa para ler uma string e um caractere. Sempre que o caractere lido
aparecer na frase, ele deverá ser substituído por asterisco.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch;
    int i;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    printf("Digite um caractere: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            str[i] = '*';
        }
    }

    printf("String modificada: %s\n", str);

    return 0;
}