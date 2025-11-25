#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MAX, embora nao usado diretamente no BFS simples

#define MAX 100 // Numero maximo de vertices (localidades)

// A constante MAX_QUEUE e usada para o array da fila no algoritmo BFS.
#define MAX_QUEUE MAX 

// Definição da estrutura de um nó na lista de adjacência.
typedef struct No{
    int vertice;    // O vertice vizinho (localidade de destino).
    int peso;       // O peso/custo da aresta (distancia/tempo).
    struct No *prox;
}No;

// Definição da estrutura da lista de adjacência.
typedef struct lista{
    struct No *inicio;
}Lista;

// Definição da estrutura do Grafo.
typedef struct Grafo{
    Lista listaAdj[MAX];
    int numVertices;
}Grafo;

/*
 * A funcao 'criaNo' e uma funcao auxiliar que aloca memoria dinamicamente para um novo no da lista de adjacencia.
 * Recebe o numero do 'vertice' (destino) e o 'peso' (custo) da aresta.
 * O novo no e inicializado com o valor do vertice e peso fornecidos, e seu ponteiro 'prox' e definido como NULL.
 * Essa funcao e crucial para construir as listas de adjacencia do grafo ponderado.
 */
No *criaNo(int vertice, int peso){
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        perror("Erro ao alocar memoria para novoNo");
        exit(EXIT_FAILURE);
    }
    novoNo->vertice = vertice;
    novoNo->peso = peso;
    novoNo->prox = NULL;
    return novoNo;
}

/*
 * A funcao 'inicializaGrafo' prepara a estrutura do grafo para uso.
 * Recebe um ponteiro para a estrutura 'Grafo' e o numero de 'vertices' que o grafo tera.
 * Define o campo 'numVertices' da estrutura 'Grafo' com o valor fornecido.
 * Em seguida, percorre o array de listas de adjacencia ('listaAdj') e inicializa o ponteiro 'inicio' de cada lista como NULL.
 * Isso garante que todas as listas de adjacencia estejam vazias no inicio.
 */
void inicializaGrafo(Grafo *g, int numVertices){
    g->numVertices = numVertices;
    int i; // Declaracao do contador fora do for
    for(i = 0; i < numVertices; i++){
        g->listaAdj[i].inicio = NULL;
    }
}

/*
 * A funcao 'adicionaAresta' e responsavel por adicionar uma aresta **ponderada** ao grafo.
 * Recebe um ponteiro para o 'Grafo', o vertice de 'origem', o vertice de 'destino' e o 'peso' da aresta.
 * O grafo e implementado como **nao-direcionado**.
 * Um novo no e criado para o 'destino' e adicionado ao **inicio** da lista de adjacencia da 'origem'.
 * Em seguida, para garantir a natureza nao-direcionada, um novo no e criado para a 'origem' e adicionado ao **inicio** da lista de adjacencia do 'destino', exceto se a origem e o destino forem o mesmo vertice (laco).
 */
void adicionaAresta(Grafo *g, int origem, int destino, int peso){
    No *novoDestino = criaNo(destino, peso);
    novoDestino->prox = g->listaAdj[origem].inicio;
    g->listaAdj[origem].inicio = novoDestino;

    if(origem != destino){
        No *novoOrigem = criaNo(origem, peso);
        novoOrigem->prox = g->listaAdj[destino].inicio;
        g->listaAdj[destino].inicio = novoOrigem;
    }
}

/*
 * A funcao 'imprimeGrafo' e usada para visualizar a estrutura do grafo, mostrando suas listas de adjacencia.
 * Ela itera por todos os vertices (de 0 ate 'numVertices' - 1).
 * Para cada vertice 'i', ela imprime o numero do vertice e percorre sua lista de adjacencia correspondente, comecando pelo ponteiro 'inicio'.
 * Imprime todos os vizinhos conectados ao vertice 'i' e o **peso** da aresta.
 */
