#include <stdio.h>

int somaDigitos(int n){
    int soma = 0;
    while(n > 0){
        soma = soma + (n % 10);
        n = n / 10;
    }
    return soma;
}

int main(){
    int valor;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &valor);

    int resultado = somaDigitos(valor);
    printf("Saída do programa: %d\n", resultado);
    return 0;
}