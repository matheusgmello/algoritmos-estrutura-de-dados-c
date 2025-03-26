/*
Uma cafeteria possui o seguinte cardápio:

Especificação Código Preço
Café expresso pequeno 100 2,00
Café expresso grande 101 3,00
Café com leite pequeno 102 2,50
Café com leite grande 103 3,50
Água sem gás (200 ml) 104 1,50
Água com gás (500 ml) 105 2,40

Fazer um algoritmo que leia a quantidade e o código do item pedido, e calcule o valor a ser pago.
Considere que em cada execução somente será calculado um tipo de item. O algoritmo deve
escrever a descrição do produto pedido, a quantidade, o valor unitário e o total a ser pago.
*/

#include <stdio.h>

int main() {
    int codigo, quantidade;
    float preco, total;
    char descricao[50];
    
    printf("insira o codigo do item (100 ate 105): ");
    scanf("%d", &codigo);
    printf("informe a quantidade desejada: ");
    scanf("%d", &quantidade);
    
    if (codigo == 100) {
        preco = 2.00;
        sprintf(descricao, "cafe expresso pequeno");
    } else if (codigo == 101) {
        preco = 3.00;
        sprintf(descricao, "cafe expresso grande");
    } else if (codigo == 102) {
        preco = 2.50;
        sprintf(descricao, "cafe com leite pequeno");
    } else if (codigo == 103) {
        preco = 3.50;
        sprintf(descricao, "cafe com leite grande");
    } else if (codigo == 104) {
        preco = 1.50;
        sprintf(descricao, "agua sem gas (200 ml)");
    } else if (codigo == 105) {
        preco = 2.40;
        sprintf(descricao, "agua com gas (500 ml)");
    } else {
        printf("codigo incorreto!\n");
        return 1;
    }
    
    total = preco * quantidade;
    
    printf("\nitem escolhido: %s\n", descricao);
    printf("quantidade escolhida: %d\n", quantidade);
    printf("valor unitario: R$ %.2f\n", preco);
    printf("total a ser pago: R$ %.2f\n", total);
    
    return 0;
}

