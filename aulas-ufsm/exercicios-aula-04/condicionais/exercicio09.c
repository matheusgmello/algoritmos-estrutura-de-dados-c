/*
9. Um professor resolveu considerar, para cálculo da média final do semestre, somente as duas
maiores notas das três provas realizadas pelos alunos. Para auxiliá-lo, deve-se fazer um algoritmo
que leia as três notas de um aluno e escreva a média aritmética considerando apenas as suas duas
maiores notas.
*/

#include <stdio.h>

int main(){
	
	float mediaFinal, notaUm, notaDois, notaTres;
	
	printf("qual foi sua primeira nota?: ");
	scanf("%f", &notaUm);
	
	printf("qual foi sua segunda nota?: ");
	scanf("%f", &notaDois);
	
	printf("qual foi sua terceira nota?: ");
	scanf("%f", &notaTres);
	
	if (notaUm <= notaDois && notaUm <= notaTres){
		mediaFinal = (notaDois + notaTres) / 2;
	} else if(notaDois <= notaUm && notaUm <= notaTres ){
		mediaFinal = (notaUm + notaTres) / 2;
	} else {
		mediaFinal = (notaUm + notaDois) / 2;
	}
	
	printf("A media eh %2.f\n", mediaFinal);
	
	return 0;
}