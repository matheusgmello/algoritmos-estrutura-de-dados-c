#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Josephus{
	int id;
	struct Josephus *prox;
	struct Josephus *ant;
};

typedef struct Josephus guerreiros;

guerreiros *criaLista(guerreiros *l, int n, int i){
	guerreiros *novo;
	novo = (guerreiros *) malloc(sizeof(guerreiros));
	novo->id = i;
	if (l == NULL){
		novo->ant = NULL;
		novo->prox = NULL;
		return novo;
	}
	else{
		if(l->prox == NULL){ //testa se há só um elemento
			l->prox = novo;
			l->ant = novo;
			novo->prox = l;
			novo->ant = l;
		}
		else{
			guerreiros *p = l;
			while(p->prox != l){
				p = p->prox;
			}
			novo->prox = p->prox; //faz novo->prox apontar para l
			novo->ant = p;
			p->prox = novo;
			l->ant = novo;			
		}
		return l;
	}
}

void imprimeGuerreiros(guerreiros *l){
	guerreiros *p;
	printf("\nGuerreiros: ");
	for(p=l;p->prox!=l;p=p->prox){
		printf("%d ", p->id);
	}
	printf("%d", p->id);
}

guerreiros *eliminaGuerreiro(guerreiros *l, int k, int n){
	int primeiroGuerreiro = rand() % n;
	if(primeiroGuerreiro == 0){
		primeiroGuerreiro++;
	}
	
	while(l->id != primeiroGuerreiro){
		l= l->prox;
	}
	imprimeGuerreiros(l);
	printf("\nEliminacoes iniciam no soldado %d.\n\n", l->id);
	
	guerreiros *soldado = l;
	guerreiros *soldadoAnterior = soldado->ant;
	
	while(soldado->prox != l && soldado->ant != l){ //esse laço será executado até sobrar apenas um soldado
		int i, cont = 0;
		
		for(i=0; i<k; i++){ // encontra o soldado a ser eliminado
			soldadoAnterior = soldado;
			soldado = soldado->prox;
		}
		
		printf("\nGuerreiro a ser eliminado: %d\n", soldado->id);
		soldadoAnterior->prox = soldado->prox;
		soldado->prox->ant = soldadoAnterior;
		l = soldado->prox;
		free(soldado);
		imprimeGuerreiros(l);
		soldado = l;
	}
	return l;
}

void resolveProblema(guerreiros *l, int n){
	int k = rand() % 4;
	
	if (k == 0){
		k++;
	}
	
	printf("\nEliminar guerreiro a cada %d soldados\n", k);
	l = eliminaGuerreiro(l, k, n);
	printf("\nSoldado remanescente: %d\n", l->id);
}

int main(){
	srand(time(NULL));
	
	guerreiros *L = NULL;
	int n = rand() % 40;
	if (n <= 2){
		n += 10;
	}
	printf("\nTotal de guerreiros: %d\n", n);
	int i;
	for(i=1; i<=n; i++){
		L = criaLista(L, n, i);	
	}
	imprimeGuerreiros(L);
	resolveProblema(L, n);
	
	
	return 0;
}