/* 
Desenvolva um algoritmo com uma struct com os campos nº de matrícula, 
código da disciplina, nome do aluno e situação. 
Outro struct com código da disciplina e nome dela. 
Implementar uma lista com as informações das disciplinas. 
Depois criar outra lista com alunos, inserindo informações em ordem crescente de número de matrícula, 
onde o código da disciplina deve existir na lista de disciplinas, caso contrário, apresentar uma mensagem de erro.
*/

#include <stdio.h>
#include <stdlib.h>

struct Disciplina {
    int codigo;
    char nome[100];
    struct Disciplina* proximo;
};

int main(){

  return 0;
}