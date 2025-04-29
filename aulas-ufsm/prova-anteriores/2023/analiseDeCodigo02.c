#include <stdio.h>

void exercicioProva(int count){
	do {
		printf("%d", count+1);
		count++;
	} while ( count > 10);
}

int main(){
	
	exercicioProva(0);
	
	return 0;
}