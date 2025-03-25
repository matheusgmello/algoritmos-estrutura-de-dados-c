#include <stdio.h>

int main(){
	
	int codigo;
	
	printf("qual o codigo do produto: ");
	scanf("%d", &codigo);
	
	switch(codigo){
		case 1:
			printf("produto sem lactose\n");
			break;
		case 2:
			printf("produto sem gluten\n");
			break;
		case 3:
			printf("produto sem farinha\n");
			break;
		case 4:
			printf("produto vencido\n");
			break;
		default:
			printf("codigo invalido trouxa\n");
	}
	
	return 0;
}