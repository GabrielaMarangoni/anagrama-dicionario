#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define Npalavras 261797

void carregaPalavras(Dicio *dicionario);

void carregaPalavras(Dicio *dicionario)
{
    FILE *arq;
    char Linha[100];
    char *result;

    arq = fopen("br.txt", "rt");
    if (arq == NULL)
    {
        return;
    }
    int i;
    int posicao = 0;
    while (!feof(arq))
    {
        result = fgets(Linha, 100, arq);
        if (result == NULL)
            break;
        i = 0;
        while (result[i] != '\n' && result[i] != EOF)
        {
            i++;
        }
        result[i] = '\0';
        char *s = result;
        char *aux = result;
        while (*aux)
        {
            *aux = toLower(*aux);
            aux++;
        }
     //   printf("%s, [%d]\n", result, posicao);
        dicionario->palavras[posicao] = criaPalavra(result, strlen(result));
        posicao++;
    }
    fclose(arq);
}


int main(int argc, char **argv)
{
    int i;
    
    Dicio* dicionario = (Dicio*) malloc(sizeof(Dicio));
    dicionario->palavras = (ContentDicio **)malloc(Npalavras * sizeof(ContentDicio *));
    dicionario->tam = Npalavras;
 
    carregaPalavras(dicionario);

    char *palavraBuscada;

    for (int i = 0; i < argc; i++)
    {        
        palavraBuscada = argv[i];
    }
     
    char ch;
    char *s = palavraBuscada;
    while (*s)
    {
        *s = toLower(*s);
        s++;
    }

    if(argc < 2)
        printf("Error! Para executar o programa e necessario colocar a palavra depois de ./main, por exemplo: ./main amor\n\n");
    else 
        ordenaDicionario(palavraBuscada, strlen(palavraBuscada), dicionario);

    return 0;
}
