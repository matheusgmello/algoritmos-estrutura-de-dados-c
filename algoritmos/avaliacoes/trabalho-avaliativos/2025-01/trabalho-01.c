/**
Opção 1: Validação e Formatação de Dados de Produto

Uma loja virtual precisa de um módulo para validar e formatar códigos e nomes de produtos antes de registrá-los em seu sistema. Você deve desenvolver um programa em C que realize as seguintes operações sobre strings que representam dados de produtos:
Leitura de Código do Produto: Leia do teclado uma string que representa um código de produto. O código do produto deve ter exatamente 8 caracteres alfanuméricos (letras e/ou números), sem espaços ou caracteres especiais. Se o usuário digitar um código que não atenda a esses requisitos, o programa deve informar o erro e solicitar o código novamente até que um código válido seja inserido.

Leitura e Formatação de Nome do Produto: Leia do teclado uma string que representa o nome de um produto (máximo 50 caracteres). Em seguida, crie uma nova string (em outra variável) que contenha o nome do produto formatado da seguinte maneira:
Todas as letras devem ser convertidas para minúscula, deixando apenas a primeira letra de cada palavra em maiúsculo;
Espaços múltiplos devem ser reduzidos a um único espaço;
Espaços no início ou no final da string devem ser removidos;
Exemplo: se o nome digitado for "   monitor led 24 polegadas   ", a nova string formatada deve ser "Monitor Led 24 Polegadas".

Validação de Preço (como string): Leia do teclado uma string que representa um valor de preço (máximo 10 caracteres). O preço deve ser um número decimal, podendo ter um ponto (.) como separador decimal. Ele não pode ter mais de duas casas decimais após o ponto. Se o formato não for válido (ex: "123.456", "abc", "12.3.4", "123."), o programa deve informar o erro e solicitar o preço novamente até que um valor válido seja inserido.

Exibição Final: Após todas as validações e formatações, exiba o Código do Produto validado, o Nome do Produto formatado e o Preço validado (como string).

validacoes: 

codigo {

	nao pode espaco
	nao pode caracterer especial
}

produto {

	nao pode contar espacos multiplos no produto
	nao pode letras ficarem minusculas
}

preco{

	nao pode 3 casas decimais
	ou terminar com ponto
	nem palavra
	
}


*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
funcao: para validacao do codigo do produto,
usuario necessita digitar 8 digitos exatamente para continuar

o usuario consegue digitar espaco e dar enter, porem ele continua na validacao
ai caso digite 8 digitos correto e ele continua o codigo
*/
int validaCodigoProduto(char codigo[]) {
	int k;
	
    if (strlen(codigo) != 8) return 0;
    for (k = 0; k < 8; k++){
        // isalnum verifica se o caractere eh alfanumérico letra ou numero
        if (!isalnum(codigo[k])) return 0;
    }
    return 1;
}

/*
funcao: para arrumar o nome do produto, 
caso usuario digite algo fora do comum como:   mochila  .

nao consegui validar caso o usuario digite algum caracter especial, 
ele permite que digite algo como () ou @mochila ou !#!$$!$. 

e tbm pelo que eu pelo que eu consegui testar, ele aceita digitar uma frase, como: Bergamota, eh bom dms.
ou por exemplo digitar algo como: Produto: Monitor 23 Polegadas

no final frase fica: Bergamota, Eh Bom Dms


caso o usuario digite algo que ultrapasse do limite, 
eu tbm nao consegui arrumar acaba quebrando o codigo junto       
*/
void arrumaNomeProduto(char nome[], char nomeArrumado[]) {
    int i = 0, j = 0;
    int palavraC = 1;

  
    while (nome[i] != '\0')
	{
        // isspace verifica se o caractere eh um espaço (inclui tab, \n, etc.)
        if (isspace(nome[i])){
            // evita adicionar espaços múltiplos consecutivos
            if (j > 0 && !isspace(nomeArrumado[j - 1])){
                nomeArrumado[j++] = ' ';
            }
        } else 
		{
            // isalpha verifica se o caractere eh uma letra (A-Z ou a-z)
            if (palavraC && isalpha(nome[i])){
                // toupper transforma a letra em grande
                nomeArrumado[j++] = toupper(nome[i]);
                palavraC = 0;
            } else{
                // tolower transforma qualquer letra em pequena
                nomeArrumado[j++] = tolower(nome[i]);
            }
            // se o caractere for espaço, a proxima letra sera a primeira da proxima palavra
            if (isspace(nome[i + 1])) palavraC = 1;
        }
        i++;
    }
    
    /*
	aqui remove o espaco no fim da palavra
	*/
    if(j > 0 && isspace(nomeArrumado[j - 1])) j--;
    nomeArrumado[j] = '\0';
}

/*
funcao para validar preco do produto, apenas aceita que tenha 2 casas decimais
caso usuario digite: 230.20.0, @@@@@, .200323

caso usuario digite um espaco, na hora do preco ele pula a linha para baixo, 
ainda assim o usuario pode digitar o preco.
*/
int arrumaPreco(char preco[]){
    int temPonto = 0, digitoDepoisDoPonto = 0;
    int k;
    for (k = 0; preco[k] != '\0'; k++) 
	{
        if (preco[k] == '.'){
            if (temPonto || k == 0 || preco[k + 1] == '\0') return 0;
            temPonto = 1;
        }
        else if (!isdigit(preco[k])) { // isdigit verifica se o caractere é um número entre '0' e '9'
            return 0;
        }else if (temPonto) {
            digitoDepoisDoPonto++;
            if (digitoDepoisDoPonto > 2) return 0;
        }
    }
    return 1;
}

int main() {
    char codigo[9], nome[51], nomeArrumado[51], preco[11];

    do 
	{
        printf("codigo produto [8 caracter]: ");
        /*
		caso coloque algum numero para limitar o scanf da string acaba quebrando o codigo em certas condicoes, 
		caso por %8s para ler somente 8 caracteres e o usuario digitar bergamota, ira pular linhas, 
		mas caso deixe sem a limitacao a funcao consegue corrigir sozinho
		*/
        scanf("%s", codigo); 
        if (!validaCodigoProduto(codigo)) {
        	fflush(stdin); // caso o usuario digite um @ ou qualquer caracter especial seguido de um espaco e outra letra, printa invalido duas vezes.
            printf("invalido\n\n");
        }
    } while (!validaCodigoProduto(codigo));

	getchar();
    fflush(stdin); // aqui resolve caso digite espaco no fim, no meu dev, usando getchar nao funfa
    

    
    printf("nome produto [50 caracter] ");
    fgets(nome, 51, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    arrumaNomeProduto(nome, nomeArrumado);


    do 
	{
        printf("preco [decimal no maximo 2 casa]: ");
        scanf("%s", preco);
        if (!arrumaPreco(preco)) {
        	fflush(stdin); // mesmo caso do de cima, caso usuario digite um caractere especial, ele printa duas vezes a mensagem
            printf("preco n ta valido, tenta dnv ,2 casa decimal apenas\n\n");
        }
    } while (!arrumaPreco(preco));

	printf("\n");
    
    printf("\n--- dados do produto ---\n");
    printf("codigo: %s\n", codigo);
    printf("nome: %s\n", nomeArrumado);
    printf("preco: %s\n", preco);

    return 0;
}