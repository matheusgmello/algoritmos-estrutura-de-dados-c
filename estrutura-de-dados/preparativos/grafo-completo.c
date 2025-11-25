#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Tamanho maximo fixo para os arrays (lista e matriz)

// Definicao das Estruturas de Dados
// ----------------------------------------------------

typedef struct no {
    int vertice;
    struct no *prox;
} No;

typedef struct lista {
    struct no *inicio;
} Lista;

typedef struct grafo {
    Lista listaAdj[MAX_VERTICES];
    int matrizAdj[MAX_VERTICES][MAX_VERTICES]; // Estrutura: Matriz de Adjacencia
    int numVertices;
} Grafo;

// ----------------------------------------------------
// Funcoes Auxiliares de Lista
// ----------------------------------------------------

/*
 * A funcao 'criaNo' e uma funcao auxiliar que aloca memoria
 * dinamicamente para um novo no da lista de adjacencia.
 * Recebe o numero do 'vertice' que o novo no ira representar.
 */
No *criaNo(int vertice) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria para No.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->vertice = vertice;
    novoNo->prox = NULL;
    return novoNo;
}

/*
 * A funcao 'removeNo' remove o primeiro no com o valor 'verticeParaRemover'
 * encontrado na lista encadeada que comeca em 'inicio'.
 * Retorna o novo ponteiro de inicio da lista apos a remocao.
 */
No *removeNo(No *inicio, int verticeParaRemover) {
    No *noAtual = inicio;
    No *noAnterior = NULL;

    if (noAtual != NULL && noAtual->vertice == verticeParaRemover) {
        inicio = noAtual->prox;
        free(noAtual);
        return inicio;
    }

    while (noAtual != NULL && noAtual->vertice != verticeParaRemover) {
        noAnterior = noAtual;
        noAtual = noAtual->prox;
    }

    if (noAtual == NULL) {
        return inicio;
    }

    noAnterior->prox = noAtual->prox;
    free(noAtual);
    return inicio;
}

// ----------------------------------------------------
// Operacoes Basicas do Grafo (Inicializacao, Insercao, Remocao)
// ----------------------------------------------------

/*
 * A funcao 'inicializaGrafo' prepara a estrutura do grafo para uso,
 * configurando a lista e a matriz de adjacencia para o numero inicial de vertices.
 * Recebe um ponteiro para a estrutura 'Grafo' e o numero de vertices.
 */
void inicializaGrafo(Grafo *grafo, int numVertices) {
    int i, j;
    grafo->numVertices = numVertices;

    for (i = 0; i < numVertices; i++) {
        grafo->listaAdj[i].inicio = NULL;
        for (j = 0; j < numVertices; j++) {
            grafo->matrizAdj[i][j] = 0;
        }
    }
}

/*
 * A funcao 'insereVertice' adiciona um novo vertice ao grafo,
 * aumentando o campo 'numVertices' e inicializando suas estruturas.
 * Retorna 1 se o vertice foi adicionado, ou 0 se o limite foi atingido.
 */
int insereVertice(Grafo *grafo) {
    int novoVertice = grafo->numVertices;
    int i;

    if (novoVertice >= MAX_VERTICES) {
        printf("Limite maximo de vertices atingido (%d).\n", MAX_VERTICES);
        return 0; // FALSE
    }

    // Inicializa a nova linha e coluna na Matriz de Adjacencia
    for (i = 0; i < novoVertice; i++) {
        grafo->matrizAdj[novoVertice][i] = 0;
        grafo->matrizAdj[i][novoVertice] = 0;
    }
    grafo->matrizAdj[novoVertice][novoVertice] = 0; // Se houver laco

    // Inicializa a nova Lista de Adjacencia
    grafo->listaAdj[novoVertice].inicio = NULL;
    grafo->numVertices++;
    return 1; // TRUE
}

/*
 * A funcao 'removeVertice' remove um vertice do grafo,
 * liberando suas arestas e ajustando as estruturas.
 * Retorna 1 se o vertice foi removido, 0 caso contrario.
 */
