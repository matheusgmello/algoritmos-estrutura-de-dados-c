#include <stdio.h>
#include <string.h>

int main(){
  char a[6] = "hello";
  char b[20] = "world";
  strcat(a, b);

  printf("%s\n", a);
  return 0;
}

/**

Sobre o código acima, marque as afirmativas corretas:

a) ( f ) A função strcat copia a string b para a.
b) ( v ) a após a concatenação conterá "helloworld".
c) ( f ) a precisa ter espaço suficiente para conter as duas strings.
d) ( f ) O código irá falhar por erro de sintaxe.


a) na verdade ela nao copia mas sim, concatena as strings

c) na verdade ela nao necessariamente precisa de espaco para conter as duas strings, ela pode ter 5 ou 6 como dimensao que ainda sim vai printar helloworld, pois a strcat concatena e nao copia

d) o codigo funciona normalmente printando helloworld na tela

 */