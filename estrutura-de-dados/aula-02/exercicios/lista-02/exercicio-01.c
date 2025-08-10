/*
Faça um programa que receba dois valores e, utilizando ponteiros, retorne o maior e
menor deles. O programa deve ter um controle sobre valores iguais.
*/

#include <stdio.h>
void funcao(int a, int b, int *maior, int *menor){
	
	if (a> b){
		*maior = a;
		*menor = b;
	} else if(b > a){
		*maior = b;
    	*menor = a;
	} else {
		*maior = a; // Ou b, já que são iguais
    	*menor = b; // Ou a, já que são iguais
	}

}


int main(){
	
	int n1, n2;
	int menor, maior;
	
	scanf("%d", &n1);
	scanf("%d", &n2);
	
	funcao(n1,n2, &maior, &menor);
	
	
	if (n1 == n2){
		printf("iguais");
	} else {
		printf("menor: %d\n", menor);
		printf("maior: %d\n\n", maior);
	}
	
	return 0;
}