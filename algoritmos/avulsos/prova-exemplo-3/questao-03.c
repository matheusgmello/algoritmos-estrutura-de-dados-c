int main(){

  char nome[20];
  printf("Digite seu nome: ");
  gets(nome);


  return 0;
}

/**
Sobre o código acima:
a) ( ) O código está seguro, pois nome tem tamanho suficiente.
b) ( ) gets() deve ser evitado pois pode causar estouro de buffer.
c) ( ) Uma alternativa mais segura seria scanf("%s", nome).
d) ( ) O mais seguro seria usar fgets(nome, 20, stdin).
*/