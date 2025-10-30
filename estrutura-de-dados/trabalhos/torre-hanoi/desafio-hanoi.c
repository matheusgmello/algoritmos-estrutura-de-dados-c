/*
Pilha* criar_pilha(): Aloca e inicializa uma nova pilha;
void empilhar(Pilha* p, int disco): Adiciona um disco ao topo da pilha;
int desempilhar(Pilha* p): Remove e retorna o disco do topo da pilha;
int pilha_vazia(Pilha* p): Verifica se a pilha está vazia;
void liberar_pilha(Pilha* p): Libera toda a memória usada pela pilha.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// troque caso queira delay
#define DELAY 0000 

typedef struct No {
    int disco;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
    char nome;
} Pilha;

Pilha *criacaoDePilha() {
    Pilha *pilhaLocal = (Pilha *)malloc(sizeof(Pilha));
    if (pilhaLocal != NULL) {
        pilhaLocal->topo = NULL;
        pilhaLocal->nome = '?';
    }
    return pilhaLocal;
}

int pilhaVazia(Pilha *p) {
    return (p == NULL || p->topo == NULL);
}

void empilhar(Pilha *p, int disco) {
    if (p != NULL) {
        No *novo = (No *)malloc(sizeof(No));
        if (novo != NULL) {
            novo->disco = disco;
            novo->prox = p->topo;
            p->topo = novo;
        }
    }
}

int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) return -1;

    No *noAtual = p->topo;
    int disco = noAtual->disco;
    p->topo = noAtual->prox;
    free(noAtual);
    return disco;
}

void liberaPilha(Pilha *p) {
    if (p != NULL) {
        while (!pilhaVazia(p)) {
            No *noAtual = p->topo;
            p->topo = noAtual->prox;
            free(noAtual);
        }
        free(p);
    }
}

void imprimiHastes(Pilha *p1, Pilha *p2, Pilha *p3) {
    Pilha *arr[3] = {p1, p2, p3};

    for (int i = 0; i < 3; i++) {
        Pilha *pilhaLocal = arr[i];
        if (pilhaLocal != NULL) {
            printf("Haste %c: [", pilhaLocal->nome);

            if (pilhaVazia(pilhaLocal)) {
                printf("vazia");
            } else {
                No *noAtual = pilhaLocal->topo;
                int ehPrimeiro = 1;           
                while (noAtual != NULL) {
                    if (!ehPrimeiro) printf(" ");
                    printf("%d", noAtual->disco);
                    ehPrimeiro = 0;
                    noAtual = noAtual->prox; 
                }
            }
            printf("]\n");
        }
    }
    printf("\n");
    Sleep(DELAY);
}

void resolverHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar, int *movimentos) {
    if (n > 0) {
        if (n == 1) {
            if (!pilhaVazia(origem)) {
                int disco = desempilhar(origem);
                empilhar(destino, disco);
                (*movimentos)++;
                printf("Jogada %d: Moveu disco %d da haste %c para %c\n",
                       *movimentos, disco, origem->nome, destino->nome);
                imprimiHastes(origem, destino, auxiliar);
            }
        } else {
            resolverHanoi(n - 1, origem, auxiliar, destino, movimentos);
            if (!pilhaVazia(origem)) {
                int disco = desempilhar(origem);
                empilhar(destino, disco);
                (*movimentos)++;
                printf("Jogada %d: Moveu disco %d da haste %c para %c\n",
                       *movimentos, disco, origem->nome, destino->nome);
                imprimiHastes(origem, destino, auxiliar);
            }
            resolverHanoi(n - 1, auxiliar, destino, origem, movimentos);
        }
    }
}

int main() {
    int n = 0;
    printf("Digite numero de discos: ");
    if (scanf("%d", &n) == 1 && n > 0) {
        Pilha *hasteA = criacaoDePilha();
        Pilha *hasteB = criacaoDePilha();
        Pilha *hasteC = criacaoDePilha();

        if (hasteA && hasteB && hasteC) {
            hasteA->nome = 'A';
            hasteB->nome = 'B';
            hasteC->nome = 'C';

            for (int i = n; i >= 1; i--) {
                empilhar(hasteA, i);
            }

            imprimiHastes(hasteA, hasteB, hasteC);

            int movimentos = 0;
            resolverHanoi(n, hasteA, hasteC, hasteB, &movimentos);

            printf("\nTotal de jogadas realizadas: %d\n", movimentos);
            printf("Minimo de jogadas (na teoria): %d\n", (1 << n) - 1);

            liberaPilha(hasteA);
            liberaPilha(hasteB);
            liberaPilha(hasteC);
        }
    }
    return 0;
}
