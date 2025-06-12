#include <stdio.h>
#include <string.h>

#define MAX_PEDIDOS 10           // Máximo de pedidos que podem ser cadastrados
#define ITENS_POR_PEDIDO 3       // Cada pedido possui exatamente 3 itens

// Struct que representa um item de um pedido
struct ItemPedido {
    int codigo_item;                 // Código identificador do item
    char nome_item[30];             // Nome do item
    float preco_unitario;           // Preço unitário do item
    int quantidade_comprada;        // Quantidade comprada do item
};

// Struct que representa um pedido completo
struct Pedido {
    int numero_pedido;                         // Número identificador do pedido
    int dia, mes, ano;                         // Data do pedido
    struct ItemPedido itens_pedido[ITENS_POR_PEDIDO]; // Lista de 3 itens no pedido
};

// Função para cadastrar um novo pedido
int cadastrarPedido(struct Pedido pedidos[], int totalPedidos) {
    if (totalPedidos >= MAX_PEDIDOS) {
        printf("limite de pedidos atingido!\n");
        return totalPedidos; // Se atingiu o limite, não adiciona
    }

    struct Pedido novo; // Cria um novo pedido local

    // Entrada do número e data do pedido
    printf("numero do pedido: ");
    scanf("%d", &novo.numero_pedido);
    printf("data do pedido (dia mes ano): ");
    scanf("%d %d %d", &novo.dia, &novo.mes, &novo.ano);

    // Entrada dos 3 itens do pedido
    for (int i = 0; i < ITENS_POR_PEDIDO; i++) {
        printf("\n--- item %d ---\n", i + 1);
        printf("codigo do item: ");
        scanf("%d", &novo.itens_pedido[i].codigo_item);
        printf("nome do item: ");
        scanf(" %[^\n]", novo.itens_pedido[i].nome_item); // Lê nome com espaços
        printf("preco unitario: ");
        scanf("%f", &novo.itens_pedido[i].preco_unitario);
        printf("quantidade comprada: ");
        scanf("%d", &novo.itens_pedido[i].quantidade_comprada);
    }

    pedidos[totalPedidos] = novo; // Adiciona o novo pedido na lista
    printf("\npedido cadastrado com sucesso!\n");

    return totalPedidos + 1; // Atualiza o total de pedidos
}

// Função para consultar um pedido pelo número
void consultarPedido(struct Pedido pedidos[], int totalPedidos) {
    int numero;
    printf("digite o numero do pedido para consultar: ");
    scanf("%d", &numero);

    int encontrado = 0;
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].numero_pedido == numero) {
            encontrado = 1;

            // Exibe dados do pedido
            printf("\npedido #%d - data: %02d/%02d/%04d\n",
                   pedidos[i].numero_pedido, pedidos[i].dia, pedidos[i].mes, pedidos[i].ano);

            float total = 0; // Para calcular o total do pedido

            // Exibe detalhes de cada item e calcula subtotal
            for (int j = 0; j < ITENS_POR_PEDIDO; j++) {
                struct ItemPedido item = pedidos[i].itens_pedido[j];
                float subtotal = item.preco_unitario * item.quantidade_comprada;
                total += subtotal;

                printf("item %d: codigo: %d | nome: %s | preco: r$ %.2f | quantidade: %d | subtotal: r$ %.2f\n",
                       j + 1, item.codigo_item, item.nome_item, item.preco_unitario,
                       item.quantidade_comprada, subtotal);
            }

            printf("preco total do pedido: r$ %.2f\n", total);
            break;
        }
    }

    if (!encontrado) {
        printf("pedido nao encontrado.\n");
    }
}

// Função para gerar um relatório resumido de todos os pedidos
void gerarRelatorio(struct Pedido pedidos[], int totalPedidos) {
    printf("\n--- relatorio geral de pedidos ---\n");

    for (int i = 0; i < totalPedidos; i++) {
        float total = 0;

        // Calcula o valor total do pedido somando os subtotais dos itens
        for (int j = 0; j < ITENS_POR_PEDIDO; j++) {
            total += pedidos[i].itens_pedido[j].preco_unitario *
                     pedidos[i].itens_pedido[j].quantidade_comprada;
        }

        // Exibe número, data e valor total
        printf("pedido #%d | data: %02d/%02d/%04d | valor total: r$ %.2f\n",
               pedidos[i].numero_pedido, pedidos[i].dia, pedidos[i].mes,
               pedidos[i].ano, total);
    }
}

// Função para atualizar a quantidade de um item específico em um pedido
void atualizarQuantidade(struct Pedido pedidos[], int totalPedidos) {
    int numero, codigo, nova_qtd;

    // Solicita número do pedido
    printf("digite o numero do pedido: ");
    scanf("%d", &numero);

    int pedidoEncontrado = -1;

    // Busca o pedido pelo número
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].numero_pedido == numero) {
            pedidoEncontrado = i;
            break;
        }
    }

    if (pedidoEncontrado == -1) {
        printf("pedido nao encontrado.\n");
        return;
    }

    // Solicita código do item
    printf("digite o codigo do item que deseja atualizar: ");
    scanf("%d", &codigo);

    int itemEncontrado = -1;

    // Busca o item dentro do pedido
    for (int j = 0; j < ITENS_POR_PEDIDO; j++) {
        if (pedidos[pedidoEncontrado].itens_pedido[j].codigo_item == codigo) {
            itemEncontrado = j;
            break;
        }
    }

    if (itemEncontrado == -1) {
        printf("item nao encontrado neste pedido.\n");
        return;
    }

    // Atualiza a quantidade comprada do item
    printf("digite a nova quantidade: ");
    scanf("%d", &nova_qtd);
    pedidos[pedidoEncontrado].itens_pedido[itemEncontrado].quantidade_comprada = nova_qtd;

    printf("quantidade atualizada com sucesso!\n");
}

// Função principal com menu interativo
int main() {
    struct Pedido pedidos[MAX_PEDIDOS]; // Array para armazenar os pedidos
    int totalPedidos = 0;               // Contador de pedidos cadastrados
    int opcao;                          // Opção escolhida no menu

    do {
        // Menu de opções
        printf("\n======= menu principal =======\n");
        printf("1. cadastrar novo pedido\n");
        printf("2. consultar pedido por numero\n");
        printf("3. gerar relatorio de todos os pedidos\n");
        printf("4. atualizar quantidade de item em um pedido\n");
        printf("5. sair do programa\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executa a ação conforme a escolha
        switch (opcao) {
            case 1:
                totalPedidos = cadastrarPedido(pedidos, totalPedidos);
                break;
            case 2:
                consultarPedido(pedidos, totalPedidos);
                break;
            case 3:
                gerarRelatorio(pedidos, totalPedidos);
                break;
            case 4:
                atualizarQuantidade(pedidos, totalPedidos);
                break;
            case 5:
                printf("encerrando o programa...\n");
                break;
            default:
                printf("opcao invalida. tente novamente.\n");
        }

    } while (opcao != 5); // Repete até o usuário escolher sair

    return 0;
}
