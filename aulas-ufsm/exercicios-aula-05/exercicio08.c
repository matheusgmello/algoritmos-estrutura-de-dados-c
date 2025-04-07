/*
Elaborar um programa que apresente os números da série Fibonacci até o décimo quinto termo.
A série Fibonacci é iniciada por 0, 1. Os próximos termos são resultados das somas de seus 2
antecessores.
*/

#include <stdio.h>

int main() {
    int fibonnaciTermo1 = 0, fibonnaciTermo2 = 1, proximoTermo;
    int i;
    
    printf("%d, %d", fibonnaciTermo1, fibonnaciTermo2);
    
    for (i = 3; i <= 15; i++) {
        proximoTermo = fibonnaciTermo1 + fibonnaciTermo2;
        printf(", %d", proximoTermo);
        
        fibonnaciTermo1 = fibonnaciTermo2;
        fibonnaciTermo2 = proximoTermo;
    }
    
    printf("\n");
    return 0;
}