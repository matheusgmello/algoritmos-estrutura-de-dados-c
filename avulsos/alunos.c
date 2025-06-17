#include <stdio.h>
#include <ctype.h> // Para isalpha e isspace

#define MAX_ALUNOS 100

// Struct aninhada para data de matrícula
struct Data {
    int dia;
    int mes;
    int ano;
};

// Struct principal do aluno
struct Aluno {
    int id;
    char nome[50];
    int idade;
    float notaFinal;
    struct Data matricula;
    int ativo; // 1 = ativo, 0 = removido
};

// Verifica se o nome contém apenas letras e espaços
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

// Cadastra novo aluno e retorna novo total
int cadastrarAluno(struct Aluno lista[], int total) {
    if (total >= MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return total;
    }

    struct Aluno novo;

    novo.id = total + 1;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", novo.nome);

    if (!nomeValido(novo.nome)) {
        printf("Nome inválido. Use apenas letras e espaços.\n");
        return total;
    }

    printf("Digite a idade: ");
    scanf("%d", &novo.idade);

    printf("Digite a nota final: ");
    scanf("%f", &novo.notaFinal);

    printf("Digite a data de matrícula (dd mm aaaa): ");
    scanf("%d %d %d", &novo.matricula.dia, &novo.matricula.mes, &novo.matricula.ano);

    novo.ativo = 1;
    lista[total] = novo;

    printf("Aluno cadastrado com sucesso!\n");
    return total + 1;
}

// Remove aluno por ID (marca como inativo)
void removerAluno(struct Aluno lista[], int total) {
    int id;
    int i;

    // Verifica se há algum aluno ativo
    int haAtivos = 0;
    for (i = 0; i < total; i++) {
        if (lista[i].ativo == 1) {
            haAtivos = 1;
            break;
        }
    }

    if (!haAtivos) {
        printf("Nenhum aluno disponível para remoção.\n");
        return;
    }

    printf("Digite o ID do aluno a ser removido: ");
    scanf("%d", &id);

    for (i = 0; i < total; i++) {
        if (lista[i].id == id && lista[i].ativo == 1) {
            lista[i].ativo = 0;
            printf("Aluno removido com sucesso.\n");
            return;
        }
    }

    printf("Aluno não encontrado ou já removido.\n");
}

// Lista alunos ativos
void listarAlunos(struct Aluno lista[], int total) {
    int i;
    int encontrados = 0;

    for (i = 0; i < total; i++) {
        if (lista[i].ativo == 1) {
            encontrados = 1;
            break;
        }
    }

    if (!encontrados) {
        printf("Nenhum aluno registrado para exibição.\n");
        return;
    }

    printf("\n--- Alunos Ativos ---\n");
    for (i = 0; i < total; i++) {
        if (lista[i].ativo == 1) {
            printf("ID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Idade: %d\n", lista[i].idade);
            printf("Nota Final: %.2f\n", lista[i].notaFinal);
            printf("Data de Matrícula: %02d/%02d/%04d\n",
                   lista[i].matricula.dia,
                   lista[i].matricula.mes,
                   lista[i].matricula.ano);
            printf("----------------------\n");
        }
    }
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int total = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Remover Aluno\n");
        printf("3 - Listar Alunos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            total = cadastrarAluno(alunos, total);
        } else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhum aluno cadastrado ainda.\n");
            } else {
                removerAluno(alunos, total);
            }
        } else if (opcao == 3) {
            if (total == 0) {
                printf("Nenhum aluno cadastrado ainda.\n");
            } else {
                listarAlunos(alunos, total);
            }
        } else if (opcao != 0) {
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
