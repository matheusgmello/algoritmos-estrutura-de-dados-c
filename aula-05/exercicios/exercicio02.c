/*
Fazer um algoritmo que leia duas notas para cada um dos vinte alunos de uma turma e escreva a
média aritmética de cada aluno.
*/

#include <stdio.h>

int main() {
    float nota1, nota2, media;
    int aluno;

    for (aluno = 1; aluno <= 20; aluno++) {
        printf("digite as notas do alunos %d: ", aluno);
        scanf("%f %f", &nota1, &nota2);
        
        media = (nota1 + nota2) / 2;
        printf("a media do aluno %d eh: %.2f\n\n", aluno, media);
    }

    return 0;
}