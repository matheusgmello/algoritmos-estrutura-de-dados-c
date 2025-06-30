#include <stdio.h>
#include <string.h>

void inverter(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main(){
    char texto[100]; // Declara o array de caracteres

    // Inicialização correta usando strcpy
    strcpy(texto, "carro"); 

    printf("String original: %s\n", texto);

    inverter(texto);

    printf("String invertida: %s\n", texto);

    return 0;
}

/**
Pergunta:
a) O que a função inverter faz?
a funcao inverte a string recebidade, por exemplo teste ficara etset

b) O que será impresso se a string "carro" for passada a essa função?
ira mostrar a string carro inversa, no caso orrac


c) Há algum risco se essa string vier de fgets()?
sim tanto se receber de gets ou fgets, pois ha necessidade de validar tanto o \n e tanto \0 para nao passar como parametro


*/