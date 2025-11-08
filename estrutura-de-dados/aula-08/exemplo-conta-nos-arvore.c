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

int contaNos(struct arvore* r) {
    if (r == NULL) {
        return 0;
    }
    // Conta o nó atual + nós da subárvore esquerda + nós da subárvore direita
    return 1 + contaNos(r->esq) + contaNos(r->dir);
}

int main() {
    arv* r = NULL;
    r = insere(r, 30);
    r = insere(r, 15);
    r = insere(r, 35);
    r = insere(r, 10);
    r = insere(r, 20);
    r = insere(r, 12);

    int totalNos = contaNos(r);
    printf("Total de nos na arvore: %d\n", totalNos);

    return 0;
}