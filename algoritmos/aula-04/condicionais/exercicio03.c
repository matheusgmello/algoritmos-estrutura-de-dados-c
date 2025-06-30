/*
Escrever um algoritmo que solicite a distância em km e o tempo de viagem em horas de um
automóvel e dizer se a velocidade média foi superior ao limite de 110km/h ou não.
*/

#include <stdio.h>
int main()
{
	float distanciaPercorrida, tempoDaViagem, velocidadeMedia;
	
	printf("qual foi a distancia percorrida?: ");
	scanf("%f", &distanciaPercorrida);
	
	printf("qual foi o tempo da viagem?: ");
	scanf("%f", &tempoDaViagem);
	
	velocidadeMedia = (distanciaPercorrida / tempoDaViagem);
	
	if (velocidadeMedia > 110){
		printf("velocidade media foi %2.f, esta acima do limite permitido (110Km/H)", velocidadeMedia);
	} else{
		printf("velocidade media foi %2.f, esta dentro do limite", velocidadeMedia);
	}

	return 0;	
}