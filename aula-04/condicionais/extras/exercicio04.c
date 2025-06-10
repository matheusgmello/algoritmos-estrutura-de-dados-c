/*
Desenvolva um algoritmo que leia o valor a ser pago por um produto, considerando o preço
normal de etiqueta e a escolha da condição de pagamento. Para realizar o cálculo, utilize os
códigos a seguir referentes à condição de pagamento escolhida pelo cliente.
Código Condição de pagamento
a. À vista em dinheiro ou cheque, recebe 10% de desconto.
b. À vista no cartão de crédito, recebe 15% de desconto.
c. Em duas vezes, preço normal de etiqueta mais juros de 10%.
*/

#include <stdio.h>

int main() {
    float precoDaEtiqueta, valorFinal;
    char opcaoDePagamento;
    
    printf("digite o preco do produto: R$ ");
    scanf("%f", &precoDaEtiqueta);


    printf("\nopcoes de pagamento:\n");
    printf("a. a vista em dinheiro ou cheque (10%% de desconto)\n");
    printf("b. a vista no cartao de credito (15%% de desconto)\n");
    printf("c. em duas vezes (preco normal + 10%% de juros)\n");
    printf("escolha a opcao de pagamento (a-c): ");
    scanf(" %c", &opcaoDePagamento);

    if (opcaoDePagamento == 'a' || opcaoDePagamento == 'A') {
        valorFinal = precoDaEtiqueta * 0.90; 
        printf("\nvalor a ser pago: R$ %.2f (a vista com 10%% de desconto)\n", valorFinal);
    } 
    else if (opcaoDePagamento == 'b' || opcaoDePagamento == 'B') {
        valorFinal = precoDaEtiqueta * 0.85; 
        printf("\nvalor a ser pago: R$ %.2f (a vista no cartao com 15%% de desconto)\n", valorFinal);
    } 
    else if (opcaoDePagamento == 'c' || opcaoDePagamento == 'C') {
        valorFinal = precoDaEtiqueta * 1.10; 
        printf("\nvalor a ser pago: 2x de R$ %.2f (total: R$ %.2f)\n", valorFinal / 2, valorFinal);
    } 
    else {
        printf("\nopcao invalida!.\n");
    }

    return 0;
}