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

// a) Mostrar na tela os valores de 1a10.
// b) O laco não sera executado nenhuma vez.
// c) o codigo não funciona corretamente.
// d) Mostrara na tela o valor 6.
// e) Mostrara a palavra count por 10 vezes.
