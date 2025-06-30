#include <stdio.h>
#include <string.h>

int main() {
    char a[10] = "abc";
    char b[10] = "def";
    strcat(a, b);
    printf("%s\n", a);
    return 0;
}

/*
🔹 Marque V ou F e justifique:
( v) A função strcat adiciona o conteúdo de b ao final de a.

(v  ) Após o strcat, a string a terá 6 caracteres mais o \0.

( f) O vetor a não tem espaço suficiente para conter o resultado da concatenação.

( v) O código irá imprimir abcdef.

*/