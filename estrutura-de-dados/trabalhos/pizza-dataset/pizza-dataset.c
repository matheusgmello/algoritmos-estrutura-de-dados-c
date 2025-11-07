/*
Trabalho ordenação e pesquisa (pizza dataset)

Utilizando o arquivo disponibilizado no moodle, desenvolver um programa com funções para ordenar os dados e permitir pesquisa por itens específicos. Para isso considere:
Utilizar vetores ou listas encadeadas para resolver o exercício;
O programa deve permitir ordenação e pesquisa por dados solicitados pelo usuário;
Escolher dois métodos de ordenação estudados para organizar os registros do dataset. O usuário deve escolher, em tempo de execução, o método que será aplicado;
O programa deve permitir a realização de pesquisas sequenciais e binárias;
As buscas por registros devem acontecer a partir do ID e/ou Origem da pizza;
No caso de busca por origem, apresentar todos os registros que possuem o valor solicitado pelo usuário.
O programa só deve ser encerrado se o usuário assim desejar;
Enviar também um arquivo .txt com informações sobre o trabalho (funcionalidade parcialmente ou não implementadas, particularidades de execução, etc.).

Casos omissos devem ser tratados pelo desenvolvedor e fazem parte da avaliação

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct pizzaDataset {
    int id;
    char nome[20];
    char ingredientes[100];
    float ranking;
    char origem[20];
};

// Função para preencher o vetor com os dados do dataset
void inserirPizzas(struct pizzaDataset dataset[]) {
    // Preenchendo todos os registros
    dataset[0].id = 9;
    strcpy(dataset[0].nome, "Bacon e Cheddar");
    strcpy(dataset[0].ingredientes, "Molho de tomate-queijo cheddar-bacon-cebola");
    dataset[0].ranking = 4.8;
    strcpy(dataset[0].origem, "Estados Unidos");

    dataset[1].id = 3;
    strcpy(dataset[1].nome, "Pepperoni");
    strcpy(dataset[1].ingredientes, "Molho de tomate-queijo mozzarela-pepperoni");
    dataset[1].ranking = 4.7;
    strcpy(dataset[1].origem, "Estados Unidos");

    dataset[2].id = 6;
    strcpy(dataset[2].nome, "Frango com Catupiry");
    strcpy(dataset[2].ingredientes, "Molho de tomate-queijo mozzarela-frango desfiado-catupiry");
    dataset[2].ranking = 4.4;
    strcpy(dataset[2].origem, "Brasil");

    dataset[3].id = 21;
    strcpy(dataset[3].nome, "Frango Barbecue");
    strcpy(dataset[3].ingredientes, "Molho barbecue-queijo mozzarela-frango desfiado-cebola roxa");
    dataset[3].ranking = 4.3;
    strcpy(dataset[3].origem, "Estados Unidos");

    dataset[4].id = 4;
    strcpy(dataset[4].nome, "Portuguesa");
    strcpy(dataset[4].ingredientes, "Molho de tomate-queijo mozzarela-presunto-ovos-azeitonas-cebola");
    dataset[4].ranking = 4.2;
    strcpy(dataset[4].origem, "Brasil");

    dataset[5].id = 16;
    strcpy(dataset[5].nome, "Frango com Milho");
    strcpy(dataset[5].ingredientes, "Molho de tomate-queijo mozzarela-frango desfiado-milho");
    dataset[5].ranking = 4.5;
    strcpy(dataset[5].origem, "Brasil");

    dataset[6].id = 19;
    strcpy(dataset[6].nome, "Armadillo");
    strcpy(dataset[6].ingredientes, "Molho de tomate-queijo mozzarela-carne moida-bacon-pimentao");
    dataset[6].ranking = 4.4;
    strcpy(dataset[6].origem, "Brasil");

    dataset[7].id = 7;
    strcpy(dataset[7].nome, "Veggie");
    strcpy(dataset[7].ingredientes, "Molho de tomate-queijo mozzarela-cogumelos-pimentao-abobrinha");
    dataset[7].ranking = 4.1;
    strcpy(dataset[7].origem, "Brasil");

    dataset[8].id = 24;
    strcpy(dataset[8].nome, "Lombo Canadense");
    strcpy(dataset[8].ingredientes, "Molho de tomate-queijo mozzarela-lombo canadense-cogumelos");
    dataset[8].ranking = 4.3;
    strcpy(dataset[8].origem, "Brasil");

    dataset[9].id = 1;
    strcpy(dataset[9].nome, "Margherita");
    strcpy(dataset[9].ingredientes, "Molho de tomate-queijo mozzarela-manjericao-azeite");
    dataset[9].ranking = 4.5;
    strcpy(dataset[9].origem, "Italia");

    dataset[10].id = 8;
    strcpy(dataset[10].nome, "Hawaii");
    strcpy(dataset[10].ingredientes, "Molho de tomate-queijo mozzarela-presunto-abacaxi");
    dataset[10].ranking = 3.9;
    strcpy(dataset[10].origem, "Estados Unidos");

    dataset[11].id = 18;
    strcpy(dataset[11].nome, "Trufada");
    strcpy(dataset[11].ingredientes, "Molho de tomate-queijo mozzarela-azeite trufado-cogumelos-queijo parmesao");
    dataset[11].ranking = 4.9;
    strcpy(dataset[11].origem, "Italia");

    dataset[12].id = 13;
    strcpy(dataset[12].nome, "Peito de Peru");
    strcpy(dataset[12].ingredientes, "Molho de tomate-queijo mozzarela-peito de peru-cogumelos");
    dataset[12].ranking = 4.3;
    strcpy(dataset[12].origem, "Brasil");

    dataset[13].id = 5;
    strcpy(dataset[13].nome, "Quatro Queijos");
    strcpy(dataset[13].ingredientes, "Molho de tomate-queijo mozzarela-gorgonzola-parmesao-provolone");
    dataset[13].ranking = 4.6;
    strcpy(dataset[13].origem, "Italia");

    dataset[14].id = 17;
    strcpy(dataset[14].nome, "Frutos do Mar");
    strcpy(dataset[14].ingredientes, "Molho de tomate-queijo mozzarela-camaroes-mexilhoes-lula");
    dataset[14].ranking = 4.6;
    strcpy(dataset[14].origem, "Italia");

    dataset[15].id = 12;
    strcpy(dataset[15].nome, "Caponata");
    strcpy(dataset[15].ingredientes, "Molho de tomate-queijo mozzarela-berinjela-abobrinha-pimentao-azeitonas");
    dataset[15].ranking = 4.2;
    strcpy(dataset[15].origem, "Italia");

    dataset[16].id = 25;
    strcpy(dataset[16].nome, "Pesto");
    strcpy(dataset[16].ingredientes, "Molho pesto-queijo mozzarela-tomate cereja-nozes");
    dataset[16].ranking = 4.5;
    strcpy(dataset[16].origem, "Italia");

    dataset[17].id = 14;
    strcpy(dataset[17].nome, "Alho e Oleo");
    strcpy(dataset[17].ingredientes, "Molho de tomate-queijo mozzarela-alho-azeite");
    dataset[17].ranking = 4.0;
    strcpy(dataset[17].origem, "Italia");

    dataset[18].id = 10;
    strcpy(dataset[18].nome, "Marguerita Vegana");
    strcpy(dataset[18].ingredientes, "Molho de tomate-queijo vegano-manjericao-azeite");
    dataset[18].ranking = 4.0;
    strcpy(dataset[18].origem, "Italia");

    dataset[19].id = 26;
    strcpy(dataset[19].nome, "Chester e Catupiry");
    strcpy(dataset[19].ingredientes, "Molho de tomate-queijo mozzarela-chester desfiado-catupiry");
    dataset[19].ranking = 4.4;
    strcpy(dataset[19].origem, "Brasil");

    dataset[20].id = 15;
    strcpy(dataset[20].nome, "Vegetariana");
    strcpy(dataset[20].ingredientes, "Molho de tomate-queijo mozzarela-cogumelos-pimentao-tomate-cebola");
    dataset[20].ranking = 4.1;
    strcpy(dataset[20].origem, "Brasil");

    dataset[21].id = 20;
    strcpy(dataset[21].nome, "Peperoncino");
    strcpy(dataset[21].ingredientes, "Molho de tomate-queijo mozzarela-pimenta calabresa-manjericao");
    dataset[21].ranking = 4.2;
    strcpy(dataset[21].origem, "Italia");

    dataset[22].id = 28;
    strcpy(dataset[22].nome, "Mac e Queijo");
    strcpy(dataset[22].ingredientes, "Molho de queijo-macarrao-bacon-queijo mozzarela");
    dataset[22].ranking = 4.6;
    strcpy(dataset[22].origem, "Estados Unidos");

    dataset[23].id = 11;
    strcpy(dataset[23].nome, "Frango com Bacon");
    strcpy(dataset[23].ingredientes, "Molho de tomate-queijo mozzarela-frango desfiado-bacon");
    dataset[23].ranking = 4.4;
    strcpy(dataset[23].origem, "Brasil");

    dataset[24].id = 22;
    strcpy(dataset[24].nome, "Champignon");
    strcpy(dataset[24].ingredientes, "Molho de tomate-queijo mozzarela-cogumelos champignon-azeite");
    dataset[24].ranking = 4.1;
    strcpy(dataset[24].origem, "Italia");

    dataset[25].id = 2;
    strcpy(dataset[25].nome, "Calabresa");
    strcpy(dataset[25].ingredientes, "Molho de tomate-queijo mozzarela-calabresa-cebola");
    dataset[25].ranking = 4.3;
    strcpy(dataset[25].origem, "Brasil");

    dataset[26].id = 23;
    strcpy(dataset[26].nome, "Carbonara");
    strcpy(dataset[26].ingredientes, "Molho branco-queijo mozzarela-bacon-ovos-queijo parmesao");
    dataset[26].ranking = 4.7;
    strcpy(dataset[26].origem, "Italia");

    dataset[27].id = 30;
    strcpy(dataset[27].nome, "Mexicana");
    strcpy(dataset[27].ingredientes, "Molho de tomate-queijo mozzarela-carne moida-pimentao-milho-jalapenos");
    dataset[27].ranking = 4.5;
    strcpy(dataset[27].origem, "Mexico");

    dataset[28].id = 29;
    strcpy(dataset[28].nome, "Lasagna");
    strcpy(dataset[28].ingredientes, "Molho bolonhesa-queijo mozzarela-carne moida-queijo parmesao");
    dataset[28].ranking = 4.8;
    strcpy(dataset[28].origem, "Italia");

    dataset[29].id = 27;
    strcpy(dataset[29].nome, "Brocolis com Alho");
    strcpy(dataset[29].ingredientes, "Molho de tomate-queijo mozzarela-brocolis-alho");
    dataset[29].ranking = 4.2;
    strcpy(dataset[29].origem, "Italia");
}


void exibirPizza(struct pizzaDataset pizza) {
    printf("\nID: %d\n", pizza.id);
    printf("Nome: %s\n", pizza.nome);
    printf("Ingredientes: %s\n", pizza.ingredientes);
    printf("Ranking: %.1f\n", pizza.ranking);
    printf("Origem: %s\n", pizza.origem);
}
/*
faz uma copia do dataset
*/
void copiarDataset(struct pizzaDataset origem[], struct pizzaDataset destino[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

/*
funcao para comparar dentro do dataset
ID
ORIGEM
RANKING
*/
int comparar(struct pizzaDataset pizzaA, struct pizzaDataset pizzaB, int tipo) {
    if (tipo == 1) {
        return pizzaA.id - pizzaB.id;
    } else if (tipo == 2) {
        return strcmp(pizzaA.origem, pizzaB.origem);
    } else {
        if (pizzaA.ranking < pizzaB.ranking){
            return -1;	
        } 
        else if (pizzaA.ranking > pizzaB.ranking){
            return 1;	
        } 
        else{
        	return 0;
		}
    }
}

/*
 * combina dois sub-arrays em um unico array.
 * recebe o array e limites
 */
void merge(struct pizzaDataset vetorDePizzas[], int inicio, int meio, int fim, int tipo, int *comparacoes, int *trocas) {
    int i = inicio, j = meio + 1, k = 0;
    struct pizzaDataset pizzaTemp[fim - inicio + 1];

    while (i <= meio && j <= fim) {
        (*comparacoes)++;
        if (comparar(vetorDePizzas[i], vetorDePizzas[j], tipo) <= 0){
            pizzaTemp[k++] = vetorDePizzas[i++];
        } 
        else {
            pizzaTemp[k++] = vetorDePizzas[j++];
            (*trocas)++;
        }
    }

    while (i <= meio) {
        pizzaTemp[k++] = vetorDePizzas[i++];
    }
    while (j <= fim) {
        pizzaTemp[k++] = vetorDePizzas[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++){
        vetorDePizzas[i] = pizzaTemp[k];
    }
}

/*
 * algoritmo de ordenacoa Merge Sort recursivamente.
 * divide a array em metades ate que cada subarray tenha 1 elemento
 */
void mergeSort(struct pizzaDataset pizzaTemp[], int inicio, int fim, int tipo, int *comparacoes, int *trocas) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(pizzaTemp, inicio, meio, tipo, comparacoes, trocas);
        mergeSort(pizzaTemp, meio + 1, fim, tipo, comparacoes, trocas);
        merge(pizzaTemp, inicio, meio, fim, tipo, comparacoes, trocas);
    }
}

/*
Funcao para ordenar Selection Sort
*/
void selectionSort(struct pizzaDataset vetorDePizzas[], int n, int tipo, int *comparacoes, int *trocas) {
    int i, j, min;
    struct pizzaDataset pizzaTemp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (comparar(vetorDePizzas[j], vetorDePizzas[min], tipo) < 0){
                min = j;
            }
        }
        if (min != i) {
            pizzaTemp = vetorDePizzas[i];
            vetorDePizzas[i] = vetorDePizzas[min];
            vetorDePizzas[min] = pizzaTemp;
            (*trocas)++;
        }
    }
}


