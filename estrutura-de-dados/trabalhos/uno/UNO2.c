#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// escolha o tempo de DELAY = 1000, 1500, 2000, 0000
#define DELAY 3000

// struct que representa uma unica carta do baralho
typedef struct carta {
    char cor[10];
    char valor[35];
    struct carta *prox;
} Carta;

// struct auxiliar para definir o baralho inicial
typedef struct {
    char cor[10];
    char valor[35];
} CartaBase;


// representa uma lista encadeada de cartas
typedef struct {
    Carta *inicio;
} Lista;


/**
 * cria e inicializa uma nova lista,
 retornando um ponteiro para lista recem criada 
 */
Lista *criaLista() {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

/**
 * poe uma nova carta no inicio da lista,
 * l > ponteiro para a lista onde a carta vai ser inserida
 * cor > string com a cor da carta.
 * valor > string com o valor da carta (0 a 5).
 */
void insereCarta(Lista *l, char *cor, char *valor) {
    Carta *nova = (Carta*)malloc(sizeof(Carta));
    if (nova == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    strcpy(nova->cor, cor);
    strcpy(nova->valor, valor);
    nova->prox = l->inicio;
    l->inicio = nova;
}

/**
 * remove e retorna a primeira carta da lista.
 * retorna: ponteiro para a carta removida ou NULL se a lista estiver vazia.
 */
Carta *removeCartaNoInicio(Lista *l) {
    if (l->inicio == NULL) {
        return NULL;
    } else {
        Carta *c = l->inicio;
        l->inicio = c->prox;
        c->prox = NULL;
        return c;
    }
}

/**
 * remove uma carta especifica da mao do jogador, faz a busca pela cor e valor.
 * retorna ponteiro para a carta removida, ou NULL se nnao a encontrar.
 */
Carta *removeCartaMao(Lista *l, char *cor, char *valor) {
    Carta *ant = NULL;
    Carta *p = l->inicio;
    while (p != NULL) {
        if (strcmp(p->cor, cor) == 0 && strcmp(p->valor, valor) == 0) {
            if (ant == NULL) {
                l->inicio = p->prox;
            } else {
                ant->prox = p->prox;
            }
            p->prox = NULL;
            return p;
        }
        ant = p;
        p = p->prox;
    }
    return NULL;
}

/**
 * imprime uma carta no terminal com a cor correspondente (eh pra funcionar com as cores).
 */
void mostraCarta(Carta *c) {
    if (strcmp(c->cor, "Vermelho") == 0) {
        printf("\033[31m[%s %s]\033[0m ", c->cor, c->valor);
    } else if (strcmp(c->cor, "Azul") == 0) {
        printf("\033[34m[%s %s]\033[0m ", c->cor, c->valor);
    } else if (strcmp(c->cor, "Verde") == 0) {
        printf("\033[32m[%s %s]\033[0m ", c->cor, c->valor);
    } else {
        printf("[%s %s] ", c->cor, c->valor);
    }
}

/**
 * imprime todas as cartas na mao do jogador.
 */
void mostraMao(Lista *mao) {
    Carta *p = mao->inicio;
    while (p != NULL) {
        mostraCarta(p);
        p = p->prox;
    }
    printf("\n");
}

/**
 * conta o numero de cartas na mao de um jogador.
 * retornando o numero de cartas.
 */
int contarMao(Lista *mao) {
    int count = 0;
    Carta *p = mao->inicio;
    while (p != NULL) {
        count++;
        p = p->prox;
    }
    return count;
}

/**
 * verifica se uma carta pode ser jogada sobre a carta do topo do descarte.
 * retorna: 1 se a carta puder ser jogada ou seja(jogada valida (combinando cor ou valor)),
  0 caso contrário.
 */
int podeJogar(Carta *c, Carta *topo) {
    if (c == NULL || topo == NULL){
    	return 0;
	} 
    if (strcmp(c->cor, topo->cor) == 0) {
        return 1;
    }
    if (strcmp(c->valor, topo->valor) == 0) {
        return 1;
    }
    return 0;
}

/**
 * embaralha a ordem dos ponteiros para as cartas em uma lista.
 */
void embaralharLista(Lista *l) {
    int n = contarMao(l);
    if (n <= 1){
        return;
    }

    Carta *arrayCartas = (Carta*)malloc(n * sizeof(Carta));
    if (arrayCartas == NULL){
        return;
    } 

    Carta *atual = l->inicio;
    int i = 0;
    while (atual != NULL) {
        strcpy(arrayCartas[i].cor, atual->cor);
        strcpy(arrayCartas[i].valor, atual->valor);
        i++;
        atual = atual->prox;
    }

    // Embaralha o vetor de structs
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = arrayCartas[i];
        arrayCartas[i] = arrayCartas[j];
        arrayCartas[j] = temp;
    }

    // Recria a lista a partir do vetor embaralhado
    atual = l->inicio;
    i = 0;
    while (atual != NULL) {
        strcpy(atual->cor, arrayCartas[i].cor);
        strcpy(atual->valor, arrayCartas[i].valor);
        atual = atual->prox;
        i++;
    }

    free(arrayCartas);
}


/**
 * move as cartas do descarte para o monte de compras, a ultima carta jogada
 * (topo do descarte) permanece na pilha.
 */
void reciclaDescarte(Lista *monte, Lista *descarte) {
	// retorna se o descarte estiver vazio ou tiver apenas uma carta
    if (descarte->inicio == NULL || descarte->inicio->prox == NULL) {
        return;
    }

    printf("\nO monte de compras acabou. Reciclando o descarte para formar um novo monte.\n");
    Sleep(DELAY);

    // salva a ultima carta jogada (topo do descarte)
    Carta *topoDescarte = descarte->inicio;
    descarte->inicio = descarte->inicio->prox;
    topoDescarte->prox = NULL; // tira o topo do resto do descarte

    // move todas as cartas restantes do descarte para o inicio do monte
    while (descarte->inicio != NULL) {
        Carta *c = descarte->inicio;
        descarte->inicio = c->prox;
        c->prox = monte->inicio;
        monte->inicio = c;
    }
    
    // devolve a ultima carta ao descarte
    topoDescarte->prox = descarte->inicio;
    descarte->inicio = topoDescarte;

    // embaralha o novo monte
    embaralharLista(monte);
}

/**
 * logica recursiva para a carta de acao "+2". Se o defensor tiver um +2,
 ele pode joga-lo, empilhando a penalidade e passando o ataque de volta.
 
 * atacante o ponteiro para a mão do jogador que jogou o +2.
 * defensor o ponteiro para a mão do jogador que deve reagir.
 
 * monte o ponteiro para o monte de compras.
 * descarte O ponteiro para a pilha de descarte.
 
 * qtd quantidade de cartas a serem compradas (acumulada).
 * nomeAtacante O nome do jogador que atacou.
 * nomeDefensor O nome do jogador que defende.
 */
void aplicaCartaMais2(Lista *atacante, Lista *defensor, Lista *monte, Lista *descarte, int qtd, char *nomeAtacante, char *nomeDefensor) {
    Carta *p = defensor->inicio;
    int i;

    printf("\n%s foi atacado com um +2! Ele precisa comprar %d cartas.\n", nomeDefensor, qtd);
    Sleep(DELAY);

    // verifica se o defensor tem +2 para rebater
    while (p != NULL) {
        if (strcmp(p->valor, "+2") == 0) {
        	
            // remove a carta da mao do defensor
            Carta *c = removeCartaMao(defensor, p->cor, p->valor);
            
            // joga o +2 e o coloca no topo do descarte
            c->prox = descarte->inicio;
            descarte->inicio = c;

            printf("%s jogou ", nomeDefensor);
            mostraCarta(c);
            printf("empilhando penalidade para %s! Total agora de %d cartas.\n", nomeAtacante, qtd + 2);
            Sleep(DELAY);

            // recursaop: inverte a logica e passa o ataque para o outro jogador
            aplicaCartaMais2(defensor, atacante, monte, descarte, qtd + 2, nomeDefensor, nomeAtacante);
            return;
        }
        p = p->prox;
    }

    // se o defensor noa tinha +2 para rebater, ele compra as cartas acumuladas
    printf("%s nao tem um +2. Comprou %d cartas.\n", nomeDefensor, qtd);
    Sleep(DELAY);
    for (i = 0; i < qtd; i++) {
    	// recicla o descarte se o monte acabar durante a compra
        if (monte->inicio == NULL) {
            reciclaDescarte(monte, descarte);
        }
        // se ainda houver cartas no monte apos a reciclagem, compra
        if (monte->inicio != NULL) {
            Carta *c = removeCartaNoInicio(monte);
            c->prox = defensor->inicio;
            defensor->inicio = c;
        } else {
            printf("Nao ha mais cartas no jogo!\n");
            return; // Sai da função se não houver mais cartas
        }
    }
}

// aplica a carta de bloqueio, impedindo o jogador que foi bloqueado de jogar, retornando 1
// fazendo o jogador que jogou a carta, jogue novamente
int aplicaCartaBloqueio(char *nomeJogador, char *nomeAdversario){
	printf("%s Bloqueou %s", nomeJogador, nomeAdversario);
	printf("%s Perdeu a vez", nomeAdversario);
	return 1;
}

/**
 * Executa um turno completo para um jogador, incluindo a jogada, compra e acoes especiais.
 * jogador ponteiro para a mao do jogador atual.
 * adversario ponteiro para a mão do adversario.
 * monte: ponteiro para a lista de cartas do monte.
 * descarte: ponteiro para a lista de descarte.
 * nomeJogador: nome do jogador atual.
 * nomeAdversario: nome do adversario.
 * Retorna: 0 ao finalizar o turno.
 */
int turno(Lista *jogador, Lista *adversario, Lista *monte, Lista *descarte, char *nomeJogador, char *nomeAdversario) {
    printf("\n====================================\n");
    printf("        TURNO DE %s\n", nomeJogador);
    printf("====================================\n");

    printf("Topo do descarte: ");
    mostraCarta(descarte->inicio);
    printf("\n------------------------------------\n");

    printf("Mao de %s (%d cartas):\n", nomeJogador, contarMao(jogador));
    mostraMao(jogador);
    printf("------------------------------------\n");

    Carta *topo = descarte->inicio;
    Carta *p = jogador->inicio;

    // Tenta jogar uma carta valida
    while (p != NULL) {
        if (podeJogar(p, topo)) {
            Carta *c = removeCartaMao(jogador, p->cor, p->valor);
            c->prox = descarte->inicio;
            descarte->inicio = c;

            printf("%s jogou: ", nomeJogador);
            mostraCarta(c);
            printf("\n");
            
			 // Se a carta for um +2, chama a logica recursiva
            if (strcmp(c->valor, "+2") == 0) {
                aplicaCartaMais2(jogador, adversario, monte, descarte, 2, nomeJogador, nomeAdversario);
            }
            else if(strcmp(c->valor, "Bloqueio") == 0){
            	if(aplicaCartaBloqueio(nomeJogador, nomeAdversario)){
            		return 1;
				}
			}

            printf("====================================\n");
            return 0;
        }
        p = p->prox;
    }

    // Se nao tinha carta valida, tenta comprar
    printf("%s nao tem carta para jogar. Vai comprar uma.\n", nomeJogador);
    Sleep(DELAY);

	// recicla o descarte se o monte estiver vazio
    if (monte->inicio == NULL) {
        reciclaDescarte(monte, descarte);
    }
    
    // tenta comprar uma carta do monte
    if (monte->inicio != NULL) {
        Carta *c = removeCartaNoInicio(monte);
        printf("%s comprou: ", nomeJogador);
        mostraCarta(c);
        printf("\n");
		
		
        // verifica se a carta comprada pode ser jogada
        if (podeJogar(c, topo)) {
            // Se sim, joga a carta imediatamente
            c->prox = descarte->inicio;
            descarte->inicio = c;
            printf("%s jogou imediatamente a carta comprada!\n", nomeJogador);
            mostraCarta(c);
            printf("\n");

            if (strcmp(c->valor, "+2") == 0) {
                aplicaCartaMais2(jogador, adversario, monte, descarte, 2, nomeJogador, nomeAdversario);
            }
        } else {
            // Se nao, adiciona a carta comprada a mao
            c->prox = jogador->inicio;
            jogador->inicio = c;
            printf("%s nao pode jogar a carta comprada.\n", nomeJogador);
        }
    } else {
        printf("Nao ha mais cartas no jogo para comprar.\n");
    }

    printf("====================================\n");
    return 0;
}


/**
 * Verifica se a mão de um jogador esta vazia.
 */
int maoTaVazia(Lista *mao) {
    return mao->inicio == NULL;
}

/**
 * embaralha um array de inteiros (embaralha as cartas)
 * ordem: ponteiro para o array de índices.
 * n: tamanho do array.
 */
void embaralhar(int *ordem, int n) {
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = ordem[i];
        ordem[i] = ordem[j];
        ordem[j] = temp;
    }
}

