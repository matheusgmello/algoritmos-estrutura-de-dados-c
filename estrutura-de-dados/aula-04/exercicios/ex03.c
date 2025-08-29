/* 
Implementar uma lista encadeada para gerenciar uma lista de tarefas.Cada item da lista (nó) deve ser uma tarefa com os seguintes dados:
id: um número inteiro único para a tarefa;
descricao: uma string (máximo de 100 caracteres) com a descrição da tarefa;
prioridade: alta, média ou baixa.
O programa deve:
Definir a struct para o nó da lista encadeada.
Criar uma lista encadeada vazia.
Implementar uma função adicionarTarefa que insere uma nova tarefa. Para isso, considere que as tarefas devem aparecer 
por ordem de prioridade. Primeiro, todas as altas. Depois, todas as médias. E, por fim, as baixas. Uma nova tarefa deve ser inserida no final do seu grupo de prioridade;
Implementar uma função exibirTarefas que percorre a lista e imprime todos os detalhes de cada tarefa no console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    int id;
    char descricao[100];
    char prioridade; // 'A', 'M' ou 'B'
    struct Tarefa* proximo;
} Tarefa;

int prioridadeValor(char p) {
    if (p == 'A') return 3;
    if (p == 'M') return 2;
    return 1; // 'B'
}

Tarefa* adicionarTarefa(Tarefa* lista, int id, char* descricao, char prioridade) {
    Tarefa* nova = (Tarefa*)malloc(sizeof(Tarefa));
    nova->id = id;
    strcpy(nova->descricao, descricao);
    nova->prioridade = prioridade;
    nova->proximo = NULL;

    // insere no início se a lista estiver vazia ou se a nova for mais prioritária
    if (!lista || prioridadeValor(prioridade) > prioridadeValor(lista->prioridade)) {
        nova->proximo = lista;
        return nova;
    }

    Tarefa* atual = lista;
    while (atual->proximo && prioridadeValor(prioridade) <= prioridadeValor(atual->proximo->prioridade)) {
        atual = atual->proximo;
    }

    nova->proximo = atual->proximo;
    atual->proximo = nova;
    return lista;
}

void exibirTarefas(Tarefa* lista) {
    while (lista) {
        printf("ID: %d\nDescricao: %s\nPrioridade: %c\n\n",
               lista->id, lista->descricao, lista->prioridade);
        lista = lista->proximo;
    }
}

int main() {
    Tarefa* lista = NULL;

    lista = adicionarTarefa(lista, 1, "Estudar C", 'M');
    lista = adicionarTarefa(lista, 2, "Fazer compras", 'B');
    lista = adicionarTarefa(lista, 3, "Entregar trabalho", 'A');
    lista = adicionarTarefa(lista, 4, "Ler livro", 'M');

    exibirTarefas(lista);
    return 0;
}
