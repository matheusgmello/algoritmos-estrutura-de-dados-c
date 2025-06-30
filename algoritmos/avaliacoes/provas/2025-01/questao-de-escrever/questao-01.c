#include <stdio.h>


int verifica(int senhaC, int senhaD){
	
	if (senhaC == senhaD){
		return 1;
	}
	else {
		return 0;
	}
}

int main(){
	
	int senhaCorreta = 123;
	int i;
	int senhaDigitada;
	int resultado;
	
	printf("digite sua senha: ");
	for (i =0;i<5;i++){
		scanf("%d", &senhaDigitada);
		resultado = verifica(senhaCorreta, senhaDigitada);
		if (resultado == 1){
			printf("bem vindo a rede social\n");
			printf("numero de tentativas: %d ", i+1);
			break;
		} else{
			printf("tente novamente!!!\n");
		}
	}
	
	if (i == 5 && resultado == 0){
		printf("acesso bloqueado!!!!\n");
	}
	
	return 0;
}