/*
A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes, coletando dados sobre o
salário e número de filhos. Faça algoritmo com uma função que leia esses dados para um número
não determinado de pessoas e apresente a média de salário da população, a média do número de
filhos, o maior salário e o percentual de pessoas com salário até R$350,00.

percentual de salario até 350 -> feito
maior salario -> Feito
media de filhos > todo
media de salario -> todo

*/
#include <stdio.h>
#include <stdlib.h>

void pesquisaPrefeitura(){
	
	int qntdFilhos = 0, totalDeFilhos = 0, pessoas = 0, i;
    float salario = 0, totalDeSalarios = 0, maiorSalario = 0, qtdPessoasSalarioAte350 = 0;
    float mediaDeSalario = 0, mediaDeFilhos = 0, percentualSalario350 = 0;
    char opcao;
    
	
	while(1){
		printf("digite seu salario: ");
		scanf("%f", &salario);
		
		if (salario < 0){
			printf("salario invalido!, tente novamente\n");
			continue;
		}
		
		printf("digite quantos filhos voce tem: ");
		scanf("%d", &qntdFilhos);
		
		if (qntdFilhos < 0){
			printf("quantia invalida digite novamente\n");
			continue;
		}
		system("cls");
		
		pessoas++;
		
		totalDeSalarios += salario;
        totalDeFilhos += qntdFilhos;
        
        if (salario <= 350.00){
			qtdPessoasSalarioAte350++;
		}
		
		if (salario > maiorSalario){
			maiorSalario = salario;
		}
		
		printf("Deseja continuar? (s ou n): ");
		scanf(" %c", &opcao);
		
		if (opcao == 'n' || opcao == 'N'){
			break;
		}
	}
		
	if (pessoas > 0){
		mediaDeFilhos = (float)totalDeFilhos / pessoas;
		mediaDeSalario = totalDeSalarios / pessoas;
		percentualSalario350 = (qtdPessoasSalarioAte350 / pessoas) * 100;
	} else {
		printf("nenhuma pessoa participou da pesquisa\n");
	}
	
	system("cls");
	
	printf("quantas pessoas participaram da pesquisa: %d\n", pessoas);
	printf("maior salario eh: %.2f\n", maiorSalario);
	printf("a media de filhos foi: %.2f\n", mediaDeFilhos);
	printf("a media de salarios foi: %.2f\n", mediaDeSalario);
	printf("percentual de pessoas com salario ate 350R$ foi de: %.2f%%\n", percentualSalario350);
	
}

int main(){
	
	pesquisaPrefeitura();
	
	return 0;
}