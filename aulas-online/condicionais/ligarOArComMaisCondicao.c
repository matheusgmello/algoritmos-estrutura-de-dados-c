#include <stdio.h>

int main(){
	
	float tempGraus;
	
	printf("qual a tempertura de hj: ");
	scanf("%f", &tempGraus);
	
	if (tempGraus > 30){
		printf("ligue o ar condicionado no 21");
	} else if (tempGraus < 10) {
		printf("ligar o ar condicionado no 28");
	} else {
		printf("nao liga porra nenhuma");
	}
	
	
	return 0;
}