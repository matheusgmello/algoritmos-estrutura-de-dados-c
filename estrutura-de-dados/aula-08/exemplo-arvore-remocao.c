#include <stdio.h>
#include <stdlib.h>

struct arvore
{
    int valor;
    struct arvore *esq;
    struct arvore *dir;
    };

typedef struct arvore arv;

arv *insere(arv *r, int c)
{
    arv *novo = (arv*) malloc(sizeof(arv));
    novo->valor = c;
    novo->esq = NULL;
    novo->dir = NULL;

    if (r == NULL)
        r = novo;
    else {
        arv *aux = r, *ult;
        while (aux !=NULL)
        {
            ult = aux;
            if (c < aux->valor)
                aux = aux->esq;
            else
                aux = aux->dir;
        }

        aux = ult;
        if (c < aux->valor)
                aux->esq = novo;
            else
                aux->dir = novo;
        }
    return r;
}

void imprime (arv *raiz)
{
    if (raiz != NULL)
    {
        printf("%d, ", raiz->valor);
        imprime(raiz->esq);
        imprime(raiz->dir);
    }
}

arv *folha(arv *no){
    arv *aux;
    if (no->esq == NULL && no->dir == NULL){
        return no;
    }
    else {
        if (no->esq != NULL){
            aux = folha(no->esq);
        }
        if (no->dir != NULL){
            aux = folha(no->dir);
        }
        return aux;
    }
}

arv *retira(arv *raiz, arv *r, arv *ant, int c){
    arv *aux = r;
    int teste;
    arv *no;
    arv *auxEsquerda = r->esq;
    arv *auxDireita = r->dir;
    
    //caso 1: remover folha
    if (r->esq == NULL && r->dir == NULL){
        if (ant->esq == r) {
        ant->esq = NULL; 
        }
        else if(ant->dir == r){
        ant->dir = NULL; 
        }
        free(r);
    }
    else {
        if (ant->esq == r){
            if (r->esq != NULL && r->dir == NULL){ //testa se há apenas um filho e está na subarvore da esquerda
                ant->esq = r->esq;
                free(r);
                return raiz; 
            }
            else if(r->esq == NULL && r->dir != NULL){
                ant->esq = r->dir;
                free(r);
                return raiz; 
            }   
        }
        else if (ant->dir == r){
            if (r->esq != NULL && r->dir == NULL){ //testa se há apenas um filho e está na subarvore da direita
                ant->dir = r->esq;
                free(r);
            }
            else if(r->esq == NULL && r->dir != NULL){
                ant->dir = r->dir;
                free(r);
            }
            return raiz;
        }

        //remover elementos com dois filhos
        if(r->esq != NULL && r->dir != NULL){
            if(auxEsquerda->dir != NULL){ //substituir o removido pelo elemento mais a direita da sub-árvore da esquerda
                no = folha(auxEsquerda->dir); //encontra o nó folha para substituir o removido
                no->esq = r->esq;
                no->dir = r->dir;
                auxEsquerda->dir = NULL;

                if (ant->esq == r){
                    ant->esq = no;
                }
                else if (ant->dir == r){
                    ant->dir = no;
                }
                free(r);
            }
            else if(auxDireita->esq != NULL){
                no = folha(auxDireita->esq); //encontra o nó folha para substituir o removido
                no->esq = r->esq;
                no->dir = r->dir;
                auxDireita->esq = NULL;

                if (ant->esq == r){
                    ant->esq = no;
                }
                else if (ant->dir == r){
                    ant->dir = no;
                }
                free(r);
            }
            
            //remover nó que não não se enquadra nos itens anteriores (aula 8.3, slide 7)
            else{
                if (r->esq == no){
                    no->dir = r->dir;
                    free(r);
                }
                else if(r->dir == no){
                    no->esq = r->esq;
                    free(r);
                }
            }
        }
    }
    return raiz;
}

int busca (arv *raiz, arv *a, arv *ant, int c) {
    int r;
    if (a == NULL)
	{
        return 0; // arvore vazia
    }
    else
	{
        if (c == a->valor)
		{
            printf("Valor encontrado. Deseja remover (1. sim/ 2. nao): ");
            scanf("%d", &r);
            if (r == 1){
                raiz = retira(raiz, a, ant, c);
                printf("Valor removido. \n");
                return 0;
            }
        }
        else if(busca(raiz, a->esq, a, c) == 1) // entra no ELSE IF se o retorno for 1
        {
            return 1;
        }
        else
        {
            return busca(raiz, a->dir, a, c);
        }
    }
}

arv *removeRaiz(arv *raiz){
    arv *r = raiz;
    if(raiz->esq == NULL && raiz->dir == NULL){ //se a raíz não tem filhos, apenas remover
        free(raiz);
        return NULL; // pois a árvore ficará vazia.
    }
    else if(raiz->esq != NULL && raiz->dir == NULL){ // testa se raiz tem apenas filho da esquerda
        raiz = raiz->esq;
        free(r);
        return raiz;
    }
    else if(raiz->esq == NULL && raiz->dir != NULL){ // testa se raiz tem apenas filho da direita
        raiz = raiz->dir;
        free(r);
        return raiz;
    }
    else{ // se tiver dois filhos
        printf("\nAtividade: adaptar aqui o código das linhas 111 a 154 da função \"retira\" \n");
    }

}


int main()
{
    arv *r = NULL;
    int x,v;
    r = insere (r, 30);
    r = insere (r, 15);
    r = insere (r, 35);
    r = insere (r, 10);
    r = insere (r, 20);
    r = insere (r, 12);
    
    imprime(r);
    printf("\n");

    printf("Digite um valor para buscar: ");
    scanf("%d", &v); 
    if (r->valor == v){ //função para remover elemento da raiz.
       r = removeRaiz(r);
    }
    else{
        x = busca(r, r, NULL, v);
        if (x == 1){
            printf("\nExiste na arvore!\n");
        }
    }
    
    imprime(r);
    printf("\n");

    return 0;
    }
