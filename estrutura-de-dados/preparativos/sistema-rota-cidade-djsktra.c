#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Incluída como biblioteca "normal", embora nao usada para calculos complexos

#define MAX 100 
#define INFINITO 1000000 // Valor alto para representar o infinito (distancias max: 1 milhao)

// Definição da estrutura de um nó na lista de adjacência (aresta ponderada).
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
 * Recebe um ponteiro para a estrutura 'Grafo' e o numero de 'numVertices' que o grafo tera.
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
    printf("\n--- Representacao do Grafo de Rotas (Localidades e Custos) ---\n");
    for(i = 0; i < g->numVertices; i++){
        printf("Localidade %d: ", i);
        No *temp = g->listaAdj[i].inicio;
        while(temp != NULL){
            printf("-> %d (Custo: %d)", temp->vertice, temp->peso);
            temp = temp->prox;
        }
        printf("\n");
    }
    printf("--------------------------------------------------------------\n");
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
 * A funcao 'encontraMinDistancia' e uma funcao auxiliar que encontra o vertice nao visitado com a menor distancia registrada.
 * Ela itera sobre todos os vertices, verificando o array 'visitado' e 'distancia'.
 * Retorna o indice do vertice que sera o proximo a ser processado pelo Algoritmo de Dijkstra.
 */
int encontraMinDistancia(int distancia[], int visitado[], int numVertices) {
    int minDistancia = INFINITO;
    int minIndice = -1;
    int v; // Declaracao do contador fora do for

    for (v = 0; v < numVertices; v++) {
        // Se nao foi visitado E a distancia e menor ou igual a minima encontrada ate agora
        if (visitado[v] == 0 && distancia[v] <= minDistancia) {
            minDistancia = distancia[v];
            minIndice = v;
        }
    }
    return minIndice;
}

/*
 * A funcao 'imprimeCaminhoDijkstra' reconstroi e imprime o caminho mais curto usando o array 'pai'.
 * Ela imprime o caminho do destino ate a origem e o custo total do percurso.
 * Esta funcao e chamada apos o 'algoritmoDijkstra' ter sido executado.
 */
void imprimeCaminhoDijkstra(int pai[], int distancia[], int origem, int destino) {
    if (distancia[destino] == INFINITO) {
        printf("❌ Nao ha caminho da Localidade %d para a Localidade %d.\n", origem, destino);
        return;
    }
    
    int caminho[MAX];
    int tamanhoCaminho = 0;
    int passo = destino;
    int i; // Declaracao do contador fora do for

    // 1. Reconstroi o caminho do destino para a origem usando o array pai
    while (passo != -1) {
        caminho[tamanhoCaminho++] = passo;
        passo = pai[passo];
    }

    printf("\n✅ Caminho Mais Curto Encontrado (Custo Total: %d):\n", distancia[destino]);
    printf("   Origem (%d)", caminho[tamanhoCaminho - 1]);

    // 2. Imprime o caminho na ordem correta (da origem ao destino)
    for (i = tamanhoCaminho - 2; i >= 0; i--) {
        printf(" -> %d", caminho[i]);
    }
    printf(" (Destino)\n");
}

/*
 * A funcao 'algoritmoDijkstra' implementa o Algoritmo de Dijkstra para encontrar o caminho mais curto e seus custos.
 * Recebe o 'Grafo', a 'origem' e o 'destino'.
 * Calcula as distancias mais curtas da origem para todos os outros vertices, usando o peso das arestas.
 * Armazena as distancias finais no array 'distancia' e o caminho no array 'pai'.
 */
void algoritmoDijkstra(Grafo *g, int origem, int destino) {
    int numVertices = g->numVertices;
    int distancia[MAX];     // Armazena a distancia mais curta da origem para i
    int visitado[MAX];      // True se o vertice ja foi incluido no caminho mais curto
    int pai[MAX];           // Armazena o vertice anterior no caminho mais curto
    int i;                  // Declaracao do contador fora do for

    // Inicializacao: Distancia infinita para todos, 0 para a origem.
    for (i = 0; i < numVertices; i++) {
        distancia[i] = INFINITO;
        visitado[i] = 0;
        pai[i] = -1;
    }
    distancia[origem] = 0; // A distancia da origem para si mesma e 0.

    // Itera por todos os vertices para encontrar o caminho mais curto
    for (i = 0; i < numVertices - 1; i++) {
        // Encontra o vertice 'u' com a distancia minima dentre os nao visitados.
        int u = encontraMinDistancia(distancia, visitado, numVertices);

        // Se 'u' for -1, todos os vertices alcançaveis foram processados
        if (u == -1) {
            break;
        }

        visitado[u] = 1; // Marca o vertice 'u' como visitado.

        // Percorre os vizinhos 'v' de 'u'
        No *temp = g->listaAdj[u].inicio;
        while (temp != NULL) {
            int v = temp->vertice;
            int peso = temp->peso;

            // Condicao de "Relaxamento":
            // (Nao visitado E distancia[u] nao é INFINITO E nova_distancia < distancia_atual)
            // Se distancia[u] for INFINITO, a soma resultaria em um valor muito alto
            if (!visitado[v] && distancia[u] != INFINITO && (long long)distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
                pai[v] = u; // Atualiza o pai para o novo caminho
            }
            temp = temp->prox;
        }
    }

    // Imprime o caminho
    imprimeCaminhoDijkstra(pai, distancia, origem, destino);
}

/*
 * A funcao 'main' e o ponto de entrada do programa.
 * Ela demonstra a criacao do grafo de rotas ponderado e a busca pelo caminho mais curto em custo/distancia usando Dijkstra.
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
    adicionaAresta(&rotasGrafo, 1, 3, 1);
    adicionaAresta(&rotasGrafo, 2, 3, 20);
    adicionaAresta(&rotasGrafo, 2, 4, 3);
    adicionaAresta(&rotasGrafo, 3, 5, 5);
    adicionaAresta(&rotasGrafo, 4, 5, 1);
    
    // Visualizacao do Grafo
    imprimeGrafo(&rotasGrafo);
    
    // Busca de Caminho 1
    int origemRota1 = 0;
    int destinoRota1 = 5;
    printf("\nBuscando o caminho mais curto (em custo) entre a Localidade %d e a Localidade %d...", origemRota1, destinoRota1);
    
    algoritmoDijkstra(&rotasGrafo, origemRota1, destinoRota1);
    
    // Busca de Caminho 2 (Outra rota)
    int origemRota2 = 1;
    int destinoRota2 = 4;
    printf("\nBuscando o caminho mais curto (em custo) entre a Localidade %d e a Localidade %d...", origemRota2, destinoRota2);
    algoritmoDijkstra(&rotasGrafo, origemRota2, destinoRota2);

    // Limpeza
    liberaGrafo(&rotasGrafo);
    
    return 0;
}