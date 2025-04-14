/*
Desenvolva um algoritmo com uma função que recebe a idade de um nadador por parâmetro e
apresenta sua categoria de acordo com a tabela abaixo:
Idade Categoria
5 a 7 anos Infantil A
8 a 10 anos Infantil B
11-13 anos Juvenil A
14-17 anos Juvenil B
Maiores de 18 anos (inclusive) Adulto
*/

#include <stdio.h>

void qualCategoria(int idade){
	switch(idade){
		case 5 ... 7:{
			printf("sua categoria eh\ninfantil A\n");
			break;
		}
		case 8 ... 10: {
			printf("sua categoria eh\ninfantil B\n");
			break;
		}
		case 11 ... 13: {
			printf("sua categoria eh\njuvenil A\n");
			break;
		}
		case 14 ... 17: {
			printf("sua categoria eh\njuvenil B\n");
			break;
		}
		case 18 ... 60: {
			printf("sua categoria eh\nadulto \n");
			break;
		}
		default:{
			printf("voce n tem idade suficiente/ ou eh mt velho");
			break;
		}
	}
	
}

int main(){
	int idade;
	
	printf("qual tua idade: ");
	scanf("%d", &idade);
	
	qualCategoria(idade);
	
	return 0;
}