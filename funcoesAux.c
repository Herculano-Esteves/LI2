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
    for(int i = 0;listaatual[i].naipe;i++){
        listaatual[i].naipe = APAGADO;
        listaatual[i].valor = 0;
    }
    if(cartas[0] != L'P'){
        for (int x = 0; cartas[x]; x++)
        {
            listaatual[x].naipe = naipe(cartas[x]);
            listaatual[x].valor = valor(cartas[x]);
        }
    } else {
        listaatual[0].naipe = PASSO;
    }
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
    case PASSO:
        return '>';
    case APAGADO:
        return 'D';
    default:
        return '?';
    }
} // converte o naipe para char

void wprintfCartas(wchar_t cartas[],CartaDef def[], int space)
{
    if(def[0].naipe == PASSO){
        wprintf(L"wchar == PASSO");
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
    for (int i = 0; lista[i].valor && lista[i].naipe != APAGADO; i++)
    {
        if(lista[i].naipe == PASSO){
            wprintf(L"CartaDef == PASSO\n");   
        } else {
            char c = printnaipe(lista[i].naipe);
            wprintf(L"Carta %d: Naipe: %c, Valor: %d\n", i, c, lista[i].valor);
        }
    } 
    if(lista[0].naipe != APAGADO) wprintf(L"é apagado\n");
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
    if(lista[0].naipe == PASSO);
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
} // devolve o tamanho do array ignorando espaços comecando do 0

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

// retorna a posicao a partir do 1, se der 0 nao pertence ao deck ou seja para usar em funçoes subtrair 1
int cardPos(CartaDef deck[],CartaDef carta,int tamanhoDeck){
    int m = tamanhoDeck/2,u = tamanhoDeck,l = 0;
    while(l <= u){
        m = l + (u-l)/2;
        if(carta.valor == deck[m].valor && carta.naipe == deck[m].naipe) return m+1;
        if(carta.valor < deck[m].valor || (carta.valor == deck[m].valor && carta.naipe < deck[m].naipe)){
            u = m-1;
        } else {
            l = m+1;
        }
    }
    return 0;
}

//nao esquecer de diminuir o tamanho no tamanhoArray[] (NAO USAR ESTA USAR A removeCardsDeck MESMO QUE SEJA SO UMA CARTA)
void apagarCarta(wchar_t cartas[],CartaDef defcartas[],int posErase){
    int i;
    for(i = posErase; cartas[i+1];i++){
        cartas[i] = cartas[i+1];
        defcartas[i] = defcartas[i+1];
    }
    cartas[i] = L'\0';
    defcartas[i].naipe = APAGADO;
}

//remove um array de cartas a um array de cartas
void removeCardsDeck(wchar_t wchardeck[],CartaDef defcartas[],CartaDef paraApagar[],int tamanhos[],int arrayTamanhos){
    for(int i = 0;i < tamanhos[arrayTamanhos];i++){
        int posParaApagar = cardPos(defcartas,paraApagar[i],tamanhos[0])-1;
        apagarCarta(wchardeck,defcartas,posParaApagar);
        tamanhos[0] += -1;
    }
}