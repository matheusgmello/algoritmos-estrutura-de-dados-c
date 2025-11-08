/*
BFS (Busca em Largura):

Usa uma fila para percorrer o grafo.

Explora todos os vizinhos do vertice atual antes de seguir para o proximo nivel.

Util para achar o menor caminho em grafos nao ponderados.


DFS (Busca em Profundidade):

Usa recursao (ou uma pilha) para visitar vertices.

Vai o mais fundo possivel em um caminho antes de voltar.

Util para detectar ciclos, componentes conexos e percorrer o grafo inteiro.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_ARESTAS 10

// Estrutura do grafo
typedef struct {
    int numVertices;                     
    int listaAdj[MAX_VERTICES][MAX_ARESTAS]; 
    int numArestas[MAX_VERTICES];        
} Grafo;

// Cria o grafo com N vertices
void criaGrafo(Grafo *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->numArestas[i] = 0;
        for (int j = 0; j < MAX_ARESTAS; j++) {
            g->listaAdj[i][j] = -1; // sem aresta
        }
    }
}

// Adiciona uma aresta (nao direcionado)
void adicionaAresta(Grafo *g, int origem, int destino) {
    if (origem >= g->numVertices || destino >= g->numVertices) {
        printf("Vertice invalido!\n");
        return;
    }

    g->listaAdj[origem][g->numArestas[origem]++] = destino;
    g->listaAdj[destino][g->numArestas[destino]++] = origem;
}

// Remove uma aresta (nao direcionado)
void removeAresta(Grafo *g, int origem, int destino) {
    if (origem >= g->numVertices || destino >= g->numVertices) {
        printf("Vertice invalido!\n");
        return;
    }

    // remove destino da lista da origem
    for (int i = 0; i < g->numArestas[origem]; i++) {
        if (g->listaAdj[origem][i] == destino) {
            for (int j = i; j < g->numArestas[origem] - 1; j++) {
                g->listaAdj[origem][j] = g->listaAdj[origem][j + 1];
            }
            g->numArestas[origem]--;
            break;
        }
    }

    // remove origem da lista do destino
    for (int i = 0; i < g->numArestas[destino]; i++) {
        if (g->listaAdj[destino][i] == origem) {
            for (int j = i; j < g->numArestas[destino] - 1; j++) {
                g->listaAdj[destino][j] = g->listaAdj[destino][j + 1];
            }
            g->numArestas[destino]--;
            break;
        }
    }
}

// Verifica se dois vertices sao adjacentes
int saoAdjacentes(Grafo *g, int origem, int destino) {
    if (origem >= g->numVertices || destino >= g->numVertices) {
        return 0;
    }

    for (int i = 0; i < g->numArestas[origem]; i++) {
        if (g->listaAdj[origem][i] == destino) {
            return 1;
        }
    }
    return 0;
}

// Imprime o grafo
void imprimeGrafo(Grafo *g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertice %d:", i);
        for (int j = 0; j < g->numArestas[i]; j++) {
            printf(" -> %d", g->listaAdj[i][j]);
        }
        printf("\n");
    }
}

// ---------------------------
// BUSCA EM LARGURA (BFS)
// ---------------------------
void BFS(Grafo *g, int inicio) {
    int visitado[MAX_VERTICES] = {0};
    int fila[MAX_VERTICES];
    int frente = 0, tras = 0;

    // marca o vertice inicial como visitado e coloca na fila
    visitado[inicio] = 1;
    fila[tras++] = inicio;

    printf("BFS a partir do vertice %d: ", inicio);

    while (frente < tras) {
        int atual = fila[frente++];
        printf("%d ", atual);

        // percorre os vizinhos do vertice atual
        for (int i = 0; i < g->numArestas[atual]; i++) {
            int vizinho = g->listaAdj[atual][i];
            if (!visitado[vizinho]) {
                visitado[vizinho] = 1;
                fila[tras++] = vizinho;
            }
        }
    }
    printf("\n");
}

// ---------------------------
// BUSCA EM PROFUNDIDADE (DFS)
// ---------------------------
void DFSUtil(Grafo *g, int v, int visitado[]) {
    visitado[v] = 1;
    printf("%d ", v);

    // chama recursivamente para cada vizinho nao visitado
    for (int i = 0; i < g->numArestas[v]; i++) {
        int vizinho = g->listaAdj[v][i];
        if (!visitado[vizinho]) {
            DFSUtil(g, vizinho, visitado);
        }
    }
}

void DFS(Grafo *g, int inicio) {
    int visitado[MAX_VERTICES] = {0};
    printf("DFS a partir do vertice %d: ", inicio);
    DFSUtil(g, inicio, visitado);
    printf("\n");
}

// ---------------------------
// PROGRAMA PRINCIPAL
// ---------------------------
int main() {
    Grafo g;
    criaGrafo(&g, 5);

    adicionaAresta(&g, 0, 1);
    adicionaAresta(&g, 0, 4);
    adicionaAresta(&g, 1, 2);
    adicionaAresta(&g, 1, 3);
    adicionaAresta(&g, 1, 4);
    adicionaAresta(&g, 2, 3);
    adicionaAresta(&g, 3, 4);

    printf("Lista de adjacencia do grafo:\n");
    imprimeGrafo(&g);

    printf("\nVerificando adjacencia:\n");
    printf("0 e 1 sao adjacentes? %s\n", saoAdjacentes(&g, 0, 1) ? "Sim" : "Nao");
    printf("2 e 4 sao adjacentes? %s\n", saoAdjacentes(&g, 2, 4) ? "Sim" : "Nao");

    printf("\nRemovendo aresta entre 1 e 4...\n");
    removeAresta(&g, 1, 4);
    imprimeGrafo(&g);

    printf("\n");
    BFS(&g, 0);  // busca em largura
    DFS(&g, 0);  // busca em profundidade

    return 0;
}
