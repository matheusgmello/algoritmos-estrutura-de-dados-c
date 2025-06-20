/**
Analise os códigos fornecidos e identifique possíveis problemas, erros ou oportunidades de melhoria. Faça
as correções necessárias e explique as razões das mudanças realizadas.
*/

#include <stdio.h>
#include <string.h>

#define N 20

void concatenarStrings(char str1[], char str2[]) {
    int tamanho1 = strlen(str1);
    int tamanho2 = strlen(str2);
    for (int i = 0; i <= tamanho2; i++) {
        str1[tamanho1 + i] = str2[i];
    }
}

int main() {
    char string1[N] = "Hello\0";
    char string2[N] = "world!\0";
    concatenarStrings(string1, string2);
    printf("Strings concatenadas: %s\n", string1);
    return 0;
}