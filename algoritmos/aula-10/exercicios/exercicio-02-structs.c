/*
Desenvolva um algoritmo para ler o nome, sexo e idade de 10 pessoas. Em seguida,
solicitar ao usuário que digite um sexo e exibir o nome e idade das pessoas que possuem
aquele sexo.
*/
#include <stdio.h>
#include <string.h>

struct dados {
	
	char nome[20];
	int idade;
	char sexo;
	
};


int main(){
	
	struct dados pessoas[10];
	
	int i = 0, encontrou = 0;
	char sexoEscolhido;
	
	for (i=0;i<9;i++){
		
		printf("digite seu nome: ");
		gets(pessoas[i].nome);
		fflush(stdin);
		
		printf("digite sua idade: ");
		scanf("%d", &pessoas[i].idade);
		
		fflush(stdin);
		printf("digite seu sexo (M/F): ");
		scanf("%c", &pessoas[i].sexo);
		fflush(stdin);
		
	}
	
	
	do {
		printf("digite um sexo: ");
		scanf("%c", &sexoEscolhido);
		fflush(stdin);
	} while (sexoEscolhido != 'F' && sexoEscolhido != 'f' && sexoEscolhido != 'M' && sexoEscolhido != 'm');

	
	
	for (i=0;i<9;i++){
		if (sexoEscolhido == pessoas[i].sexo){
			encontrou++;
			printf("\n");
			puts(pessoas[i].nome);
			printf("idade: %d\n", pessoas[i].idade);
			printf("sexo: %c\n", pessoas[i].sexo);
		}
		
	}
	
	if (encontrou == 0){
		printf("nenhuma pessoa foi encontrada com esse sexo");
	}
	
	
	return 0;
}