#include <stdio.h>

int main(){
	
	float tempGraus;
	
	
	printf("qual a temperatura de hj: ");
	scanf("%f", &tempGraus);
	
	
	if (tempGraus > 30 || tempGraus < 10){
		printf("ta podendo ligar o ar");
	} else{
		printf("num pode ligar o ar");
	}
	
	return 0;
}