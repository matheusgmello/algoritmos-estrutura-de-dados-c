/*
Fazer um algoritmo que leia e verifique se três valores (a,b,c) podem ser os comprimentos dos lados
de um triângulo, escrevendo o tipo do triângulo (equilátero, isósceles, escaleno).
*/

#include <stdio.h>
int main(){
	
	int valorA, valorB, valorC;
	
	printf("qual o primeiro valor?: ");
	scanf("%d", &valorA);
	
	printf("qual o segundo valor?: ");
	scanf("%d", &valorB);
	
	printf("qual o terceiro valor?: ");
	scanf("%d", &valorC);
	
	if (valorA + valorB > valorC && valorA + valorC > valorB && valorB + valorC > valorA) {
        if (valorA == valorB && valorB == valorC) {
            printf("O triangulo eh equilatero.\n");
        } else if (valorA == valorB || valorA == valorC || valorB == valorC) {
            printf("O triangulo eh isosceles.\n");
        } else {
            printf("O triangulo eh escaleno.\n");
        }
    } else {
        printf("os valores num formam um triangulo.\n");
    }
    
    return 0;
}