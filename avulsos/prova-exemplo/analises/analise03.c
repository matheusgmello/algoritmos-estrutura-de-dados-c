#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inverterPalavras(char entrada[], char saida[]) {
    int i = 0, j = 0, inicio = 0;

    while (entrada[i] != '\0') {
        if (entrada[i] == ' ' || entrada[i+1] == '\0') {
            int fim = (entrada[i] == ' ') ? i - 1 : i;
            for (int k = fim; k >= inicio; k--) {
                saida[j++] = entrada[k];
            }
            if (entrada[i] == ' ') {
                saida[j++] = ' ';
            }
            inicio = i + 1;
        }
        i++;
    }
    saida[j] = '\0';
}

int main() {
    char frase[100], resultado[100];
    printf("Digite uma frase: ");
    gets(frase);
    inverterPalavras(frase, resultado);
    printf("Resultado: %s\n", resultado);
    return 0;
}


/**
🔹 Perguntas:
a) Qual é a função do inverterPalavras?

a funcao do inverter palavras é rodar um loop ate encontrar o fim da palavra para inverter ele, invertando cada um dos caracteres, e tbm confere se ha espaco digitado na palavra

b) Se a entrada for "teste 123", qual será a saída?

a saida sera etset 321, pois ele inverte as palavras na ordem que é recebida entao no caso foi recebido teste 123, ele continua na mesma ordem, apenas muda a ordem dos caracteres

c) O uso de gets() é seguro? Justifique.

nao o uso do gets nao é seguro para qualquer aplicacao, pois ele permite que o usuario acabe estourando o buffer de entrada, por isso é recomendado o uso de fgets()


*/