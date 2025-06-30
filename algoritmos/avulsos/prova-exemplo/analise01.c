#include <stdio.h>
#include <string.h>

int iguais(char t1[50], char t2[50]) {
  for (int i = 0; i <= strlen(t1); i++) {
    if (t1[i] != t2[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  char a[50], b[50];
  printf("Titulo 1: ");
  gets(a);
  printf("Titulo 2: ");
  gets(b);
  if (iguais(a, b) == 0) {
    printf("Sao iguais.\n");
  } else {
    printf("Sao diferentes.\n");
  }
}

/*
a) O que esse código tenta fazer?
b) Quais são os erros ou riscos?
c) Corrija o código para que funcione corretamente e seja seguro.

a) tenta comprar duas strings, se forem iguais imprime que sao iguais, se forem diferentes imprime que sao diferentes.

b) ele utiliza gets() que pode estourar o buffer, deveria usar fgets(), alem que a comparacao deveria ser ate strlen(t1) - 1

c) nao irei mandar o codigo corrigido, mas as correcoes sao:
- trocar gets() por fgets()
- trocar o for para comparar ate strlen(t1) - 1
- corrigir a condicao de comparacao para retornar 0 se forem iguais e 1
- corrigir o retorno da funcao iguais para retornar 0 se forem iguais e 1

e tbm poderia usar strcmp() para comparar as strings, que ja faz isso de forma segura e correta.
*/