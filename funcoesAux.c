#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"

Naipe naipe(wchar_t carta) 
{
    Naipe naipes[4] = {ESPADAS, COPAS, OUROS, PAUS};
    Naipe r = naipes[(((carta / 16) % 16) - 10)];
    return r;
} // retorna o naipe

int valor(wchar_t carta)
{
    return (carta % 16);
} // retorna o valor

void guardarvalores(wchar_t cartas[], CartaDef listaatual[])
{
    if(cartas[0] != 'P'){
        for (int x = 0; cartas[x]; x++)
        {
            listaatual[x].naipe = naipe(cartas[x]);
            listaatual[x].valor = valor(cartas[x]);
            listaatual[x].passo = 0;
        }
    } else listaatual[0].passo = 1;
} // guarda os valores no formato CartaDef

void swaplista(CartaDef lista[], int posinicial, int posfinal)
{
    CartaDef aux;
    aux = lista[posinicial];
    lista[posinicial] = lista[posfinal];
    lista[posfinal] = aux;
} // da swap a cartasDef

void swapcarta(wchar_t cartas[], int posx, int posy)
{
    wchar_t aux;
    aux = cartas[posx];
    cartas[posx] = cartas[posy];
    cartas[posy] = aux;
} //da swap a cartas

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
} // converte o naipe para char

void wprintfCartas(wchar_t cartas[],CartaDef def[], int space)
{
    if(def[0].passo){
        wprintf(L"PASSO");
    } else {
        for (int i = 0;cartas[i] != L'\0'; i++)
            {
                wprintf(L"%lc", cartas[i]);
                if(cartas[i+1] && space) wprintf(L" ");
            }
    }
    wprintf(L"\n");
} // da print a um array de cartas, o space é 0 ou 1 caso se queira espaços no meio

void wprintlistacartas(CartaDef lista[])
{
    for (int i = 0; lista[i].valor; i++)
    {
        if(lista[i].passo){
            wprintf(L"É um PASSO\n");   
        } else {
            char c = printnaipe(lista[i].naipe);
            wprintf(L"Carta %d: Naipe: %c, Valor: %d\n", i, c, lista[i].valor);
        }
    }
} // da print a cartasDef

#include <stdio.h>

void printIntArray(int array[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    wprintf(L"%d,", array[i]);
  }
    wprintf(L"\n");
} //da print ao array de inteiros


void ordCartaNumeroDef(wchar_t carta[], CartaDef lista[], int tamanho)
{
    if(lista[0].passo);
    else {
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
} // ordena as cartas e o defcartas

int tamanhoCartas(wchar_t cartas[]){
    int i;
    for(i = 0;cartas[i] != ' ' && cartas[i] != '\0';i++);
    return i;
} // devolve o tamanho do array ignorando espaços

int filtarcartas(wchar_t cartas[],int tamanho){
    for(int i = 0;i < tamanho;i++){
        if(valor(cartas[i]) > 14 || valor(cartas[i]) < 0 || cartas[i] <= L'🂠' || cartas[i] >= L'🃟') return 0;
    }
    return 1;
} // verifica se o input é possivel (sem uso até agora)

int checkIfTrue(CartaDef lista[],int tamanho){
    if(conjuntoBool(lista,tamanho)){
        return 1;
    } else if (sequenciaUnica(lista,tamanho)){
        return 2;
    } else if (sequenciaDupla(lista,tamanho)){
        return 3;
    } else return 0;
}