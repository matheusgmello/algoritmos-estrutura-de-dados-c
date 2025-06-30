/*
O índice de massa corporal (IMC) é calculado dividindo-se o peso de uma pessoa pela sua altura ao
quadrado. A partir do valor de IMC podemos classificar a pessoa quanto ao peso conforme os
intervalos apresentados a seguir (revista Galileu nov2004):

 imc = peso / (altura * altura)
*/

#include <stdio.h>

int main(){
	
	float altura, peso, imc;
	
	printf("qual eh sua altura?: ");
	scanf("%f", &altura);
	
	printf("qual eh seu peso?: ");
	scanf("%f", &peso);
	
	imc = peso / (altura * altura);
	
	if (imc < 18.5){
		printf("tu ta abaixo do peso");
	} else if (imc < 25){
		printf("tu ta normal");
	} else if (imc < 30) {
		printf("tu ta pre obeso");
	} else if (imc < 35){
		printf("obesidade nivel I");
	} else if (imc < 40){
		printf("obesidade nivel II");
	} else {
		printf("obesidade nivel III");
	}

	
	return 0;
}