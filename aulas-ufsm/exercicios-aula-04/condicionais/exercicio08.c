/*
Escreva um algoritmo que leia uma letra e imprima uma mensagem dizendo se é vogal ou não.
*/

#include <stdio.h>

#include <stdio.h>

int main() {
    char letra;
    
    printf("Digite uma letra: ");
    scanf(" %c", &letra);
    
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
        letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
        printf("a letra '%c' eh uma vogal.\n", letra);
    } else {
        printf("A letra '%c' num eh uma vogal.\n", letra);
    }
    
    return 0;
}
