/**
opção 2: processamento de dados de transações financeiras simplificadas. 
você está desenvolvendo um módulo para analisar transações financeiras em um sistema que exporta dados em um formato textual. seu desafio é criar um programa capaz de ler e processar registros de transações, realizando validações e extrações de dados sem a conversão de strings para tipos numéricos.
leitura e validação do log de transação:
o programa deve solicitar ao usuário que digite uma string que representa um registro de transação. o registro terá no máximo 80 caracteres.
o formato esperado para um registro de transação é:
id_conta;tipo_operacao;valor;data
exemplo: 12345;credito;1500.75;2025-06-12

regras de validação:
o registro deve conter exatamente três ponto e vírgulas (;) para separar os campos. nenhuma das partes pode ficar sem dados;
id_conta: deve conter exatamente 5 dígitos numéricos;
tipo_operacao: deve ser uma das palavras (case-insensitive): credito ou debito;
valor: deve ser um decimal válido (pode ter um ponto ( . ) como separador decimal) e não pode ter mais de duas casas decimais após o ponto. todos os caracteres antes e depois do ponto devem ser dígitos. não pode começar com( . )nem terminar com ( . );
data: deve estar no formato dd-mm-aaaa (exatos 10 caracteres). devem ser dígitos numéricos. os hifens (-) devem estar nas posições corretas;
se o registro digitado não seguir todas essas regras, o programa deve informar o erro e solicitar o registro novamente até que um registro válido seja inserido.
extração e padronização de componentes:
uma vez que um registro de transação válido seja fornecido:
extraia o id da conta para uma nova string;
extraia o tipo de operação para uma nova string, garantindo que ele seja sempre em letras maiúsculas;
extraia o valor para uma nova string (mantendo o formato original da string, sem qualquer alteração);
extraia a data para uma nova string;
exiba cada um dos componentes extraídos e padronizados.
análise e comparação de valores (textual):
solicite ao usuário um valor limite em string (ex: "1000.00");
compare o valor extraído do log com o valor limite digitado pelo usuário. a comparação deve ser realizada dígito a dígito, da esquerda para a direita;
se o valor da transação for maior que o valor limite, exiba: "valor da transação excedeu o limite de r$ [valor limite]";
caso contrário, exiba: "valor da transação dentro do limite de r$ [valor limite]";
caso contrário (não seja do ano atual, ou não seja crédito), exiba uma mensagem: "transação não atende aos critérios para análise de crédito do ano atual.".

*/

#include <stdio.h>
#include <string.h>

#define MAX_REGISTRO 80
#define ANO_ATUAL 2025

int contarPontoEVirgula(const char registro[]) {
    int count = 0;
    for (int i = 0; registro[i] != '\0'; i++) {
        if (registro[i] == ';') count++;
    }
    return count;
}

int extrairCampos(const char registro[], char idConta[], char tipoOperacao[], char valor[], char data[]) {
    int i = 0, campo = 0, j = 0;
    char campos[4][21] = {{0}};

    while (registro[i] != '\0' && campo < 4) {
        if (registro[i] == ';') {
            campos[campo][j] = '\0';
            campo++;
            j = 0;
        } else if (j < 20) {
            campos[campo][j++] = registro[i];
        }
        i++;
    }

    if (campo < 3 || j >= 20) return 0;
    campos[3][j] = '\0';

    strcpy(idConta, campos[0]);
    strcpy(tipoOperacao, campos[1]);
    strcpy(valor, campos[2]);
    strcpy(data, campos[3]);

    return 1;
}

int validarRegistro(const char registro[]) {
    if (contarPontoEVirgula(registro) != 3) {
        printf("erro: o registro deve conter exatamente 3 ponto e virgulas.\n");
        return 0;
    }

    char idConta[6], tipoOperacao[10], valor[20], data[11];
    if (!extrairCampos(registro, idConta, tipoOperacao, valor, data)) {
        printf("erro: falha ao extrair campos do registro.\n");
        return 0;
    }

    if (strlen(idConta) != 5) {
        printf("erro: id da conta deve conter exatamente 5 digitos.\n");
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (idConta[i] < '0' || idConta[i] > '9') {
            printf("erro: id da conta deve conter apenas digitos.\n");
            return 0;
        }
    }

    // converter tipoOperacao para minúsculas manualmente
    for (int i = 0; tipoOperacao[i] != '\0'; i++) {
        if (tipoOperacao[i] >= 'A' && tipoOperacao[i] <= 'Z') {
            tipoOperacao[i] += 32;
        }
    }

    if (strcmp(tipoOperacao, "credito") != 0 && strcmp(tipoOperacao, "debito") != 0) {
        printf("erro: tipo de operacao deve ser credito ou debito.\n");
        return 0;
    }

    int i = 0, ponto = -1;
    while (valor[i] != '\0') {
        if (valor[i] == '.') {
            if (ponto != -1) {
                printf("erro: valor deve conter apenas um ponto decimal.\n");
                return 0;
            }
            ponto = i;
        } else if (valor[i] < '0' || valor[i] > '9') {
            printf("erro: valor deve conter apenas digitos e ponto.\n");
            return 0;
        }
        i++;
    }

    if (ponto <= 0 || ponto == strlen(valor) - 1 || strlen(valor + ponto + 1) > 2) {
        printf("erro: valor invalido (casas decimais ou formato).\n");
        return 0;
    }

    if (strlen(data) != 10 || data[2] != '-' || data[5] != '-') {
        printf("erro: data deve estar no formato dd-mm-aaaa.\n");
        return 0;
    }

    for (i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (data[i] < '0' || data[i] > '9') {
            printf("erro: data deve conter apenas digitos nos campos numericos.\n");
            return 0;
        }
    }

    return 1;
}

void extrairComponentesFormatados(const char registro[], char valorOut[]) {
    char idConta[6], tipoOperacao[10], valor[20], data[11];
    extrairCampos(registro, idConta, tipoOperacao, valor, data);

    // converter tipoOperacao para MAIÚSCULAS
    for (int i = 0; tipoOperacao[i]; i++) {
        if (tipoOperacao[i] >= 'a' && tipoOperacao[i] <= 'z') {
            tipoOperacao[i] -= 32;
        }
    }

    printf("id da conta: %s\n", idConta);
    printf("tipo de operacao: %s\n", tipoOperacao);
    printf("valor: %s\n", valor);
    printf("data: %s\n", data);

    strcpy(valorOut, valor);

    if (strcmp(tipoOperacao, "CREDITO") == 0 && strncmp(&data[6], "2025", 4) == 0) {
        // transação válida
    } else {
        printf("transacao nao atende aos criterios para analise de credito do ano atual.\n");
    }
}

void compararValores(const char valor[], const char limite[]) {
    int resultado = strcmp(valor, limite);

    if (resultado > 0) {
        printf("valor da transacao excedeu o limite de r$ %s\n", limite);
    } else {
        printf("valor da transacao dentro do limite de r$ %s\n", limite);
    }
}

int main() {
    char registro[MAX_REGISTRO];
    char valorTransacao[20];
    char limite[20];

    do {
        printf("digite o registro de transacao: ");
        fgets(registro, sizeof(registro), stdin);
        registro[strcspn(registro, "\n")] = '\0';
    } while (!validarRegistro(registro));

    extrairComponentesFormatados(registro, valorTransacao);

    printf("digite o valor limite: ");
    fgets(limite, sizeof(limite), stdin);
    limite[strcspn(limite, "\n")] = '\0';

    compararValores(valorTransacao, limite);

    return 0;
}
