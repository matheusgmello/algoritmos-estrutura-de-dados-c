#include <stdio.h>
#include <string.h>

struct Biblioteca {
    char nome[50];
    char autor[50];
    int ano;
    char disponibilidade[10]; 
};

void cadastrarLivro(struct Biblioteca livros[], int n) {
  int i;

  for (i=0; i < n; i++) {
    printf("Digite o nome do livro: ");
    scanf(" %[^\n]", livros[i].nome);
    
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", livros[i].autor);
    
    printf("Digite o ano de publicacao: ");
    scanf("%d", &livros[i].ano);
    
    printf("Digite a disponibilidade (disponivel/indisponivel): ");
    scanf(" %[^\n]", livros[i].disponibilidade);
  }
}



void listarLivros(struct Biblioteca livros[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("Livro %d:\n", i + 1);
    printf("Nome: %s\n", livros[i].nome);
    printf("Autor: %s\n", livros[i].autor);
    printf("Ano: %d\n", livros[i].ano);
    printf("Disponibilidade: %s\n", livros[i].disponibilidade);
    printf("-------------------------\n");
  }
}

int main() {
  struct Biblioteca livros[100];
  int n;

  printf("Quantos livros deseja cadastrar? ");
  scanf("%d", &n);

  cadastrarLivro(livros, n);
  listarLivros(livros, n);

  return 0;
}
