#include <stdio.h>

int codigoProva(int valor){
  int a = 0;
  while (valor > 0){
    int digito = valor % 10;
    //a+= digito;
    a = a + digito;
    //valor /= 10;
    valor = valor / 10;
  }
  return a;
}

int main(){
  int numero;

  printf("digite um numero inteiro positivo: ");
  scanf("%d", &numero);

  int retornoFunc = codigoProva(numero);
  printf("saida do programa: %d\n", retornoFunc);
  return 0;

}

// O codigo funciona corretamente? Justifique.




// Qual o objetivo do programa?