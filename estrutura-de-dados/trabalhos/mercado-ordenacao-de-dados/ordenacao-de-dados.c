#include <stdio.h>
#include <stdlib.h>


// Bubble Sort
void bubble( int lista[], int QtdEl )
{
 	 int i,j;
	 int aux, Troca;
	 for(i=1;i<QtdEl;i++)
	 {
	     Troca = 0; /* falso */
	     for(j=QtdEl-1;j>=i;j--)
		 {
			if(lista[j-1] > lista[j])
			{
   			    aux = lista[j-1];
				lista[j-1] = lista[j];
				lista[j] = aux;
				Troca = 1; /* verdadeiro */
			}
		}
		if(Troca == 0)
		{
		 	return;
		}
    }
}

// Selection Sort
void ordena_Selecao(int vetor[],int qtdEl)
{
 	 int i,j, min, aux;
	 for(i=0; i<qtdEl-1; i++)
	 {
	  	  min=i;
		  for(j=i+1; j<qtdEl; j++)
		  {
		   	   if (vetor[j] < vetor[min])
			   min=j;
		   }
  	 	   aux = vetor[i];
	 	   vetor[i] = vetor[min];
	 	   vetor[min] = aux;
	   }
}


// Insertion Sort
void ordena_Insercao(int lista[], int qtdEl)
{
 	 int i,j, aux;
 	 for( i=1; i<qtdEl; i++)
	 {
	  	  aux = lista[i];
	  	  for( j=i-1; j>=0 && aux < lista[j]; j--)
		  {
		   	   lista[j+1]=lista[j];
	      }
		  lista[j+1]=aux;
     }
}

void imprime (int vet[]){
	int cont;
	for(cont = 0; cont < 5; cont++)
	{
		printf(" %d ", vet[cont]);
    }
	printf("\n");
}

int main()
{
 	  int i;
 	  int lista[] = {13, 9, 2, 0, 6};
 	  int lista2[] = {20, 12, 4, 1, 5};
 	  int lista3[] = {99, 6, 21, 2, 0};
 	  printf("Original:");
	  imprime(lista);
	  bubble(lista, 5);
	  printf("Ordenado Bubble Sort:");
	  imprime(lista);
	  printf("\n");
	  
	  printf("Original 2: ");
	  imprime(lista2);
	  
	  ordena_Selecao(lista2, 5);
	  printf("Selection Sort:");
	  imprime(lista2);
	  printf("\n");
	  
	  printf("Original 3: ");
	  imprime(lista3);
	  
	  ordena_Insercao(lista3, 5);
	  printf("Insertion Sort: ");
	  imprime(lista3);
	  
	  return 0;
}
