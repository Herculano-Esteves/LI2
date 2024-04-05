#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include <stdlib.h>
#include "guiao1.h"

Naipe naipe(wchar_t carta){
    Naipe naipes[4] = {ESPADAS,COPAS,OUROS,PAUS};
    char r = naipes[(((carta / 16) % 16) - 10)];
    return r;
}

int valor(wchar_t carta){
    return(carta % 16);
}

void guardarvalores(wchar_t cartas[],CartaDef listaatual[]){
    for(int x = 0;cartas[x];x++){
        listaatual[x].naipe = naipe(cartas[x]);
        listaatual[x].valor = valor(cartas[x]);
    }
}

void swaplista(CartaDef lista[], int posinicial, int posfinal)
{
    CartaDef aux;
    aux = lista[posinicial];
    lista[posinicial]=lista[posfinal];
    lista[posfinal]=aux;
}

void swapcarta(wchar_t cartas[],int posx, int posy){
    wchar_t aux;
    aux = cartas[posx];
    cartas[posx] = cartas[posy];
    cartas[posy] = aux;
}

char printnaipe(Naipe naipe){
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
void wprintfCartas(wchar_t cartas[]){
    for (int i = 0; i < 10 && cartas[i] != L'\0'; i++) {
        wprintf(L"%lc", cartas[i]);
    }
    wprintf(L"\n");
}

void wprintlistacartas(int tamanho,CartaDef lista[]){
        for (int i = 0;i < tamanho; i++) {
        char c = printnaipe(lista[i].naipe);
        wprintf(L"Carta %d: Naipe: %c, Valor: %d\n", i, c, lista[i].valor);
        }
}

//ordenar as cartas pelos numeros delas
void ordCartaNumero(wchar_t carta[],CartaDef lista[],int tamanho){
    wchar_t auxchar;
    CartaDef auxlista = {ESPADAS,1};
    int i = 0, j = 0, min_idx = 0;
    for (i; i < tamanho; i++)
    {
        min_idx = i;
        for (j = i; j < tamanho;j++){
            if ((lista[j].valor) < (lista[min_idx].valor)) min_idx = j;
            if (lista[j].valor == lista[min_idx].valor && lista[j].naipe < lista[min_idx].naipe)  min_idx = j;
        }
        // Swap the found minimum element with the first element
        if(min_idx != i){
            swaplista(lista,min_idx,i); // para trocar os elementos
            swapcarta(carta,min_idx,i);
        }
    }
}


void funcaoguiao1(){
    wchar_t cartas[10];
    CartaDef listaatual[10];
    int leituras = 0;
    wscanf(L"%d",&leituras);


    for(;leituras > 0;leituras--){
        wscanf(L"%ls",cartas);
        int tamanho = 0;
        for(;cartas[tamanho];tamanho++);
        CartaDef listaatual[10];
        guardarvalores(cartas,listaatual); // atualiza a listaatual
        ordCartaNumero(cartas,listaatual,tamanho); // atualiza a lista atual por ordem
        wprintlistacartas(tamanho,listaatual);
        wprintfCartas(cartas);
    }


}