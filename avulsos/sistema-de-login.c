#include <stdio.h> // Para entrada e saída (printf, scanf, fgets)
#include <string.h> // Para manipulação de strings (strcpy, strcmp, strlen)
#include <stdlib.h> // Para system("cls") ou system("clear") e exit()

// Define o número máximo de usuários que o sistema pode armazenar.
// Evita ponteiros para arrays dinâmicos.
#define MAX_USUARIOS 10
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

// Struct aninhada para as credenciais de login
struct Credenciais {
    char username[MAX_USERNAME_LEN + 1]; // +1 para o terminador nulo '\0'
    char password[MAX_PASSWORD_LEN + 1]; // +1 para o terminador nulo '\0'
};

// Struct principal para o usuário, contendo as credenciais aninhadas
struct Usuario {
    struct Credenciais login;
    int ativo; // 0 para inativo (deletado), 1 para ativo
};

// Array de structs para armazenar os usuários. Sem ponteiros.
struct Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0; // Contador de usuários ativos. Sem variável global, mas é mantido como estado.

// --- Funções de Utilitário ---

// Limpa o buffer de entrada para evitar problemas com fgets/scanf misturados
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Limpa a tela do console
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// --- Funções do Sistema de Login ---

// Inicializa o array de usuários
void inicializarUsuarios() {
    int i;
    for (i = 0; i < MAX_USUARIOS; i++) {
        usuarios[i].ativo = 0; // Marca todos como inativos inicialmente
        strcpy(usuarios[i].login.username, "");
        strcpy(usuarios[i].login.password, "");
    }
}

// Função para criar um novo usuário
void criarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite máximo de usuários atingido. Impossível criar novo usuário.\n");
        return;
    }

    char novoUsername[MAX_USERNAME_LEN + 1];
    char novaPassword[MAX_PASSWORD_LEN + 1];
    int i;

    printf("\n--- Criar Novo Usuário ---\n");

    // Encontra a primeira posição disponível (inativa) no array
    int indiceDisponivel = -1;
    for (i = 0; i < MAX_USUARIOS; i++) {
        if (usuarios[i].ativo == 0) {
            indiceDisponivel = i;
            break;
        }
    }

    if (indiceDisponivel == -1) { // Caso não haja mais slots disponíveis, mesmo após deleções
        printf("Não há slots disponíveis para novos usuários.\n");
        return;
    }

    printf("Digite o nome de usuário (max %d caracteres): ", MAX_USERNAME_LEN);
    fgets(novoUsername, sizeof(novoUsername), stdin);
    novoUsername[strcspn(novoUsername, "\n")] = 0; // Remove o newline

    // Verifica se o username já existe
    for (i = 0; i < MAX_USUARIOS; i++) {
        if (usuarios[i].ativo == 1 && strcmp(usuarios[i].login.username, novoUsername) == 0) {
            printf("Nome de usuário já existe. Escolha outro.\n");
            return;
        }
    }

    printf("Digite a senha (max %d caracteres): ", MAX_PASSWORD_LEN);
    fgets(novaPassword, sizeof(novaPassword), stdin);
    novaPassword[strcspn(novaPassword, "\n")] = 0; // Remove o newline

    // Copia os dados para a struct do novo usuário
    strcpy(usuarios[indiceDisponivel].login.username, novoUsername);
    strcpy(usuarios[indiceDisponivel].login.password, novaPassword);
    usuarios[indiceDisponivel].ativo = 1; // Ativa o usuário
    totalUsuarios++;

    printf("Usuário '%s' criado com sucesso!\n", novoUsername);
}

// Função para realizar o login de um usuário
void fazerLogin() {
    char usernameInput[MAX_USERNAME_LEN + 1];
    char passwordInput[MAX_PASSWORD_LEN + 1];
    int i;
    int loginSucesso = 0;

    printf("\n--- Login ---\n");
    printf("Nome de usuário: ");
    fgets(usernameInput, sizeof(usernameInput), stdin);
    usernameInput[strcspn(usernameInput, "\n")] = 0; // Remove o newline

    printf("Senha: ");
    fgets(passwordInput, sizeof(passwordInput), stdin);
    passwordInput[strcspn(passwordInput, "\n")] = 0; // Remove o newline

    for (i = 0; i < MAX_USUARIOS; i++) {
        if (usuarios[i].ativo == 1 &&
            strcmp(usuarios[i].login.username, usernameInput) == 0 &&
            strcmp(usuarios[i].login.password, passwordInput) == 0) {
            printf("\nLogin bem-sucedido! Bem-vindo, %s!\n", usuarios[i].login.username);
            loginSucesso = 1;
            break;
        }
    }

    if (!loginSucesso) {
        printf("\nNome de usuário ou senha incorretos.\n");
    }
}

// Função para exibir o relatório de usuários
void relatorioUsuarios() {
    int i;
    int encontrouAtivo = 0;

    printf("\n--- Relatório de Usuários ---\n");
    printf("------------------------------\n");
    printf("ID | Nome de Usuário\n");
    printf("------------------------------\n");

    for (i = 0; i < MAX_USUARIOS; i++) {
        if (usuarios[i].ativo == 1) {
            printf("%2d | %s\n", i, usuarios[i].login.username);
            encontrouAtivo = 1;
        }
    }

    if (!encontrouAtivo) {
        printf("Nenhum usuário ativo registrado.\n");
    }
    printf("------------------------------\n");
}

// Função para deletar um usuário
void deletarUsuario() {
    char usernameParaDeletar[MAX_USERNAME_LEN + 1];
    int i;
    int usuarioEncontrado = 0;

    printf("\n--- Deletar Usuário ---\n");
    printf("Digite o nome de usuário a ser deletado: ");
    fgets(usernameParaDeletar, sizeof(usernameParaDeletar), stdin);
    usernameParaDeletar[strcspn(usernameParaDeletar, "\n")] = 0; // Remove o newline

    for (i = 0; i < MAX_USUARIOS; i++) {
        if (usuarios[i].ativo == 1 && strcmp(usuarios[i].login.username, usernameParaDeletar) == 0) {
            usuarios[i].ativo = 0; // Marca como inativo
            strcpy(usuarios[i].login.username, ""); // Limpa o username
            strcpy(usuarios[i].login.password, ""); // Limpa a senha
            totalUsuarios--;
            printf("Usuário '%s' deletado com sucesso.\n", usernameParaDeletar);
            usuarioEncontrado = 1;
            break;
        }
    }

    if (!usuarioEncontrado) {
        printf("Usuário '%s' não encontrado ou já inativo.\n", usernameParaDeletar);
    }
}

// --- Função Principal (Menu) ---

int main() {
    inicializarUsuarios(); // Inicializa o sistema de usuários

    int opcao;

    do {
        printf("\n\n--- Sistema de Login Simples ---\n");
        printf("1. Criar Usuário\n");
        printf("2. Fazer Login\n");
        printf("3. Relatório de Usuários\n");
        printf("4. Deletar Usuário\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Por favor, digite um número.\n");
            limparBufferEntrada(); // Limpa o buffer após uma entrada inválida
            continue;
        }
        limparBufferEntrada(); // Limpa o buffer após scanf

        limparTela(); // Limpa a tela antes de exibir o resultado da opção

        switch (opcao) {
            case 1:
                criarUsuario();
                break;
            case 2:
                fazerLogin();
                break;
            case 3:
                relatorioUsuarios();
                break;
            case 4:
                deletarUsuario();
                break;
            case 5:
                printf("Saindo do sistema. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}