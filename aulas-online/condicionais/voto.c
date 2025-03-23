#include <stdio.h>

int main(){
	
	int idade;
	
	printf("digite sua idade: ");
	scanf("%d", &idade);
	
	if (idade >= 18 && idade < 70){
		printf("Voto obrigatorio\n");
	} else{
		printf("Voto nao obrigatorio");
	}
	
	
	return 0;
}