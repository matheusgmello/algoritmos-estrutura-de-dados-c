/*
Uma fábrica de tecidos armazena as seguintes informações sobre cada tecido: código,
descrição, preço do metro, quantidade em estoque (em metros). Faça um algoritmo que
leia um lote de 8 tecidos e depois imprima:
a) Um relatório contendo as informações de cada tecido, cada qual em uma coluna;
b) Um relatório dos tecidos com estoque inferior a 50 metros;
c) Um relatório dos tecidos com preço do metro inferior a R$ 0,60.
*/

#include <stdio.h>
#include <string.h>

#define LOTE 2

struct fabrica{
	int codigo;
	char descricao[20];
	float precoDoMetro;
	float qtdEstoqueMetro;
};

int main(){
	
	struct fabrica tecidos[LOTE];
	int i;
	
	for (i=0;i< LOTE;i++){
		printf("qual o codigo do tecido: ");
		scanf("%d", &tecidos[i].codigo);
		fflush(stdin);
		
		printf("descricao do produto: ");
		gets(tecidos[i].descricao);
		fflush(stdin);
		
		printf("qual o preco do metro: ");
		scanf("%f", &tecidos[i].precoDoMetro);
		fflush(stdin);
		
		printf("quantidade em estoque em metros: ");
		scanf("%f", &tecidos[i].qtdEstoqueMetro);
		
		printf("\n");
	}
	

	printf("qual coluna esta cada tecido\n");
	printf("codigo\tdesc\t\tpreco do metro\testoque\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; i < LOTE; i++) {
	    printf("%d\t%-20s\t%.2f\t\t%.2f\n",
	           tecidos[i].codigo, tecidos[i].descricao, tecidos[i].precoDoMetro, tecidos[i].qtdEstoqueMetro);
	}

	printf("\n");
	
	printf("tecidos com estoque inferior a 50 metros:\n");
	for (i = 0; i < LOTE; i++) {
	    if (tecidos[i].qtdEstoqueMetro < 50) {
	        printf("codigo: %d\ndescricao: %s\nPreco: %.2f\nestoque: %.2f\n",
	               tecidos[i].codigo, tecidos[i].descricao, tecidos[i].precoDoMetro, tecidos[i].qtdEstoqueMetro);
	    }
	}
	
	printf("\n");
	
	printf("tecidos com preco do metro inferior a 0.60:\n");
	for (i = 0; i < LOTE; i++) {
	    if (tecidos[i].precoDoMetro < 0.60) {
	        printf("codigo: %d\ndesc: %s\nPreco: %.2f\nestoque: %.2f\n",
	               tecidos[i].codigo, tecidos[i].descricao, tecidos[i].precoDoMetro, tecidos[i].qtdEstoqueMetro);
	    }
	}
	
	
	
	return  0;
}