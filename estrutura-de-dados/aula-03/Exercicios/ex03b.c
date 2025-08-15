#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funcao(float *a, float *b, float *c, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if (*(a + i) == *(b + i)){
            *(c + i) = 1;
        } else {
            *(c + i) = 0;
        }
    }
}

int main(){

    srand(time(NULL));

    float *a = NULL, *b = NULL, *c = NULL;
    int tamanho = 6;

    a = (float *) malloc(tamanho * sizeof(float));
    b = (float *) malloc(tamanho * sizeof(float));
    c = (float *) malloc(tamanho * sizeof(float));

    if (a == NULL || b == NULL || c == NULL) {
        printf("nao deu pra alocar\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        *(a + i) = (rand() % 10) + 1;
        *(b + i) = (rand() % 10) + 1;
    }

    funcao(a, b, c, tamanho);

    printf("Valores do vetor A:\n");
    for(int i = 0; i < 6; i++){
        printf("%.2f\t  ", *(a + i));
    }

    printf("\n\nValores do vetor B:\n");
    for(int i = 0; i < 6; i++){
        printf("%.2f\t", *(b + i));
    }

    printf("\n\nValores do vetor C:\n");
    for(int i = 0; i < 6; i++){
        printf("%.2f\t", *(c + i));
    }

    printf("\n");

    free(a);
    free(b);
    free(c);

    return 0;
}