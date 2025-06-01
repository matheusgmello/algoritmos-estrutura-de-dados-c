/*
Faça um algoritmo para realizar cadastro e consulta de informações sobre
automóveis usados na concessionária FastCar, onde é apresentado o seguinte menu:
1. Cadastrar automóvel
2. Consultar automóvel
3. Gerar relatório
4. Sair do programa

Na opção 1 o usuário cadastra a placa, descrição, fabricante, cor, ano de
fabricação e preço.

Na opção 2 o usuário deve informar uma placa e o algoritmo deve exibir as
informações sobre o veículo.
Caso não encontre, deve exibir uma mensagem informando isso.

A opção 3 deve gerar um relatório contendo todos os dados dos automóveis
cadastrados. Considere um máximo de 12 veículos no cadastro.

*/
/*
algoritmo para cadastro e consulta de informacoes sobre automoveis usados
concessionaria fastcar
*/

#include <stdio.h>
#include <string.h>

struct fastcar {
    char placa[7];
    char descricao[50];
    char fabricante[20];
    char cor[10];
    int ano_de_fabricacao;
    float preco_do_veiculo;
};

int main() {
    struct fastcar carros[12];
    int quantidade_de_cadastro = 0;
    int opcao, i;
    char placa_consulta[10];

    do {
        printf("\n-------------------------------\n");
        printf("bem vindo ao menu da fastcar\n");
        printf("-------------------------------\n");
        printf("1 - cadastrar veiculo\n");
        printf("2 - consultar veiculo\n");
        printf("3 - relatorio de veiculos\n");
        printf("4 - sair\n");
        printf("escolha a opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            if (quantidade_de_cadastro < 12) {
                printf("\ninforme a placa: ");
                gets(carros[quantidade_de_cadastro].placa);
                fflush(stdin);

                printf("fabricante: ");
                gets(carros[quantidade_de_cadastro].fabricante);
                fflush(stdin);

                printf("descricao do veiculo: ");
                gets(carros[quantidade_de_cadastro].descricao);
                fflush(stdin);

                printf("cor do carro: ");
                gets(carros[quantidade_de_cadastro].cor);
                fflush(stdin);

                printf("ano de fabricacao: ");
                scanf("%d", &carros[quantidade_de_cadastro].ano_de_fabricacao);
                fflush(stdin);

                printf("valor do carro: ");
                scanf("%f", &carros[quantidade_de_cadastro].preco_do_veiculo);
                fflush(stdin);

                quantidade_de_cadastro++;
                printf("veiculo cadastrado com sucesso!\n");

            } else {
                printf("limite de cadastro atingido\n");
            }

        } else if (opcao == 2) {
            if (quantidade_de_cadastro == 0) {
                printf("nenhum veiculo cadastrado\n");
            } else {
                printf("\ndigite a placa para consulta: ");
                gets(placa_consulta);

                int encontrou = 0;

                for (i = 0; i < quantidade_de_cadastro; i++) {
                    if (strcmp(carros[i].placa, placa_consulta) == 0) {
                        printf("\n--- veiculo encontrado ---\n");
                        printf("placa: %s\n", carros[i].placa);
                        printf("fabricante: %s\n", carros[i].fabricante);
                        printf("descricao: %s\n", carros[i].descricao);
                        printf("cor: %s\n", carros[i].cor);
                        printf("ano: %d\n", carros[i].ano_de_fabricacao);
                        printf("valor: %.2f\n", carros[i].preco_do_veiculo);
                        encontrou = 1;
                        break;
                    }
                }
                if (!encontrou) {
                    printf("veiculo nao encontrado\n");
                }
            }

        } else if (opcao == 3) {
            if (quantidade_de_cadastro == 0) {
                printf("nenhum veiculo cadastrado\n");
            } else {
                printf("\n--- relatorio de veiculos ---\n");
                for (i = 0; i < quantidade_de_cadastro; i++) {
                    printf("\nveiculo %d:\n", i + 1);
                    printf("placa: %s\n", carros[i].placa);
                    printf("fabricante: %s\n", carros[i].fabricante);
                    printf("descricao: %s\n", carros[i].descricao);
                    printf("cor: %s\n", carros[i].cor);
                    printf("ano: %d\n", carros[i].ano_de_fabricacao);
                    printf("valor: %.2f\n", carros[i].preco_do_veiculo);
                }
            }

        } else if (opcao == 4) {
            printf("\nsaindo do programa...\n");
        } else {
            printf("\nopcao invalida\n");
        }

    } while (opcao != 4);

    return 0;
}
