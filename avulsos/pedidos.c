// inclui as bibliotecas necessarias para entrada/saida e manipulacao de strings
#include <stdio.h>
#include <string.h>

#define MAX_PEDIDOS 5
#define ITENS_POR_PEDIDO 3

// struct para representar cada item do pedido
struct ItemPedido {
    int codigo_item;
    char nome_item[30];
    float preco_unitario;
    int quantidade_comprada;
};

// struct para representar o pedido completo
struct Pedido {
    int numero_pedido;
    int dia, mes, ano;
    struct ItemPedido itens[ITENS_POR_PEDIDO];
};

int main() {
    struct Pedido pedidos[MAX_PEDIDOS];
    int totalPedidos = 0;
    int opcao;

    do {
        printf("\n--- menu ---\n");
        printf("1. cadastrar pedido\n");
        printf("2. visualizar pedidos\n");
        printf("3. atualizar quantidade de item\n");
        printf("4. sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            if (totalPedidos >= MAX_PEDIDOS) {
                printf("limite de pedidos atingido.\n");
                break;
            }

            printf("\n--- cadastro de pedido ---\n");
            pedidos[totalPedidos].numero_pedido = totalPedidos + 1;

            printf("data do pedido (dia mes ano): ");
            scanf("%d %d %d", &pedidos[totalPedidos].dia, &pedidos[totalPedidos].mes, &pedidos[totalPedidos].ano);

            for (int i = 0; i < ITENS_POR_PEDIDO; i++) {
                printf("\nitem %d\n", i + 1);
                printf("codigo do item: ");
                scanf("%d", &pedidos[totalPedidos].itens[i].codigo_item);
                printf("nome do item: ");
                scanf(" %[^]", pedidos[totalPedidos].itens[i].nome_item);
                printf("preco unitario: ");
                scanf("%f", &pedidos[totalPedidos].itens[i].preco_unitario);
                printf("quantidade comprada: ");
                scanf("%d", &pedidos[totalPedidos].itens[i].quantidade_comprada);
            }

            totalPedidos++;
            printf("pedido cadastrado com sucesso!\n");
            break;

        case 2:
            printf("\n--- visualizacao de pedidos ---\n");
            for (int i = 0; i < totalPedidos; i++) {
                printf("\npedido #%d - data: %02d/%02d/%04d\n", pedidos[i].numero_pedido,
                    pedidos[i].dia, pedidos[i].mes, pedidos[i].ano);

                float total = 0.0;
                for (int j = 0; j < ITENS_POR_PEDIDO; j++) {
                    struct ItemPedido item = pedidos[i].itens[j];
                    float subtotal = item.preco_unitario * item.quantidade_comprada;
                    total += subtotal;

                    printf("item %d: %s | codigo: %d | preco: r$ %.2f | quantidade: %d | subtotal: r$ %.2f\n",
                        j + 1, item.nome_item, item.codigo_item,
                        item.preco_unitario, item.quantidade_comprada, subtotal);
                }

                printf("valor total do pedido: r$ %.2f\n", total);
            }
            break;

        case 3:
            printf("\n--- atualizar quantidade de item ---\n");
            int numPedido, numItem;
            printf("digite o numero do pedido (1 a %d): ", totalPedidos);
            scanf("%d", &numPedido);

            if (numPedido < 1 || numPedido > totalPedidos) {
                printf("pedido invalido.\n");
                break;
            }

            printf("digite o numero do item (1 a 3): ");
            scanf("%d", &numItem);

            if (numItem < 1 || numItem > 3) {
                printf("item invalido.\n");
                break;
            }

            printf("nova quantidade: ");
            scanf("%d", &pedidos[numPedido - 1].itens[numItem - 1].quantidade_comprada);
            printf("quantidade atualizada com sucesso!\n");
            break;

        case 4:
            printf("encerrando o programa...\n");
            break;

        default:
            printf("opcao invalida. tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
