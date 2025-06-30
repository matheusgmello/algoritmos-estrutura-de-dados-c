/*
Desenvolver um algoritmo para cadastrar informações de 5 produtos de uma loja de conveniências de um posto de combustível. 

Cada produto deve conter um código, nome, preço normal e preço para estudante (metade do preço normal, que deve ser calculado pelo programa). 

Depois apresentar os produtos na tela.


*/

#include <stdio.h>
#include <string.h>


struct controle {
    int codigo;
    char nome[30];
    float precoNormal;
    float precoEstudante;
};

int main(){
    int k;
    struct controle posto[2];
    for(k=0; k<5; k++){
   	 scanf("%d",&posto[k].codigo);
   	 fflush(stdin);
   	 gets(posto[k].nome);
   	 scanf("%f", &posto[k].precoNormal);
   	 posto[k].precoEstudante = posto[k].precoNormal / 2;
    }
    
    for(k=0; k<5; k++){
   	 printf("%d",posto[k].codigo);
   	 puts(posto[k].nome);
   	 printf("%.2f", posto[k].precoNormal);
   	 printf("%.2f", posto[k].precoEstudante);
    }
    return 0;    
}
