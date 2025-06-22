#include <stdio.h>
#include <ctype.h> // Para isalpha e isspace

#define MAX_FUNCIONARIOS 100

// Struct aninhada para data de admissão
struct Data {
    int dia;
    int mes;
    int ano;
};

// Struct principal do funcionário
struct Funcionario {
    int id;
    char nome[50];
    int idade;
    float salario;
    struct Data admissao;
    int ativo; // 1 = ativo, 0 = removido
};

// Função para validar nome (somente letras e espaços)
int nomeValido(const char nome[]) {
    int i = 0;
    while (nome[i] != '\0') {
        if (!isalpha(nome[i]) && !isspace(nome[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Cadastrar novo funcionário
int cadastrarFuncionario(struct Funcionario lista[], int total) {
    if (total >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionários atingido.\n");
        return total;
    }

    struct Funcionario novo;

    novo.id = total + 1;

    printf("Digite o nome do funcionário: ");
    scanf(" %[^\n]", novo.nome);

    if (!nomeValido(novo.nome)) {
        printf("Nome inválido. Use apenas letras e espaços.\n");
        return total;
    }

    printf("Digite a idade: ");
    scanf("%d", &novo.idade);

    printf("Digite o salário: ");
    scanf("%f", &novo.salario);

    printf("Digite a data de admissão (dd mm aaaa): ");
    scanf("%d %d %d", &novo.admissao.dia, &novo.admissao.mes, &novo.admissao.ano);

    novo.ativo = 1;
    lista[total] = novo;

    printf("Funcionário cadastrado com sucesso!\n");
    return total + 1;
}

// Remover funcionário por ID (marcar como inativo)
void removerFuncionario(struct Funcionario lista[], int total) {
    int i, id;
    int haAtivos = 0;

    for (i = 0; i < total; i++) {
        if (lista[i].ativo == 1) {
            haAtivos = 1;
            break;
        }
    }

    if (!haAtivos) {
        printf("Nenhum funcionário disponível para remoção.\n");
        return;
    }

    printf("Digite o ID do funcionário a ser removido: ");
    scanf("%d", &id);

    for (i = 0; i < total; i++) {
        if (lista[i].id == id && lista[i].ativo == 1) {
            lista[i].ativo = 0;
            printf("Funcionário removido com sucesso.\n");
            return;
        }
    }

    printf("Funcionário não encontrado ou já removido.\n");
}

// Listar funcionários ativos
void listarFuncionarios(struct Funcionario lista[], int total) {
    int i, haAtivos = 0;

    for (i = 0; i < total; i++) {
        if (lista[i].ativo == 1) {
            haAtivos = 1;
            break;
        }
    }

    if (!haAtivos) {
        printf("Nenhum funcionário registrado para exibição.\n");
        return;
    }

    printf("\n--- Funcionários Ativos ---\n");
    for (i = 0; i < total; i++) {
        if (lista[i].ativo == 1) {
            printf("ID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Idade: %d\n", lista[i].idade);
            printf("Salário: R$ %.2f\n", lista[i].salario);
            printf("Data de Admissão: %02d/%02d/%04d\n",
                   lista[i].admissao.dia,
                   lista[i].admissao.mes,
                   lista[i].admissao.ano);
            printf("-----------------------------\n");
        }
    }
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int total = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar Funcionário\n");
        printf("2 - Remover Funcionário\n");
        printf("3 - Listar Funcionários\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            total = cadastrarFuncionario(funcionarios, total);
        } else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhum funcionário cadastrado ainda.\n");
            } else {
                removerFuncionario(funcionarios, total);
            }
        } else if (opcao == 3) {
            if (total == 0) {
                printf("Nenhum funcionário cadastrado ainda.\n");
            } else {
                listarFuncionarios(funcionarios, total);
            }
        } else if (opcao != 0) {
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
