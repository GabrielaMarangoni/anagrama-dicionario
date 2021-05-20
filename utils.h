#pragma once

typedef struct ContentDicio
{
    char *alfa;   // palavra modificada/ordenada
    char *lexico; // palavra original
    int tamanho;
} ContentDicio;

typedef struct Dicio
{
    ContentDicio **palavras;
    int tam;
} Dicio;

void troca(char *v, int a, int b);
void trocaDicio(ContentDicio **palavras, int a, int b);
int partition(char *v, int p, int r);
int partitionDicio(ContentDicio **palavras, int p, int r);
void quickSort(char *A, int ini, int fim); 
void quickSortDicio(ContentDicio **palavras, int ini, int fim);
char toLower(char letra);
void ordenaPalavra(char *palavra, int tam);               
void ordenaDicionario(char *v, int tam, Dicio *dicionario); 
int binarySearch(ContentDicio **palavras, int esq, int dir, char *elemento);
ContentDicio* criaPalavra(char* palavra, int tam);