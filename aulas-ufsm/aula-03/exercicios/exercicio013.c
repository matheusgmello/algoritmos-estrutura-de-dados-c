/*
Calcular o volume de uma lata de óleo utilizando a fórmula: volume = 3.14159 x r² x Altura.
*/

#include <stdio.h>

float calculaVolume(double raioDaLata, double alturaDaLata) {
    const double PI = 3.14159;
    return PI * raioDaLata * raioDaLata * alturaDaLata;
}

int main() {
    double raioDaLata, alturaDaLata, volumeDaLata;

    printf("insira o raio da lata em cm: ");
    scanf("%lf", &raioDaLata);

    printf("insira a altura da lata em cm: ");
    scanf("%lf", &alturaDaLata);
    
    volumeDaLata = calculaVolume(raioDaLata, alturaDaLata);

    printf("\no volume da lata eh: %.2f cm\n", volumeDaLata);

    return 0;
}