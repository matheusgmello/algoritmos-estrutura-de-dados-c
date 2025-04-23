/*
Desenvolver um programa que leia três valores inteiros e apresente como resultado o valor do quadrado da soma dos três valores lidos.
*/

#include <stdio.h>

int main() {
    /*
    primeira versao
    
	int x, y, z, soma, quadradoDaSoma;
    printf("informe o valor de x: ");
    scanf("%d", &x);
    printf("informe o valor de y: ");
    scanf("%d", &y);
    printf("informe o valor de z: ");
    scanf("%d", &z);

    soma = x + y + z;
    
    quadradoDaSoma = soma * soma;
    printf("quadrado da soma dos 3 valores eh: %d\n", quadradoDaSoma);

    return 0;
	*/
	
	// tentando simplificar
	
	int x, y, z, resultadoDoQuadradoDaSoma;

    printf("digite tres numeros inteiros para x,y e z respectivamente: \n ");
    scanf("%d %d %d", &x, &y, &z);

    resultadoDoQuadradoDaSoma = (x + y + z) * (x + y + z);

    printf("quadrado da soma dos 3 valores eh: %d\n", resultadoDoQuadradoDaSoma);

    return 0;
}