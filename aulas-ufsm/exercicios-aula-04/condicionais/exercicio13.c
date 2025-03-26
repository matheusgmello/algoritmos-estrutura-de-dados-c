/*
Fazer um algoritmo que leia valores para as variáveis hora, minuto e segundo; verificando e
escrevendo se elas correspondem a um horário válido ou não. Para um horário ser valido, a hora
deve estar no intervalo de 0 a 23, o minuto e o segundo no intervalo de 0 a 59.
*/

#include <stdio.h>

int main() {
    int hora, minutos, segundos;

    printf("qual eh a hora: ");
    scanf("%d", &hora);

    printf("quantos minutos: ");
    scanf("%d", &minutos);

    printf("e quantos segundos: ");
    scanf("%d", &segundos);

    if (hora >= 0 && hora <= 23 && minutos >= 0 && minutos <= 59 && segundos >= 0 && segundos <= 59) {
        printf("a hora eh %d horas, %d minutos e %d segundos.\n", hora, minutos, segundos);
    } else {
        printf("horario inserido incorreto.\n");
    }

    return 0;
}