int removeVertice(Grafo *grafo, int verticeParaRemover) {
    int i, j;

    if (verticeParaRemover < 0 || verticeParaRemover >= grafo->numVertices) {
        printf("Erro: Vertice %d e invalido para remocao.\n", verticeParaRemover);
        return 0; // FALSE
    }

    // 1. Remove os nos referentes a verticeParaRemover de *TODAS* as outras listas
    for (i = 0; i < grafo->numVertices; i++) {
        if (i != verticeParaRemover) {
            grafo->listaAdj[i].inicio = removeNo(grafo->listaAdj[i].inicio, verticeParaRemover);
        }
    }

    // 2. Libera e limpa a Lista de Adjacencia do verticeParaRemover
    No *noAtual = grafo->listaAdj[verticeParaRemover].inicio;
    No *proximoNo;
    while (noAtual != NULL) {
        proximoNo = noAtual->prox;
        free(noAtual);
        noAtual = proximoNo;
    }
    grafo->listaAdj[verticeParaRemover].inicio = NULL;

    // 3. Atualiza as estruturas: Move o ultimo vertice para a posicao removida
    int ultimoVertice = grafo->numVertices - 1;
    if (verticeParaRemover != ultimoVertice) {
        // Copia a lista do ultimo vertice para a posicao removida
        grafo->listaAdj[verticeParaRemover] = grafo->listaAdj[ultimoVertice];
        grafo->listaAdj[ultimoVertice].inicio = NULL;

        // Copia as linhas e colunas da matriz
        for (j = 0; j < grafo->numVertices; j++) {
            grafo->matrizAdj[verticeParaRemover][j] = grafo->matrizAdj[ultimoVertice][j];
        }
        for (i = 0; i < grafo->numVertices; i++) {
            grafo->matrizAdj[i][verticeParaRemover] = grafo->matrizAdj[i][ultimoVertice];
        }
    }
    grafo->numVertices--;
    
    return 1; // TRUE
}

/*
 * A funcao 'insereAresta' adiciona uma aresta nao-direcionada ao grafo,
 * atualizando tanto a lista quanto a matriz de adjacencia.
 * Recebe um ponteiro para o 'Grafo', o vertice de 'origem' e o vertice de 'destino'.
 */
void insereAresta(Grafo *grafo, int origem, int destino) {
    if (origem < 0 || origem >= grafo->numVertices || destino < 0 || destino >= grafo->numVertices) {
        printf("Erro: Vertices invalidos para a insercao da aresta.\n");
        return;
    }

    // 1. Atualiza a Lista de Adjacencia
    No *novoNo = criaNo(destino);
    novoNo->prox = grafo->listaAdj[origem].inicio;
    grafo->listaAdj[origem].inicio = novoNo;

    if (origem != destino) {
        novoNo = criaNo(origem);
        novoNo->prox = grafo->listaAdj[destino].inicio;
        grafo->listaAdj[destino].inicio = novoNo;
    }

    // 2. Atualiza a Matriz de Adjacencia
    grafo->matrizAdj[origem][destino] = 1;
    if (origem != destino) {
        grafo->matrizAdj[destino][origem] = 1;
    }
}

/*
 * A funcao 'removeAresta' remove uma aresta nao-direcionada,
 * atualizando tanto a lista quanto a matriz de adjacencia.
 * Recebe um ponteiro para o 'Grafo', o vertice de 'origem' e o vertice de 'destino'.
 */
void removeAresta(Grafo *grafo, int origem, int destino) {
    if (origem < 0 || origem >= grafo->numVertices || destino < 0 || destino >= grafo->numVertices) {
        printf("Erro: Vertices invalidos para a remocao da aresta.\n");
        return;
    }

    // 1. Remove da Lista de Adjacencia
    grafo->listaAdj[origem].inicio = removeNo(grafo->listaAdj[origem].inicio, destino);
    if (origem != destino) {
        grafo->listaAdj[destino].inicio = removeNo(grafo->listaAdj[destino].inicio, origem);
    }

    // 2. Remove da Matriz de Adjacencia
    grafo->matrizAdj[origem][destino] = 0;
    if (origem != destino) {
        grafo->matrizAdj[destino][origem] = 0;
    }
}

