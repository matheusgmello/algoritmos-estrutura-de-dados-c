/*
Desenvolva um algoritmo que leia duas notas de um aluno e calcule a média aritmética. Depois,
apresente a mensagem “Aprovado”, caso a média seja maior ou igual a 7.0, ou “Reprovado” caso
seja menor que 7.0.
*/
#include <stdio.h>

int main()
{		
	float notaUM, notaDOIS, mediaFinal;
	
	printf("qual foi sua primeira nota?: ");
	scanf("%f", &notaUM);
	
	printf("qual foi sua segunda nota?: ");
	scanf("%f", &notaDOIS);
	
	mediaFinal = (notaUM + notaDOIS) / 2;
	
	if (mediaFinal >= 7.0){
		printf("parabens vc foi aprovado, sua media foi de %2.f", mediaFinal);
	} else{
		printf("tu reprovou bobao, sua media foi de %2.f", mediaFinal);
	}
	
		
	return 0;
}