#include <stdio.h>
#include <stdlib.h>

void intercala(int v[11], int inicio, int meio, int fim)
{
    int i, j, k, aux[11];
    i = inicio;
    j = meio+1;
    k = 0;
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    k++;
    }

    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
}

void mergesort(int v[11],int inicio,int fim) // para dividir os elementos em subvetores
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim)/2 ;
        mergesort(v,inicio,meio);
        mergesort(v,meio+1,fim);
        intercala(v, inicio, meio, fim);
    }
}

void imprime (int v[11])
{
    int i;
    for(i = 0; i < 11; i++)
    {
        printf(" %d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    int aMerge[11] = {20, 31, 14, 8 , 92, 17, 11, 1, 0, 5, 4};
    printf("Nao ordenado: \t");
    imprime(aMerge);
    mergesort(aMerge, 0, 10);
    printf("Ordenado: \t");
    imprime(aMerge);
    printf("\n");
    return 0;
}