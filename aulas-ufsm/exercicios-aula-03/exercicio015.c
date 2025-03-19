/*
Calcular a quantidade de litros de combustível gasta em uma viagem, utilizando um automóvel que faz 12km
por litro. Para obter o cálculo, o usuário deve fornecer o tempo gasto e a velocidade média durante a
viagem. Desta forma, será possível obter a distância percorrida com a fórmula:
distância = tempo x velocidade
Tendo o valor da distância, basta calcular a quantidade de litros de combustível utilizada na viagem com
a fórmula: Litros_usados = distância/ 12
O programa deve apresentar os valores da velocidade média, tempo gasto na viagem, distância
percorrida e a quantidade de litros utilizada na viagem
*/

#include <stdio.h>

#define DISTANCIAPERCORRIDA(tempoDaViagem, velocidadeMedia) ((double)(tempoDaViagem) * (double)(velocidadeMedia))
#define CONSUMODAVIAGEM(distanciaPercorridaDaViagem) ((double)(distanciaPercorridaDaViagem) / 12.0)

int main() {
    double tempoDaViagem, velocidadeMedia, distanciaPercorridaDaViagem, litrosUsados;

    printf("insira o tempo gasto na viagem em horas: ");
    scanf("%lf", &tempoDaViagem);

    printf("insira a velocidade media da viagem km/h: ");
    scanf("%lf", &velocidadeMedia);

    distanciaPercorridaDaViagem = DISTANCIAPERCORRIDA(tempoDaViagem, velocidadeMedia);
    litrosUsados = CONSUMODAVIAGEM(distanciaPercorridaDaViagem);


    printf("velocidade media percorrida: %.2lf km/h\n", velocidadeMedia);
    printf("tempo de viagem: %.2lf horas\n", tempoDaViagem);
    printf("distancia percorrida da viagem: %.2lf km\n", distanciaPercorridaDaViagem);
    printf("quanto de combustivel foi usado: %.2lf litros\n", litrosUsados);

    return 0;
}
