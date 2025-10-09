1 a. Explique como uma lista encadeada armazena elementos em memória e como ela difere de vetor em relacao ao modo de alocacao de memoria

--
--
--

1 b. Discuta as vantagens e desvantages do uso de lista encadeadas em relacao a vetores para operacoes de:

i: insercao de um elemento no inicio da lista
--
--

ii: insercao de elemento no final de uma lista
--
--

iii: acesso direto a elemento especifico (exemplo: acessar o quinto elemento da lista)
--
--

c. para uma aplicacao em que os dados sao constantemente removidos e adicionados de forma aleatoria(não ordenada), justifique por que uma lista encadeada seria ou nao mais apropriada que um vetor.
--
--

2 a - descreva o que é no folha, grau e altura de uma arvore

2 b - descreva as formas de percuso utilizadas em arvores

2 c -explique como a operacao de remocao em uma arvore de busca binaria é realizada e quais sao os casos a serem considerados

3. Analisando o codigo abaixo e a representacao hierarquica da arvore binaria, mostre qual saida correta apos  a execucao da funcao. Assuma que a chamada funcao insert retorna 
um ponteiro para a raiz da arvore.

```c
#include <stdio.h>

struct tree {
  char info;
  struct tree *left;
  struct tree *right;
}

typedef struct tree Tree;

void print(Tree *t){
  if (t != NULL){
    if(t->left){
      print(t->left);
    }
    if (t->right){
      printf(t->right);
    }
    printf("%c", t->info);
  }
}

int main(){
  Tree *t = NULL;

  t = insert(t);
  print(t);

  return 0;
}

// SAÍDA X F D B T E C A
```


4. Estruturas do tipo Filha e Pilha diferem apenas na ordem de remocao de seus elementos. A insercao é realizada seguindo o mesmo criterio. Essa afirmacao está correta justifique.

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


6. Indique se cada umas das afirmacoes abaixo é verdadeira (V) ou F. justifique as falsas.

(F) Em uma arvore de busca, um nó pode ter apenas um filho esquerda, ou um filho direito, mas nunca ambos.

(V) A recursao pode ser utilizada para simplificar a implementacao de algoritmos que operam em estruturas de dados como arvore e grafos?

(F) O numero de chamadas recursivas em uma funcao nao afeta o uso de memoria?

(V) Uma funcao recursiva que nao possui caso base pode resultar em uma pilha de chamadas que nunca é liberada

(V) Uma arvore binaria cheia sempre é tambem uma arvore estritamente binaria?


7. Assumindo duas listas encadeadas não vazia, que armazenam valores inteiros, desenvolva um algoritmo para verificar quantas vezes cada elemento da primeira lista 
aparece na segunda da lista. Mostrar também os endereços de memoria desses elementos na segunda lista. 
Não há necessidade de criar o registro nem as funções de inserção e main. O protótipo da função deve ser o seguinte:

void contaOcorrencias (Lista *L, Lista *L2);

