/*
O restaurante a quilo Bem-Bão cobra R$12,00 por cada quilo de refeição. Escreva um
algoritmo que leia o peso do prato montado pelo cliente (em quilos) e imprima o valor a
pagar. Assuma que a balança já desconte o peso do prato. 
*/

#include <stdio.h>
#define PRECOPORKILO 12.0 

int main() {
	
    double pesoDoPrato, valorASerPago;

    printf("qual o peso da comida  em (kg): ");
    scanf("%lf", &pesoDoPrato);

    valorASerPago = pesoDoPrato * PRECOPORKILO;

    printf("valor a ser pago eh: R$ %.2f\n", valorASerPago);

    return 0;
}
