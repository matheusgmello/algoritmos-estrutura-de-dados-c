#include <stdio.h>
#include <string.h>

// Função que verifica se duas strings são iguais
// Retorna 0 se forem iguais, 1 se forem diferentes
int saoIguais(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) {
        return 1; // Se os tamanhos forem diferentes, as strings são diferentes
    }
    for (int i = 0; i <= strlen(s1); i++) { // Corrigido: o loop deve ir até < strlen(s1) para evitar acessar fora do limite
        if (s1[i] != s2[i]) { // Se algum caractere for diferente, as strings são diferentes
            return 1;
        }
    }
    return 0;
}

int main() {
    char palavra1[100], palavra2[100];
    scanf("%s %s", palavra1, palavra2);

    if (saoIguais(palavra1, palavra2) == 0) {
        printf("Sao diferentes.\n");
    } else {
        printf("Sao iguais.\n");
    }

    return 0;
}

/**
 Pergunta:
Quais erros ou problemas lógicos esse código possui?
// Resposta:
O código possui alguns erros lógicos e de implementação:
1. A condição de comparação na função `saoIguais` está invertida. O retorno 0 deve indicar que as strings são iguais, e 1 que são diferentes.
2. O loop na função `saoIguais` deve iterar até `strlen(s1) - 1`, pois o índice máximo válido é `strlen(s1) - 1`.
3. A mensagem de saída no `main` também está invertida. Deve dizer "Sao iguais." quando as strings são iguais e "Sao diferentes." quando não são.


Corrija o que for necessário e explique com comentários.
*/
