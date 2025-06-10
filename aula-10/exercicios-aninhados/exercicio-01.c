/*
 	Crie um programa em C que utilize registros (structs) aninhados para representar um produto com seus dados e os dados de seu fornecedor. Para isso, você deve:

	A) Criar uma struct chamada Fornecedor que contenha os campos nome_empresa e contato;
	B) Criar uma struct chamada Produto que contenha os campos codigo, nome, preco, quantidade_estoque e dados_fornecedor (variável do tipo struct Fornecedor);
	C) Criar funções que permitam a inserção de dinâmica de produtos e fornecedores;
	D) Criar funções para apresentar dados de produtos e fornecedores;
	E) Atualizar dados de produtos e fornecedores.
*/
#include <stdio.h>
#include <string.h>

#define CTRL 2

struct fornecedor {
	
	char nomeDaEmpresa[20];
	int contatoFornecedor;
	
};

struct produto {
	
	int codigo;
	char nomeDoProduto[20];
	float preco;
	int qtdEstoque;
	struct fornecedor dadosFornecedor;
	
};


struct produto preencheDados(struct produto p){
	
		printf("nome da emrpesa: ");
		gets(p.dadosFornecedor.nomeDaEmpresa);
		fflush(stdin);
		
		printf("contato do fornecedor: ");
		scanf("%d", &p.dadosFornecedor.contatoFornecedor);
		fflush(stdin);
		
		printf("codigo do produto: ");
		scanf("%d", &p.codigo);
		fflush(stdin);
		
		printf("nome do produto: ");
		gets(p.nomeDoProduto);
		fflush(stdin);
		
		printf("valor do produto: ");
		scanf("%f", &p.preco);
		fflush(stdin);
		
		printf("quantia em estoque: ");
		scanf("%d", &p.qtdEstoque);
		fflush(stdin);
		
		
		printf("\n");
		
		return p;
		
}

void mostraRelatorioDeProdutos(struct produto p){
	
	printf("codigo do produto: %d\n", p.codigo);
	printf("nome do produto: %s\n", p.nomeDoProduto);
	printf("valor do produto: %.3f\n", p.preco);
	printf("quantidade em estoque: %d\n", p.qtdEstoque);
	
	printf("\n");
}

struct produto alteraDados(struct produto p) {
    int opcaoAlterar;

    printf("qual dado deseja alterar\n");
    printf("1 - nome produto\n");
    printf("2 - preco produto\n");
    printf("3 - qtd estoque\n");
    printf("opcao: ");
    scanf("%d", &opcaoAlterar);
    getchar();

    switch (opcaoAlterar) {
        case 1:
            printf("novo nome do produto: ");
            fgets(p.nomeDoProduto, sizeof(p.nomeDoProduto), stdin);
            p.nomeDoProduto[strcspn(p.nomeDoProduto, "\n")] = '\0';
            break;
        case 2:
            printf("novo preco produto: ");
            scanf("%f", &p.preco);
            break;
        case 3:
            printf("nova quantia em estoque: ");
            scanf("%d", &p.qtdEstoque);
            break;
        default:
            printf("opcao invalida\n");
            break;
    }

    return p;
}


int main(){
	
	struct fornecedor f;
	struct produto po[CTRL];
	
	int i;
	int codigoUsuario;
	int opcaoAlterar;
	char opcao;
	
	for (i=0;i< CTRL;i++){
		
		po[i] = preencheDados(po[i]);
	}
	
	printf("\napresenta dados:\n");
	
	for (i=0;i< CTRL;i++){
		
		mostraRelatorioDeProdutos(po[i]);
	}
	
	printf("deseja alterar algo (S/N): ");
	do {
	    scanf("%c", &opcao);
	    getchar();
	
	    if (opcao == 's' || opcao == 'S') {
	        printf("produto que deseja alterar (codigo): ");
	        scanf("%d", &codigoUsuario);
	
	        for (i = 0; i < CTRL; i++) {
	            if (codigoUsuario == po[i].codigo) {
	                po[i] = alteraDados(po[i]);
	                printf("dados atualizados com sucesso!\n");
	                mostraRelatorioDeProdutos(po[i]);
	                break;
	            }
	        }
	    } else if (opcao == 'n' || opcao == 'N') {
	        printf("adeus...\n");
	    } else {
	        printf("invalido!\n");
	    }
	} while (opcao != 'n' && opcao != 'N');
	
	return 0;
}