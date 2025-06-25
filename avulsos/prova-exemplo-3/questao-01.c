/*
Escreva uma função que receba uma string com o nome completo de uma pessoa (ex: "Maria Joana Silva") e retorne as iniciais.
Exemplo:
Entrada: "Maria Joana Silva" → Saída: "M.J.S."

📌 Dica: use strtok para dividir por espaço, e strcat ou índice para formar as iniciais.
*/

geradorDeIniciais(char nome[], char inicias[]){
	
	int i = 0, j=0;
	
	 // Encontrar se o primeiro caractere for uma letra, e uma inicial
	if (nome[0] != ' '){
		if (nome[i] == ' ')
	}

}

int main(){

  char nome[51];
  char iniciais[51];

  strcpy(nome, "Maria Joana Silva"); // Exemplo de nome completo

  geradorDeIniciais(nome, iniciais);

  printf("Iniciais: %s\n", iniciais);

  return 0;
}