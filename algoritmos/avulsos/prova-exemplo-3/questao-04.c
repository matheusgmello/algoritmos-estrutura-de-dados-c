int somaPares(int v[], int n) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] % 2 == 0) {
      total += v[i];
    }
  }
  return total;
}

int main() {
  int vetor[5] = {2, 5, 8, 9, 12};
  int resultado = somaPares(vetor, 5);
  
  printf("A soma dos números pares é: %d\n", resultado);
  
  return 0;
}

/**
Dado v = {2, 5, 8, 9, 12}, o valor retornado será:

a) ( ) 36
b) ( ) 22
c) ( ) 32
d) ( ) 20
*/