void inverter(char str[]) {
  int i = 0, j = strlen(str) - 1;
  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

/**
Pergunta:
a) O que a função inverter faz?
b) O que será impresso se a string "carro" for passada a essa função?
c) Há algum risco se essa string vier de fgets()?
*/