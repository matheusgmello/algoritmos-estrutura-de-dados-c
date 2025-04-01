#include <stdio.h>

int main() {
    char nome[50];
    char escolha;
    int tem_chave = 0; // 0 = nao tem chave, 1 = tem chave

    // mini introducao ao jogo
    printf("\n=== LABIRINTO DO TEMPO ===\n");
    printf("Um mini jogo de aventura onde tu decide teu destino!\n");
    printf("Neste jogo, tu eh um viajante do tempo perdido num labirinto temporal.\n");
    printf("Cada escolha muda teu destino.\n\n");

    printf("Digite seu nome: ");
    scanf("%s", nome);
    
    printf("\n=== LABIRINTO DO TEMPO ===\n");
    printf("%s, voce esta em uma sala com um portal do tempo. Escolha:\n", nome);
    printf("1. Ir ao PASSADO (digite 'P')\n");
    printf("2. Ir para o FUTURO (digite 'F')\n");
    printf("3. Ficar no PRESENTE (digite 'C')\n");
    printf("Sua escolha: ");
    scanf(" %c", &escolha);

    // escolha passado
    if (escolha == 'P' || escolha == 'p') {
        printf("\n%s, voce viajou para o PASSADO (Ano 1150)! Um cavaleiro pede ajuda:\n", nome);
        printf("1. Ajudar a lutar contra um dragao (digite 'L')\n");
        printf("2. Roubar um artefato magico (digite 'R')\n");
        printf("Sua escolha: ");
        scanf(" %c", &escolha);

        if (escolha == 'L' || escolha == 'l') {
            printf("\nVoce derrotou o dragao! Ganhou uma CHAVE DO TEMPO.\n");
            tem_chave = 1;
        } else {
            printf("\n%s, voce foi preso pelos guardas! FIM DO JOGO.\n", nome);
            return 0;
        }

    // escolha futuro
    } else if (escolha == 'F' || escolha == 'f') {
        printf("\n%s, voce viajou para o FUTURO (Ano 2222)! Robos dominaram o mundo:\n", nome);
        printf("1. Juntar-se aos rebeldes (digite 'J')\n");
        printf("2. Tentar consertar uma maquina do tempo (digite 'M')\n");
        printf("Sua escolha: ");
        scanf(" %c", &escolha);

        if (escolha == 'M' || escolha == 'm') {
            printf("\nVoce tenta consertar a maquina, mas falta uma CHAVE...\n");
            printf("\nO que deseja fazer?\n");
            printf("1. Vasculhar em busca da chave (digite 'V')\n");
            printf("2. Desistir (digite 'D')\n");
            printf("Sua escolha: ");
            scanf(" %c", &escolha);

            if (escolha == 'V' || escolha == 'v') {
                printf("\n%s, voce encontrou duas opcoes de busca:\n", nome);
                printf("1. Procurar na sala de controle (digite 'C')\n");
                printf("2. Procurar nos corredores subterraneos (digite 'S')\n");
                printf("Sua escolha: ");
                scanf(" %c", &escolha);

                if (escolha == 'C' || escolha == 'c') {
                    printf("\nVoce encontrou a CHAVE DO TEMPO!\n");
                    tem_chave = 1;
                } else {
                    printf("\n%s, voce caiu em um calabouco sem saida! FIM DO JOGO.\n", nome);
                    return 0;
                }
            } else {
                printf("\nVoce desiste e fica preso no tempo! FIM DO JOGO.\n");
                return 0;
            }
        } else {
            printf("\nOs robos te capturam! FIM DO JOGO.\n");
            return 0;
        }
    } else {
        printf("\n%s, escolha invalida! O portal se fecha... FIM DO JOGO.\n", nome);
        return 0;
    }

    // parte final se jogador nao falhar antes
    printf("\nO portal se reabre! %s, voce:\n", nome);
    printf("1. Usar a CHAVE DO TEMPO para voltar (digite 'U')\n");
    printf("2. Viajar para uma era aleatoria (digite 'A')\n");
    printf("Sua escolha: ");
    scanf(" %c", &escolha);

    if ((escolha == 'U' || escolha == 'u') && tem_chave == 1) {
        printf("\nPARABENS, %s! Voce voltou para casa com a CHAVE DO TEMPO!\n", nome);
    } else if (escolha == 'A' || escolha == 'a') {
        printf("\n%s, voce viaja para a era dos dinossauros...\nInfelizmente nao tem nada pra fazer com os dinossauros. FIM DO JOGO.\n", nome);
    } else {
        printf("\n%s, voce nao possui a chave e ficou preso no paradoxo do tempo! FIM DO JOGO.\n", nome);
    }

    return 0;
}