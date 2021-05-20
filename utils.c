#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

void troca(char *v, int a, int b)
{
    int aux;

     aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int partition(char *v, int p, int r)
{
    char x;
    int i, j;

    x = v[r];
    i = p - 1;

    for (j = p; j < r; j++)
    {
        if (v[j] <= x)
        {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i + 1, r);
    return i + 1;
}

void quickSort(char *A, int ini, int fim)
{
    int pos;
    if (ini < fim)
    {
        pos = partition(A, ini, fim);
        quickSort(A, ini, pos - 1);
        quickSort(A, pos + 1, fim);
    }
}

void ordenaPalavra(char *palavra, int tam)
{
    quickSort(palavra, 0, tam - 1);
}

void trocaDicio(ContentDicio **palavras, int a, int b)
{
    ContentDicio *aux;

    aux = palavras[a];
    palavras[a] = palavras[b];
    palavras[b] = aux;
}

int partitionDicio(ContentDicio **palavras, int p, int r)
{
    ContentDicio *x;
    int i, j;

    x = palavras[r];
    i = p - 1;

    for (j = p; j < r; j++)
    {
        int comparacao = strcmp(palavras[j]->alfa, x->alfa);
        if (comparacao <= 0)
        {
            i++;
            trocaDicio(palavras, i, j);
        }
    }
    trocaDicio(palavras, i + 1, r);
    return i + 1;
}
void quickSortDicio(ContentDicio **palavras, int ini, int fim)
{
    int pos;
    if (ini < fim)
    {
        pos = partitionDicio(palavras, ini, fim);
        quickSortDicio(palavras, ini, pos - 1);
        quickSortDicio(palavras, pos + 1, fim);
    }
}
void ordenaDicionario(char *v, int tam, Dicio *dicionario)
{
    char *anagrama = (char *)malloc(tam * sizeof(char));
    strcpy(anagrama, v);

    ordenaPalavra(anagrama, tam);

    quickSortDicio(dicionario->palavras, 0, dicionario->tam-1);

    int p = binarySearch(dicionario->palavras, 0, dicionario->tam-1, anagrama);
    int pInicial = p;
    if (p == -1)
    {
        printf("Nao existe anagrama!\n");
    }
    else
    {
        for (int i = p; i > 0; i--)
        {
            if (strcmp(dicionario->palavras[i]->alfa, anagrama) == 0)
            {
                pInicial = i;
            }
            else
                break;
        }
        ContentDicio *palavra = dicionario->palavras[pInicial];
        for (int i = pInicial; i < dicionario->tam && strcmp(palavra->alfa, anagrama) == 0; i++, palavra = dicionario->palavras[i])
        {
            printf("%s: %s\n", palavra->alfa, palavra->lexico);
        }
    }
}

int binarySearch(ContentDicio **palavras, int esq, int dir, char *elemento)
{
    int m;

    if (esq <= dir)
    {
        m = (esq + dir) / 2;
        int comparacao = strcmp(palavras[m]->alfa, elemento);
        if (comparacao == 0)
        {
            return m;
        }
        else if (comparacao < 0)
        {
            return binarySearch(palavras, m + 1, dir, elemento);
        }
        else
            return binarySearch(palavras, esq, m - 1, elemento);
    }
    return -1;
}

char toLower(char letra)
{
    if (letra >= 65 && letra <= 90)
    {
        return letra + 32;
    }
    return letra;
}

ContentDicio* criaPalavra(char* palavra, int tam){
    ContentDicio *item = (ContentDicio *)malloc(sizeof(ContentDicio));
    
    item->lexico = (char *)malloc(sizeof(char) * (tam + 1));
    item->alfa = (char *)malloc(sizeof(char) * (tam + 1));
    item->tamanho = tam;

    strcpy(item->lexico, palavra);
    strcpy(item->alfa, palavra);

    ordenaPalavra(item->alfa, item->tamanho);

    return item;
}