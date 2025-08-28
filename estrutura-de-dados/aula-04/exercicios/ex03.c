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

struct Tarefa {
    int id;
    char descricao[100];
    char prioridade;
    struct Tarefa* proximo;
};

void adicionarTarefa(struct Tarefa** lista, int id, char* descricao, char prioridade) {
    struct Tarefa* nova = (struct Tarefa*)malloc(sizeof(struct Tarefa));
    nova->id = id;
    strcpy(nova->descricao, descricao);
    nova->prioridade = prioridade;
    nova->proximo = NULL;

    if (*lista == NULL) {
        *lista = nova;
        return;
    }

    struct Tarefa *atual = *lista, *anterior = NULL;
    while (atual) {
        if (prioridade == 'A' && atual->prioridade != 'A'){
        	break;
		}
        if (prioridade == 'M' && atual->prioridade == 'B') {
        	break;
		}
        anterior = atual;
        atual = atual->proximo;
    }
    if (anterior == NULL) {
        nova->proximo = *lista;
        *lista = nova;
    } else {
        nova->proximo = atual;
        anterior->proximo = nova;
    }
}

void exibirTarefas(struct Tarefa* lista) {
    while (lista) {
        printf("ID: %d\n", lista->id);
        printf("Descricao: %s\n", lista->descricao);
        printf("Prioridade: %c\n\n", lista->prioridade);
        lista = lista->proximo;
    }
}

int main() {
    struct Tarefa* lista = NULL;
    adicionarTarefa(&lista, 1, "Estudar C", 'M');
    adicionarTarefa(&lista, 2, "Fazer compras", 'B');
    adicionarTarefa(&lista, 3, "Entregar trabalho", 'A');
    adicionarTarefa(&lista, 4, "Ler livro", 'M');
    exibirTarefas(lista);
    return 0;
}