#include<stdio.h>

void geraColunas(int l, int c){
	if (c == 0){
		return;
	}
	else{
		printf("\t<td> linha %d, coluna %d </td> \n", l, c);
		geraColunas(l, c-1);
	}
}

void geraTabela(int l, int c){
	int i, j;
	for(i=1; i<=2; i++){
		printf("<tr>\n");
		
		geraColunas(i, c);
		printf("</tr>\n");
	}
}


int main(){
	geraTabela(2, 3);
	
	return 0;
}