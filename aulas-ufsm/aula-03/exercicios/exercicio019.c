/*
Desenvolver um programa que leia três valores inteiros e apresente como resultado o valor da soma dos
quadrados dos três valores lidos.
*/

#include <stdio.h>

int main() {
    int x, y, z, resultadoDoQuadrado;

    printf("informe tres valores inteiros para x y z: ");
    scanf("%d %d %d", &x, &y, &z);

    resultadoDoQuadrado = (x * x) + (y * y) + (z * z);

    printf("a soma do quadrado de tres valores eh: %d\n", resultadoDoQuadrado);

    return 0;
}
