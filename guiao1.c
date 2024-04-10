#include <stdio.h>
#include <stdlib.h>
#include "guiao1.h"

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

int sequenciaUnica(CartaDef lista[], int tamanho){
    int i;
    for(i = 0;lista[i].valor+1 == lista[i+1].valor && i < tamanho-1;i++);
    if (i == tamanho-1 && i > 1) return 1;
    return 0;
}

int sequenciaDupla(CartaDef lista[], int tamanho){
    int i=0;
    if(lista[i].valor != lista[i+1].valor) return 0;
    for(i = 2;(i < tamanho-1) && (tamanho % 2 == 0);i += 2){
        if(lista[i].valor != lista[i+1].valor || lista[i-1].valor+1 != lista[i].valor) return 0;
    }
    if (i == tamanho && tamanho > 5) return 1;
    return 0;
}

int conjuntoBool(CartaDef lista[],int tamanho)
{
    int i;
    for(i = 0;i < tamanho-1 && lista[i].valor == lista[i+1].valor && tamanho < 5;i++ );
    if (i == tamanho-1){
        for(int w = 0;w < tamanho;w++){
            for(int n = w+1;n < tamanho;n++){
                if(lista[w].naipe == lista[n].naipe) return 0; // nao é nada
            }
        }
    }
    if (i == tamanho-1) return 1;
    return 0;
}

void outputsGuiao1(CartaDef lista[],wchar_t cartas[],int tamanho){
    if(conjuntoBool(lista,tamanho)){
        wprintf(L"conjunto com %d cartas onde a carta mais alta é %lc\n", tamanho,cartas[tamanho-1]);
    } else if (sequenciaUnica(lista,tamanho)){
        wprintf(L"sequência com %d cartas onde a carta mais alta é %lc\n", tamanho,cartas[tamanho-1]);
    } else if (sequenciaDupla(lista,tamanho)){
        wprintf(L"dupla sequência com %d cartas onde a carta mais alta é %lc\n", tamanho/2,cartas[tamanho-1]);
    } else wprintf(L"Nada!\n");
    
}

int filtarcartas(wchar_t cartas[],int tamanho){
    for(int i = 0;i < tamanho;i++){
        if(valor(cartas[i]) > 14 || valor(cartas[i]) < 0 || cartas[i] <= L'🂠' || cartas[i] >= L'🃟') return 0;
    }
    return 1;
}

int funcaoguiao1(int guiaoB)
{
    int leituras = 0;
    wscanf(L"%d\n", &leituras);
    
    for (; leituras > 0; leituras--)
    {
        wchar_t cartas[1000];
        CartaDef listaatual[1000];
        int tamanho = 0;
        wscanf(L"%ls",cartas);
        //wprintfCartas(cartas);
        tamanho = tamanhoCartas(cartas);
        if (filtarcartas(cartas,tamanho)){
        guardarvalores(cartas, listaatual);          // atualiza a listaatual
        ordCartaNumero(cartas, listaatual, tamanho); // atualiza a lista atual por ordem
        outputsGuiao1(listaatual,cartas,tamanho);
        } else wprintf(L"Nada!\n");

        //wprintlistacartas(listaatual,tamanho);
        //wprintf(L"%d\n",tamanho);
        
    }
    return 0;
}