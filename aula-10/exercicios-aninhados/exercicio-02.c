#include <stdio.h>
#include <string.h>

// definicao da struct itempedido
struct itempedido {
    int codigo_item;
    char nome_item[50];
    float preco_unitario;
    int quantidade_comprada;
};

// definicao da struct pedido
struct pedido {
    int numero_pedido;
    int dia;
    int mes;
    int ano;
    struct itempedido itens_pedido[3]; // cada pedido tem exatamente 3 itens
};

// funcao para criar um item
struct itempedido criar_item() {
    struct itempedido novo_item;
    printf("digite o codigo do item: ");
    scanf("%d", &novo_item.codigo_item);
    getchar(); // consome o newline
    printf("digite o nome do item: ");
    fgets(novo_item.nome_item, sizeof(novo_item.nome_item), stdin);
    novo_item.nome_item[strcspn(novo_item.nome_item, "\n")] = 0; // remove o newline
    printf("digite o preco unitario do item: ");
    scanf("%f", &novo_item.preco_unitario);
    printf("digite a quantidade comprada: ");
    scanf("%d", &novo_item.quantidade_comprada);
    return novo_item;
}

// funcao para criar um pedido
struct pedido criar_pedido() {
    struct pedido novo_pedido;
    printf("\n--- criacao de novo pedido ---\n");
    printf("digite o numero do pedido: ");
    scanf("%d", &novo_pedido.numero_pedido);
    printf("digite o dia do pedido: ");
    scanf("%d", &novo_pedido.dia);
    printf("digite o mes do pedido: ");
    scanf("%d", &novo_pedido.mes);
    printf("digite o ano do pedido: ");
    scanf("%d", &novo_pedido.ano);

    printf("\n--- adicao dos 3 itens do pedido ---\n");
    for (int i = 0; i < 3; i++) {
        printf("\nitem %d:\n", i + 1);
        novo_pedido.itens_pedido[i] = criar_item();
    }
    return novo_pedido;
}

// funcao para exibir dados completos de um pedido
void exibir_pedido(struct pedido p) {
    printf("\n--- dados do pedido %d ---\n", p.numero_pedido);
    printf("data: %02d/%02d/%d\n", p.dia, p.mes, p.ano);
    printf("itens do pedido:\n");
    for (int i = 0; i < 3; i++) {
        printf("  item %d:\n", i + 1);
        printf("    codigo: %d\n", p.itens_pedido[i].codigo_item);
        printf("    nome: %s\n", p.itens_pedido[i].nome_item);
        printf("    preco unitario: %.2f\n", p.itens_pedido[i].preco_unitario);
        printf("    quantidade: %d\n", p.itens_pedido[i].quantidade_comprada);
    }
}

// funcao para atualizar a quantidade de um item em um pedido
void atualizar_quantidade_item(struct pedido *p) {
    int codigo_busca;
    int nova_quantidade;
    int encontrado = 0;

    printf("\ndigite o codigo do item que deseja atualizar: ");
    scanf("%d", &codigo_busca);

    for (int i = 0; i < 3; i++) {
        if (p->itens_pedido[i].codigo_item == codigo_busca) {
            printf("item '%s' encontrado. digite a nova quantidade: ", p->itens_pedido[i].nome_item);
            scanf("%d", &nova_quantidade);
            p->itens_pedido[i].quantidade_comprada = nova_quantidade;
            printf("quantidade do item atualizada com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("item com codigo %d nao encontrado neste pedido.\n", codigo_busca);
    }
}

int main() {
    struct pedido meu_pedido;
    int opcao;

    do {
        printf("\n--- menu de pedidos ---\n");
        printf("1. criar novo pedido\n");
        printf("2. exibir dados do pedido\n");
        printf("3. atualizar quantidade de item\n");
        printf("0. sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // consome o newline

        switch (opcao) {
            case 1:
                meu_pedido = criar_pedido();
                break;
            case 2:
                exibir_pedido(meu_pedido);
                break;
            case 3:
                atualizar_quantidade_item(&meu_pedido);
                break;
            case 0:
                printf("saindo do programa. ate mais!\n");
                break;
            default:
                printf("opcao invalida. por favor, tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}