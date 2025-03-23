#include <stdio.h>

int main(){
	
	int idade;
	
	printf("sua idade eh: ");
	scanf("%d", &idade);
	
	if(idade < 18 || idade > 65){
		printf("so eh permitido com um acompanhete no hospital");
	} else{
		printf("nao eh necessario acompanhante");
	}
	
	
	return 0;
}