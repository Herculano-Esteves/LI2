#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesAux.h"

int leituraDaRonda(wchar_t arrayCartas[][60],CartaDef arrayDef[][60],int tamanhoArray[]){
    int leituras,repeticao;
    wscanf(L"%d\n", &leituras);
    for(repeticao = 0;repeticao < leituras+2;repeticao++){
        wscanf(L"%ls",arrayCartas[repeticao]);
        guardarvalores(arrayCartas[repeticao],arrayDef[repeticao]);
        tamanhoArray[repeticao] = tamanhoCartas(arrayCartas[repeticao]);
        ordCartaNumeroDef(arrayCartas[repeticao],arrayDef[repeticao],tamanhoArray[repeticao]);
    }
    return leituras+2;
}

void funcaoGuiaoC(){

    wchar_t arrayCartas[60][60]; // arrayCartas[0] é o baralho, a partir disso são as jogadas pretendidas arrayCartas[tamanho] é a jogada
    CartaDef arrayDef[60][60];
    int tamanhoArrays[60];
    int leituras,repeticao,numeroDeJogadas;
    wscanf(L"%d\n", &leituras);
    for (repeticao = 0; repeticao < leituras;repeticao++){
        wprintf(L"Teste %d\n",repeticao+1);
        numeroDeJogadas = leituraDaRonda(arrayCartas,arrayDef,tamanhoArrays);



        //wprintfCartas(arrayCartas[0],arrayDef[0],1);
        //wprintlistacartas(arrayDef[0]);
    }
}