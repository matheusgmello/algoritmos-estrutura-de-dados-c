struct Livros {
  int codigo;
  char titulo[50];
  int quantidade;
};

int removerLivro(struct Livros livros[], int n, int codigo) {
  int encontrado = 0;
  for (int i = 0; i < n; i++) {
    if (livros[i].codigo == codigo) {
      // Desloca os livros para remover o encontrado
      for (int j = i; j < n - 1; j++) {
        livros[j] = livros[j + 1];
      }

      // Limpa o último (opcional)
      livros[n - 1].codigo = 0;
      livros[n - 1].titulo[0] = '\0';
      livros[n - 1].quantidade = 0;

      encontrado = 1;
      n--; // Atualiza o tamanho
      break; // Sai do loop, pois já removeu
    }
  }

  if (!encontrado) {
    printf("Livro com codigo %d nao encontrado.\n", codigo);
  } else {
    printf("Livro removido com sucesso.\n");
  }

  return n;
}


int totalLivros(struct Livros livros[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += livros[i].quantidade;
    }
    return total;
}

int main() {
    struct Livros livros[100];
    int n = 0; // Contador de livros
    int codigo;

    // Exemplo de adição de livros
    livros[n++] = (struct Livros){1, "Livro A", 5};
    livros[n++] = (struct Livros){2, "Livro B", 3};

    // Exemplo de remoção de um livro
    codigo = 1; // Código do livro a ser removido
    removerLivro(livros, n, codigo);
    n = removerLivro(livros, n, codigo);

    // Exibir total de livros
    printf("Total de livros: %d\n", totalLivros(livros, n));

    return 0;
}

/**
int removerLivro(struct Livros livros[], int n, int codigo){
  for (int i=0;i<n;i++){
    if (livros[i].codigo == codigo){
      for(int j=i; i<n-1; j++){

      	}
	  }
  }
}

*/