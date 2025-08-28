/*
Remover os n primeiros elementos de uma lista encadeada, onde n é definido pelo usuário.
*/

#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista *proximo;
};

int main() {
    int n, i, k;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);
    struct lista *inicio = NULL, *atual = NULL;
    for (i = 0; i < n; i++) {
        struct lista *novo = malloc(sizeof(struct lista));
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &novo->info);
        novo->proximo = NULL;
        
        if (inicio == NULL){
        	inicio = novo;
		} else {
			atual->proximo = novo;	
		}
		
        atual = novo;
    }

    printf("Digite quantos elementos deseja remover do inicio: ");
    scanf("%d", &k);
    for (i = 0; i < k && inicio != NULL; i++) {
        struct lista *temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }

    printf("\nLista apos a remocao:\n");
    atual = inicio;
    while (atual != NULL) {
        printf("%d\n", atual->info);
        struct lista *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
