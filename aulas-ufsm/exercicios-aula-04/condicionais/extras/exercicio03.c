/*
Faça um algoritmo que leia o sexo e o estado civil de uma pessoa. Caso sexo seja “F” e
estado civil seja “CASADO”, solicitar o tempo de casada (anos). As possibilidades de estado
civil são:
a. Solteiro
b. Casado
c. Viúvo
d. Desquitado
*/

#include <stdio.h>
#include <stdio.h>

int main() {
    char sexo, estadoCivil;
    int tempoCasada = 0;

    printf("qual eh o seu sexo (M/F): ");
    scanf(" %c", &sexo);

    printf("qual eh seu estado civil:\n");
    printf("a. solteiro\n");
    printf("b. casado\n");
    printf("c. viuvo\n");
    printf("d. desquitado\n");
    printf("opcao (a-d): ");
    scanf(" %c", &estadoCivil);

    
    if ((sexo == 'F' || sexo == 'f') && (estadoCivil == 'B' || estadoCivil == 'b')) {
        printf("quanto tempo casada? (em anos): ");
        scanf("%d", &tempoCasada);
    }

    printf("Sexo: ");
    if (sexo == 'M' || sexo == 'm') {
        printf("Masculino\n");
    } else if (sexo == 'F' || sexo == 'f') {
        printf("Feminino\n");
    } else {
        printf("Inválido\n");
    }


    printf("Estado civil: ");
    if (estadoCivil == 'A' || estadoCivil == 'a') {
        printf("Solteiro(a)\n");
    } else if (estadoCivil == 'B' || estadoCivil == 'b') {
        printf("Casado(a)\n");
    } else if (estadoCivil == 'C' || estadoCivil == 'c') {
        printf("Viúvo(a)\n");
    } else if (estadoCivil == 'D' || estadoCivil == 'd') {
        printf("Desquitado(a)\n");
    } else {
        printf("invalido\n");
    }

    if ((sexo == 'F' || sexo == 'f') && (estadoCivil == 'B' || estadoCivil == 'b')) {
        printf("tempo de casada: %d anos\n", tempoCasada);
    }

    return 0;
}