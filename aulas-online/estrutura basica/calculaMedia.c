#include <stdio.h>

int main(){
	
	float n1,n2, mediaFinal;
	
	printf("qual foi sua primeira nota: ");
	scanf("%f", &n1);
	
	printf("qual foi sua segunda nota: ");
	scanf("%f", &n2);
	
	mediaFinal = (n1+n2) /2 ;
	
	printf("sua media final foi %.2f", mediaFinal);
	
	
	return 0;
	
}