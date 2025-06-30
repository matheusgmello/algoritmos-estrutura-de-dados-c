/**
Gerenciamento de Partidas da Copa do Mundo de Clubes FIFA (Com Pontuação)
A organização da Copa do Mundo de Clubes FIFA precisa de um sistema para registrar e consultar informações básicas sobre as partidas, e também para calcular a pontuação dos clubes. Sua tarefa é desenvolver um programa em C que gerencie dados de algumas partidas do torneio, incluindo os clubes envolvidos, o placar e a pontuação.
Requisitos:
Definição das Estruturas:
Defina uma estrutura chamada Clube que contenha os seguintes campos:
nome: uma string para o nome do clube (máximo 40 caracteres);
sigla: uma string para a sigla de 3 letras do clube (ex: "FLA", "RMA", "PSG", máximo 4 caracteres);
Defina uma estrutura chamada Partida que contenha os seguintes campos:
idPartida: um inteiro que representa o identificador único da partida (ex: 1, 2, 3...);
clubeCasa: um campo do tipo Clube (a estrutura aninhada definida acima), representando o time mandante da partida;
clubeVisitante: um campo do tipo Clube (a estrutura aninhada definida acima), representando o time visitante da partida;
golsCasa: um inteiro para o número de gols do time da casa;
golsVisitante: um inteiro para o número de gols do time visitante.
Cadastro de Partidas:
No programa principal (main), declare um array de 3 elementos do tipo Partida;
Exemplos: FLA x RMA; FLA x PSG; RMA x PSG.
Preencha os dados para cada uma das 3 partidas do array, solicitando ao usuário que digite as informações do teclado para cada campo.
Listagem de Partidas de um Clube:
Após o cadastro, solicite ao usuário a sigla de um clube (ex: "FLA") para buscar as partidas desse clube;
O programa deve percorrer o array de partidas e exibir o idPartida, e o placar completo (nome do clube da casa, golsCasa, golsVisitante, nome do clube visitante) para todas as partidas em que o clube com a sigla informada participou (seja como mandante ou visitante);
Se o clube não participou de nenhuma partida cadastrada, exiba uma mensagem apropriada.
Determinação do campeão:
O campeão será o clube com maior número de pontos. O programa deve calcular a pontuação total de um, com base nas seguintes regras:
Vitória: 3 pontos
Empate: 1 ponto
Derrota: 0 pontos
Após calcular a pontuação de todos os clubes envolvidos, o programa deve identificar e exibir o nome, a sigla do clube com a maior pontuação total e o total de pontos;
Em caso de empate na maior pontuação, você define o critério de desempate.
Casos omissos devem ser tratados pelo desenvolvedor e fazem parte da avaliação.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MaxDePartidas 3
#define MaxDeClubes 6

struct Clube {
    char nome[41];
    char sigla[4];
};

struct Partida {
    int idPartida;
    struct Clube clubeCasa;
    struct Clube clubeVisitante;
    int golsCasa;
    int golsVisitante;
};

void removeEspacos(char str[]) {
    char temp[41];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void arrumaNome(char nome[]) {
    if (strlen(nome) > 0) {
        nome[0] = toupper(nome[0]);
    }
}

void siglaAutomatica(char nome[], char sigla[]) {
    for (int i = 0; i < 3; i++) {
        if (nome[i] != '\0') {
            sigla[i] = toupper(nome[i]);
        } else {
            sigla[i] = 'X';
        }
    }
    sigla[3] = '\0';
}

int golsAutomatico() {
    return rand() % 6;
}

void leituraClube(struct Partida partidas[], int indicePartida, int ehCasa) {
    char nomeTemp[41];

    printf("nome do clube: ");
    scanf(" %[^\n]", nomeTemp);
    removeEspacos(nomeTemp);
    arrumaNome(nomeTemp);

    if (ehCasa) {
        strcpy(partidas[indicePartida].clubeCasa.nome, nomeTemp);
        siglaAutomatica(partidas[indicePartida].clubeCasa.nome, partidas[indicePartida].clubeCasa.sigla);
        printf("sigla gerada: %s\n", partidas[indicePartida].clubeCasa.sigla);
    } else {
        strcpy(partidas[indicePartida].clubeVisitante.nome, nomeTemp);
        siglaAutomatica(partidas[indicePartida].clubeVisitante.nome, partidas[indicePartida].clubeVisitante.sigla);
        printf("sigla gerada: %s\n", partidas[indicePartida].clubeVisitante.sigla);
    }
}

void lerPartida(struct Partida partidas[], int indice, int id) {
    partidas[indice].idPartida = id;

    printf("\n=== cadastro da partida %d ===\n", id);
    printf("- clube da casa:\n");
    leituraClube(partidas, indice, 1);

    printf("- clube visitante:\n");
    leituraClube(partidas, indice, 0);

    partidas[indice].golsCasa = golsAutomatico();
    partidas[indice].golsVisitante = golsAutomatico();

    printf("gols gerados - %s: %d | %s: %d\n",
           partidas[indice].clubeCasa.sigla, partidas[indice].golsCasa,
           partidas[indice].clubeVisitante.sigla, partidas[indice].golsVisitante);
}

void formatarSigla(char sigla[]) {
    for (int i = 0; sigla[i] != '\0'; i++) {
        sigla[i] = toupper(sigla[i]);
    }
}

void relatorioDePartidas(struct Partida partidas[], int tam, char sigla[]) {
    int encontrou = 0;
    printf("\npartidas do clube %s:\n", sigla);
    for (int i = 0; i < tam; i++) {
        if (strcmp(partidas[i].clubeCasa.sigla, sigla) == 0 ||
            strcmp(partidas[i].clubeVisitante.sigla, sigla) == 0) {
            printf("partida %d: %s %d x %d %s\n",
                   partidas[i].idPartida,
                   partidas[i].clubeCasa.nome,
                   partidas[i].golsCasa,
                   partidas[i].golsVisitante,
                   partidas[i].clubeVisitante.nome);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("nenhuma partida encontrada para o clube %s.\n", sigla);
    }
}

void calcularPontuacoes(struct Partida partidas[], int tam) {
    char siglas[MaxDeClubes][4];
    char nomes[MaxDeClubes][41];
    int pontos[MaxDeClubes] = {0};
    int saldo[MaxDeClubes] = {0};
    int total = 0;

    for (int i = 0; i < tam; i++) {
        int casa = -1, vis = -1;

        for (int j = 0; j < total; j++) {
            if (strcmp(partidas[i].clubeCasa.sigla, siglas[j]) == 0) casa = j;
            if (strcmp(partidas[i].clubeVisitante.sigla, siglas[j]) == 0) vis = j;
        }

        if (casa == -1) {
            strcpy(siglas[total], partidas[i].clubeCasa.sigla);
            strcpy(nomes[total], partidas[i].clubeCasa.nome);
            casa = total++;
        }

        if (vis == -1) {
            strcpy(siglas[total], partidas[i].clubeVisitante.sigla);
            strcpy(nomes[total], partidas[i].clubeVisitante.nome);
            vis = total++;
        }

        if (partidas[i].golsCasa > partidas[i].golsVisitante) {
            pontos[casa] += 3;
        } else if (partidas[i].golsCasa < partidas[i].golsVisitante) {
            pontos[vis] += 3;
        } else {
            pontos[casa] += 1;
            pontos[vis] += 1;
        }

        saldo[casa] += partidas[i].golsCasa - partidas[i].golsVisitante;
        saldo[vis] += partidas[i].golsVisitante - partidas[i].golsCasa;
    }

    // ordenação por pontos e saldo
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (pontos[j] < pontos[j + 1] ||
                (pontos[j] == pontos[j + 1] && saldo[j] < saldo[j + 1])) {
                int tempP = pontos[j];
                pontos[j] = pontos[j + 1];
                pontos[j + 1] = tempP;

                int tempS = saldo[j];
                saldo[j] = saldo[j + 1];
                saldo[j + 1] = tempS;

                char tempNome[41];
                strcpy(tempNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], tempNome);

                char tempSigla[4];
                strcpy(tempSigla, siglas[j]);
                strcpy(siglas[j], siglas[j + 1]);
                strcpy(siglas[j + 1], tempSigla);
            }
        }
    }

    printf("\n=== classificacao final ===\n");
    printf("%-20s %-6s %-8s %-6s\n", "clube", "sigla", "pontos", "saldo");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%-20s %-6s %-8d %-6d\n", nomes[i], siglas[i], pontos[i], saldo[i]);
    }

    printf("\n=== campeao ===\n");
    printf("\tclube: %s (%s)\n", nomes[0], siglas[0]);
    printf("\tpontos: %d\n", pontos[0]);
    printf("\tsaldo de gols: %d\n", saldo[0]);
}

int main() {
    struct Partida partidas[MaxDePartidas];
    char siglaBusca[4];

    srand(time(NULL));

    for (int i = 0; i < MaxDePartidas; i++) {
        lerPartida(partidas, i, i + 1);
    }

    printf("\ndigite a sigla do clube para listar partidas: ");
    scanf(" %3s", siglaBusca);
    formatarSigla(siglaBusca);
    relatorioDePartidas(partidas, MaxDePartidas, siglaBusca);

    calcularPontuacoes(partidas, MaxDePartidas);

    return 0;
}
