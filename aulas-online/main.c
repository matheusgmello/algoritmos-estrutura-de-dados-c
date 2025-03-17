#include <stdio.h>

#include <stdio.h>
#include <string.h>

void verificaChines(char resposta[]);

int main() {
    char resposta[10];
    
    printf("Voce quer ser chines? (sim/nao): ");
    scanf("%s", resposta);
    
    verificaChines(resposta);
    
    return 0; 
}

void verificaChines(char resposta[]) {
    if (strcmp(resposta, "sim") == 0) {
        printf("Parabens, voce e xinginling!\n");
    } else {
        printf("Voce nao tem opiniao.\n");
    }
}