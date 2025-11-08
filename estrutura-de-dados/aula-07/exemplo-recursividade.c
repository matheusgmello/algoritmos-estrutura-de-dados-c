#include<stdio.h>
#include<stdlib.h>

struct Lista{
	int valor;
	struct Lista *prox;
};
typedef struct Lista Lista;

Lista *insere(Lista *l){
	char op;
	printf("deseja inserir um valor? s/n ");
	fflush(stdin);
	scanf("%c", &op);
	
	if(op == 's'){
		Lista *novo = (Lista*) malloc(sizeof(Lista));
		int v;
		printf("Digite o valor: ");
		scanf("%d", &v);
		novo->valor = v;
		novo->prox = l;
		l = insere(novo);
	}
	return l;
}

void imprime(Lista *l){
	Lista *atual = l;
	if(atual != NULL){
		printf("%d \t", atual->valor);
		imprime(atual->prox);
	}
}

int pesquisa(Lista *l, int n){
	Lista *atual = l;
	int r;
	if(atual != NULL){
		if(atual->valor != n){
			r = pesquisa(atual->prox, n);	
		}
		else{
			printf("valor encontrado. \n");
			return 1;
		}
	}
	else{
		printf("valor nao encontrado.\n");
		return 0;
	}
	return r;
}

Lista *remover(Lista *l, Lista *atual, int n, Lista *ant){

	
	while(atual->valor != n){
		ant = atual;
		atual = atual->prox;
	}
	
	if(atual == l){ //primeiro elemento da lista
		l = l->prox;
	}
	else if(atual->prox == NULL){ // ultimo elemento da lista
		ant->prox = NULL;
	}
	else{ // meio da lista
		ant->prox = atual->prox;
	}
	return(l);
}

int main(){
	Lista *minhaLista = NULL, *aux = NULL;
	minhaLista = insere(minhaLista);
	imprime(minhaLista);
	
	int num;
	char op;
	printf("\n\nDigite um numero para pesquisar: ");
	scanf("%d", &num);
	int r = pesquisa(minhaLista, num);
	if(r == 1){
		printf("Deseja excluir? s/n");
		getchar();
		scanf("%c", &op);
		if(op == 's'){
			minhaLista = remover(minhaLista, minhaLista, num, aux);
		}
	}
	printf("Nova lista:\n");
	imprime(minhaLista);
	
	return 0;
}





