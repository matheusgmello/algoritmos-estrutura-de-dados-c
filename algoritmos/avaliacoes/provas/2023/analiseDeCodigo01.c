#include <stdio.h>

void ExercicioProva(int testa, int par, int total){  // testa = 2, par = 0, total = 5
	int i;
	for(i=total;i>0;i--){
		if (i % testa == 0){
			par++;
		}
		par--;
	}
	int z = par + 1;
	printf("%d\n", par);
	printf("%d", i);
}

int main(){
	
	ExercicioProva(2,0,5);
	
	return 0;
}

// Qual o valor da varivel par na linha 11, justifique:



// Qual o valor da variavel i na linha 12, justifique: