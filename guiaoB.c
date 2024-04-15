#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesAux.h"



int checkIfEqual(int tamanhos[],int size){
    int i;
    for(i = 0;tamanhos[i] == tamanhos[i+1] && i < size-1;i++);
    if(i == size-1) return 1;
    return 0;
}

int checkIfTrue(CartaDef lista[],int tamanho){
    if(conjuntoBool(lista,tamanho)){
        return 1;
    } else if (sequenciaUnica(lista,tamanho)){
        return 2;
    } else if (sequenciaDupla(lista,tamanho)){
        return 3;
    } else return 0;
}

void swapArrayCarta(wchar_t cartasarray[][60], int t, int k) {
    wchar_t aux[60];
    memcpy(aux, cartasarray[t], sizeof(wchar_t) * 60);
    memcpy(cartasarray[t], cartasarray[k], sizeof(wchar_t) * 60);
    memcpy(cartasarray[k], aux, sizeof(wchar_t) * 60);
}

void swapArrayLista(CartaDef cartasdef[][60], int t, int k) {
    CartaDef aux[60];
    memcpy(aux, cartasdef[t], sizeof(CartaDef) * 60);
    memcpy(cartasdef[t], cartasdef[k], sizeof(CartaDef) * 60);
    memcpy(cartasdef[k], aux, sizeof(CartaDef) * 60);
}

void ordfinal(wchar_t cartasarray[][60] ,CartaDef defarray[][60] ,int numeroarrays,int tamanhoarray){
    int i, j = 0, min_idx = 0;
    for (i = 0; i < numeroarrays; i++)
    {
        min_idx = i;
        for (j = i; j < numeroarrays; j++)
        {
            if ((defarray[j][tamanhoarray-1].valor) < (defarray[min_idx][tamanhoarray-1].valor))
                min_idx = j;
            if (defarray[j][tamanhoarray-1].valor == defarray[min_idx][tamanhoarray-1].valor && defarray[j][tamanhoarray-1].naipe < defarray[min_idx][tamanhoarray-1].naipe)
                min_idx = j;
        }
        
        if (min_idx != i)
        {
            swapArrayCarta(cartasarray,min_idx,i);
            swapArrayLista(defarray,min_idx,i);
        }
    }
}

void printAux(wchar_t cartasarray[]){
    wprintfCartas(cartasarray, 1);
}

void leiturasDasCartas(int numeroArrays,wchar_t cartasarray[][60], CartaDef defArray[][60], int tamanhoArray[]){
    for (int n = 0; n < numeroArrays;n++){
        
        wscanf(L"%ls",cartasarray[n]);
        guardarvalores(cartasarray[n],defArray[n]);
        tamanhoArray[n] = tamanhoCartas(cartasarray[n]);
        ordCartaNumero(cartasarray[n],defArray[n],tamanhoArray[n]);
    }
}

void printFinal(int tamanhoarray, int i,int c, int numeroArrays, wchar_t cartasarray[][60], CartaDef defArray[][60]){
    if(c == numeroArrays-1){
        ordfinal(cartasarray,defArray,numeroArrays,tamanhoarray);
        wprintf(L"Teste %d\n",i+1);
        for(int print = 0;print < numeroArrays;print++){
            printAux(cartasarray[print]);
        }
    } 
    else wprintf(L"Teste %d\nCombinações não iguais!\n",i+1);
}

void funcaoGiaoB(){

    wchar_t cartasarray[60][60];
    CartaDef defArray[60][60];
    int leituras,i;
    wscanf(L"%d\n", &leituras);
    for (i = 0; i < leituras;i++){
        int numeroArrays;
        int tamanhoArray[60];
        wscanf(L"%d\n", &numeroArrays);
        leiturasDasCartas(numeroArrays,cartasarray,defArray,tamanhoArray);
        //funcao principal
        int c = 0;
        if (checkIfEqual(tamanhoArray,numeroArrays)){
            for(;c < numeroArrays-1 && checkIfTrue(defArray[c],tamanhoArray[c]) == checkIfTrue(defArray[c+1],tamanhoArray[c+1]) && checkIfTrue(defArray[c],tamanhoArray[c]);c++);
        }
        printFinal(tamanhoArray[0],i,c,numeroArrays,cartasarray,defArray);
    }
}