#include <stdio.h>

int main(){
	
	int i, valor;
	
	printf("digite um valor: ");
	scanf("%d", &valor);
	
	for(i = 0; i <= valor; i++){
		
		printf("%d\n", i);
	}
	
	printf("segunda parte\n");
	for(i = valor; i >= 0; i--){
		
		printf("%d\n", i);
	}
	
	return 0;
}