void imprimeGrafo(Grafo *g){
    int i; // Declaracao do contador fora do for
    printf("\n--- Representacao do Grafo de Rotas ---\n");
    for(i = 0; i < g->numVertices; i++){
        printf("Localidade %d: ", i);
        No *temp = g->listaAdj[i].inicio;
        while(temp != NULL){
            printf("-> %d (Custo: %d)", temp->vertice, temp->peso);
            temp = temp->prox;
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
}

/*
 * A funcao 'liberaGrafo' desaloca toda a memoria alocada dinamicamente para o grafo.
 * Ela itera por todas as listas de adjacencia.
 * Para cada lista, ela percorre os nos, liberando cada no individualmente.
 * Isso e crucial para evitar vazamento de memoria (memory leaks).
 */
void liberaGrafo(Grafo *g) {
    int i; // Declaracao do contador fora do for
    for (i = 0; i < g->numVertices; i++) {
        No *atual = g->listaAdj[i].inicio;
        No *proximo;
        while (atual != NULL) {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
        g->listaAdj[i].inicio = NULL;
    }
    printf("\nMemoria do grafo liberada com sucesso.\n");
}

/*
 * A funcao 'buscaCaminhoMaisCurtoBFS' utiliza o algoritmo Breadth-First Search (BFS) para encontrar o caminho com o menor numero de arestas (paradas) entre a 'origem' e o 'destino'.
 * Usa uma fila para controlar a exploracao dos vertices e um array 'pai' para reconstruir o caminho.
 * O caminho e impresso na tela do destino de volta a origem.
 */
void buscaCaminhoMaisCurtoBFS(Grafo *g, int origem, int destino) {
    if (origem >= g->numVertices || destino >= g->numVertices || origem < 0 || destino < 0) {
        printf("Erro: Origem ou Destino fora do intervalo de vertices.\n");
        return;
    }
    if (origem == destino) {
        printf("Origem e Destino sao a mesma localidade: %d.\n", origem);
        return;
    }

    int visitado[MAX];  // Array para marcar vertices visitados (0: Nao visitado, 1: Visitado)
    int pai[MAX];       // Array para armazenar o vertice 'pai' no caminho mais curto
    int fila[MAX_QUEUE]; // Fila para o BFS
    int frente = 0;     // Indice da frente da fila
    int tras = 0;       // Indice do tras da fila
    int i;              // Declaracao do contador fora do for

    // Inicializa 'visitado' e 'pai'
    for (i = 0; i < g->numVertices; i++) {
        visitado[i] = 0;
        pai[i] = -1; // -1 indica que nao tem pai ainda
    }

    // Inicia o BFS
    visitado[origem] = 1;
    fila[tras++] = origem; // Enfileira a origem

    int verticeAtual;
    int caminhoEncontrado = 0;

    // Loop principal do BFS
    while (frente != tras) {
        verticeAtual = fila[frente++]; // Desenfileira o proximo vertice
        
        // Se o destino foi encontrado, podemos parar
        if (verticeAtual == destino) {
            caminhoEncontrado = 1;
            break;
        }

        No *temp = g->listaAdj[verticeAtual].inicio;
        while (temp != NULL) {
            int vizinho = temp->vertice;
            if (visitado[vizinho] == 0) {
                visitado[vizinho] = 1;
                pai[vizinho] = verticeAtual; // Define o pai para reconstruir o caminho
                fila[tras++] = vizinho;     // Enfileira o vizinho
            }
            temp = temp->prox;
        }
    }

    // Reconstroi e imprime o caminho
    if (caminhoEncontrado) {
        int caminho[MAX];
        int tamanhoCaminho = 0;
        int passo = destino;

        // Itera de volta usando o array 'pai'
        while (passo != -1) {
            caminho[tamanhoCaminho++] = passo;
            passo = pai[passo];
        }

        printf("\n✅ Caminho Mais Curto Encontrado (em numero de paradas):\n");
        printf("   Origem (%d) -> ", origem);

        // Imprime o caminho da origem ao destino (inverso da reconstrucao)
        for (i = tamanhoCaminho - 2; i > 0; i--) { // Comeca no penultimo (apos a origem)
            printf("%d -> ", caminho[i]);
        }
        printf("Destino (%d)\n", destino);
    } else {
        printf("\n❌ Nao foi encontrado um caminho da Localidade %d para a Localidade %d.\n", origem, destino);
    }
}

/*
 * A funcao 'main' e o ponto de entrada do programa.
 * Ela demonstra a criacao do grafo de rotas, a adicao de arestas ponderadas (custos) e a busca pelo caminho mais curto.
 */
int main(){
    Grafo rotasGrafo;
    int numLocalidades = 6; // Representa 6 localidades (0 a 5)
    
    // Inicializacao
    inicializaGrafo(&rotasGrafo, numLocalidades);
    
    // Adicao de Arestas (Localidade Origem, Localidade Destino, Custo/Distancia)
    printf("Configurando as rotas do mapa...\n");
    // Rotas de Exemplo:
    adicionaAresta(&rotasGrafo, 0, 1, 10);
    adicionaAresta(&rotasGrafo, 0, 2, 5);
    adicionaAresta(&rotasGrafo, 1, 3, 15);
    adicionaAresta(&rotasGrafo, 2, 3, 20);
    adicionaAresta(&rotasGrafo, 2, 4, 30);
    adicionaAresta(&rotasGrafo, 3, 5, 5);
    adicionaAresta(&rotasGrafo, 4, 5, 10);
    
    // Visualizacao do Grafo
    imprimeGrafo(&rotasGrafo);
    
    // Busca de Caminho
    int origemRota = 0;
    int destinoRota = 5;
    printf("\nBuscando o caminho mais curto entre a Localidade %d e a Localidade %d...\n", origemRota, destinoRota);
    
    // A funcao BFS encontra o caminho com o menor numero de paradas.
    buscaCaminhoMaisCurtoBFS(&rotasGrafo, origemRota, destinoRota);

    // Demonstra outro caminho
    origemRota = 1;
    destinoRota = 4;
    printf("\nBuscando o caminho mais curto entre a Localidade %d e a Localidade %d...\n", origemRota, destinoRota);
    buscaCaminhoMaisCurtoBFS(&rotasGrafo, origemRota, destinoRota);

    // Limpeza
    liberaGrafo(&rotasGrafo);
    
    return 0;
}