// ----------------------------------------------------
// Operacoes de Visualizacao e Grau
// ----------------------------------------------------

/*
 * A funcao 'imprimeListaAdj' visualiza a estrutura do grafo usando
 * suas listas de adjacencia, mostrando todos os vizinhos de cada vertice.
 * Recebe um ponteiro para a estrutura 'Grafo'.
 */
void imprimeListaAdj(Grafo *grafo) {
    int i;
    for (i = 0; i < grafo->numVertices; i++) {
        printf("Vertice %d: ", i);
        No *temp = grafo->listaAdj[i].inicio;
        while (temp != NULL) {
            printf("-> %d", temp->vertice);
            temp = temp->prox;
        }
        printf("\n");
    }
}

/*
 * A funcao 'imprimeMatrizAdj' visualiza a estrutura do grafo usando
 * sua matriz de adjacencia, mostrando o estado (0 ou 1) de todas as conexoes.
 * Recebe um ponteiro para a estrutura 'Grafo'.
 */
void imprimeMatrizAdj(Grafo *grafo) {
    int i, j;
    printf("   ");
    for (j = 0; j < grafo->numVertices; j++) {
        printf(" %d", j);
    }
    printf("\n");
    printf("  -");
    for (j = 0; j < grafo->numVertices; j++) {
        printf("--");
    }
    printf("\n");

    for (i = 0; i < grafo->numVertices; i++) {
        printf("%d |", i);
        for (j = 0; j < grafo->numVertices; j++) {
            printf(" %d", grafo->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

/*
 * A funcao 'grauVertice' calcula e retorna o grau de um vertice.
 * O grau em um grafo nao-direcionado e o numero de arestas incidentes.
 * Recebe um ponteiro para o 'Grafo' e o numero do 'vertice'.
 */
int grauVertice(Grafo *grafo, int vertice) {
    if (vertice < 0 || vertice >= grafo->numVertices) {
        return -1; // Vertice invalido
    }
    int grau = 0;
    No *temp = grafo->listaAdj[vertice].inicio;
    while (temp != NULL) {
        grau++;
        temp = temp->prox;
    }
    return grau;
}

// ----------------------------------------------------
// Estrutura Fila e Operacoes (Para BFS)
// ----------------------------------------------------

typedef struct Fila {
    int itens[MAX_VERTICES];
    int frente;
    int tras;
} Fila;

/*
 * A funcao 'inicializaFila' prepara uma estrutura de Fila
 * para ser usada no algoritmo de Busca em Largura (BFS).
 * Recebe um ponteiro para a estrutura 'Fila'.
 */
void inicializaFila(Fila *f) {
    f->frente = -1;
    f->tras = -1;
}

/*
 * A funcao 'filaVazia' verifica se a fila esta vazia.
 * Retorna 1 se a fila estiver vazia, 0 caso contrario.
 */
int filaVazia(Fila *f) {
    if (f->frente == -1) {
        return 1; // TRUE
    }
    return 0; // FALSE
}

/*
 * A funcao 'enfileira' adiciona um 'vertice' ao final da Fila.
 * Retorna 1 se a operacao foi bem-sucedida, 0 se a fila estiver cheia.
 */
int enfileira(Fila *f, int vertice) {
    if (f->tras == MAX_VERTICES - 1) {
        return 0; // FALSE
    } else {
        if (f->frente == -1) {
            f->frente = 0;
        }
        f->tras++;
        f->itens[f->tras] = vertice;
        return 1; // TRUE
    }
}

/*
 * A funcao 'desenfileira' remove e retorna o vertice da frente da Fila.
 * Retorna -1 se a Fila estiver vazia.
 */
int desenfileira(Fila *f) {
    int vertice;
    if (f->frente == -1) {
        return -1;
    } else {
        vertice = f->itens[f->frente];
        f->frente++;
        if (f->frente > f->tras) {
            f->frente = f->tras = -1; // Resetar a fila quando vazia
        }
        return vertice;
    }
}

// ----------------------------------------------------
// Operacoes de Percurso e Caminho (Busca em Largura - BFS)
// ----------------------------------------------------

/*
 * A funcao 'buscaEmLargura' executa o algoritmo BFS (Busca em Largura),
 * percorrendo o grafo a partir de um 'verticeInicial' e imprimindo a ordem.
 * Recebe um ponteiro para o 'Grafo' e o vertice de inicio da busca.
 */
void buscaEmLargura(Grafo *grafo, int verticeInicial) {
    if (verticeInicial < 0 || verticeInicial >= grafo->numVertices) {
        printf("Erro: Vertice inicial %d e invalido.\n", verticeInicial);
        return;
    }

    int visitado[MAX_VERTICES]; // 1 = visitado, 0 = nao visitado
    Fila fila;
    inicializaFila(&fila);
    int verticeAtual, i;

    for (i = 0; i < grafo->numVertices; i++) {
        visitado[i] = 0; // FALSE
    }

    visitado[verticeInicial] = 1; // TRUE
    enfileira(&fila, verticeInicial);

    printf("Percurso BFS: ");
    while (filaVazia(&fila) == 0) { // Enquanto a fila NAO estiver vazia
        verticeAtual = desenfileira(&fila);
        printf("%d ", verticeAtual);

        No *temp = grafo->listaAdj[verticeAtual].inicio;
        while (temp != NULL) {
            int vizinho = temp->vertice;
            if (visitado[vizinho] == 0) { // Se nao foi visitado
                visitado[vizinho] = 1;
                enfileira(&fila, vizinho);
            }
            temp = temp->prox;
        }
    }
    printf("\n");
}

/*
 * A funcao 'procuraCaminhoBFS' usa a Busca em Largura (BFS) para encontrar
 * um caminho (se existir) entre 'origem' e 'destino' e imprime esse caminho.
 * Retorna 1 se o caminho for encontrado, 0 caso contrario.
 */
int procuraCaminhoBFS(Grafo *grafo, int origem, int destino) {
    if (origem < 0 || origem >= grafo->numVertices || destino < 0 || destino >= grafo->numVertices) {
        printf("Erro: Vertices de origem ou destino invalidos.\n");
        return 0; // FALSE
    }
    if (origem == destino) {
        printf("Caminho encontrado: %d\n", origem);
        return 1; // TRUE
    }

    int visitado[MAX_VERTICES]; // 1 = visitado, 0 = nao visitado
    int pai[MAX_VERTICES];
    Fila fila;
    inicializaFila(&fila);
    int verticeAtual;
    int i;

    for (i = 0; i < grafo->numVertices; i++) {
        visitado[i] = 0; // FALSE
        pai[i] = -1; // Inicializa o vetor pai
    }

    visitado[origem] = 1; // TRUE
    enfileira(&fila, origem);

    while (filaVazia(&fila) == 0) {
        verticeAtual = desenfileira(&fila);

        if (verticeAtual == destino) {
            // Caminho encontrado, reconstroi e imprime
            int caminho[MAX_VERTICES];
            int caminhoTamanho = 0;
            int verticePonteiro = destino;

            while (verticePonteiro != -1) {
                caminho[caminhoTamanho++] = verticePonteiro;
                verticePonteiro = pai[verticePonteiro];
            }

            printf("Caminho encontrado (%d -> %d): ", origem, destino);
            for (i = caminhoTamanho - 1; i >= 0; i--) {
                printf("%d%s", caminho[i], (i > 0) ? " -> " : "");
            }
            printf("\n");
            return 1; // TRUE
        }

        No *temp = grafo->listaAdj[verticeAtual].inicio;
        while (temp != NULL) {
            int vizinho = temp->vertice;
            if (visitado[vizinho] == 0) { // Se nao foi visitado
                visitado[vizinho] = 1;
                pai[vizinho] = verticeAtual;
                enfileira(&fila, vizinho);
            }
            temp = temp->prox;
        }
    }

    printf("Nao foi encontrado caminho entre %d e %d.\n", origem, destino);
    return 0; // FALSE
}

/*
 * A funcao 'liberaGrafo' libera toda a memoria alocada dinamicamente
 * para os nos nas listas de adjacencia de cada vertice.
 * Recebe um ponteiro para a estrutura 'Grafo'.
 */
void liberaGrafo(Grafo *grafo) {
    int i;
    for (i = 0; i < grafo->numVertices; i++) {
        No *noAtual = grafo->listaAdj[i].inicio;
        No *proximoNo;

        while (noAtual != NULL) {
            proximoNo = noAtual->prox;
            free(noAtual);
            noAtual = proximoNo;
        }
        grafo->listaAdj[i].inicio = NULL;
    }
    grafo->numVertices = 0; // Opcional: Redefine o numero de vertices
    printf("Memoria do grafo liberada.\n");
}

/*
 * A funcao 'main' e o ponto de entrada do programa,
 * demonstrando a inicializacao, operacoes, e liberacao de memoria do grafo.
 * Testa as funcoes de Matriz, Insercao/Remocao de Vertice e BFS.
 */
int main() {
    Grafo meuGrafo;
    int i; 
    int numVerticesIniciais = 4;

    printf("### Inicializando Grafo com %d vertices ###\n", numVerticesIniciais);
    inicializaGrafo(&meuGrafo, numVerticesIniciais);

    insereAresta(&meuGrafo, 0, 1);
    insereAresta(&meuGrafo, 0, 2);
    insereAresta(&meuGrafo, 1, 3);
    insereAresta(&meuGrafo, 2, 3);
    insereAresta(&meuGrafo, 3, 3); // Laco

    printf("\n## Estruturas de Adjacencia Iniciais\n");
    printf("--- Lista de Adjacencia ---\n");
    imprimeListaAdj(&meuGrafo);
    printf("--- Matriz de Adjacencia ---\n");
    imprimeMatrizAdj(&meuGrafo);
    printf("--------------------------------------\n");

    printf("\n## Operacoes de Vertice\n");
    if (insereVertice(&meuGrafo) == 1) {
        printf("Vertice %d inserido com sucesso.\n", meuGrafo.numVertices - 1); 
    }
    // Conecta o novo vertice (4)
    insereAresta(&meuGrafo, 4, 1);
    insereAresta(&meuGrafo, 4, 2);

    printf("\n--- Grafo apos insercao e novas arestas ---\n");
    imprimeListaAdj(&meuGrafo);

    int verticeParaRemover = 0;
    if (removeVertice(&meuGrafo, verticeParaRemover) == 1) {
        printf("Vertice %d removido com sucesso. Novo numVertices: %d\n", verticeParaRemover, meuGrafo.numVertices);
    }

    printf("\n--- Grafo apos remocao de vertice %d ---\n", verticeParaRemover);
    imprimeListaAdj(&meuGrafo);
    imprimeMatrizAdj(&meuGrafo);
    printf("--------------------------------------\n");

    printf("\n## Operacoes de Percurso e Caminho (BFS)\n");

    // Percurso (BFS) a partir do vertice 1
    printf("\nTeste de Percurso BFS a partir de 1:\n");
    buscaEmLargura(&meuGrafo, 1);

    // Procura de Caminho (BFS)
    int origemCaminho = 1;
    int destinoCaminho = 3;
    printf("\nTeste de Procura de Caminho:\n");
    procuraCaminhoBFS(&meuGrafo, origemCaminho, destinoCaminho);

    printf("\n--------------------------------------\n");

    // Libera a memoria
    liberaGrafo(&meuGrafo);

    return 0;
}