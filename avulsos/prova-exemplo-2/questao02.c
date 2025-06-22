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


/*
Escreva uma função que, dado um código, remova o produto correspondente e atualize a quantidade de itens no vetor. Retorne o novo valor de n.
*/
