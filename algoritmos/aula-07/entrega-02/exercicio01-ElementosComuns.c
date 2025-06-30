/*
1. Ler 2 vetores, R de 5 elementos e S de 10 elementos. 
Gere um vetor X que possua os elementos comuns a R e a S. Considere que no mesmo vetor não haverá números repetidos. Escrever o vetor X.
*/ 

#include <stdio.h>

void elementosComuns();


int main(){
	
	elementosComuns();
	
	return 0;
}

void elementosComuns(){
	int vetorR[5];
	int vetorS[10];
	int vetorX[15];
	
	int i,j,k,tamanhoX=0;
	
	// Preenchendo os dois primeiros vetores
	for (i=0;i<5;i++){
		scanf("%d", &vetorR[i]);
	}
	
	printf("\n");
	
	for (i=0;i<10;i++){
		scanf("%d", &vetorS[i]);
	}
	
	// comparando elementos nos vetores
	
	for (i=0;i<5;i++){
		for(j=0;j < 10;j++){
			if (vetorR[i] == vetorS[j]){
				int igual = 0;
				for(k=0;k<tamanhoX;k++){
					if(vetorX[k]== vetorR[i]){
						igual = 1;
						break;
					}
				}
				if(!igual){
                    vetorX[tamanhoX] = vetorR[i];
                    tamanhoX++;
                }
			}
		}
	} 
	
	
	for (i=0;i<5;i++){
		printf("%d\t", vetorR[i]);
	}
	
	printf("\n");
	
	for (i=0;i<10;i++){
		printf("%d\t", vetorS[i]);
	}
	
	printf("\n");
	
	for (i=0;i<tamanhoX;i++){
		printf("%d\t", vetorX[i]);
	}
}