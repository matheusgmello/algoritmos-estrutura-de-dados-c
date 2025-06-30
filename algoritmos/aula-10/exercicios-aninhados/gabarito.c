#include <stdio.h>
#include <string.h>

// Definição da estrutura Fornecedor
struct Fornecedor {
    char nomeEmpresa[20];
    char contato[30];
};

// Definição da estrutura Produto que inclui um Fornecedor
struct Produto {
    int codigo;
    char nome[20];
    float preco;
    float qtd;
    struct Fornecedor emp;
};

// Função para buscar um fornecedor pelo contato
int buscaEmpresa(struct Fornecedor forn[100], int cf, char contato[30]) {
    int i = 0;
    while (i < cf && strcmp(contato, forn[i].contato) != 0) {
        i++;
    }
    return i;
}

// Função para inserir um produto
void insereProduto(struct Fornecedor forn[100], struct Produto prod[200], int cp, int cf) {
    printf("\nInsira os dados do produto\n");
    prod[cp].codigo = 100 + cp;
    printf("Codigo: %d\n", prod[cp].codigo);

    printf("Nome: ");
    fflush(stdin);
    gets(prod[cp].nome);

    printf("Preco: ");
    scanf("%f", &prod[cp].preco);

    printf("Quantidade: ");
    scanf("%f", &prod[cp].qtd);

    printf("Contato do fornecedor: ");
    int r;
    do {
        fflush(stdin);
        gets(prod[cp].emp.contato);
        r = buscaEmpresa(forn, cf, prod[cp].emp.contato);

        if (r == cf) {
            printf("Empresa não encontrada. Digite o contato: \n");
        } else {
            strcpy(prod[cp].emp.nomeEmpresa, forn[r].nomeEmpresa);
        }
    } while (r == cf);
}

// Função para inserir um fornecedor
void insereFornecedor(struct Fornecedor forn[100], int cf) {
    printf("\nInsira os dados do fornecedor: \n");

    printf("Nome da empresa: ");
    fflush(stdin);
    gets(forn[cf].nomeEmpresa);

    printf("Contato da empresa: ");
    fflush(stdin);
    gets(forn[cf].contato);
}

// Função para exibir o relatório de produtos
void relatorioProdutos(struct Produto prod[200], int cp) {
    int i;
    for (i = 0; i < cp; i++) {
        printf("\nDados do produto\n");
        printf("Codigo: %d\n", prod[i].codigo);

        printf("Nome: ");
        puts(prod[i].nome);

        printf("Preco: %.2f\n", prod[i].preco);
        printf("Quantidade: %.2f\n", prod[i].qtd);

        printf("Nome da empresa: ");
        puts(prod[i].emp.nomeEmpresa);

        printf("Contato do fornecedor: ");
        puts(prod[i].emp.contato);
        printf("\n");
    }
}

// Função para exibir o relatório de fornecedores
void relatorioFornecedores(struct Fornecedor forn[100], int cf) {
    int i;
    for (i = 0; i < cf; i++) {
        printf("\nDados do fornecedor: \n");

        printf("Nome da empresa: ");
        puts(forn[i].nomeEmpresa);

        printf("Contato: ");
        puts(forn[i].contato);
    }
}

// Função para atualizar dados de um produto
void atualizaProduto(struct Fornecedor forn[100], struct Produto prod[200], int cp, int cf) {
    int cod, i = 0, op;

    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);

    while (i < cp && cod != prod[i].codigo) {
        i++;
    }

    if (i == cp) {
        printf("Produto não encontrado. \n");
        return;
    } else {
        printf("Escolha um campo para atualizar\n");
        printf("1. Nome\n");
        printf("2. Preco\n");
        printf("3. Quantidade\n");
        printf("4. Dados do fornecedor\n");
        scanf("%d", &op);

        if (op == 1) {
            printf("Digite o novo nome: ");
            fflush(stdin);
            gets(prod[i].nome);
        } else if (op == 2) {
            printf("Digite o novo preco: ");
            scanf("%f", &prod[i].preco);
        } else if (op == 3) {
            printf("Digite a nova quantidade: ");
            scanf("%f", &prod[i].qtd);
        } else if (op == 4) {
            printf("Digite o contato da empresa: ");
            int r;
            char c[30];
            do {
                fflush(stdin);
                gets(c);
                r = buscaEmpresa(forn, cf, c);
                if (r == cf) {
                    printf("Empresa não encontrada. Digite o contato: \n");
                } else {
                    strcpy(prod[i].emp.nomeEmpresa, forn[r].nomeEmpresa);
                    strcpy(prod[i].emp.contato, forn[r].contato);
                }
            } while (r == cf);
        }
    }
}

// Função para atualizar dados de um fornecedor
void atualizaFornecedor(struct Fornecedor forn[100], struct Produto prod[200], int cp, int cf) {
    int i, r;
    char contato[30];

    printf("Digite o contato da empresa a ser atualizada: ");
    fflush(stdin);
    gets(contato);

    r = buscaEmpresa(forn, cf, contato);

    if (r == cf) {
        printf("Empresa nao encontrada. \n");
    } else {
        printf("Digite os novos dados:\n");

        printf("Nome da empresa: ");
        fflush(stdin);
        gets(forn[r].nomeEmpresa);

        printf("Contato da empresa: ");
        fflush(stdin);
        gets(forn[r].contato);

        for (i = 0; i < cp; i++) {
            if (strcmp(contato, prod[i].emp.contato) == 0) {
                strcpy(prod[i].emp.nomeEmpresa, forn[r].nomeEmpresa);
                strcpy(prod[i].emp.contato, forn[r].contato);
            }
        }
    }
}

// Função principal
int main() {
    struct Fornecedor forn[100];
    struct Produto prod[200];
    int contaProd = 0, contaForn = 0, op;

    do {
        printf("\n1. Inserir produto\n");
        printf("2. Inserir fornecedor\n");
        printf("3. Relatorio de produtos\n");
        printf("4. Relatorio de fornecedores\n");
        printf("5. Atualizar produto\n");
        printf("6. Atualizar fornecedor\n");
        printf("7. Sair\n");
        scanf("%d", &op);

        if (op == 1) {
            if (contaForn == 0) {
                printf("Primeiro voce deve cadastrar um fornecedor. \n");
            } else {
                insereProduto(forn, prod, contaProd, contaForn);
                contaProd++;
            }
        } else if (op == 2) {
            insereFornecedor(forn, contaForn);
            contaForn++;
        } else if (op == 3) {
            relatorioProdutos(prod, contaProd);
        } else if (op == 4) {
            relatorioFornecedores(forn, contaForn);
        } else if (op == 5) {
            atualizaProduto(forn, prod, contaProd, contaForn);
        } else if (op == 6) {
            atualizaFornecedor(forn, prod, contaProd, contaForn);
        }
    } while (op != 7);

    return 0;
}
