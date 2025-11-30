/*
Navegação em um Sistema de Streaming usando Grafos Neste trabalho, você irá implementar operações sobre grafos representados por matriz de adjacência, simulando o fluxo de navegação entre páginas
 de um sistema de streaming. 
 O foco é compreender a estrutura de grafos, manipular matrizes e aplicar noções de conectividade, graus e buscas em largura (BFS). 
 Considere um sistema fictício de streaming que possui as seguintes páginas: INÍCIO CATEGORIAS VÍDEO PERFIL HISTÓRICO BUSCA CONFIG Cada página é um nó do grafo, e cada clique do usuário 
 (isto é, navegação entre páginas) é uma aresta direcionada. 
 Você receberá um código base (disponível no Moodle) contendo a matriz de adjacência preenchida, 
 os nomes das páginas e funções auxiliares para impressão e medidas básicas. Tarefas Obrigatórias: implementar, no código fornecido, as funcionalidades abaixo. 
 Todas as tarefas devem operar sobre a matriz de adjacência já carregada no código. 
 1) Exibir a matriz de adjacência formatada (0,5 ponto): aprimore a função já fornecida para exibir o grafo em formato 
 de tabela legível. Requisitos: linhas e colunas nomeadas; alinhamento adequado; não alterar a matriz. 
 2) Listar páginas alcançáveis a partir de uma página inicial definida pelo usuário (1,0 ponto): implemente uma função que, usando Busca em Largura: Receba uma página inicial (índice inteiro); 
 Percorra o grafo; Exiba todas as páginas que podem ser acessadas a partir dela (mostrar o nome das páginas, não o índice da matriz). Atenção: Lembre-se que os nós de um grafo devem ser visitados uma 
 única vez. 
 3) Identificar páginas populares (0,5 ponto): Uma página é considerada popular se recebe mais de 1 acesso (grau de entrada > 1). 
 Você deve calcular o grau de entrada de cada página e exibir somente as páginas populares. 
 4) Listar páginas sem saída (grau de saída = 0) (0,5 ponto): Exiba todas as páginas cujo grau de saída é zero. Isso ajuda a identificar "becos sem saída" na navegação do sistema. 
 5) Verificar se o grafo é conexo (0,5 ponto): Utilizando a matriz de adjacência, implemente uma função que determine se todos os sites da rede estão conectados, isto é, se é possível 
 alcançar qualquer página a partir de qualquer outra, considerando apenas a existência de links (não é necessário considerar direção). 
 Caso todas as páginas pertençam ao mesmo conjunto de vértices alcançáveis, o grafo é conexo; 
 Utilizar o arquivo navegaStreaming.c disponível no moodle como base para a realização da atividade.
*/

// trabalho isaac e matheus
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 7

/*
   Legenda para ordem dos nos:
   0 - inicio
   1 - categorias
   2 - video
   3 - perfil
   4 - historico
   5 - busca
   6 - config
*/

/*
   Exibe a matriz de adjacencia,
   incluindo nomes das colunas e linhas.
*/
void imprimeGrafo(int grafo[N][N], char paginas[N][20]) {
    int i, j;

    printf("\t");
    for(i = 0; i < N; i++) {
        printf("%10s ", paginas[i]);
    }
    printf("\n");

    for(i = 0; i < N; i++) {
        printf("%10s", paginas[i]);
        for(j = 0; j < N; j++) {
            printf("%10d", grafo[i][j]);
        }
        printf("\n");
    }
}

/*
	busca em largura para exibir todas
   as paginas que podem ser alcancadas a partir de uma
   pagina inicial fornecida pelo usuario.
*/
void listarAlcancaveis(int grafo[N][N], char paginas[N][20], int paginaIniciar) {
    int visitado[N];
    int fila[N];
    int inicioFila = 0;
    int fimFila = 0;
    int i, j;

    for(i = 0; i < N; i++) {
        visitado[i] = 0;
    }

    fila[fimFila] = paginaIniciar;
    fimFila++;
    visitado[paginaIniciar] = 1;

    printf("Paginas alcancaveis a partir de %s:\n", paginas[paginaIniciar]);

    while(inicioFila < fimFila) {
        int atual = fila[inicioFila];
        inicioFila++;

        for(j = 0; j < N; j++) {
            if(grafo[atual][j] == 1 && visitado[j] == 0) {
                visitado[j] = 1;
                fila[fimFila] = j;
                fimFila++;
                printf("- %s\n", paginas[j]);
            }
        }
    }
}


/*
   calcula o grau de entrada de cada pagina e exibe
   apenas aquelas que possuem grau maior que 1,
   classificadas como paginas populares.
*/
void listarPaginasPopulares(int grafo[N][N], char paginas[N][20]) {
    int i, j;

    printf("Paginas populares:\n");

    for(i = 0; i < N; i++) {
        int grauEntrada = 0;

        for(j = 0; j < N; j++) {
            if(grafo[j][i] == 1) {
                grauEntrada++;
            }
        }

        if(grauEntrada > 1) {
            printf("- %s (grau de entrada = %d)\n", paginas[i], grauEntrada);
        }
    }
}

