#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct No{
  int vertice;
  struct No *prox;
}No;

typedef struct lista{
  struct No *inicio;
}Lista;

typedef struct Grafo{
  Lista listaAdj[MAX];
  int numVertices;
}Grafo;

// Estrutura Simples de Fila para BFS
typedef struct Fila {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

/*
 * A funcao 'criaFila' inicializa os ponteiros 'frente' e 'tras' da fila.
 */
void criaFila(Fila *f) {
    f->frente = -1;
    f->tras = -1;
}

/*
 * A funcao 'estaVazia' verifica se a fila esta vazia.
 * Retorna 1 (verdadeiro) se estiver vazia e 0 (falso) caso contrario.
 */
int estaVazia(Fila *f) {
    return f->tras == -1;
}

/*
 * A funcao 'adicionarFila' (enqueue) insere um 'vertice' no final da fila.
 */
void adicionarFila(Fila *f, int vertice) {
    if (f->tras == MAX - 1) {
        printf("Erro: Fila Cheia\n");
    } else {
        if (f->frente == -1) f->frente = 0;
        f->tras++;
        f->itens[f->tras] = vertice;
    }
}

/*
 * A funcao 'removerFila' (dequeue) remove e retorna o vertice no inicio da fila.
 * Retorna -1 se a fila estiver vazia.
 */
int removerFila(Fila *f) {
    int item;
    if (estaVazia(f)) {
        item = -1;
    } else {
        item = f->itens[f->frente];
        f->frente++;
        if (f->frente > f->tras) {
            f->frente = f->tras = -1; // Reseta a fila se estiver vazia
        }
    }
    return item;
}


/*
 * A funcao 'criaNo' e uma funcao auxiliar que aloca memoria dinamicamente para um novo no da lista de adjacencia.
 * Recebe o numero do 'vertice' que o novo no ira representar.
 * O novo no e inicializado com o valor do vertice fornecido, e seu ponteiro 'prox' e definido como NULL.
 * Essa funcao e crucial para construir as listas de adjacencia do grafo.
 */
No *criaNo(int vertice){
  No *novo = (No*) malloc(sizeof(No));
  novo->vertice = vertice;
  novo->prox = NULL;
  return novo;
}

/*
 * A funcao 'inicializaGrafo' prepara a estrutura do grafo para uso.
 * Recebe um ponteiro para a estrutura 'Grafo' e o numero de 'vertice's que o grafo tera.
 * Define o campo 'numVertices' da estrutura 'Grafo' com o valor fornecido.
 * Em seguida, percorre o array de listas de adjacencia ('listaAdj') e inicializa o ponteiro 'inicio' de cada lista como NULL.
 * Isso garante que todas as listas de adjacencia estejam vazias no inicio.
 */
void inicializaGrafo(Grafo *g, int vertice){
  g->numVertices = vertice;
  for(int i = 0; i<vertice; i++){
    g->listaAdj[i].inicio = NULL;
  }
}

/*
 * A funcao 'criaGrafo' e responsavel por adicionar uma aresta ao grafo.
 * Recebe um ponteiro para o 'Grafo', o vertice de 'origem' e o vertice de 'destino'.
 * O grafo e implementado como **nao-direcionado** por padrao.
 * Primeiro, um novo no e criado para o 'destino' e adicionado ao **inicio** da lista de adjacencia da 'origem'.
 * Em seguida, para garantir a natureza nao-direcionada, um novo no e criado para a 'origem' e adicionado ao **inicio** da lista de adjacencia do 'destino', exceto se a origem e o destino forem o mesmo vertice (laco).
 * Essa implementacao de adicao no inicio resulta em uma complexidade de tempo $O(1)$ para a insercao de arestas.
 */
void criaGrafo(Grafo *g, int origem, int destino){
  No *novo = criaNo(destino);
  novo->prox = g->listaAdj[origem].inicio;
  g->listaAdj[origem].inicio = novo;
  if(origem != destino){
    novo = criaNo(origem);
    novo->prox = g->listaAdj[destino].inicio;
    g->listaAdj[destino].inicio = novo;
  }
}

/*
 * A funcao 'removeNo' remove o primeiro no com o valor 'verticeParaRemover'
 * encontrado na lista encadeada que comeca em 'inicio'.
 * Retorna o novo ponteiro de inicio da lista apos a remocao.
 *
 * Esta funcao lida com dois casos principais:
 * 1. O no a ser removido e o primeiro da lista.
 * 2. O no a ser removido esta no meio ou fim da lista.
 *
 * Em caso de remocao, a memoria alocada para o no e liberada usando 'free()'.
 */
No *removeNo(No *inicio, int verticeParaRemover){
    No *atual = inicio;
    No *anterior = NULL;

    // Caso 1: O no a ser removido e o 'inicio'
    if(atual != NULL && atual->vertice == verticeParaRemover){
        inicio = atual->prox; // Muda o inicio
        free(atual);         // Libera a memoria
        return inicio;       // Retorna o novo inicio
    }

    // Caso 2: Procura o no, mantendo o rastro do anterior
    while(atual != NULL && atual->vertice != verticeParaRemover){
        anterior = atual;
        atual = atual->prox;
    }

    // Se 'atual' for NULL, o vertice nao foi encontrado na lista
    if(atual == NULL){
        return inicio;
    }

    // O no foi encontrado (agora 'atual' aponta para ele)
    anterior->prox = atual->prox; // Desliga o no 'atual' da lista
    free(atual);                   // Libera a memoria
    return inicio;               // O inicio permanece o mesmo
}

/*
 * A funcao 'removeAresta' remove uma aresta nao-direcionada entre 'origem' e 'destino'.
 * Recebe um ponteiro para o 'Grafo', o vertice de 'origem' e o vertice de 'destino'.
 *
 * 1. Remove o no 'destino' da lista de adjacencia da 'origem'.
 * 2. Se nao for um laco (origem != destino), remove o no 'origem' da lista de adjacencia do 'destino'.
 *
 * A remocao e feita atualizando o ponteiro 'inicio' da respectiva lista de adjacencia
 * com o resultado da funcao 'removeNo'.
 */
void removeAresta(Grafo *g, int origem, int destino){
    // 1. Remove o no 'destino' da lista de adjacencia da 'origem'
    g->listaAdj[origem].inicio = removeNo(g->listaAdj[origem].inicio, destino);

    // 2. Se nao for um laco (self-loop), remove o no 'origem' da lista de adjacencia do 'destino'
    if(origem != destino){
        g->listaAdj[destino].inicio = removeNo(g->listaAdj[destino].inicio, origem);
    }
}

/*
 * A funcao 'imprimeGrafo' e usada para visualizar a estrutura do grafo, mostrando suas listas de adjacencia.
 * Ela itera por todos os vertices (de 0 ate 'numVertices' - 1).
 * Para cada vertice 'i', ela imprime o numero do vertice e percorre sua lista de adjacencia correspondente, comecando pelo ponteiro 'inicio'.
 * Imprime todos os vizinhos conectados ao vertice 'i', seguindo a sequencia de ponteiros 'prox' ate que o ponteiro temporario atinja NULL.
 * Isso permite verificar se as arestas foram adicionadas corretamente.
 */
void imprimeGrafo(Grafo *g){
  int i;
  for(i = 0; i < g->numVertices; i++){
    printf("Vertice %d: ", i);
    No *temp = g -> listaAdj[i].inicio;
    while(temp != NULL){
      printf("-> %d", temp->vertice);
      temp = temp->prox;
    }
    printf("\n");
    
  }
}

/*
 * A funcao 'buscaEmLargura' percorre o grafo a partir de um 'verticeInicial'
 * usando o algoritmo BFS, que explora os vizinhos mais proximos antes de
 * se mover para os de proximo nivel.
 *
 * Usa um array 'visitados' e uma fila para gerenciar a ordem de exploracao.
 */
void buscaEmLargura(Grafo *g, int verticeInicial) {
    Fila filaDeExploracao;
    int verticeAtual;
    int i;
    // Array para marcar os vertices visitados (0 = Não visitado, 1 = Visitado)
    int visitados[MAX];

    // 1. Inicializa o array de visitados e a fila
    for (i = 0; i < g->numVertices; i++) {
        visitados[i] = 0;
    }
    criaFila(&filaDeExploracao);

    // 2. Começa a exploração pelo vertice inicial
    visitados[verticeInicial] = 1;
    adicionarFila(&filaDeExploracao, verticeInicial);
    printf("BFS (Busca em Largura) a partir do vertice %d: ", verticeInicial);

    // 3. Explora o grafo
    while (!estaVazia(&filaDeExploracao)) {
        verticeAtual = removerFila(&filaDeExploracao);
        printf("%d ", verticeAtual);

        // Percorre a lista de adjacencia do vertice atual
        No *vizinho = g->listaAdj[verticeAtual].inicio;
        while (vizinho != NULL) {
            int v_vizinho = vizinho->vertice;

            if (visitados[v_vizinho] == 0) {
                visitados[v_vizinho] = 1;
                adicionarFila(&filaDeExploracao, v_vizinho);
            }
            vizinho = vizinho->prox;
        }
    }
    printf("\n");
}

/*
 * A funcao auxiliar 'buscaEmProfundidade_recursiva' realiza a travessia DFS.
 * Ela usa recursao para explorar o maximo possivel em cada ramo antes de
 * retroceder (backtrack).
 */
void buscaEmProfundidade_recursiva(Grafo *g, int verticeAtual, int *visitados) {
    // 1. Marca o vertice atual como visitado e imprime
    visitados[verticeAtual] = 1;
    printf("%d ", verticeAtual);

    // 2. Percorre a lista de adjacencia
    No *vizinho = g->listaAdj[verticeAtual].inicio;
    while (vizinho != NULL) {
        int v_vizinho = vizinho->vertice;

        // 3. Se o vizinho nao foi visitado, chama a DFS recursivamente
        if (visitados[v_vizinho] == 0) {
            buscaEmProfundidade_recursiva(g, v_vizinho, visitados);
        }
        vizinho = vizinho->prox;
    }
}

/*
 * A funcao 'buscaEmProfundidade' é a função principal que prepara o ambiente
 * e inicia a travessia DFS a partir de um 'verticeInicial'.
 */
void buscaEmProfundidade(Grafo *g, int verticeInicial) {
    int visitados[MAX];
    int i;
    // Inicializa o array de visitados
    for (i = 0; i < g->numVertices; i++) {
        visitados[i] = 0;
    }

    printf("DFS (Busca em Profundidade) a partir do vertice %d: ", verticeInicial);
    // Inicia a recursao
    buscaEmProfundidade_recursiva(g, verticeInicial, visitados);
    printf("\n");
}

/*
 * A funcao 'main' e o ponto de entrada do programa.
 * Ela declara uma estrutura 'Grafo' e define o numero de vertices ('vertices' = 5).
 * Chama 'inicializaGrafo' para preparar a estrutura.
 * Adiciona algumas arestas ao grafo usando a funcao 'criaGrafo'. Por exemplo, cria uma aresta entre 1 e 2, 3 e 4, e um laco no vertice 0 (0-0).
 * Finalmente, chama 'imprimeGrafo' para exibir a estrutura de lista de adjacencia do grafo e demonstra o uso das novas funcoes.
 */
int main(){
  Grafo g;
  int vertices = 5; 
  int vertice_inicio = 1; // Vertice de inicio para as buscas
  
  inicializaGrafo(&g, vertices);
  
  criaGrafo(&g, 1, 2);
  criaGrafo(&g, 3, 4);
  criaGrafo(&g, 0, 0); 
  criaGrafo(&g, 1, 3); 
  criaGrafo(&g, 1, 4); 
  
  printf("## Grafo e Estrutura de Adjacencia\n");
  imprimeGrafo(&g);
  printf("--------------------------------------\n");

  printf("## Teste dos Algoritmos de Busca\n");
  
  // Teste BFS
  buscaEmLargura(&g, vertice_inicio);
  
  // Teste DFS
  buscaEmProfundidade(&g, vertice_inicio);
  printf("--------------------------------------\n");

  // Teste de uma função anterior (grau)
  printf("Grau do Vertice %d: %d\n", vertice_inicio, grauVertice(&g, vertice_inicio)); 
  
  // Liberação de memória
  // liberaGrafo(&g); 
  
  return 0;
}