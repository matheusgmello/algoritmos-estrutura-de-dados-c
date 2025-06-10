/*
Desenvolva um algoritmo com um registro que contenha o nome do aluno, nota 1, nota 2, e média final. 
Faça a leitura dos valores dos campos e apresente ao usuário.
*/
#include <stdio.h>
#include <string.h>

struct materia{
	char nome[20];
	float nota1, nota2;
	float media;	
};

int main(){
	
	struct materia aluno;
	
	gets(aluno.nome);
	scanf("%f %f", &aluno.nota1, &aluno.nota2);
	aluno.media = (aluno.nota1  + aluno.nota2) / 2;
	printf("\n");
	puts(aluno.nome);
	
	printf("%.2f", aluno.media);
	
	return 0;
}
