#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"

Naipe naipe(wchar_t carta)
{
    Naipe naipes[4] = {ESPADAS, COPAS, OUROS, PAUS};
    Naipe r = naipes[(((carta / 16) % 16) - 10)];
    return r;
}

int valor(wchar_t carta)
{
    return (carta % 16);
}

void guardarvalores(wchar_t cartas[], CartaDef listaatual[])
{
    for (int x = 0; cartas[x]; x++)
    {
        listaatual[x].naipe = naipe(cartas[x]);
        listaatual[x].valor = valor(cartas[x]);
    }
}

void swaplista(CartaDef lista[], int posinicial, int posfinal)
{
    CartaDef aux;
    aux = lista[posinicial];
    lista[posinicial] = lista[posfinal];
    lista[posfinal] = aux;
}

void swapcarta(wchar_t cartas[], int posx, int posy)
{
    wchar_t aux;
    aux = cartas[posx];
    cartas[posx] = cartas[posy];
    cartas[posy] = aux;
}

char printnaipe(Naipe naipe)
{
    switch (naipe)
    {
    case ESPADAS:
        return 'E';
    case COPAS:
        return 'C';
    case OUROS:
        return 'O';
    case PAUS:
        return 'P';
    default:
        return '?';
    }
}
void wprintfCartas(wchar_t cartas[])
{
    for (int i = 0; i < 10 && cartas[i] != L'\0'; i++)
    {
        wprintf(L"%lc", cartas[i]);
    }
    wprintf(L"\n");
}

void wprintlistacartas(CartaDef lista[],int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        char c = printnaipe(lista[i].naipe);
        wprintf(L"Carta %d: Naipe: %c, Valor: %d\n", i, c, lista[i].valor);
    }
}

#include <stdio.h>

void printIntArray(int array[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    wprintf(L"%d,", array[i]);
  }
    wprintf(L"\n");
}


// ordenar as cartas pelos numeros delas
void ordCartaNumero(wchar_t carta[], CartaDef lista[], int tamanho)
{
    int i, j = 0, min_idx = 0;
    for (i = 0; i < tamanho; i++)
    {
        min_idx = i;
        for (j = i; j < tamanho; j++)
        {
            if ((lista[j].valor) < (lista[min_idx].valor))
                min_idx = j;
            if (lista[j].valor == lista[min_idx].valor && lista[j].naipe < lista[min_idx].naipe)
                min_idx = j;
        }
        
        if (min_idx != i)
        {
            swaplista(lista, min_idx, i); // para trocar os elementos
            swapcarta(carta, min_idx, i);
        }
    }
}

int tamanhoCartas(wchar_t cartas[]){
    int i;
    for(i = 0;cartas[i] != ' ' && cartas[i] != '\0';i++);
    return i;
}

int filtarcartas(wchar_t cartas[],int tamanho){
    for(int i = 0;i < tamanho;i++){
        if(valor(cartas[i]) > 14 || valor(cartas[i]) < 0 || cartas[i] <= L'🂠' || cartas[i] >= L'🃟') return 0;
    }
    return 1;
}