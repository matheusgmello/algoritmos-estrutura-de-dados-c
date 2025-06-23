struct Produto {
  int codigo;
  char nome[30];
  int quantidade;
};

struct Produto estoque[4] = {
  {101, "Lapis", 10},
  {102, "Caneta", 5},
  {103, "Borracha", 8},
  {104, "Cola", 2}
};

/**
Implemente uma função atualizarQuantidade que receba o vetor, o tamanho n, um codigo e um valor inteiro qtdNova.
A função deve localizar o produto e atualizar a quantidade. Se não encontrar, exibir uma mensagem.
*/