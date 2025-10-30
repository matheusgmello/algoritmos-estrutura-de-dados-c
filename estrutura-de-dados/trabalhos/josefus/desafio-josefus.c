/*
Desafio listas duplamente encadeadas: Problema de Josephus

A lenda do Problema de Josephus é baseada na história de Flavius Josephus, um historiador e líder militar judeu do primeiro século.
Durante o cerco romano a uma cidade judaica, Josephus e um grupo de 40 soldados ficaram encurralados em uma caverna.
Em vez de se renderem, eles preferiram a morte à escravidão. Para isso, 
formaram um círculo e decidiram que a eliminação aconteceria de forma sistemática: começando a partir de um soldado de referência, 
a cada três pessoas, uma delas seria executada. O processo se repetiria, com a contagem recomeçando a partir do soldado seguinte ao que foi eliminado, 
até que restasse apenas um sobrevivente. Esse último sobrevivente deveria então tirar a própria vida.
Josephus, no entanto, desejava viver. Ele calculou rapidamente a posição no círculo que ele deveria ocupar para ser o último sobrevivente. 
Ao fazer isso, conseguiu escapar da morte se entregando aos romanos e fazendo um pacto de liberdade em troca de informações valiosas.
O problema, portanto, é determinar a posição no círculo que garante a sobrevivência.
O Problema de Josephus descreve uma situação em que n pessoas estão dispostas em um círculo. 
Começando em uma posição específica, a contagem avança de k em k pessoas, e a k-ésima pessoa é eliminada. 
O processo continua até que reste apenas um sobrevivente. Sua tarefa é simular este processo em C, utilizando uma lista duplamente encadeada e circular. 
A estrutura de dados deve permitir que a travessia (contagem) ocorra tanto no sentido horário quanto no anti-horário.


Parte 1: Implementação Básica:
Estrutura de Dados: Crie uma struct Node para representar uma pessoa no círculo. Ela deve conter um identificador (id) e dois ponteiros: 
next (para o próximo nó) e prev (para o nó anterior);
Criação da Lista: Implemente uma função que cria uma lista duplamente encadeada e circular com n nós, numerados de 1 a n;
Função de Remoção: Implemente uma função que, dado um nó, o remove da lista, atualizando os ponteiros dos nós adjacentes (anterior e próximo). 
Esta função deve ser robusta o suficiente para lidar com a remoção de qualquer nó;
Resolução do Problema: Implemente uma função que executa a simulação. 
A contagem deve iniciar com a pessoa de id = 1 e sempre avançar no sentido horário. 
A cada k passos, a pessoa é eliminada (nó removido). A função deve imprimir a sequência de eliminações e, ao final, retornar o ID do sobrevivente.


Parte 2: Variações do Problema (Desafio): para evitar que outros como Josephus tentem escapar da morte calculando a posição do último sobrevivente, 
modifique sua solução para atender às seguintes variações, que exploram a capacidade de travessia da lista duplamente encadeada:

Contagem Alternada: A cada eliminação, a direção da contagem deve ser alternada. A primeira contagem de k passos é no sentido horário (next), a 
segunda é no sentido anti-horário (prev), a terceira no sentido horário novamente, e assim por diante;
Passos Variáveis: Em vez de usar um k fixo, o número de passos a cada contagem deve ser incremental. A primeira contagem tem k passos, 
a segunda tem k+1 passos, a terceira k+2, e assim por diante.
Orientações e Dicas

Ponteiro para o Círculo: Em vez de usar um ponteiro para a head (cabeça) da lista, pode ser mais prático manter um ponteiro para o nó "atual" (current), que se move durante a contagem e a remoção.
Final da Simulação: A simulação termina quando o ponteiro current->next for igual ao current, indicando que apenas um nó restou.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// parte 2 nao saiu

typedef struct lista {
    int id;
    struct lista *prox;
    struct lista *anterior;
} lista;

lista *criar(int n) {
    if (n <= 0) {
    	return NULL;
	}

    lista *cabecao = (lista *)malloc(sizeof(lista));
    cabecao->id = 1;
    cabecao->prox = cabecao;
    cabecao->anterior = cabecao;

    lista *atual = cabecao;

    for (int i = 2; i <= n; i++) {
        lista *novo = (lista *)malloc(sizeof(lista));
        novo->id = i;

        novo->prox = cabecao;
        novo->anterior = atual;

        atual->prox = novo;
        cabecao->anterior = novo;

        atual = novo;
    }

    return cabecao;
}

lista *remover(lista *li) {
    if (li->prox == li) {
        free(li);
        return NULL;
    }

    lista *anterior = li->anterior;
    lista *proximo = li->prox;

    anterior->prox = proximo;
    proximo->anterior = anterior;

    free(li);
    return proximo;
}

void imprime(lista *l) {
    if (l == NULL){
    	return;
	}

    lista *p = l;
    do {
        printf("%d ", p->id);
        p = p->prox;
    } while (p != l);
    printf("\n\n");
}

int simulacaoSimploria(int n, int k) {
    lista *atual = criar(n);

    while (atual->prox != atual) {
        for (int i = 1; i < k; i++) {
            atual = atual->prox;
        }
        printf("Eliminado: %d\n", atual->id);
        atual = remover(atual);
        imprime(atual);
    }

    int sobrevivente = atual->id;
    free(atual);
    return sobrevivente;
}


int main() {
    srand(time(NULL));
    int n = (rand() % 10) + 4;
    int k = n - 1;

    printf("valor de n ou soldados: %d\n", n);
    printf("valor de k ou mortos: %d\n", k);

    printf("\n--- simulation simples P1 ---\n");
    int sobreviventeP1 = simulacaoSimploria(n, k);
    printf("vivo: %d\n", sobreviventeP1);


    return 0;
}

