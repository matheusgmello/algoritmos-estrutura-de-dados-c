#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr);
void update(int *p);

int main(){
		
	/*
	Ponteiros: 
	*ptr: o apontado por, conteudo do endereco da variavel que ponteiro aponta
	ptr: o endereco da variavel
	&ptr: o endereco do ponteiro
	*/
		
	int var = 15;
	int *ptr;
	
	ptr = &var;
	
	display(var,ptr);
	
	update(&var);
	
	printf("\n\n-----------------------------\n\n");
	
	display(var,ptr);
	
	printf("\n\ntermina...");
	return 0;
}

void display(int var, int *ptr){
	printf("valor de var: %d\n", var);
	printf("endereco de var: %d\n", &var);
	
	printf("\n");
	
	printf("conteudo/valor apontado por ponteiro: %d\n", *ptr);
	printf("endereco apontado de ponteiro: %d\n", ptr);
	
	printf("\n");
	
	printf("endereco real do ponteiro: %d\n ", &ptr);
	
}

void update(int *p){
	*p = *p+1;
}

