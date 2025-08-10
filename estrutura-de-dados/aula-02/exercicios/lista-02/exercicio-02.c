/*
Desenvolver um programa que possua a função alteraValores() para realizar a troca
dos valores de duas variáveis. Essa função recebe os endereços das variáveis passadas
pela função main(), armazenando-os nos ponteiros p1 e p2. Dentro da função, trocam-
se os conteúdos dos endereços, retornando para a função chamadora, onde deverão
ser impressos.
*/

#include <stdio.h>

void alteraValores(int *p1, int *p2){
	
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;	
}

int main(){
	
	int v1, v2;
	
	v1 = 10;
	v2 = 20;
	
	printf("antes de trocar\n");
	printf("%d\n", v1);
	printf("%d\n\n", v2);
	
	alteraValores(&v1, &v2);
	
	printf("depois de trocar\n");
	printf("%d\n", v1);
	printf("%d\n\n", v2);
	
	return 0;
}