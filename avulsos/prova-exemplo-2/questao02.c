struct Produto {
  int codigo;
  char nome[30];
  int quantidade;
};

struct Produto estoque[5] = {
  {1, "Papel", 10},
  {2, "Caneta", 15},
  {3, "Lapis", 20},
  {4, "Borracha", 12},
  {5, "Cola", 8}
};


int removeProduto(struct Produto e[], int n, int codigo){
	for (int i = 0; i < n; i++) {
		if (e[i].codigo == codigo) {
			for (int j = i; j < n - 1; j++) {
				e[j] = e[j + 1];
			}
			e[n - 1].codigo = 0;
			e[n - 1].nome[0] = '\0';
			e[n - 1].quantidade = 0;
			printf("produto removido com sucesso.\n");
			return n - 1;
		}
	}
	printf("produto nao encontrado\n");
	return n;
}


/*
Escreva uma função que, dado um código, remova o produto correspondente e atualize a quantidade de itens no vetor. Retorne o novo valor de n.
*/
