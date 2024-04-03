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
int ordCartaNumero(CartaLista lista[],wchar_t carta[]){
    wchar_t auxcarta;
    CartaLista auxlista;
    int i, j, min_idx; 
    for (int i = 0; carta[i]; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; carta[j]; j++) 
          if (carta[j] < carta[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
           if(min_idx != i) 
            swap(&carta[min_idx], &carta[i]); 
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
        guardarvalores(cartas,listaatual); // atualiza a listaatual
        wprintlistacartas(cartas,listaatual);
    }


}