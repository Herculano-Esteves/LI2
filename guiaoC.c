#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesAux.h"

int verificarJogada(wchar_t arrayCartas[][60],CartaDef arrayDef[][60],int tamanhoArray[], int numeroJogadas){
    int condicao = 1;
    condicao = belongToDeck(arrayDef,tamanhoArray,numeroJogadas);
    removeCardsDeck(arrayCartas[0],arrayDef[0],arrayDef[numeroJogadas],tamanhoArray,numeroJogadas);
    return condicao;
}

int leituraDaRonda(wchar_t arrayCartas[][60],CartaDef arrayDef[][60],int tamanhoArray[]){
    int leituras,repeticao;
    wscanf(L"%d\n", &leituras);
    for(repeticao = 0;repeticao < leituras+2;repeticao++){
        wscanf(L"%ls",arrayCartas[repeticao]);
        guardarvalores(arrayCartas[repeticao],arrayDef[repeticao]);
        tamanhoArray[repeticao] = tamanhoCartas(arrayCartas[repeticao]);
        ordCartaNumeroDef(arrayCartas[repeticao],arrayDef[repeticao],tamanhoArray[repeticao]);
    }
    return leituras+1;
}

void funcaoGuiaoC(){
    int leituras,repeticao;
    wscanf(L"%d\n", &leituras);
    for (repeticao = 0; repeticao < leituras;repeticao++){

        wchar_t arrayCartas[60][60]; // arrayCartas[0] é o baralho, a partir disso são as jogadas pretendidas arrayCartas[tamanho] é a jogada
        CartaDef arrayDef[60][60];
        int tamanhoArrays[60] = {0},numeroDeJogadas; // tamanhos a partir do 0

        wprintf(L"Teste %d\n",repeticao+1);
        numeroDeJogadas = leituraDaRonda(arrayCartas,arrayDef,tamanhoArrays);
        wprintfCartas(arrayCartas[0],arrayDef[0],1);
        int verify = verificarJogada(arrayCartas,arrayDef,tamanhoArrays,numeroDeJogadas);

        wprintf(L"Vou ler %d linhas, jogada pertence ao baralho? :%d\n",numeroDeJogadas +1,verify);
        wprintfCartas(arrayCartas[0],arrayDef[0],1);
        wprintfCartas(arrayCartas[numeroDeJogadas],arrayDef[numeroDeJogadas],1);
        wprintlistacartas(arrayDef[0]);
    }
}