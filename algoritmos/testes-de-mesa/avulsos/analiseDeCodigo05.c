#include <stdio.h>

int contaPares(int n){
    int pares = 0;
    while(n > 0){
        int digito = n % 10;
        if(digito % 2 == 0){
            pares++;
        }
        n = n / 10;
    }
    return pares;
}

int main(){
    int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    int resultado = contaPares(numero);
    printf("Quantidade de dígitos pares: %d\n", resultado);
    return 0;
}