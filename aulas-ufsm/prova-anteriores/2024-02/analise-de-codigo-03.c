#include <stdio.h>
#include <string.h>

void func(char p[100], int v, char s[100]){
  int i,k,j;
  for (i=0,j=0; i<= v; i++){
    if ((p[i] == ' ') || p[i] (== '\0')){
     for (k=0; k<i; k++){
        s[j+k] = p[i-1-k];
      }
      s[j+k] = ' ';
      j=i+1;
  }
  }
  s[v] = '\0';

}

int main(){
    int t=0,i,j,k,c=1;
    char f[100], fi[100], fg[4]={"fim"};
    while(c == 1){
        printf("Entrada: ");
        gets(f);
        t = strlen(f);
        if((strcmp(strlwr(f),fg))!=0){
            func(f,t,fi);
            printf("%s\n",fi);
        }
        else{
            c=0;
        }
    }
    return 0;
}

/**
Alternativas

a) Objetivo deste algorítmo é identificar quando fim" é digitado.
b) Se a entrada for "teste 123" na linha 23, o valor mostrado na línha 29 será "321 etset".
c) A função 'func' inverte as palavras de 'p'e armazena em 's'.
d) O laço de repetição da linha 21, é encerrado somente quando "fim"for o valor de entrada na linha 23.
e) A função 'func', na linha 26, poderia ser substituída por strcpy(f,fi}

Justifique suas respostas.

*/