#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"



int checkIfEqual(int tamanhos[],int size){
    int i;
    for(i = 0;tamanhos[i] == tamanhos[i+1] && i < size-1;i++);
    if(i == size-1) return 1;
    return 0;
}

int checkIfTrue(CartaDef lista[],wchar_t cartas[],int tamanho){
    if(conjuntoBool(lista,tamanho)){
        return 1;
    } else if (sequenciaUnica(lista,tamanho)){
        return 2;
    } else if (sequenciaDupla(lista,tamanho)){
        return 3;
    } else return 0; 
}

void printFinalB(wchar_t cartasarray[][60] ,CartaDef defarray[][60] ,int numeroarrays, int tamanhoarray){

}

void funcaoGiaoB(){

    wchar_t cartasarray[60][60];
    CartaDef defarray[60][60];
    int leituras,i,n;
    wscanf(L"%d\n", &leituras);
    for (i = 0; i < leituras;i++){
        int numeroArrays;
        int tamanhoArray[60];
        wscanf(L"%d\n", &numeroArrays);
        for (n = 0; n < numeroArrays;n++){
            
            wscanf(L"%ls",cartasarray[n]);
            guardarvalores(cartasarray[n],defarray[n]);
            tamanhoArray[n] = tamanhoCartas(cartasarray[n]);
            ordCartaNumero(cartasarray[n],defarray[n],tamanhoArray[n]);
        }
        //funcao principal
        int c = 0;
        if (checkIfEqual(tamanhoArray,numeroArrays)){
            for(;c < numeroArrays-1 && checkIfTrue(defarray[c],cartasarray[c],tamanhoArray[c]) == checkIfTrue(defarray[c+1],cartasarray[c+1],tamanhoArray[c+1]);c++);
        } else wprintf(L"Teste %d\nCombinações não iguais!\n",i+1);
        if(c == numeroArrays-1) printFinalB(cartasarray,defarray,numeroArrays, tamanhoArray[0]);
    }
}