/*
2. Desenvolver um programa que recebe uma palavra e o tipo de conversão que o usuário
deseja que ela sofra, que poderá ser letras (m)aiúsculas ou mi(n)úsculas. Observe que o campo
(variável) tipo de conversão deverá ser validado.
*/

#include <stdio.h>
#include <string.h>

void transforma(char palavra[], char tipo){
  
  if(tipo == 'm' || tipo == 'M'){
    strupr(palavra);
  }else if(tipo == 'n' || tipo == 'N'){
    strlwr(palavra);
  }else{
    printf("tipo de conversao invalido, tente novamente\n");
  }
  
  puts(palavra);
  
}

int main(){

  char palavra[20];
  char tipo;
  
  printf("uma palavra: ");
  gets(palavra);
  
  printf("qual o tipo de conversao (m/n): ");
  scanf("%c", &tipo);
  
  transforma(palavra, tipo);
  
  return 0;


}