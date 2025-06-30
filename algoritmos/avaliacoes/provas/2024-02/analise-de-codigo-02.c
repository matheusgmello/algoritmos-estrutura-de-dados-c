/*
Analise o código abaixo e marque V para as afirmações verdadeiras e F para as falsas. Justifique as falsas.
*/

#include <stdio.h>
#include <string.h>

int main(){

  char str1[20] = "Programming";
  char str2[20] = "is";
  char str3[20] = "fun";

  strcat(str1, str2); 
  strcat(str3, str2); 

  printf("str1: %s\n", str1);
  printf("str3: %s\n", str3);

  return 0;
}

/**
Marque verdadeira ou falso

() O resultado da execução do código será "Programmingis" para str1
() O resultado da execução do código será "funis" para str3
() A funcao strcat(str1, str2); garante que str1 será corretamente terminada com o caractere nulo ('\0') apos a concatenacao
() A funcao strcat(str3, str2); garante que str3 tera um total de 4 caracteres apos a concatenacao
() o codigo nao irá compilar corretamente, pois a erro de sintaxe.
*/