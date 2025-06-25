#include<string.h>
#include<stdio.h>

struct func {
	char nome[50];
	int dia, mes;
};

void cadastra(struct func f[2]){
	int i;
	for(i=0; i<2; i++){
		fflush(stdin);
		gets(f[i].nome);
		scanf("%d %d", &f[i].dia, &f[i].mes);
	}
}

void aniversariantes(struct func f[2]){
	int i, j, cont = 0;
	for(i=0; i<12; i++){
		printf("\nMes %d: \n", i+1);
		for(j=0; j<2; j++){
			if(i+1 == f[j].mes){
				puts(f[j].nome);
				printf("%d/%d\n\n",f[j].dia, f[j].mes);
			}	
		}
		if(cont == 0){
			printf("Sem aniversariantes nesse mes.\n");
		}
		cont = 0;
	}
}

int main(){
	struct func f[2];
	cadastra(f);
	aniversariantes(f);
	
	return 0;
}