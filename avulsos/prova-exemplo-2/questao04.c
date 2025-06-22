#include <stdio.h>


int main(){
  int v[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
      v[i] = v[i] * 2;
  }

  
  return 0;
}

/**
Qual será o conteúdo do vetor v ao final?

a) ( ) {1, 2, 3, 4, 5}
b) ( ) {2, 4, 6, 8, 10}
c) ( ) {1, 4, 9, 16, 25}
d) ( ) {0, 0, 0, 0, 0}


*/