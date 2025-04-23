/*Ler 5 elementos de um vetor e apresentá-los ao usuário.*/
#include <stdio.h>

void mostraValores(){
	
	int elementos[5];
	int i;
	
	for (i=0;i<5;i++){
		scanf("%d", &elementos[i]);
	}
	
	for (i=0; i<5;i++){
		printf("%d\n", elementos[i]);
	}
}

int main(){
	
	mostraValores();
	
	return 0;
}