/*
 * Realiza uma busca sequencial em toda a array pelo ID da pizza.
 * Retorna o indice da primeira ocorrencia do ID ou -1 se nao encontrar.
 */
int buscaSequencialPorID(struct pizzaDataset vetorDePizzas[], int n, int id) {
	int i;
    for (i = 0; i < n; i++)
        if (vetorDePizzas[i].id == id){
            return i;	
        }
    return -1;
}

/*
 * Realiza uma busca binaria pelo ID da pizza.
 * Requer que 'vetorDePizzas' esteja ordenado por ID.
 * Retorna o indice do ID ou -1 se nao for encontrado.
 */
int buscaBinariaPorID(struct pizzaDataset vetorDePizzas[], int n, int id) {
    int inicio = 0, fim = n - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetorDePizzas[meio].id == id){
        	return meio;
		}
        else if (id < vetorDePizzas[meio].id){
        	fim = meio - 1;
		}
        else{
        	inicio = meio + 1;
		}
    }
    return -1;
}

/*
 * realiza uma busca sequencial por pizzas com uma determinada origem.
 * exibe as informacoes de todas as pizzas encontradas.
* Trata entradas do usuario, permitindo buscas mesmo que
 * o texto esteja em maiusculas, minusculas ou misto (ex.: "ESTADOS UNIDOS").
 */
