#include <stdio.h>


int verifica(int temperatura){
	
	if (temperatura < 15){
		return -1;
	}
	else if (temperatura >= 15 && temperatura <= 25){
		return 0;
	} else{
		return 1;
	}
}

int main(){
	
	int i;
	int vet[7];
	int resultado;
	int qtdfrio=0, qtdquente=0, qtdmorno=0;
	float media, soma;
	
	for (i =0;i<7;i++){
		printf("digite a temperatura: ");
		scanf("%d", &vet[i]);
	}
	
	for (i = 0; i < 7; i++) {
        resultado = verifica(vet[i]);

        switch (resultado) {
            case -1:
                qtdfrio++;
                break;
            case 0:
                qtdmorno++;
                soma += vet[i]; 
                break;
            case 1:
                qtdquente++;
                break;
        }
    }
	
	if (qtdmorno > 0) {
        media = soma / qtdmorno;
    } else {
        media = 0;
    }
	
	printf("temp frio: %d\n", qtdfrio);
	printf("temp morno: %d\n", qtdmorno);
	printf("temp quente: %d\n", qtdquente);
	printf("media: %2.f\n", media);
	
	return 0;
}