/**
carrega o baralho embaralhado para a lista do monte de compras.
 */
void carregaBaralho(Lista *monte, CartaBase *cartas, int n) {
    int ordem[n];
    int i;
    for (i = 0; i < n; i++) {
        ordem[i] = i;
    }
    embaralhar(ordem, n);
    for (i = 0; i < n; i++) {
        insereCarta(monte, cartas[ordem[i]].cor, cartas[ordem[i]].valor);
    }
}

/**
 * distribui as cartas iniciais para os dois jogadores.
 * monte ponteiro para a lista do monte.
 * j1 ponteiro para a mão do jogador 1.
 * j2 ponteiro para a mão do jogador 2.
 * qtd quantidade de cartas a serem distribuidas para cada jogador.
 */
void distribuiCartas(Lista *monte, Lista *j1, Lista *j2, int qtd) {
	int i;
    for (i = 0; i < qtd; i++) {
        Carta *c1 = removeCartaNoInicio(monte);
        if (c1) {
            c1->prox = j1->inicio;
            j1->inicio = c1;
        }

        Carta *c2 = removeCartaNoInicio(monte);
        if (c2) {
            c2->prox = j2->inicio;
            j2->inicio = c2;
        }
    }
}

/**
 * Libera a memoria alocada por uma lista encadeada, incluindo todos os seus nos.
 * l O ponteiro para a lista a ser liberada.
 */
