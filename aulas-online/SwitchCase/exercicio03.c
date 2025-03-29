#include <stdio.h>

int main(){
	
	int idadeDoAtleta;
	
	printf("digite sua idade: ");
	scanf("%d", &idadeDoAtleta);
	
	switch(idadeDoAtleta){
		case 1 ... 5:
			printf("atleta pre mirim");
			break;
		case 6 ... 10:
			printf("atleta mirim");
			break;
		case 11 ... 16:
			printf("atleta infantil");
			break;
		case 17 ... 20:
			printf("atleta jovem");
			break;
		case 21 ... 60:
			printf("atleta adulto");
			break;
		default:
			printf("idade nao aceita");
	}	
	return 0;
}