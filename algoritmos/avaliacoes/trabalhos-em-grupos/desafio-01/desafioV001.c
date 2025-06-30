/*
Imagine que você está desenvolvendo um jogo interativo, onde o personagem principal precisa tomar decisões baseadas em informações que surgem durante a aventura. 
Cada decisão afeta o resultado do jogo e pode levar a diferentes caminhos, dependendo da escolha do jogador.
Neste exercício, você vai implementar uma parte do jogo usando desvios condicionais (if, else, e else if). 
O objetivo é criar uma narrativa simples, onde o jogador faz escolhas e o programa decide o resultado de acordo com essas escolhas.
*/

#include <stdio.h>
int main() {
    char escolha;
    int tem_chave = 0; // 0 = num tem chave, 1 = tem chave

	// escolher passado, futuro ou presente
    printf("\n=== LABIRINTO DO TEMPO ===\n");
    printf("tu esta em uma sala com um portal do tempo. escolha:\n");
    printf("1. ir ao PASSADO (digite 'P')\n");
    printf("2. ir para o FUTURO (digite 'F')\n");
    printf("3. ficar no PRESENTE (digite 'C')\n");
    printf("tua escolha: ");
    scanf(" %c", &escolha);

    // escolha passado
    if (escolha == 'P' || escolha == 'p') {
        printf("\ntu viajou para o PASSADO (Ano 1150) um cavaleiro pede ajuda:\n");
        printf("1. ajudar a lutar contra um dragao (digite 'L')\n");
        printf("2. roubar um artefato magico (digite 'R')\n");
        printf("tua escolha: ");
        scanf(" %c", &escolha);

        if (escolha == 'L' || escolha == 'l') {
            printf("\ntu derrotou o dragao! ganhaste uma CHAVE DO TEMPO.\n");
            tem_chave = 1;
        } else {
            printf("\ntu foi preso pelos guardas! FIM DO JOGO.\n");
            return 0;
        }

	// escolha futuro
    } else if (escolha == 'F' || escolha == 'f') {
        printf("\ntu viaja para o FUTURO (Ano 2222)! robos dominaram o mundo:\n");
        printf("1. juntar-se aos rebeldes (digite 'J')\n");
        printf("2. tentar consertar uma maquina do tempo (digite 'M')\n");
        printf("tua escolha: ");
        scanf(" %c", &escolha);

        if (escolha == 'M' || escolha == 'm') {
            printf("\ntu tenta consertar a maquina, mas falta uma CHAVE...\n");
            printf("\nO que voce deseja fazer?\n");
            printf("1. vasculhar em busca da chave (digite 'V')\n");
            printf("2. desistir (digite 'D')\n");
            printf("tua escolha: ");
            scanf(" %c", &escolha);

            if (escolha == 'V' || escolha == 'v') {
                printf("\nvoce encontrou duas opcoes de busca:\n");
                printf("1. procurar na sala de controle (digite 'C')\n");
                printf("2. procurar nos corredores subterraneos (digite 'S')\n");
                printf("tua escolha: ");
                scanf(" %c", &escolha);

                if (escolha == 'C' || escolha == 'c') {
                    printf("\nvoce encontrou a CHAVE DO TEMPO!\n");
                    tem_chave = 1;
                } else {
                    printf("\nvoce caiu em um calabouco sem saida! FIM DO JOGO.\n");
                    return 0;
                }
            } else {
                printf("\nvoce desiste e fica preso no tempo! FIM DO JOGO.\n");
                return 0;
            }
        } else {
            printf("\nos robos te capturam! FIM DO JOGO.\n");
            return 0;
        }
    
	// escolha presente
    } else if (escolha == 'C' || escolha == 'c') {
        printf("\nficar no PRESENTE causa um PARADOXO! O tempo comeca a se desfazer:\n");
        printf("1. correr para o portal (digite 'O')\n");
        printf("2. esperar (digite 'E')\n");
        printf("3. tentar estabilizar o tempo (digite 'T')\n");
        printf("tua escolha: ");
        scanf(" %c", &escolha);

        if (escolha == 'E' || escolha == 'e') {
            printf("\ninfelizmente tu foi apagado da existencia! FIM DO JOGO.\n");
            return 0;
        } else if (escolha == 'T' || escolha == 't') {
            printf("\nvoce conseguiu estabilizar o tempo e desbloqueou um novo caminho!\n");
            
            // caminho alternativo
            printf("\nduas portas aparecem na sua frente:\n");
            printf("1. escolher a porta da esquerda (digite 'E')\n");
            printf("2. escolher a porta da direita (digite 'D')\n");
            printf("tua escolha: ");
            scanf(" %c", &escolha);

            if (escolha == 'E' || escolha == 'e') {
                printf("\nvoce encontrou a CHAVE DO TEMPO!\n");
                tem_chave = 1;
            } else {
                printf("\num Cerberus aparece e te devora! FIM DO JOGO.\n");
                return 0;
            }
        }
    } else {
        printf("\nescolha invalida! o portal se fecha... FIM DO JOGO.\n");
        return 0;
    }

    // parte final se jogador nao falhar antes
    printf("\no portal se reabre! voce:\n");
    printf("1. usar a CHAVE DO TEMPO para voltar (digite 'U')\n");
    printf("2. viajar para uma era aleatoria (digite 'A')\n");
    printf("sua escolha: ");
    scanf(" %c", &escolha);

    if ((escolha == 'U' || escolha == 'u') && tem_chave == 1) {
        printf("\nPARABENS! voce voltou para casa com a CHAVE DO TEMPO!\n");
    } else if (escolha == 'A' || escolha == 'a') {
        printf("\nvoce viaja para a era dos dinossauros...\ninfelizmente num tem nada pra fazer com os dinossauros\nFIM DO JOGO.\n");
    } else {
        printf("\nvoce nao possui a chave e ficou preso no paradoxo do tempo! FIM DO JOGO.\n");
    }

    return 0;
}
