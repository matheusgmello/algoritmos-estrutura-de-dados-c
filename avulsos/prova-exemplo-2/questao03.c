#include <stdio.h>
#include <string.h>

int main(){
  char a[20] = "hello";
  char b[20] = "world";
  strcat(a, b);

  printf("%s\n", a);
  return 0;
}

/**

Sobre o código acima, marque as afirmativas corretas:

a) ( ) A função strcat copia a string b para a.
b) ( ) a após a concatenação conterá "helloworld".
c) ( ) a precisa ter espaço suficiente para conter as duas strings.
d) ( ) O código irá falhar por erro de sintaxe.


 */