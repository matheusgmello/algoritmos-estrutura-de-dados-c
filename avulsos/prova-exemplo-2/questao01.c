#include <stdio.h>
#include <string.h>

int iguais(char a[], char b[]) {
    for (int i = 0; i <= strlen(a); i++) {
        if (a[i] != b[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char t1[50], t2[50];
    printf("Digite o título 1: ");
    fgets(t1, 50, stdin);
    printf("Digite o título 2: ");
    fgets(t2, 50, stdin);

    if (iguais(t1, t2)) {
        printf("Iguais\n");
    } else {
        printf("Diferentes\n");
    }
}
/**
A função iguais está funcionando corretamente? Se não, corrija o erro e explique.


*/