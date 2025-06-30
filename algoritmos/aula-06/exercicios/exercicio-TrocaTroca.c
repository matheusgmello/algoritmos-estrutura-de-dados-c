/*
3. Desenvolva um algoritmo com uma função para receber três valores numéricos A, B e C, e trocá-los
entre as variáveis de forma que, ao final, a variável A possua o maior valor e a variável C o menor.
*/
#include <stdio.h>

void trocaTroca(){
	int a,b,c;
	int temp;
	
	printf("digite o valor de A: ");
	scanf("%d",&a);
	printf("digite o valor de B: ");
	scanf("%d",&b);
	printf("digite o valor de C: ");
	scanf("%d",&c);
	
 	if (a < b) { // se A for menor que B, troque os valores
	  	temp = a; 
		a = b; 
		b = temp; 
	 	}
	  
    if (a < c) { // se A for menor que C, troque os valores
		temp = a; 
		a = c; 
		c = temp; 
		}
	
    if (b < c) { // se B for menor que C, troque os valores
		temp = b;
		b = c; 
		c = temp; 
		}
	
	
	printf("o valor de A eh: %d\n", a);
	printf("o valor de C eh: %d\n", c);
}

int main(){
	
	trocaTroca();
	return 0;
}