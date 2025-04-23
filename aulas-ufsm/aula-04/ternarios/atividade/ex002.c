/*
2. Desenvolva um algoritmo para representar uma calculadora básica com as quatro operações aritméticas. 
O programa deve solicitar dois valores quaisquer e a operação desejada e mostrar o resultado.
*/

#include <stdio.h>

int main() {
	
	
    double a, b;
    char op;
    
    printf("digite dois numeros inteiros e\ne dps a sua operacao (+ , -, *, /): ");
    scanf("%lf %lf %c", &a, &b, &op);
    
    printf("%.2lf\n", (op == '+') ? (a + b) : (op == '-') ? (a - b) : (op == '*') ? (a * b) : (op == '/' ? (b ? a / b : 0) : 0));
    
    return 0;
}
