#include <stdio.h>

int main(){
	int abacates;
	float total;
	
	printf("digite o total de abacates comprado pelo cliente: ");
	scanf("%d", &abacates);
	
	
	if ( abacates <= 12 ){
		total = abacates * 1.0;
	} else if (abacates <= 25){
		total = abacates * 0.90;
	} else{
		total = abacates * 0.75;
	}
	
	printf("comprdo %d abacates por %f", abacates, total);
	
	
	return 0;
}