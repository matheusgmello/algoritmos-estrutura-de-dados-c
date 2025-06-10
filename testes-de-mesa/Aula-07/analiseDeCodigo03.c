#include<stdio.h>
#include<time.h>

void imprime(int vetorCompleto[], int n){
	int i;
	for(i = 0; i< n; i++){
		printf("%d \t", vetorCompleto[i]);
	}
}

void preencheVetor(int va[], int totalElementos){
	int p, valor;
	printf("\n\nDigite um posicao: ");
	scanf("%d", &p);
	printf("Digite um valor: ");
	scanf("%d", &valor);
	if(p == totalElementos-1){
		va[p] = valor;
	}
	else{
		int k;
		for(k = totalElementos-1; k >= p; k--){
			va[k] = va[k-1];
		}
		va[p] = valor;
	}
	printf("\nimpressao final: ");
	imprime(va, totalElementos);
}

int main(){
	srand(time(NULL));
	int n;
	do{
		n = rand()%10;
	} while(n<2);
	printf("total de elementos do vetor: %d\n", n);
	
	int v[n], i;
	for(i=0; i<n-1; i++){
		v[i] = rand()%20;
	}
	printf("Vetor com um elemento a menos: \n");
	imprime(v,n-1);
	preencheVetor(v,n);
		
}