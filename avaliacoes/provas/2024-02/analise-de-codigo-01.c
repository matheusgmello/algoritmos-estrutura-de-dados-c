/**
Analise os códigos fornecidos e identifique possíveis problemas, erros ou oportunidades de melhoria. Faça
as correções necessárias e explique as razões das mudanças realizadas.
*/

#include <stdio.h>
#include <string.h>

int saoIguais(char str1[], char str2[]){
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    for (int i = 0; i <= strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

void inverterString(char str[]) {
    int inicio = 0;
    int fim = strlen(str) - 1;
    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
    char palavra1[100], palavra2[100];
    printf("Digite a primeira palavra: ");
    scanf("%s", palavra1);
    printf("Digite a segunda palavra: ");
    scanf("%s", palavra2);
    if (saoIguais(palavra1, palavra2) == 0) {
        printf("são iguais.\n");
    } else {
        printf("são diferentes.\n");
    }
    inverterString(palavra1);
    printf("%s\n", palavra1);
    return 0;
}

/**


*/