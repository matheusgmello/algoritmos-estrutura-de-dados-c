struct arvore {
    int valor;
    struct arvore* esq;
    struct arvore* dir;
};
typedef struct arvore arv;

arv insere(arv* r, int c) {
    arv* novo = (arv*)malloc(sizeof(arv));
    novo->valor = c;
    novo->esq = NULL;
    novo->dir = NULL;

    if (r == NULL)
        r = novo;
    else {
        arv* aux = r;
        arv* ult;
        while (aux != NULL) {
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

int somaNos(struct arvore* r) {
    if (r == NULL) {
        return 0;
    }
    // Soma o valor do nó atual + soma da subárvore esquerda + soma da subárvore direita
    return r->valor + somaNos(r->esq) + somaNos(r->dir);
}

int main() {
    arv* r = NULL;
    r = insere(r, 30);
    r = insere(r, 15);
    r = insere(r, 35);
    r = insere(r, 10);
    r = insere(r, 20);
    r = insere(r, 12);

    int totalSoma = somaNos(r);
    printf("Soma dos valores dos nos na arvore: %d\n", totalSoma);

    return 0;
}