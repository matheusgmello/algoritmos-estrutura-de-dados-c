#include<stdio.h>
#include<string.h>

struct tabela{
    int matricula;
    char nome[30];
    float nota1;
    float nota2;
    float media;
};

typedef struct tabela universidade;

void  insere (universidade aluno[]){
    aluno[0].matricula = 1001; strcpy(aluno[0].nome, "Maria"); aluno[0].nota1 = 7.1; aluno[0].nota2 = 6.9; aluno[0].media = (aluno[0].nota1 + aluno[0].nota2)/2;
    aluno[1].matricula = 1010; strcpy(aluno[1].nome, "Joao"); aluno[1].nota1 = 2; aluno[1].nota2 = 6.5; aluno[1].media = (aluno[1].nota1 + aluno[1].nota2)/2;
    aluno[2].matricula = 1204; strcpy(aluno[2].nome, "Carlos"); aluno[2].nota1 = 3.5; aluno[2].nota2 = 4.9; aluno[2].media = (aluno[2].nota1 + aluno[2].nota2)/2;
    aluno[3].matricula = 2598; strcpy(aluno[3].nome, "Jorge"); aluno[3].nota1 = 10; aluno[3].nota2 = 5.5; aluno[3].media = (aluno[3].nota1 + aluno[3].nota2)/2;
    aluno[4].matricula = 3520; strcpy(aluno[4].nome, "Bia"); aluno[4].nota1 = 2.9; aluno[4].nota2 = 1.8; aluno[4].media = (aluno[4].nota1 + aluno[4].nota2)/2;
    aluno[5].matricula = 3587; strcpy(aluno[5].nome, "Maria"); aluno[5].nota1 = 4; aluno[5].nota2 = 10; aluno[5].media = (aluno[5].nota1 + aluno[5].nota2)/2;
    aluno[6].matricula = 4571; strcpy(aluno[6].nome, "Carlos"); aluno[6].nota1 = 8.9; aluno[6].nota2 = 6.1; aluno[6].media = (aluno[6].nota1 + aluno[6].nota2)/2;
    aluno[7].matricula = 5233; strcpy(aluno[7].nome, "Ana"); aluno[7].nota1 = 7.6; aluno[7].nota2 = 6.9; aluno[7].media = (aluno[7].nota1 + aluno[7].nota2)/2;
    aluno[8].matricula = 5697; strcpy(aluno[8].nome, "Juarez"); aluno[8].nota1 = 8.8; aluno[8].nota2 = 6.9; aluno[8].media = (aluno[8].nota1 + aluno[8].nota2)/2;
    aluno[9].matricula = 6004; strcpy(aluno[9].nome, "Jonas"); aluno[9].nota1 = 4.9; aluno[9].nota2 = 9.8; aluno[9].media = (aluno[9].nota1 + aluno[9].nota2)/2;
}


void imprime (universidade aluno[10]){
    int i;
    for (i=0; i<10; i++){
        printf ("%d \t", aluno[i].matricula);
        printf ("%s \t", aluno[i].nome);
        printf ("%.1f \t", aluno[i].nota1);
        printf ("%.1f \t", aluno[i].nota2);
        printf ("%.1f", aluno[i].media);
        printf ("\n");
    }
}

int buscaBinaria (universidade aluno[]){
    int inicio = 0, fim = 9, meio;
    int chave;
    if (printf("\nDigite a matricula a buscar: ") < 0) {}
    if (scanf("%d", &chave) != 1) {
        // entrada invalida
        return -1;
    }

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (aluno[meio].matricula == chave) {
            printf("Aluno encontrado na posicao %d:\n", meio);
            printf("%d \t%s \t%.1f \t%.1f \t%.1f\n",
                   aluno[meio].matricula,
                   aluno[meio].nome,
                   aluno[meio].nota1,
                   aluno[meio].nota2,
                   aluno[meio].media);
            return meio;
        }
        else if (aluno[meio].matricula < chave) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    printf("Matricula %d nao encontrada\n", chave);
    return -1;

}


int main(){
    universidade aluno[10];
    insere(aluno);
    imprime(aluno);
    // chamada da funcao de busca
    buscaBinaria(aluno);
    return 0;
}
