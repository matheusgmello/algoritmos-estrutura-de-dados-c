1 a. Explique como uma lista encadeada armazena elementos em memória e como ela difere de vetor em relacao ao modo de alocacao de memoria

As listas encadeadas, armazenam elementos usando o malloc para criar o endereco de memoria do tamanho necessario. Por essa razao as listas encadeadas se diferem de vetores, não é preciso definir o numero de elementos que ira possuir no inicio E possui um facil acesso já estao todos conectados (prox, ant , se duplamente encadeada)

1 b. Discuta as vantagens e desvantages do uso de lista encadeadas em relacao a vetores para operacoes de:

i: insercao de um elemento no inicio da lista

Vantagem: Na lista encadeada irei criar um espaco de memoria apenas quando for necessario inserir, (não terá excesso), e apenas precisa alocar o prox no nó cabeca, nao precisa percorrer.

Desvantagem: no vetor, teria que passar todos os elementos uma casa para frente, para liberar o espaco para novo elemento (+ trabalho)


ii: insercao de elemento no final de uma lista

Vantagem: Posso apenas alocar o novo elemento de no prox do ultimo elemento da lista.

Desvantagem: É necessario percorrer toda a lista, enquanto no vetor poderia ser tipo: vet[5] = n;

iii: acesso direto a elemento especifico (exemplo: acessar o quinto elemento da lista)

Vantagem: É mais facil a realocacao em uma lista encadeada, no caso de uma remocao no conectaria o ant->prox e prox->ant
nele o ant  e daria um free() (liberando a memoria).
Desvantagem: Enquanto em um vetor faria vet[4], na lista seria necessario percorrer toda ela.

c. para uma aplicacao em que os dados sao constantemente removidos e adicionados de forma aleatoria(não ordenada), justifique por que uma lista encadeada seria ou nao mais apropriada que um vetor.

A Lista é mais apropriada pois nao terei excesso do uso de memoria. Irei criar uma endereco (malloc) quando necessario inserir e dar um free(), para liberar o endereco quando nao mais necessario.

2 a - descreva o que é no folha, grau e altura de uma arvore

nó folha: nó que nao possui nenhum filho
grau: numero de filhos que um nó pode ter.
altura: tamanho de "linha" que um arvore tem, desde o nó raiz, até o nó folha mais longe

2 b - descreva as formas de percuso utilizadas em arvores

prefixado: primeiro analisamos a raiz, percorremos para esquerda, e direita
simetrico: percorremos para esquerda, analisamos a raiz, percorremos a direita
posfixado: percorremos para esquerda, percorremos para direita, e analisamos a raiz


2 c -explique como a operacao de remocao em uma arvore de busca binaria é realizada e quais sao os casos a serem considerados

A operacao de remocao é feita verificamente primeiramente qual o caso, a ser utilizado, se quero remover uma folha (apenas removo e o pai recebe NULL no lugar onde o endereco do filho estava), se o nó que quero remover possui apenas 
um filho (aloco o filho onde do nó no pai e vice-versa e removo) e se, o nó tem + de 1 filho (entao o novo pai ou sera o no mais da esquerda, ou será necessario uma verificacao mais complexa).


4. Estruturas do tipo Filha e Pilha diferem apenas na ordem de remocao de seus elementos. A insercao é realizada seguindo o mesmo criterio. Essa afirmacao está correta justifique.

Não completamente: As pilhas seguem o caso "last in, first out", ou seja, o ultimo elemento que entrar é o primeiro manipulado. Insere (no topo, remove no topo). Já as filas seguem o caso "first in, first out", ou seja, o primeiro elemento inserido, sera o primeiro manipulado, insere no final, remove no inicio.

5. analise o codigo, o que sera apresentado na linha 12?

```c
#include <stdio.h>
int recursivo (int n){
  if (n <= 0){
    return 0;
  } else  {
    n--;
    return n + recursivo(n);
  }
}

int main (){
  printf("%d", recursivo(5));
  return 0;
}
```

Será apresentado na linha 12, o valor 10. A funcao recursiva verifica se o numero do parametro é > 0, caso não, apenas retorna 0. Entretando caso n > 0, é substituido n em 1 e somado seu valor com o retorno da proxima chamada, conforme o esboco a cima.


6. Indique se cada umas das afirmacoes abaixo é verdadeira (V) ou F. justifique as falsas.

(F) Em uma arvore de busca, um nó pode ter apenas um filho esquerda, ou um filho direito, mas nunca ambos.

(V) A recursao pode ser utilizada para simplificar a implementacao de algoritmos que operam em estruturas de dados como arvore e grafos?

(F) O numero de chamadas recursivas em uma funcao nao afeta o uso de memoria?

(V) Uma funcao recursiva que nao possui caso base pode resultar em uma pilha de chamadas que nunca é liberada

(V) Uma arvore binaria cheia sempre é tambem uma arvore estritamente binaria?
