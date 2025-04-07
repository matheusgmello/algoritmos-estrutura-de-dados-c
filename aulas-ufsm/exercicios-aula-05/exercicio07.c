/*
Ler informações sobre 10 pessoas de um grupo. Para cada pessoa deve ser lida a altura e o sexo.
Fazer um algoritmo que calcule e mostre:
a) A maior e a menor altura do grupo;
b) A média das alturas das mulheres;
c) A média das alturas de todos do grupo
*/

#include <stdio.h>

int main() {
	
    char sexo;
    float altura, maiorAltura = 0, menorAltura = 3.0;
    float somaAlturas = 0, somaAlturaMulheres = 0;
    int qntdMulheres = 0;

    for (int i = 1; i <= 10; i++) {
        printf("\pessoa %d:\n", i);

        printf("qual eu teu sexo? (H - Homem / M - Mulher): ");
        scanf(" %c", &sexo);

        // Pede a altura
        printf("Qual sua altura (em metros)? ");
        scanf("%f", &altura);

        // Atualiza maior e menor altura
        if (altura > maiorAltura) {
            maiorAltura = altura;
        }
        if (altura < menorAltura) {
            menorAltura = altura;
        }

        // Soma para a média geral
        somaAlturas += altura;

        // Verifica se é mulher para calcular a média delas
        if (sexo == 'M' || sexo == 'm') {
            somaAlturaMulheres += altura;
            qntdMulheres++;
        }
    }

    // Calcula as médias
    float mediaGeral = somaAlturas / 10;
    float mediaMulheres = (qntdMulheres > 0) ? (somaAlturaMulheres / qntdMulheres) : 0;

    // Mostra os resultados
    printf("\n--- Resultados ---\n");
    printf("Maior altura do grupo: %.2f metros\n", maiorAltura);
    printf("Menor altura do grupo: %.2f metros\n", menorAltura);
    printf("Média de altura das mulheres: %.2f metros\n", mediaMulheres);
    printf("Média de altura geral: %.2f metros\n", mediaGeral);

    return 0;
}