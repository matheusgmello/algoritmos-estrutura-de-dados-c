/*
Ordenação híbrida: quick e insertion sort
O QuickSort é um poderoso algoritmo recursivo que funciona quebrando o vetor em partes cada vez menores, usando a estratégia de “Dividir para Conquistar”. O InsertionSort é um algoritmo iterativo e direto, muito bom em organizar vetores pequenos.
Neste desafio, você não vai implementar apenas um, mas sim criar um novo algoritmo híbrido. A ideia é usar o QuickSort como o “gerente” que divide os grandes problemas, mas quando os problemas (subconjuntos) já estiverem pequenos o suficiente, ele irá “delegar” a tarefa de ordenação final para o Insertion Sort.
Você deve implementar uma função recursiva que combina a lógica do QuickSort e do InsertionSort. A sua função usará a recursão para dividir o vetor até que os pedaços sejam pequenos, e então usará o InsertionSort para ordenar esses pedaços pequenos.
Implemente a função recursiva sortCombinado() a partir do protótipo abaixo (sugestão).
#define LIMITE_PARA_DELEGAR 5

void sortCombinado(int vetor[], int inicio, int fim) {
    // SEU CÓDIGO AQUI
}

Sua função sortCombinado deve seguir esta lógica:
Verificação de Tamanho: A função deve primeiro verificar o tamanho do sub-vetor que está analisando (ex: fim - inicio + 1).
Delegação (Novo Caso Base): Se o tamanho deste sub-vetor for menor que o LIMITE_PARA_DELEGAR, a recursão deve parar. 
Em vez de continuar dividindo, a função deve chamar insertionSort(vetor, inicio, fim) para ordenar este pequeno sub-vetor.
Recursão (Passo Normal): Se o tamanho for maior ou igual ao LIMITE_PARA_DELEGAR, a função deve executar a lógica padrão do QuickSort:
Chamar particionar() para encontrar o pivô;
Chamar recursivamente sortCombinado() para a sub-lista à esquerda do pivô;
Chamar recursivamente sortCombinado() para a sub-lista à direita do pivô.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE_PARA_DELEGAR 5
#define TAMANHO 120

void imprimeVetor(float v[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%8.2f", v[i]);
        if ((i + 1) % 5 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void copiaVetor(float vetorDeOrigem[], float vetorDestino[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        vetorDestino[i] = vetorDeOrigem[i];
    }
}

int particiona(float v[], int inicio, int fim, int *contaComparacoes, int *contaTrocas) {
    float pivo = v[fim];
    int i = (inicio - 1);
    int j;

    for (j = inicio; j <= fim - 1; j++) {
        (*contaComparacoes)++;
        if (v[j] < pivo) {
            i++;
            
            float temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            (*contaTrocas)++; 
        }
    }
    
    float temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;
    (*contaTrocas)++; 
    
    return (i + 1); 
}


void insertionSortIntervalo(float v[], int inicio, int fim, int *contaComparacoes, int *contaTrocas) {
    int i, j;
    for (i = inicio + 1; i <= fim; i++) {
        float valorAtual = v[i];
        j = i - 1;

        while (j >= inicio && v[j] > valorAtual) {
            (*contaComparacoes)++;
            v[j + 1] = v[j];
            j--;
            (*contaTrocas)++;
        }

        if (j >= inicio){
        	(*contaComparacoes)++;
		}

        v[j + 1] = valorAtual;
    }
}


void sortCombinado(float v[], int inicio, int fim, int *contaComparacoes, int *contaTrocas) {
    int tamanho = fim - inicio + 1;

    if (inicio < fim) {
        if (tamanho < LIMITE_PARA_DELEGAR) {
            insertionSortIntervalo(v, inicio, fim, contaComparacoes, contaTrocas);
            return;
        }

        int posicaoPivo = particiona(v, inicio, fim, contaComparacoes, contaTrocas);

        sortCombinado(v, inicio, posicaoPivo - 1, contaComparacoes, contaTrocas);
        sortCombinado(v, posicaoPivo + 1, fim, contaComparacoes, contaTrocas);
    }
}

/*
Funcao para executar o algoritmo hibrido completo
*/
void ordenaHibrido(float v[], int n) {
    int contaComparacoes = 0;
    int contaTrocas = 0;

    clock_t inicio = clock();

    sortCombinado(v, 0, n - 1, &contaComparacoes, &contaTrocas);

    clock_t fim = clock();
    double tempoMs = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

    printf("\033[33m\nhibrido:\033[0m\n");
    imprimeVetor(v, 20);
    printf("Algoritmo: hibrido| Comparacoes: %d | Trocas: %d | Tempo: \033[31m%.3f ms\033[0m\n", contaComparacoes, contaTrocas, tempoMs);
}


int main() {
    float precos[TAMANHO], copia[TAMANHO];
    int i;
    srand(time(NULL));
    
    float precosOriginais[20] = {
        389.42, 148.39, 324.67, 78.23, 203.81,
        271.54, 125.96, 87.58, 450.23, 375.92,
        66.42, 491.01, 410.64, 180.96, 120.78,
        253.33, 42.19, 314.04, 56.88, 171.15
    };
    
    for (i = 0; i < TAMANHO; i++) {
        if (i < 20) {
            precos[i] = precosOriginais[i];
        } else {
            precos[i] = ((float)rand() / RAND_MAX) * 9999.99f;
        }
    }

 	printf("=========================================\n");
    printf("\033[33m  DESAFIO ORDENACAO HIBRIDA  \033[0m\n");
    printf("=========================================\n\n");
    printf("Valores não ordenados:\n\n");
    imprimeVetor(precos, TAMANHO);

	copiaVetor(precos, copia, TAMANHO);
	printf("\nPressione ENTER para executar o algortimo hibrido...");
	getchar();
	system("cls");
	ordenaHibrido(copia, TAMANHO);


    return 0;
}