/*
   Identifica paginas com grau de saida zero,
   ou seja, paginas que nao possuem links para
   outras paginas do sistema.
*/
void listarPaginasSemSaida(int grafo[N][N], char paginas[N][20]) {
    int i, j;

    printf("Paginas sem saida:\n");

    for(i = 0; i < N; i++) {
        int grauSaida = 0;

        for(j = 0; j < N; j++) {
            if(grafo[i][j] == 1) {
                grauSaida++;
            }
        }

        if(grauSaida == 0) {
            printf("- %s\n", paginas[i]);
        }
    }
}

/* 
   Determina se o grafo eh conexo ignorando direcao.
   Para isso, eh criada uma versao nao direcionada
   da matriz, e realizada uma busca em largura a partir do no 0.
*/
int verificarConexo(int grafo[N][N]) {
    int grafoNaoDirecionado[N][N];
    int visitado[N];
    int fila[N];
    int inicioFila = 0;
    int fimFila = 0;
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(grafo[i][j] == 1 || grafo[j][i] == 1) {
                grafoNaoDirecionado[i][j] = 1;
            } else {
                grafoNaoDirecionado[i][j] = 0;
            }
        }
    }

    for(i = 0; i < N; i++) {
        visitado[i] = 0;
    }

    fila[fimFila] = 0;
    fimFila++;
    visitado[0] = 1;

    while(inicioFila < fimFila) {
        int atual = fila[inicioFila];
        inicioFila++;

        for(j = 0; j < N; j++) {
            if(grafoNaoDirecionado[atual][j] == 1 && visitado[j] == 0) {
                visitado[j] = 1;
                fila[fimFila] = j;
                fimFila++;
            }
        }
    }

    for(i = 0; i < N; i++) {
        if(visitado[i] == 0) {
            return 0;
        }
    }

    return 1;
}



int main() {
      // Nomes das páginas do sistema de streaming
    char paginas[N][20] = {
        "inicio",
        "categorias",
        "video",
        "perfil",
        "historico",
        "busca",
        "config"
    };
    
    int opcao = 0;
    
    // Matriz de adjacência
    int grafo[N][N] = {
    /*             i  c  v  p  h  b  cfg  */
    /* inicio    */ {0, 1, 0, 0, 0, 1, 0},
    /* categorias*/ {0, 0, 1, 0, 0, 1, 0},
    /* video     */ {0, 0, 0, 1, 1, 0, 0},
    /* perfil    */ {0, 0, 0, 0, 0, 0, 1},
    /* historico */ {0, 0, 1, 0, 0, 0, 0},
    /* busca     */ {0, 1, 1, 0, 0, 0, 0},
    /* config    */ {1, 0, 0, 0, 0, 0, 0}
    };
	
   	char paginaInicial[100];
	int paginaIniciar;
	
    do{
		printf("\n===== MATRIZ DE ADJACENCIA =====\n");
		imprimeGrafo(grafo, paginas);
	
	
		fflush(stdin);
	    printf("\n===== PAGINAS ALCANCAVEIS =====\n");
	    printf("Informe o nome da pagina inicial: ");
	    gets(paginaInicial);
	    fflush(stdin);
	    
	    if(strcmp(paginaInicial, "inicio") == 0){
	    	paginaIniciar = 0;
		}
		else if(strcmp(paginaInicial, "categorias") == 0){
	    	paginaIniciar = 1;
		}
		else if(strcmp(paginaInicial, "video") == 0){
	    	paginaIniciar = 2;
		}
		else if(strcmp(paginaInicial, "perfil") == 0){
	    	paginaIniciar = 3;
		}
		else if(strcmp(paginaInicial, "historico") == 0){
	    	paginaIniciar = 4;
		}
		else if(strcmp(paginaInicial, "busca") == 0){
	    	paginaIniciar = 5;
		}
		else if(strcmp(paginaInicial, "config") == 0){
	    	paginaIniciar = 6;
		}
		
	
		fflush(stdin);
		
	    listarAlcancaveis(grafo, paginas, paginaIniciar);
	
	    printf("\n===== PAGINAS POPULARES =====\n");
	    listarPaginasPopulares(grafo, paginas);
	
	    printf("\n===== PAGINAS SEM SAIDA =====\n");
	    listarPaginasSemSaida(grafo, paginas);
	
	    printf("\n===== EH CONEXO =====\n");
	    if(verificarConexo(grafo) == 1) {
	        printf("O grafo eh conexo.\n");
	    } else {
	        printf("O grafo NAO eh conexo.\n");
	    }
	    
	    opcao = 0;
	    fflush(stdin);
	    
	    printf("\n\nDeseja navegar por outra pagina? (1 = sim | 0 = nao): ");
	    scanf("%d", &opcao);
	    
	}while(opcao == 1);
	
    return 0;
}
