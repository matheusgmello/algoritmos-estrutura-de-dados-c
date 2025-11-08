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
        printf("%d ", raiz->valor);
        imprime(raiz->esq);
        imprime(raiz->dir);
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

    
    printf("\n");

    return 0;
    }
