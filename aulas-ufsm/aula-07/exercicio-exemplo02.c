#include <stdio.h>

void somaPrimeiroEUltimo(){
	
	int elementos[5];
	int i;
	
	for (i=0;i<5;i++){
		scanf("%d", &elementos[i]);
	}
	
	int soma = elementos[0] + elementos[4];
	
	printf("soma dos ultimos elementos eh: %d", soma);
}

int main(){
	
	somaPrimeiroEUltimo();
	
	return 0;
}