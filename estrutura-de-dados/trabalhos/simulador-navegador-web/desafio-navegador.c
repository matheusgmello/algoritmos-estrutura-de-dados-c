/*
Colégio Politécnico da UFSM
Sistemas para Internet
Disciplina: Estruturas de Dados
Exercício de Estrutura de Dados: Simulador de Navegador Web
Objetivo: desenvolver um programa que simule duas funcionalidades essenciais de um navegador
web: o histórico de navegação (botão "voltar") e uma fila de downloads. O exercício visa aplicar os
conceitos de Pilha (LIFO) e Fila (FIFO) em um contexto prático e familiar.
Cenário: todo navegador web precisa gerenciar o histórico de páginas visitadas para permitir que o
usuário volte à página anterior. Quando você clica em um link, a página atual é "guardada" para que
você possa voltar a ela. Essa funcionalidade é um exemplo clássico de uma Pilha: a última página que
você visitou é a primeira para a qual você retorna ao clicar em "voltar".
Paralelamente, quando você solicita o download de vários arquivos, o navegador os adiciona a uma
lista e os baixa um após o outro, na ordem em que foram solicitados. Essa é uma aplicação perfeita de
uma Fila: o primeiro arquivo que você pediu para baixar é o primeiro a ser processado.
Requisitos (Versão em C):
Parte 1: implementação das Estruturas de Dados. As seguintes estruturas devem ser implementadas
com listas encadeadas para gerenciar a memória dinamicamente.
1. Defina as Estruturas (structs):
○ struct No: Contendo um campo para os dados (ex: char url[200]) e um
ponteiro para o próximo nó.
○ struct Pilha: Contendo um ponteiro para o nó do topo.
○ struct Fila: Contendo ponteiros para o inicio e o fim da fila.
2. Implemente as Funções da Pilha (Histórico):
○ Pilha* criarHistorico(): Aloca e inicializa uma pilha vazia.
○ void salvarURL(Pilha* historico, char* url): Adiciona uma URL
ao topo da pilha (histórico).
○ char* voltarPagina(Pilha* historico): Remove e retorna a URL do
topo da pilha. Retorna NULL se o histórico estiver vazio.
○ int historicoVazio(Pilha* historico): Verifica se a pilha está vazia.
○ void liberarHistorico(Pilha* historico): Libera toda a memória
alocada para a pilha.
3. Implemente as Funções da Fila (Downloads):
○ Fila* criarFilaDownloads(): Aloca e inicializa uma fila vazia.
○ void adicionarDownload(Fila* downloads, char* arquivo):
Adiciona o nome de um arquivo ao final da fila de downloads.
○ char* processarDownload(Fila* downloads): Remove e retorna o
nome do arquivo do início da fila. Retorna NULL se não houver downloads
pendentes.
○ int filaDownloadsVazia(Fila* downloads): Verifica se a fila está vazia.
Colégio Politécnico da UFSM
Sistemas para Internet
Disciplina: Estruturas de Dados
○ void liberarFilaDownloads(Fila* downloads): Libera toda a
memória alocada para a fila.
Parte 2: simulação do Navegador. Crie a função main que simula a interação do usuário com o
navegador.
● Mantenha uma variável para a página atual (ex: char paginaAtual[200]).
● Apresente um menu com as seguintes opções:
1. Navegar para nova URL:
■ Pede ao usuário para digitar uma nova URL.
■ A paginaAtualantiga é salva no histórico (usando salvarURL).
■ A nova URL se torna a paginaAtual.
2. Voltar página:
■ Chama a função voltarPagina.
■ Se o retorno não for NULL, essa URL se torna a paginaAtual.
■ Se for NULL, informa que não há histórico para voltar.
3. Adicionar download:
■ Pede ao usuário o nome de um arquivo (ex: "documento.pdf").
■ Adiciona o arquivo à fila de downloads.
4. Executar próximo download:
■ Chama processarDownload.
■ Se o retorno não for NULL, exibe uma mensagem como "Baixando arquivo:
[nome do arquivo]... Concluído!".
■ Caso contrário, informa que não há downloads na fila.
5. Ver histórico: Mostra o conteúdo da pilha de histórico.
6. Ver fila de downloads: Mostra o conteúdo da fila de downloads.
7. Sair: Libera a memória de ambas as estruturas antes de encerrar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char url[200];
    struct no *prox;
} no;

typedef struct pilha {
    no *topo;
} pilha;

typedef struct fila {
    no *inicio;
    no *fim;
} fila;

pilha* criarHistorico() {
    pilha *historicoLocal = (pilha*) malloc(sizeof(pilha));
    historicoLocal->topo = NULL;
    return historicoLocal;
}

void salvarURL(pilha* historico, char* url) {
    no *novo = (no*) malloc(sizeof(no));
    strcpy(novo->url, url);
    novo->prox = historico->topo;
    historico->topo = novo;
}

char* voltarPagina(pilha* historico) {
    if (historico->topo == NULL) {
    	return NULL;	
	}
    no *temporario = historico->topo;
    historico->topo = temporario->prox;
    char *url = (char*) malloc(strlen(temporario->url)+1); // poderia ter usado sizeof
    strcpy(url, temporario->url);
    free(temporario);
    return url;
}

int historicoVazio(pilha* historico) {
    return (historico->topo == NULL);
}

void liberarHistorico(pilha* historico) {
    no *atual = historico->topo;
    while (atual != NULL) {
        no *temporario = atual;
        atual = atual->prox;
        free(temporario);
    }
    free(historico);
}

void verHistorico(pilha* historico) {
    no *atual = historico->topo;
    if (atual == NULL) {
        printf("Historico vazio\n");
        return;
    }
    printf("Historico:\n");
    while (atual != NULL) {
        printf("- %s\n", atual->url);
        atual = atual->prox;
    }
}

fila* criarFilaDownloads() {
    fila *filaLocal = (fila*) malloc(sizeof(fila));
    filaLocal->inicio = NULL;
    filaLocal->fim = NULL;
    return filaLocal;
}

void adicionarDownload(fila* downloads, char* arquivo) {
    no *novo = (no*) malloc(sizeof(no));
    strcpy(novo->url, arquivo);
    novo->prox = NULL;
    if (downloads->fim == NULL) {
        downloads->inicio = novo;
        downloads->fim = novo;
    } else {
        downloads->fim->prox = novo;
        downloads->fim = novo;
    }
}

char* processarDownload(fila* downloads) {
    if (downloads->inicio == NULL){
    	return NULL;
	}
    no *temporario = downloads->inicio;
    downloads->inicio = temporario->prox;
    
    if (downloads->inicio == NULL) {
    	downloads->fim = NULL;
	}
	
    char *arquivo = (char*) malloc(strlen(temporario->url)+1); // poderia usar sizeof
    strcpy(arquivo, temporario->url);
    free(temporario);
    return arquivo;
}

int filaDownloadsVazia(fila* downloads) {
    return (downloads->inicio == NULL);
}

void liberarFilaDownloads(fila* downloads) {
    no *atual = downloads->inicio;
    while (atual != NULL) {
        no *temporario = atual;
        atual = atual->prox;
        free(temporario);
    }
    free(downloads);
}

void verFilaDownloads(fila* downloads) {
    no *atual = downloads->inicio;
    if (atual == NULL) {
        printf("Fila de downloads vazia\n");
        return;
    }
    printf("Fila de downloads:\n");
    while (atual != NULL) {
        printf("- %s\n", atual->url);
        atual = atual->prox;
    }
}

int main() {
    pilha *historico = criarHistorico();
    fila *downloads = criarFilaDownloads();
    char paginaAtual[200] = "pagina_inicial";
    int opcao;
    char entrada[200];

    do {
    	
        printf("\nPagina atual: %s\n", paginaAtual);
        printf("1 - Navegar para nova URL\n");
        printf("2 - Voltar pagina\n");
        printf("3 - Adicionar download\n");
        printf("4 - Executar proximo download\n");
        printf("5 - Ver historico\n");
        printf("6 - Ver fila de downloads\n");
        printf("7 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        fflush(stdin); 

        if (opcao == 1) {
            printf("Digite a nova URL: ");
            gets(entrada); 
            salvarURL(historico, paginaAtual);
            strcpy(paginaAtual, entrada);
        }
        else if (opcao == 2) {
            char *url = voltarPagina(historico);
            if (url == NULL) {
                printf("Nao ha historico para voltar\n");
            } else {
                strcpy(paginaAtual, url);
                free(url);
            }
        }
        else if (opcao == 3) {
            printf("Digite o nome do arquivo: ");
            gets(entrada); 
            adicionarDownload(downloads, entrada);
        }
        else if (opcao == 4) {
            char *arq = processarDownload(downloads);
            if (arq == NULL) {
                printf("Nao ha downloads na fila\n");
            } else {
                printf("Baixando arquivo: %s... Concluido!\n", arq);
                free(arq);
            }
        }
        else if (opcao == 5) {
            verHistorico(historico);
        }
        else if (opcao == 6) {
            verFilaDownloads(downloads);
        }
        

    } while (opcao != 7);

    liberarHistorico(historico);
    liberarFilaDownloads(downloads);
    return 0;
}
