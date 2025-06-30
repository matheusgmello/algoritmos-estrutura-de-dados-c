/**
Em uma pesquisa envolvendo 20 entrevistados, uma editora solicitou os seguintes
dados: sexo, idade e quantidade de livros que leu em 2020. Faça um programa que
leia os dados digitados pelo usuário e ao final, calcule e imprima: a) A
quantidade total de livros lidos pelos entrevistados menores de 10 anos; b) A
quantidade de mulheres que leram 5 livros ou mais; c) O percentual de pessoas
que não leram livros.
*/

#include <stdio.h>
#include <string.h>

struct pesquisa{
	char sexo;
	int idade;
	int qtdLivros;
};

int main(){
	
	struct pesquisa entrevista[20];
	
	int i;
	int qtdLivrosMenores = 0;
	int qtdMulherLer5ouMais = 0;
	int qtdNaoLeuLivros = 0;
	float percentual = 0;
	
	for (i=0;i<20;i++){
		printf("qual seu sexo (M ou F): ");
		fflush(stdin);
		scanf(" %c", &entrevista[i].sexo);
		fflush(stdin);
		
		printf("qual sua idade: ");
		scanf("%d", &entrevista[i].idade);
		fflush(stdin);
		
		printf("quantos livros tu leu?: ");
		scanf("%d", &entrevista[i].qtdLivros);
		fflush(stdin);
		
		if (entrevista[i].idade < 10){
			qtdLivrosMenores += entrevista[i].qtdLivros;
		}
		
		if ((entrevista[i].sexo == 'f' || entrevista[i].sexo == 'F') && entrevista[i].qtdLivros >= 5) {
		    qtdMulherLer5ouMais++;
		}

		if (entrevista[i].qtdLivros == 0) {
		    qtdNaoLeuLivros++;
		}

	}
	
	percentual = (qtdNaoLeuLivros * 100.0) / 20;

	printf("\n");
	
	printf("total de livros lidos por menores de 10 anos: %d\n", qtdLivrosMenores);
	printf("qtd de mulheres que leram 5 ou mais: %d\n", qtdMulherLer5ouMais);
	printf("percentual de quem nao leu:  %.2f%%\n", percentual);
	
	return 0;
}