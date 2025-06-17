#include <stdio.h>
#include <ctype.h> // Fornece funções para testar caracteres (letra, espaço, etc.)

#define MAX_PRODUTOS 100

// Struct de data aninhada dentro da struct de produto
struct Data {
    int dia;
    int mes;
    int ano;
};

struct Produto {
    int id;
    char nome[50];
    float preco;
    struct Data validade;
    int ativo; // 1 = ativo, 0 = deletado
};

// Função para validar nome: apenas letras e espaços
int nomeValido(const char nome[]) {
    int i = 0;
    while (nome[i] != '\0') {
        // isalpha: verifica se é letra | isspace: verifica se é espaço
        if (!isalpha(nome[i]) && !isspace(nome[i])) {
            return 0; // nome inválido
        }
        i++;
    }
    return 1;
}

// Função para registrar novo produto
int registrarProduto(struct Produto lista[], int total) {
    if (total >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return total;
    }

    struct Produto novo;

    novo.id = total + 1;

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo.nome);

    if (!nomeValido(novo.nome)) {
        printf("Nome inválido. Use apenas letras e espaços.\n");
        return total;
    }

    printf("Digite o preço: ");
    scanf("%f", &novo.preco);

    printf("Digite a data de validade (dd mm aaaa): ");
    scanf("%d %d %d", &novo.validade.dia, &novo.validade.mes, &novo.validade.ano);

    novo.ativo = 1;

    lista[total] = novo;

    printf("Produto registrado com sucesso!\n");
    return total + 1;
}

// Função para deletar um produto por ID
void deletarProduto(struct Produto lista[], int total) {
    int id;
    int i;
    printf("Digite o ID do produto a ser removido: ");
    scanf("%d", &id);

    for (i = 0; i < total; i++) {
        if (lista[i].id == id && lista[i].ativo == 1) {
            lista[i].ativo = 0;
            printf("Produto removido com sucesso.\n");
            return;
        }
    }

    printf("Produto não encontrado ou já foi removido.\n");
}

// Função para listar todos os produtos ativos
void listarProdutos(struct Produto lista[], int total) {
    int i;
    printf("\n--- Lista de Produtos Ativos ---\n");

    for (i = 0; i < total; i++) {
        if (lista[i].ativo == 1) {
            printf("ID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Preço: R$ %.2f\n", lista[i].preco);
            printf("Validade: %02d/%02d/%04d\n", lista[i].validade.dia,
                                                 lista[i].validade.mes,
                                                 lista[i].validade.ano);
            printf("-----------------------------\n");
        }
    }
}

int main() {
    struct Produto produtos[MAX_PRODUTOS];
    int total = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Registrar Produto\n");
        printf("2 - Deletar Produto\n");
        printf("3 - Listar Produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            total = registrarProduto(produtos, total);
        } else if (opcao == 2) {
            deletarProduto(produtos, total);
        } else if (opcao == 3) {
            listarProdutos(produtos, total);
        } else if (opcao != 0) {
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
