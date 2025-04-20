#include <stdio.h>

void invertePosicoes(){
	int valores[6];
	int i;
	
	for (i=0; i < 6;i++){
		printf("digite um valor: ");
		scanf("%d", &valores[i]);		
	}
	
	for (i =5; i>=0;i--){
		
		printf("[%d] = %d\n",i ,valores[i]);
	}
}

int main(){
	
	invertePosicoes();
	
	return 0;
}