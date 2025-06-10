/*
3. Desenvolver um programa que obtenha as seguintes informações para “n” colegas da sua
turma de algoritmos:

  Nome à char nome[15];
  sobrenome à char sobrenome[30];
  endereço à char end[80];
  telefone à char fone[8];
  idade à char id[3];

Após, realizar as seguintes tarefas:
Copiar o nome para uma variável denominada nome_compl;
Concatenar o sobrenome à variável nome_compl;
Obter o tamanho da variável nome_compl;
Imprimir todas as informações (nome_compl, endereço, telefone, idade e tamanho de
nome_compl) de cada um dos seus colegas na tela.
 */

#include <stdio.h>
#include <string.h>

#define MAX_COLEGAS 10
#define MAX_NOME 15
#define MAX_SOBRENOME 30
#define MAX_ENDERECO 80
#define MAX_TELEFONE 8
#define MAX_IDADE 3
#define MAX_NOME_COMPL (MAX_NOME + MAX_SOBRENOME + 1) // +1 para o espaco

// Funcao para ler os dados de um colega
void lerDadosColega(char nome[][MAX_NOME], char sobrenome[][MAX_SOBRENOME], char end[][MAX_ENDERECO],
                    char fone[][MAX_TELEFONE], char id[][MAX_IDADE], int index) {
    printf("Colega %d:\n", index + 1);
    printf("Nome: ");
    scanf("%s", nome[index]);
    printf("Sobrenome: ");
    scanf("%s", sobrenome[index]);
    printf("Endereco: ");
    scanf("%s", end[index]);
    printf("Telefone: ");
    scanf("%s", fone[index]);
    printf("Idade: ");
    scanf("%s", id[index]);
}

// Funcao para processar e imprimir os dados de um colega
void imprimirDadosColega(char nome[][MAX_NOME], char sobrenome[][MAX_SOBRENOME], char end[][MAX_ENDERECO],
                         char fone[][MAX_TELEFONE], char id[][MAX_IDADE], int index) {
    char nome_compl[MAX_NOME_COMPL];

    // Copiar o nome para nome_compl
    strcpy(nome_compl, nome[index]);
    
    // Concatenar o sobrenome
    strcat(nome_compl, " ");
    strcat(nome_compl, sobrenome[index]);

    // Obter o tamanho de nome_compl
    int tamanho = strlen(nome_compl);

    // Imprimir as informacoes
    printf("\nInformacoes do colega %d:\n", index + 1);
    printf("Nome completo: %s\n", nome_compl);
    printf("Endereco: %s\n", end[index]);
    printf("Telefone: %s\n", fone[index]);
    printf("Idade: %s\n", id[index]);
    printf("Tamanho do nome completo: %d\n\n", tamanho);
}

int main() {
    char nome[MAX_COLEGAS][MAX_NOME];
    char sobrenome[MAX_COLEGAS][MAX_SOBRENOME];
    char end[MAX_COLEGAS][MAX_ENDERECO];
    char fone[MAX_COLEGAS][MAX_TELEFONE];
    char id[MAX_COLEGAS][MAX_IDADE];

    int n;

    printf("Quantos colegas voce deseja? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        lerDadosColega(nome, sobrenome, end, fone, id, i);
        imprimirDadosColega(nome, sobrenome, end, fone, id, i);
    }

    return 0;
}