/*
2. Escrever uma função que leia 10 números inteiros e 
verifique quantos deles são ímpares.
*/
#include <stdio.h>
void verificaImpares(){
	
	int i, numerosDigitados =0, numerosImpares=0, numerosPares=0;
	
	for(i =0; i < 10;i++){
		printf("digite 10 numeros inteiros: ");
		scanf("%d", &numerosDigitados);
		
		if (numerosDigitados % 2 != 0){
			numerosImpares++;
		} else{
			numerosPares++;
		} 
			
	}
	printf("numeros impares digitados: %d\n", numerosImpares);
	printf("numeros pares digitados: %d", numerosPares);
}

int main(){
	
	verificaImpares();
	
	return 0;
}