/*
Suponha que você queira armazenar seus gastos mensais com água, energia elétrica e
telefone, referentes ao ano passado. 
Faça um algoritmo que leia estes gastos e depois:
mostre os meses em que houve mais gasto com água, luz e telefone e a média de gasto
com cada categoria.
*/
#include <stdio.h>
#include <string.h>

#define MES 12

struct gastos{
	
	float qtdAgua;
	float qtdEnergia;
	float qtdTelefone;
	
};

int main(){
	
	struct gastos mensal[MES];
	
	int i;
	float maiorAgua = 0, maiorLuz =0, maiorTelefone =0;
	float mediaDeLuz =0, mediaDeAgua=0, mediaDeTelefone =0;
	float somaAgua =0, somaLuz =0, somaTelefone=0;
	int mesAgua, mesLuz, mesTelefone;
	
	for (i=0;i<MES;i++){
		
		printf("digite o gasto de agua no mes em R$: ");
		scanf("%f", &mensal[i].qtdAgua);
		
		printf("digite o gasto de energia no mes em R$: ");
		scanf("%f", &mensal[i].qtdEnergia);
		
		printf("digite o gasto com telefone em R$: ");
		scanf("%f", &mensal[i].qtdTelefone);
		
		printf("\n");
	}
	
	for (i=0;i<MES;i++){
		if(maiorAgua < mensal[i].qtdAgua){
			maiorAgua = mensal[i].qtdAgua;
			mesAgua = i + 1;
		}
		
		if (maiorLuz < mensal[i].qtdEnergia){
			maiorLuz = mensal[i].qtdEnergia;
			mesLuz = i + 1;
		}
	
		if (maiorTelefone < mensal[i].qtdTelefone){
			maiorTelefone = mensal[i].qtdTelefone;
			mesTelefone = i + 1;
		}
		
		somaAgua = somaAgua + mensal[i].qtdAgua;
        somaLuz += mensal[i].qtdEnergia;
        somaTelefone += mensal[i].qtdTelefone;
		
	}
	
	printf("o maior gasto de agua: %.2f\nmes: %d\n", maiorAgua, mesAgua);
	printf("o maior gasto de luz: %.2f\nmes: %d\n", maiorLuz, mesLuz);
	printf("o maior gasto de telefonia: %.2f\nmes: %d\n", maiorTelefone, mesTelefone);
	
	printf("agua: %.2f\n", somaAgua / MES);
    printf("luz: %.2f\n", somaLuz / MES);
    printf("telefone: %.2f\n", somaTelefone / MES);
	
	
	return 0;
}