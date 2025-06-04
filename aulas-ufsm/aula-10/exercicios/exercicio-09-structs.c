/*
9. Para ter seu projeto apreciado em um órgão de financiamento, um inventor deve
preencher um formulário contendo os seguintes dados: 
nome do inventor e do projeto;
breve descrição do seu inventor;
valor de financiamento solicitado;
prazo de execução em meses.
Sendo aprovado, o órgão financiador faz um cadastro destes dados, agregando um
campo que indica se o prazo está ou não atrasado. Faça um algoritmo para ler os dados de
50 projetos, e depois exibir:
a) Uma listagem dos projetos com até 6 meses de prazo, contendo o nome e o prazo,
incluindo o total financiado;
b) Uma listagem dos projetos em atraso, contendo o nome e o inventor, incluindo o total
financiado.
*/
#include <stdio.h>
#include <string.h>

#define QTD 2

struct construtora{
	char nomeDoProjeto[20];
	char nomeInvetor[20];
	char descricao[20];
	float valor;
	int prazo;
	char emAtraso;
	
};

int main(){
	
	struct construtora eng[QTD]; 
	
	int i;
	float totalFinanciado6 = 0, totalFinanciadoAtraso = 0;
	
	for (i=0;i<QTD;i++){
		printf("responsavel pelo projeto: ");
		gets(eng[i].nomeInvetor);
		fflush(stdin);
		
		printf("descricao do responsavel: ");
		gets(eng[i].descricao);
		fflush(stdin);
		
		printf("nome do projeto: ");
		gets(eng[i].nomeDoProjeto);
		fflush(stdin);
		
		printf("valor do projeto: ");
		scanf("%f", &eng[i].valor);
		fflush(stdin);
		
		printf("prazo do projeto (em meses): ");
		scanf("%d", &eng[i].prazo);
		fflush(stdin);
		
		printf("em atraso (s ou n): ");
		scanf(" %c", &eng[i].emAtraso);
		fflush(stdin);
		
		printf("\n");
		
	}
	printf("\n");
	
	printf("projetos com ate 6 meses de prazo\n");
	for (i=0;i<QTD;i++){
		if (eng[i].prazo <= 6){
			printf("projeto: %s\n", eng[i].nomeDoProjeto);
			printf("prazo: %d\n", eng[i].prazo);
			printf("financiado: %.3f\n", eng[i].valor);
			totalFinanciado6 += eng[i].valor;
		}		
	}
	
	printf("\n");
	
	printf("projetos em atraso\n");
	for (i=0;i<QTD;i++){
		if(eng[i].emAtraso == 's' || eng[i].emAtraso == 'S'){
			printf("projeto: %s\n", eng[i].nomeDoProjeto);
			printf("responsavel: %s\n", eng[i].nomeInvetor);
			totalFinanciadoAtraso += eng[i].valor;
		}
	}
	
	
	printf("total financiado com 6 meses: %.3f\n", totalFinanciado6);
	printf("total financiado com atraso: %.3f\n", totalFinanciadoAtraso);
	
	return 0;
}