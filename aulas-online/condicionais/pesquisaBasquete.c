#include <stdio.h>

int main(){
	
	int idade;
	float altura;
	
	printf("sua idade eh: ");
	scanf("%d", &idade);
	
	printf("sua altura eh: ");
	scanf("%f", &altura);
	
	if (idade >= 20 && altura >= 1.95){
		printf("voce esta apto a participar da pesquisa");
	} else {
		printf("tu nao esta apto a participar");
	}
	
	return 0;
}