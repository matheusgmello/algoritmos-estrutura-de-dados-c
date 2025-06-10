/*
Escreva um programa que contenha uma função para calcular o desconto de um produto e outra
função para calcular o valor total da venda. 

A primeira função deve receber como parâmetros o valor
do produto e a porcentagem do desconto e retornar o novo preço do produto. 

A segunda função
deve receber como parâmetro a quantidade e calcular o preço total já com o desconto. O programa
deve apresentar o preço original do produto, o desconto e o valor total da venda.
*/

#include <stdio.h>
float calculaDesconto(float valorProduto, float porcentagemDesconto){

	float desconto;
	float novoPrecoProduto;
	
	desconto = valorProduto * (porcentagemDesconto / 100);
	novoPrecoProduto = valorProduto - desconto;
	
	return novoPrecoProduto;
		
}

float valorTotalDaCompra(int quantidade, float precoComDesconto){
	
	float valorTotal;
	
	valorTotal = quantidade * precoComDesconto;
	
	return valorTotal;
	
}

int main(){
	float valorProduto, porcentagemDesconto, precoComDesconto, valorTotal;
    int quantidade;
	
	printf("qual o valor do produto: ");
	scanf("%f", &valorProduto);
	
	printf("qual o porcentagem de desconto: ");
	scanf("%f", &porcentagemDesconto);
	
	printf("qual a quantidade do produto: ");
	scanf("%d", &quantidade);
	

	precoComDesconto = calculaDesconto(valorProduto, porcentagemDesconto);
	valorTotal = valorTotalDaCompra(quantidade, precoComDesconto);
	
	printf("\npreco original: R$%.2f\n", valorProduto);
	printf("valor do desconto: R$%.2f\n", desconto);
    printf("preco com desconto: R$%.2f\n", precoComDesconto);
    printf("valor total: R$%.2f\n", valorTotal);
		
	return 0;
}