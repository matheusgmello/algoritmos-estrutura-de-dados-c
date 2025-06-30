/*
8. Crie um programa que leia duas strings (A e B) e mostre uma terceira string (C) formada
pelos caracteres contidos em A e B de forma intercalada. Exemplo: Se A = “quarta” e B =
“segunda”, a resposta obtida deverá ser “qsueagrutnada”.


A = ARROZ
B = FRANGO

C = AFRRRAONZGO
*/

#include <stdio.h>
#include <string.h>


int main(){

	char a[10];
	char b[10];
	char c[20];
	int i;
	
	gets(a);
	fflush(stdin);
	gets(b);
	
	for (i=0;i<9;i++){
		c[2*i] = a[i];
		c[2*i + 1] = b[i];
	}
	
	c[18] = '\0';
	
	puts(c);
	
	return 0;
}