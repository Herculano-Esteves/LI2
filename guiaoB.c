#include <stdio.h>
#include <stdlib.h>
#include "guiao1.h"
#include "guiao1.c"



int checkIfEqual(int tamanhos[]){
    int i,size;
    for(size = 0; tamanhos[size]; size++);
    for(i = 0;tamanhos[i] == tamanhos[i+1], i < size-1;i++);
    if(i = size-1) return  1;
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

void funcaoGiaoB(){

    wchar_t cartasarray[60][60];
    int leituras,i,n;
    wscanf(L"%d\n", &leituras);
    for (i = 0; i < leituras;i++){
        int numeroArrays;
        int tamanhoArray[60];
        wscanf(L"%d\n", &numeroArrays);
        for (n = 0; n < numeroArrays;n++){
            
            wscanf(L"%ls",cartasarray[n]);
            tamanhoArray[n] = tamanhoCartas(cartasarray[n]);
        }
        //funcao principal
        int x = checkIfEqual(tamanhoArray);
        wprintf(L"sao todos tamanho igual: %d\n",x);
    }
}