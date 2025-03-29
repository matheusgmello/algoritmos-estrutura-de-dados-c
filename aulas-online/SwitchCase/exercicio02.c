#include <stdio.h>

int main(){
	
	int opcao;
	
	printf("digite a opcao: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			printf("1");
			break;
		case 2 ... 5:
			printf("teste");
			break;
		default:
			printf("ta invalido cabeca");
	}
	
	
	return 0;
}