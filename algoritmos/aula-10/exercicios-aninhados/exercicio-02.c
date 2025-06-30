// Inclui as bibliotecas necessárias para entrada/saída e manipulação de strings
#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar um item do pedido
struct itempedido {
    int codigo_item; // Código único do item
    char nome_item[50]; // Nome do item
    float preco_unitario; // Preço unitário do item
    int quantidade_comprada; // Quantidade comprada do item
};

// Definição da estrutura para representar um pedido
struct pedido {
    int numero_pedido; // Número único do pedido
    int dia; // Dia da data do pedido
    int mes; // Mês da data do pedido
    int ano; // Ano da data do pedido
    struct itempedido itens_pedido[3]; // Array de 3 itens que compõem o pedido
};

// Função para criar um item do pedido
struct itempedido criar_item() {
    struct itempedido novo_item;
    printf("digite o codigo do item: ");
    scanf("%d", &novo_item.codigo_item); // Lê o código do item
    getchar(); // Consome o caractere de nova linha
    printf("digite o nome do item: ");
    fgets(novo_item.nome_item, sizeof(novo_item.nome_item), stdin); // Lê o nome do item
    novo_item.nome_item[strcspn(novo_item.nome_item, "\n")] = 0; // Remove o caractere de nova linha
    printf("digite o preco unitario do item: ");
    scanf("%f", &novo_item.preco_unitario); // Lê o preço unitário
    printf("digite a quantidade comprada: ");
    scanf("%d", &novo_item.quantidade_comprada); // Lê a quantidade comprada
    return novo_item; // Retorna o item criado
}

// Função para criar um pedido
struct pedido criar_pedido() {
    struct pedido novo_pedido;
    printf("\n--- criacao de novo pedido ---\n");
    printf("digite o numero do pedido: ");
    scanf("%d", &novo_pedido.numero_pedido); // Lê o número do pedido
    printf("digite o dia do pedido: ");
    scanf("%d", &novo_pedido.dia); // Lê o dia
    printf("digite o mes do pedido: ");
    scanf("%d", &novo_pedido.mes); // Lê o mês
    printf("digite o ano do pedido: ");
    scanf("%d", &novo_pedido.ano); // Lê o ano

    printf("\n--- adicao dos 3 itens do pedido ---\n");
    for (int i = 0; i < 3; i++) { // Loop para adicionar 3 itens ao pedido
        printf("\nitem %d:\n", i + 1);
        novo_pedido.itens_pedido[i] = criar_item(); // Cria e adiciona um item ao pedido
    }
    return novo_pedido; // Retorna o pedido criado
}

// Função para exibir os dados completos de um pedido
void exibir_pedido(struct pedido p) {
    printf("\n--- dados do pedido %d ---\n", p.numero_pedido);
    printf("data: %02d/%02d/%d\n", p.dia, p.mes, p.ano); // Exibe a data do pedido
    printf("itens do pedido:\n");
    for (int i = 0; i < 3; i++) { // Loop para exibir os 3 itens do pedido
        printf("  item %d:\n", i + 1);
        printf("    codigo: %d\n", p.itens_pedido[i].codigo_item); // Exibe o código do item
        printf("    nome: %s\n", p.itens_pedido[i].nome_item); // Exibe o nome do item
        printf("    preco unitario: %.2f\n", p.itens_pedido[i].preco_unitario); // Exibe o preço unitário
        printf("    quantidade: %d\n", p.itens_pedido[i].quantidade_comprada); // Exibe a quantidade comprada
    }
}

// Função para atualizar a quantidade de um item em um pedido
struct pedido atualizar_quantidade_item(struct pedido p) {
    int codigo_busca; // Código do item a ser atualizado
    int nova_quantidade; // Nova quantidade para o item
    int encontrado = 0; // Flag para verificar se o item foi encontrado

    printf("\ndigite o codigo do item que deseja atualizar: ");
    scanf("%d", &codigo_busca); // Lê o código do item a ser atualizado

    for (int i = 0; i < 3; i++) { // Loop para buscar o item no pedido
        if (p.itens_pedido[i].codigo_item == codigo_busca) { // Verifica se o código corresponde
            printf("item '%s' encontrado. digite a nova quantidade: ", p.itens_pedido[i].nome_item);
            scanf("%d", &nova_quantidade); // Lê a nova quantidade
            p.itens_pedido[i].quantidade_comprada = nova_quantidade; // Atualiza a quantidade
            printf("quantidade do item atualizada com sucesso!\n");
            encontrado = 1; // Marca que o item foi encontrado
            break;
        }
    }

    if (!encontrado) { // Caso o item não seja encontrado
        printf("item com codigo %d nao encontrado neste pedido.\n", codigo_busca);
    }

    return p; // Retorna o pedido atualizado
}

int main() {
    struct pedido meu_pedido; // Variável para armazenar o pedido atual
    int opcao; // Opção escolhida pelo usuário no menu
    int pedido_cadastrado = 0; // Flag para verificar se há um pedido cadastrado

    do {
        // Exibe o menu de opções
        printf("\n--- menu de pedidos ---\n");
        printf("1. criar novo pedido\n");
        printf("2. exibir dados do pedido\n");
        printf("3. atualizar quantidade de item\n");
        printf("0. sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao); // Lê a opção escolhida
        getchar(); // Consome o caractere de nova linha

        switch (opcao) {
            case 1:
                meu_pedido = criar_pedido(); // Cria um novo pedido
                pedido_cadastrado = 1; // Marca que há um pedido cadastrado
                break;
            case 2:
                if (pedido_cadastrado) { // Verifica se há um pedido cadastrado
                    exibir_pedido(meu_pedido); // Exibe os dados do pedido
                } else {
                    printf("nenhum pedido cadastrado ainda. crie um pedido primeiro.\n");
                }
                break;
            case 3:
                if (pedido_cadastrado) { // Verifica se há um pedido cadastrado
                    meu_pedido = atualizar_quantidade_item(meu_pedido); // Atualiza a quantidade de um item
                } else {
                    printf("nenhum pedido cadastrado. nao ha itens para atualizar.\n");
                }
                break;
            case 0:
                printf("saindo do programa. ate mais!\n"); // Mensagem de saída
                break;
            default:
                printf("opcao invalida. por favor, tente novamente.\n"); // Mensagem para opção inválida
        }
    } while (opcao != 0); // Repete o menu até que a opção 0 seja escolhida

    return 0; // Finaliza o programa
}
