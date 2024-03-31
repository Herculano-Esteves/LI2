#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include <stdlib.h>

typedef struct {
    char naipe;   // Naipe da carta
    int valor;  // Valor da carta
} CartaLista;

char naipe(wchar_t carta){
    char naipes[4] = {'E','C','O','P'};
    char r = naipes[(((carta / 16) % 16) - 10)];
    return r;
}

int valor(wchar_t carta){
    return(carta % 16);
}

void guardarvalores(wchar_t cartas[],CartaLista listaatual[]){
    for(int x = 0;cartas[x];x++){
        listaatual[x].naipe = naipe(cartas[x]);
        listaatual[x].valor = valor(cartas[x]);
    }
}

void wprintlistacartas(int tamanho,CartaLista lista[]){
        for (int i = 0;i < tamanho; i++) {
        wprintf(L"Carta %d: Naipe: %c, Valor: %d\n", i + 1, lista[i].naipe, lista[i].valor);
        }
}
//ordenar as cartas pelos numeros delas
int ordCartaNumero(CartaLista lista[],int tamanho){
    int auxint;
    char auxchar;
    for(int x = 0;x < tamanho;x++){
        for(int y = x+1;y < tamanho;y++){
            if(lista[x].valor > lista[y].valor){
                
            }
        }
    }
}

void funcaoguiao1(){
    wchar_t cartas[10];
    CartaLista listaatual[10];
    int leituras = 0;
    wscanf(L"%d",&leituras);


    for(;leituras > 0;leituras--){
        wscanf(L"%ls",cartas);
        int tamanho = 0;
        for(;cartas[tamanho];tamanho++);
        CartaLista listaatual[10];
        wprintf(L"o tamanho da string é :%d\n",tamanho);
        guardarvalores(cartas,listaatual); // atualiza a listaatual
        wprintlistacartas(cartas,listaatual);
    }


}