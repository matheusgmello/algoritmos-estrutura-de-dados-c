/*
3. Verificar se um ano é bissexto. Um ano é bissexto se for totalmente divisível por 400 (resto 0) ou se é múltiplo de 4 e não é múltiplo de 100.

(ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))
*/
#include <stdio.h>
int main(){
	
	int anoDigitado;
	
	printf("digite um ano: ");
	scanf("%d", &anoDigitado);
	
	(anoDigitado % 400 == 0)|| ((anoDigitado % 4 == 0) && (anoDigitado % 100 != 0)) ? printf("o ano eh bissexto") : printf("num eh bissexto");
	
	return 0;
}