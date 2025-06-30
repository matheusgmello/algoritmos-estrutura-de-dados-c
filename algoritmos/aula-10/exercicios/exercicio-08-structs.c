/*
Uma loja de calçados possui um cadastro de até 1000 peças de reposição em seu estoque.
Para cada peça são armazenados os seguintes dados: código da peça; preço unitário;
descrição da peça; e quantidade disponível em estoque. Você deve elaborar um programa
para:
a) Ler certa quantidade de peças para o cadastro. Considere que o código -999 encerra a
entrada de dados;
b) Exibir uma listagem das peças que possuem menos de X unidades, onde X é uma
quantidade fornecida pelo usuário.
*/

#include <stdio.h>
#include <string.h>

#define quantia 1000

struct repositorio {
	
	int codigo;
	float precoUnitario;
	char descricao[50];
	int estoque;
	
};

int main(){
	
	struct repositorio eny[quantia];
	
	int i = 0 , contPecas =0, x = 0;
	
	while(1){
		
		printf("digite o codigo da peca (-999 para sair): ");
	    scanf("%d", &eny[i].codigo);
	
	    if (eny[i].codigo == -999) {
	        break;
	    }
	
		printf("qual o preco unitario: ");
		scanf("%f", &eny[i].precoUnitario);
		fflush(stdin);
		
		printf("descricao: ");
		gets(eny[i].descricao);
		fflush(stdin);
		
		printf("quantia no estoque: ");
		scanf("%d", &eny[i].estoque);
		fflush(stdin);
		
		i++;
	} 
	
	printf("\n");
	
	printf("digite um valor para lim: ");
	scanf("%d", &x);
	for (int j=0; j<i; j++){
		if (eny[j].estoque < lim){
			printf("codigo %d\n", eny[j].codigo);
			printf("preco %.2f\n", eny[j].precoUnitario);
			printf("descricao %s\n", eny[j].descricao);
			printf("estoque %d\n", eny[j].estoque);
		}
	}

	
	return 0;
}