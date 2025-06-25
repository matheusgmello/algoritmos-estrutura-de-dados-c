#include<stdio.h>

void quadradoMagico(int m[3][3]){
	int i, j, s[7];
	for(i=0; i<7; i++){
		s[i] = 0;
	}
	
	int k = 0;
	//soma linhas
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(i == j){
				s[6] += m[i][j]; 
			}
			s[k] += m[i][j]; 
		}
		k++;
	}
	
	//soma colunas
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			s[k] += m[j][i]; 
		}
		k++;
	}
	
	int verifica=0;
	
	for(i=0; i<6; i++){
		if(s[i] == s[i+1]){
			verifica++;
		}
	}
	
	if(verifica == 6){
		printf("Quadrado magico \n");
	}
	else{
		printf("Nao eh quadrado magico\n");
	}
	for(i=0; i<7; i++){
		printf("%d\t", s[i]);
	}
	
	
	
}

int main(){
	//int m[3][3] = {10,20,30,40,50,60,70,80,90};
	int m[3][3] = {8,0,7,4,5,6,3,10,2};
	int i, j;
	printf("matriz: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d\t",m[i][j]); 
		}
		printf("\n");
	}
	printf("\n");
	quadradoMagico(m);
	
  return 0;
}