void liberaLista(Lista *l) {
    Carta *p = l->inicio;
    while(p != NULL) {
        Carta *temp = p;
        p = p->prox;
        free(temp);
    }
    free(l);
}

int main() {
    srand(time(NULL));

    Lista *maos[2] = {criaLista(), criaLista()};
    char *nomes[2] = {"Jogador1", "Jogador2"};

    Lista *monte = criaLista();
    Lista *descarte = criaLista();

    CartaBase cartas_base[30] = {
        {"Vermelho", "0"}, {"Vermelho", "1"}, {"Vermelho", "2"},
        {"Vermelho", "3"}, {"Vermelho", "4"}, {"Vermelho", "5"},
        {"Vermelho", "+2"}, {"Vermelho", "+2"}, {"Vermelho", "Bloqueio"},
        {"Vermelho", "Bloqueio"},

        {"Azul", "0"}, {"Azul", "1"}, {"Azul", "2"},
        {"Azul", "3"}, {"Azul", "4"}, {"Azul", "5"},
        {"Azul", "+2"}, {"Azul", "+2"}, {"Azul", "Bloqueio"},
        {"Azul", "Bloqueio"},

        {"Verde", "0"}, {"Verde", "1"}, {"Verde", "2"},
        {"Verde", "3"}, {"Verde", "4"}, {"Verde", "5"},
        {"Verde", "+2"}, {"Verde", "+2"}, {"Verde", "Bloqueio"}, 
		{"Verde", "Bloqueio"},
    };

	// carrega e distribui as cartas para os jogadores
    carregaBaralho(monte, cartas_base, 30);
    distribuiCartas(monte, maos[0], maos[1], 5);

    
    // inicia o jogo colocando a primeira carta do monte no descarte
    Carta *c = removeCartaNoInicio(monte);
    if (c) {
        c->prox = descarte->inicio;
        descarte->inicio = c;
    }
    
    printf("\n====================================\n");
    printf("        INICIO DO JOGO UNO\n");
    printf("====================================\n");

    // Loop principal do jogo usando um indice para alternar os turnos
    int jogadorAtual = 0;
    while (1) {
        int adversario = (jogadorAtual + 1) % 2;
        int resultadoTurno = 0;
        
        resultadoTurno = turno(maos[jogadorAtual], maos[adversario], monte, descarte, nomes[jogadorAtual], nomes[adversario]);
        
        if (maoTaVazia(maos[jogadorAtual])) {
            printf("\n====================================\n");
            printf("           FIM DE JOGO\n");
            printf("====================================\n");
            printf("%s venceu!\n", nomes[jogadorAtual]);
            printf("====================================\n");
            break;
        }

        // Passa a vez para o proximo jogador
        if(resultadoTurno == 0){
        	jogadorAtual = adversario;
    	}
        else if(resultadoTurno == 1){
        	printf("%s Joga de novo! Ele é bom!", nomes[jogadorAtual]);
		}
    }

	// chama a funcao para liberar a memoria
    liberaLista(maos[0]);
    liberaLista(maos[1]);
    liberaLista(monte);
    liberaLista(descarte);

    return 0;
}