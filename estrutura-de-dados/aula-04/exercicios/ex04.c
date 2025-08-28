/* 
Desenvolva um algoritmo para fazer o gerenciamento de Clientes (Busca e Remoção).  Cada cliente deve ter um id e um nome.
Você deve:
Definir a struct para o nó da lista de clientes.
Implementar uma função adicionarCliente que insere um novo cliente no final da lista.
Implementar uma função buscarCliente que recebe a lista e um id como parâmetro, e retorna um ponteiro para o nó do cliente encontrado. Se o cliente não for encontrado, a função deve retornar NULL.
Implementar uma função removerCliente que recebe a lista e um id como parâmetro, e remove o nó do cliente correspondente. A função deve lidar com três casos: remover o primeiro nó, remover um nó no meio e remover o último nó.
Exibir a lista completa de clientes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    int id;
    char nome[100];
    struct Cliente* proximo;
};

struct Cliente* adicionarCliente(struct Cliente* lista, int id, char nome[]) {
    struct Cliente* novo = (struct Cliente*)malloc(sizeof(struct Cliente));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = NULL;
    if (lista == NULL) {
        return novo;
    }
    struct Cliente* aux = lista;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novo;
    return lista;
}

struct Cliente* buscarCliente(struct Cliente* lista, int id) {
    struct Cliente* aux = lista;
    while (aux != NULL) {
        if (aux->id == id) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

struct Cliente* removerCliente(struct Cliente* lista, int id) {
    if (lista == NULL) return NULL;
    if (lista->id == id) {
        struct Cliente* temp = lista;
        lista = lista->proximo;
        free(temp);
        return lista;
    }
    struct Cliente* aux = lista;
    while (aux->proximo != NULL && aux->proximo->id != id) {
        aux = aux->proximo;
    }
    if (aux->proximo != NULL) {
        struct Cliente* temp = aux->proximo;
        aux->proximo = temp->proximo;
        free(temp);
    }
    return lista;
}

void exibirClientes(struct Cliente* lista) {
    struct Cliente* aux = lista;
    while (aux != NULL) {
        printf("Id: %d, Nome: %s\n", aux->id, aux->nome);
        aux = aux->proximo;
    }
}

int main() {
    struct Cliente* lista = NULL;

    lista = adicionarCliente(lista, 1, "Maria");
    lista = adicionarCliente(lista, 2, "Joao");
    lista = adicionarCliente(lista, 3, "Ana");

    printf("Lista de clientes:\n");
    exibirClientes(lista);

    struct Cliente* encontrado = buscarCliente(lista, 2);
    if (encontrado != NULL) {
        printf("Cliente encontrado: %s\n", encontrado->nome);
    }

    lista = removerCliente(lista, 2);

    printf("Lista apos remocao:\n");
    exibirClientes(lista);

    return 0;
}