void buscaSequencialPorOrigem(struct pizzaDataset vetorDePizzas[], int n, char origem[]) {
    int encontrou = 0;
    int i, j;

    for (i = 0; origem[i]; i++) {
        origem[i] = tolower(origem[i]);
    }

    for (i = 0; i < n; i++) {
        char pizzaOrigem[50];
        strcpy(pizzaOrigem, vetorDePizzas[i].origem);

        for (j = 0; pizzaOrigem[j]; j++) {
            pizzaOrigem[j] = tolower(pizzaOrigem[j]);
        }

        if (strcmp(pizzaOrigem, origem) == 0) {
            exibirPizza(vetorDePizzas[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("\nNenhuma pizza encontrada dessa origem.\n");
    }
}



int main() {
    struct pizzaDataset original[30];
    struct pizzaDataset dataset[30];
    struct pizzaDataset copia[30];

    inserirPizzas(original);
    copiarDataset(original, dataset, 30);

    int opcao, metodo, campo, id, indice;
    char origem[20];
    int ordenadoPorID = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Ordenar\n");
        printf("2 - Buscar por ID\n");
        printf("3 - Buscar por Origem\n");
        printf("4 - Exibir todas as pizzas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1: {
        	printf("Metodo (1 - Merge Sort / 2 - Selection Sort): ");
		    scanf("%d", &metodo);
		
		    int comparacoes = 0;
		    int trocas = 0;
		    int campo = 1; 
		
		    copiarDataset(original, copia, 30);
		
		    if (metodo == 1) {
		        mergeSort(copia, 0, 29, campo, &comparacoes, &trocas);
		    } else {
		        selectionSort(copia, 30, campo, &comparacoes, &trocas);
		    }
		
		    printf("\nPizzas ordenadas com sucesso!\n");
		    printf("Comparacoes realizadas: %d\n", comparacoes);
		    printf("Trocas realizadas: %d\n", trocas);
		
		    ordenadoPorID = 1;
		    copiarDataset(copia, dataset, 30);
		    break;
		}
        case 2: {
        	printf("Tipo de busca (1 - Sequencial / 2 - Binaria): ");
		    scanf("%d", &metodo);
		
		    if (metodo == 2 && !ordenadoPorID) {
		        printf("Ordene primeiro por ID para usar busca binaria!\n");
		        break;
		    }
		
		    printf("Digite o ID: ");
		    scanf("%d", &id);
		
		    if (metodo == 1){
		        indice = buscaSequencialPorID(dataset, 30, id);
		    }
		    else {
		        indice = buscaBinariaPorID(dataset, 30, id);
		    }
		
		    if (indice != -1){
		        exibirPizza(dataset[indice]);
		    }
		    else{
		        printf("\nPizza nao encontrada.\n");
		    }
		    break;
		}
		    
        case 3: {
		    printf("Digite a origem da pizza que deseja buscar: ");
		    fflush(stdin);
		    fgets(origem, sizeof(origem), stdin);
		    origem[strcspn(origem, "\n")] = 0;
		
		    buscaSequencialPorOrigem(dataset, 30, origem);
		    break;
		}


        case 4: {
        	printf("\nExibindo todas as pizzas:\n");
            for (int i = 0; i < 30; i++){
            	exibirPizza(dataset[i]);
			}
                
            break;
		}
        case 0: {
        	printf("\nEncerrando programa...\n");
            break;
		}

        default: {
        	printf("\nOpcao invalida!\n");
			break;
		}
    }

    } while (opcao != 0);

    return 0;
}
