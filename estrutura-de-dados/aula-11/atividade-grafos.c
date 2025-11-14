/**
Desenvolver um algoritmo para implementar um grafo com 6 vértices, 
onde pelo menos dois deles devem ter graus 2 e 3.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6
// struct pro no
typedef struct no {
    int destino;
    struct no *prox;
} no;

// struct pro grafo
typedef struct grafo {
    no *listaAdj[MAX_VERTICES];
} grafo;

// cria um no
no *criarNo(int destino) {
    no *novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        printf("erro de alocacao de memoria!\n");
        exit(1);
    }
    novoNo->destino = destino;
    novoNo->prox = NULL;
    return novoNo;
}

// cria um grafo com N vertices
grafo *criarGrafo() {
    grafo *novoGrafo = (grafo*)malloc(sizeof(grafo));
    if (novoGrafo == NULL) {
        printf("erro de alocacao de memoria!\n");
        exit(1);
    }

    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        novoGrafo->listaAdj[i] = NULL;
    }
    return novoGrafo;
}

// Ffncao para adicionar uma aresta (u, v) no grafo naodirecionado
void adicionarAresta(grafo *g, int u, int v) {
    no *novoNoU = criarNo(v);
    novoNoU->prox = g->listaAdj[u];
    g->listaAdj[u] = novoNoU;

    // adiciona U a lista de V (para grafo naodirecionado)
    no *novoNoV = criarNo(u);
    novoNoV->prox = g->listaAdj[v];
    g->listaAdj[v] = novoNoV;
}

void calcularGrau(grafo* g, int vertice) {
    int grau = 0;
    no *temp = g->listaAdj[vertice];
    
    while (temp != NULL) {
        grau++;
        temp = temp->prox;
    }
    printf("grauu do vertice %d: %d\n", vertice, grau);
}

void imprimirGrafo(grafo *g) {
    printf("\nrepresentacao do grafo:\n");
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        no *temp = g->listaAdj[i];
        printf("vertice %d:", i);
        while (temp != NULL) {
            printf(" -> %d", temp->destino);
            temp = temp->prox;
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
}

void liberarGrafo(grafo *g) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        no  *temp = g->listaAdj[i];
        while (temp != NULL) {
            no *proximo = temp->prox;
            free(temp);
            temp = proximo;
        }
    }
    free(g);
}

int main() {
    grafo *grafoLocal = criarGrafo();
    
    adicionarAresta(grafoLocal, 0, 1);
    adicionarAresta(grafoLocal, 0, 2); 
    
    adicionarAresta(grafoLocal, 1, 3);
    
    adicionarAresta(grafoLocal, 2, 4);
    adicionarAresta(grafoLocal, 3, 5);
    
    adicionarAresta(grafoLocal, 0, 3);
    
    imprimirGrafo(grafoLocal);
    
    calcularGrau(grafoLocal, 0);
    calcularGrau(grafoLocal, 1);
    
    liberarGrafo(grafoLocal);

    return 0;
}