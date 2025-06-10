/**
5. Crie um algoritmo para contar quantos espaços em branco existem em uma frase. Depois o
programa deve contar quantos caracteres são diferentes do caractere espaço em uma frase.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    int i, espacos = 0, diferentes = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = 0; // Remove o caractere de nova linha

    for (i = 0; i < strlen(frase); i++) {
        if (frase[i] == ' ') {
            espacos++;
        } else {
            diferentes++;
        }
    }

    printf("Quantidade de espacos em branco: %d\n", espacos);
    printf("Quantidade de caracteres diferentes do espaco: %d\n", diferentes);

    return 0;
}