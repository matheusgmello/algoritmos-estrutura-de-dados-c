/**
7. Desenvolva um programa que calcule o preco de venda, preco de custo e valor da taxa de
entrega de uma floricultura. Para isso, deve-se saber: o tipo de flor (rosa, margarida ou flores
do campo), a quantidade vendida, o preco unitario, e se haverá embalagem para presente (Sim
ou Nao). O preco de custo será a quantidade de flores vezes o preco unitario. A taxa de
entrega será de 5% sobre o preco de custo. Finalmente, o preco de venda será o preco de
custo mais o valor da taxa de entrega.
*/

#include <stdio.h>
#include <string.h>

void calcularPrecoVenda(char tipo[], int quantidade, float precoUnitario, int embalagem) {
    float precoCusto, taxaEntrega, precoVenda;

    precoCusto = quantidade * precoUnitario;
    taxaEntrega = 0.05 * precoCusto;
    precoVenda = precoCusto + taxaEntrega;

    printf("Tipo de flor: %s\n", tipo);
    printf("Quantidade vendida: %d\n", quantidade);
    printf("Preco unitario: %.2f\n", precoUnitario);
    printf("Preco de custo: %.2f\n", precoCusto);
    printf("Taxa de entrega: %.2f\n", taxaEntrega);
    printf("Preco de venda: %.2f\n", precoVenda);

    if (embalagem) {
        printf("Embalagem para presente: Sim\n");
    } else {
        printf("Embalagem para presente: Nao\n");
    }
}

int main() {
    char tipo[20];
    int quantidade, embalagem;
    float precoUnitario;

    printf("Digite o tipo de flor (rosa, margarida ou flores do campo): ");
    fgets(tipo, sizeof(tipo), stdin);
    tipo[strcspn(tipo, "\n")] = 0; // Remove o caractere de nova linha

    printf("Digite a quantidade vendida: ");
    scanf("%d", &quantidade);

    printf("Digite o preco unitario: ");
    scanf("%f", &precoUnitario);

    printf("Havera embalagem para presente? (1 para Sim, 0 para Nao): ");
    scanf("%d", &embalagem);

    calcularPrecoVenda(tipo, quantidade, precoUnitario, embalagem);

    return 0;
}
