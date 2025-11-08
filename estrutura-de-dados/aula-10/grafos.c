#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_ARESTAS 10

// Estrutura que representa o grafo
typedef struct {
    int numVertices;                     // quantidade de vertices
    int listaAdj[MAX_VERTICES][MAX_ARESTAS]; // lista de adjacencia (arestas)
    int numArestas[MAX_VERTICES];        // quantidade de arestas de cada vertice
} Grafo;

// Cria o grafo com N vertices
void criaGrafo(Grafo *g, int vertices) {
    g->numVertices = vertices;
    int i, j;
    for (i = 0; i < vertices; i++) {
        g->numArestas[i] = 0;
        // inicializa todos os espacos da lista com -1 (sem aresta)
        for (j = 0; j < MAX_ARESTAS; j++) {
            g->listaAdj[i][j] = -1;
        }
    }
}

// Adiciona uma aresta (nao direcionado)
void adicionaAresta(Grafo *g, int origem, int destino) {
    // verifica se os vertices sao validos
    if (origem >= g->numVertices || destino >= g->numVertices) {
        printf("Vertice invalido!\n");
        return;
    }

    // adiciona o destino na lista de adjacencia da origem
    g->listaAdj[origem][g->numArestas[origem]++] = destino;

    // adiciona a origem na lista de adjacencia do destino
    // pois o grafo e nao direcionado
    g->listaAdj[destino][g->numArestas[destino]++] = origem;
}

// Remove uma aresta (nao direcionado)
void removeAresta(Grafo *g, int origem, int destino) {
	int i,j;
    if (origem >= g->numVertices || destino >= g->numVertices) {
        printf("Vertice invalido!\n");
        return;
    }

    // remove o destino da lista do vertice origem
    for (i = 0; i < g->numArestas[origem]; i++) {
        if (g->listaAdj[origem][i] == destino) {
            // move os elementos para "fechar o espaco"
            for (j = i; j < g->numArestas[origem] - 1; j++) {
                g->listaAdj[origem][j] = g->listaAdj[origem][j + 1];
            }
            g->numArestas[origem]--;
            break;
        }
    }

    // remove a origem da lista do vertice destino
    for (i = 0; i < g->numArestas[destino]; i++) {
        if (g->listaAdj[destino][i] == origem) {
            for (j = i; j < g->numArestas[destino] - 1; j++) {
                g->listaAdj[destino][j] = g->listaAdj[destino][j + 1];
            }
            g->numArestas[destino]--;
            break;
        }
    }
}

// Verifica se dois vertices sao adjacentes (conectados)
int saoAdjacentes(Grafo *g, int origem, int destino) {
	int i;
    if (origem >= g->numVertices || destino >= g->numVertices) {
        return 0; // vertices invalidos
    }

    for (i = 0; i < g->numArestas[origem]; i++) {
        if (g->listaAdj[origem][i] == destino) {
            return 1; // encontrou conexao
        }
    }
    return 0; // nao ha conexao
}

// Imprime o grafo (lista de adjacencia)
void imprimeGrafo(Grafo *g) {
	int i,j;
    for (i = 0; i < g->numVertices; i++) {
        printf("Vertice %d:", i);
        for (j = 0; j < g->numArestas[i]; j++) {
            printf(" -> %d", g->listaAdj[i][j]);
        }
        printf("\n");
    }
}

// Programa principal
int main() {
    Grafo g;

    // cria grafo com 5 vertices (0 a 4)
    criaGrafo(&g, 5);

    // adiciona algumas arestas
    adicionaAresta(&g, 0, 1);
    adicionaAresta(&g, 0, 4);
    adicionaAresta(&g, 1, 2);
    adicionaAresta(&g, 1, 3);
    adicionaAresta(&g, 1, 4);
    adicionaAresta(&g, 2, 3);
    adicionaAresta(&g, 3, 4);

    printf("Lista de adjacencia do grafo:\n");
    imprimeGrafo(&g);

    // verifica conexoes
    printf("\nVerificando adjacencia:\n");
    printf("0 e 1 sao adjacentes? %s\n", saoAdjacentes(&g, 0, 1) ? "Sim" : "Nao");
    printf("2 e 4 sao adjacentes? %s\n", saoAdjacentes(&g, 2, 4) ? "Sim" : "Nao");

    // remove uma aresta
    printf("\nRemovendo aresta entre 1 e 4...\n");
    removeAresta(&g, 1, 4);
    imprimeGrafo(&g);

    return 0;
}
