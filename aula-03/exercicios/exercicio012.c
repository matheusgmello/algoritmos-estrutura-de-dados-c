/*
Ler a temperatura em graus Celsius e apresentá-la convertida em Fahrenheit. A fórmula de conversão é:
Fahrenheit = 9 x Celsius + 160 / 5
*/

#include <stdio.h>

#define CONVERTERPARAFH(C) ((9 * (C) + 160) / 5)

int main() {
    double celsius, fahrenheit;

    printf("qual a temperatura de hoje em graus celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = CONVERTERPARAFH(celsius);

    printf("\na temperatura em fahrenheit eh: %.2fF\n", fahrenheit);

    return 0;
}