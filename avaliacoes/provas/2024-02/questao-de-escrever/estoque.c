/**
(2,0) Você foi contratado para desenvolver um sistema de gerencíamento de estoque para uma loja. O
sistema deve utilizar structs para representar cada produto, com os seguintes dados: código do produto,
nome do produto, preço unitário e quantidade em estoque. 

Implemente as seguintes funcionalidades:

  Remoção de Produtos: Uma função que permite ao usuário remover um produto do estoque,
  informando o código do produto.
  Valor Total do Estoque: Uma função que calcula e imprime o valor total do estoque, considerando
  o preço unitário e a quantidade de cada produto.

Dica: Assuma que a inserção dos N produtos já esteja implementada e funciona sem problemas. Crie apenas o
registro e as funções solicitadas.

*/

#include <stdio.h>
#include <string.h>

struct loja {
  int codigo;
  char nome[25];
  float preco_unitario;
  int qtd_estoque;
};

// Função que calcula o valor total do estoque
void valor_total(struct loja produto[], int n) {
  float valor_total = 0;
  float aux;
  int i;
  for (i = 0; i < n; i++) {
    aux = produto[i].preco_unitario * produto[i].qtd_estoque;
    valor_total += aux;
  }
  printf("Valor total do estoque: R$ %.2f\n", valor_total);
}

// Função que remove um produto pelo código
// Função que remove um produto informando o código
int remocao_produto(struct loja produto[], int n) {
  int remover, encontrado = 0; // variável "remover" vai guardar o código desejado

  // Pede o código ao usuário
  printf("Codigo do produto a remover: ");
  scanf("%d", &remover);

  // Percorre todos os produtos cadastrados
  for (int i = 0; i < n; i++) {
    // Se encontrar o código
    if (produto[i].codigo == remover) {
      // Desloca todos os produtos à frente 1 posição para trás
      for (int j = i; j < n - 1; j++) {
        produto[j].codigo = produto[j + 1].codigo;
        strcpy(produto[j].nome, produto[j + 1].nome);
        produto[j].preco_unitario = produto[j + 1].preco_unitario;
        produto[j].qtd_estoque = produto[j + 1].qtd_estoque;
      }

      // Limpa o último item (opcional, mas recomendado)
      produto[n - 1].codigo = -1;
      strcpy(produto[n - 1].nome, "");
      produto[n - 1].preco_unitario = 0.0;
      produto[n - 1].qtd_estoque = 0;

      encontrado = 1; // marca que encontrou
      n--;            // diminui o total de produtos válidos
      break;          // para o laço, já que só precisa remover um
    }
  }

  // Se não encontrou nenhum produto com o código digitado
  if (!encontrado) {
    printf("Produto com codigo %d nao encontrado.\n", remover);
  } else {
    printf("Produto removido com sucesso.\n");
  }

  return n; // retorna o novo tamanho da lista
}


int main() {
  int n;
  printf("Quantos produtos deseja cadastrar? ");
  scanf("%d", &n);

  struct loja produtos[100];

  for (int i = 0; i < n; i++) {
    printf("\nProduto %d:\n", i + 1);
    printf("Codigo: ");
    scanf("%d", &produtos[i].codigo);
    printf("Nome: ");
    scanf(" %[^\n]", produtos[i].nome);
    printf("Preco unitario: ");
    scanf("%f", &produtos[i].preco_unitario);
    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[i].qtd_estoque);
  }

  // Chamada das funções
  valor_total(produtos, n);
  n = remocao_produto(produtos, n);
  valor_total(produtos, n);

  return 0;
}
