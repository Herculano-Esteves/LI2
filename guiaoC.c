#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesAux.h"

int tresReisSequenciaDupla(CartaDef lastPlay[][60],int tamanhoArrays[],int numeroJogadas){
    int baralho = numeroJogadas-1, condicao = 0;
    while (lastPlay[baralho][0].naipe == PASSO)
    {
        baralho--;
        condicao++;
        if(baralho < 1) return 0;
    }
    if(condicao > 2) return 0;
    if(tamanhoArrays[baralho] == 3 && lastPlay[baralho][0].valor == 14 && lastPlay[baralho][1].valor == 14 && lastPlay[baralho][2].valor == 14){
        if(sequenciaDupla(lastPlay[numeroJogadas],tamanhoArrays[numeroJogadas]) && tamanhoArrays[numeroJogadas] > 9 && tamanhoArrays[numeroJogadas] < 13) return 1;
    }
    return 0;
}

int doisReisSequenciaDupla(CartaDef lastPlay[][60],int tamanhoArrays[],int numeroJogadas){
    int baralho = numeroJogadas-1, condicao = 0;
    while (lastPlay[baralho][0].naipe == PASSO)
    {
        baralho--;
        condicao++;
        if(baralho < 1) return 0;
    }
    if(condicao > 2) return 0;
    if(tamanhoArrays[baralho] == 2 && lastPlay[baralho][0].valor == 14 && lastPlay[baralho][1].valor == 14){
        if(sequenciaDupla(lastPlay[numeroJogadas],tamanhoArrays[numeroJogadas]) && tamanhoArrays[numeroJogadas] > 7 && tamanhoArrays[numeroJogadas] < 10) return 1;
    }
    return 0;
}

int umReiSequenciaDupla(CartaDef lastPlay[][60],int tamanhoArrays[],int numeroJogadas){
    int baralho = numeroJogadas-1, condicao = 0;
    while (lastPlay[baralho][0].naipe == PASSO)
    {
        baralho--;
        condicao++;
        if(baralho < 1) return 0;
    }
    if(condicao > 2) return 0;
    if(tamanhoArrays[baralho] == 1 && lastPlay[baralho][0].valor == 14){
        if(sequenciaDupla(lastPlay[numeroJogadas],tamanhoArrays[numeroJogadas]) && tamanhoArrays[numeroJogadas] > 5 && tamanhoArrays[numeroJogadas] < 8) return 1;
    }
    return 0;
}

int umReiConjunto(CartaDef lastPlay[][60],int tamanhoArrays[],int numeroJogadas){
    int baralho = numeroJogadas-1, condicao = 0;
    while (lastPlay[baralho][0].naipe == PASSO)
    {
        baralho--;
        condicao++;
        if(baralho < 1) return 0;
    }
    if(condicao > 2) return 0;
    if(tamanhoArrays[baralho] == 1 && lastPlay[baralho][0].valor == 14){
        if(conjuntoBool(lastPlay[numeroJogadas],tamanhoArrays[numeroJogadas]) && tamanhoArrays[numeroJogadas] == 4) return 1;
    }
    return 0;
}

int passosAMais(CartaDef baralho[][60],int numeroJogadas){
    int mesa = numeroJogadas-1, condicao = 0;
    while (baralho[mesa][0].naipe == PASSO)
    {
        mesa--;
        condicao++;
        if(mesa < 1) return 1;
    }
    if(condicao > 2) return 1;
    else return 0;
}

int sequenciaDuplaJogador(CartaDef baralho[][60], int tamanhoArrays[],int numeroJogada)
{
    int mesa = numeroJogada-1, condicao = 0;
    while (baralho[mesa][0].naipe == PASSO)
    {
        mesa--;
        condicao++;
        if(mesa < 1) return 0;
    }
    if(condicao > 2) return 0;
    if(sequenciaDupla(baralho[mesa],tamanhoArrays[mesa]) && sequenciaDupla(baralho[numeroJogada],tamanhoArrays[numeroJogada]) && tamanhoArrays[mesa] == tamanhoArrays[numeroJogada]){
        if((baralho[mesa][tamanhoArrays[mesa]-1].valor < baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].valor) || (baralho[mesa][tamanhoArrays[mesa]-1].valor == baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].valor && baralho[mesa][tamanhoArrays[mesa]-1].naipe < baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].naipe)) return 1;
    }
    return 0;
}

int sequenciaUnicaJogador(CartaDef baralho[][60], int tamanhoArrays[],int numeroJogada)
{
    int mesa = numeroJogada-1, condicao = 0;
    while (baralho[mesa][0].naipe == PASSO)
    {
        mesa--;
        condicao++;
        if(mesa < 1) return 0;
    }
    if(condicao > 2) return 0;
    if(sequenciaUnica(baralho[mesa],tamanhoArrays[mesa]) && sequenciaUnica(baralho[numeroJogada],tamanhoArrays[numeroJogada]) && tamanhoArrays[mesa] == tamanhoArrays[numeroJogada]){
        if((baralho[mesa][tamanhoArrays[mesa]-1].valor < baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].valor) || (baralho[mesa][tamanhoArrays[mesa]-1].valor == baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].valor && baralho[mesa][tamanhoArrays[mesa]-1].naipe < baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].naipe)) return 1;
    }
    return 0;
}

int conjuntoBoolJogador(CartaDef baralho[][60], int tamanhoArrays[],int numeroJogada){
    int mesa = numeroJogada-1, condicao = 0;
    while (baralho[mesa][0].naipe == PASSO)
    {
        mesa--;
        condicao++;
        if(mesa < 1) return 0;
    }
    if(condicao > 2) return 0;
    if(conjuntoBool(baralho[mesa],tamanhoArrays[mesa]) && conjuntoBool(baralho[numeroJogada],tamanhoArrays[numeroJogada]) && tamanhoArrays[mesa] == tamanhoArrays[numeroJogada]){
        if((baralho[mesa][tamanhoArrays[mesa]-1].valor < baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].valor) || (baralho[mesa][tamanhoArrays[mesa]-1].valor == baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].valor && baralho[mesa][tamanhoArrays[mesa]-1].naipe < baralho[numeroJogada][tamanhoArrays[numeroJogada]-1].naipe)) return 1;
    }
    return 0;
}

int jogadaPossivel(CartaDef arrayDef[][60], int tamanhoArray[], int numeroJogadas){
    if(conjuntoBoolJogador(arrayDef,tamanhoArray,numeroJogadas)
    || sequenciaUnicaJogador(arrayDef,tamanhoArray,numeroJogadas)
    || sequenciaDuplaJogador(arrayDef,tamanhoArray,numeroJogadas)
    || passosAMais(arrayDef,numeroJogadas)
    || umReiConjunto(arrayDef,tamanhoArray,numeroJogadas)
    || umReiSequenciaDupla(arrayDef,tamanhoArray,numeroJogadas)
    || doisReisSequenciaDupla(arrayDef,tamanhoArray,numeroJogadas)
    || tresReisSequenciaDupla(arrayDef,tamanhoArray,numeroJogadas)
    || numeroJogadas == 1
    ) return 1;
    else return 0;
}

int belongToDeck(CartaDef arrayDef[][60], int tamanhoArray[], int numeroJogadas)
{
    int r = 1;
    for (int i = 0; i < tamanhoArray[numeroJogadas] && r != 0; i++)
    {
        r = cardPos(arrayDef[0], arrayDef[numeroJogadas][i], tamanhoArray[0]);
    }
    if (r) return 1;
    else return 0;
}

int verificarJogada(CartaDef arrayDef[][60], int tamanhoArray[], int numeroJogadas)
{
    if (belongToDeck(arrayDef, tamanhoArray, numeroJogadas) && checkIfTrue(arrayDef[numeroJogadas], tamanhoArray[numeroJogadas]))
    {
        if(jogadaPossivel(arrayDef,tamanhoArray,numeroJogadas)) return 1;
    }
    return 0;
}

// return a leituras+1 ou seja de 0 a x+1 com input de x em leituras que inclui o baralho e a jogada
int leituraDaRonda(wchar_t arrayCartas[][60], CartaDef arrayDef[][60], int tamanhoArray[])
{
    int leituras, repeticao;
    wscanf(L"%d\n", &leituras);
    for (repeticao = 0; repeticao < leituras + 2; repeticao++)
    {
        wscanf(L"%ls", arrayCartas[repeticao]);
        guardarvalores(arrayCartas[repeticao], arrayDef[repeticao]);
        tamanhoArray[repeticao] = tamanhoCartas(arrayCartas[repeticao]);
        ordCartaNumeroDef(arrayCartas[repeticao], arrayDef[repeticao], tamanhoArray[repeticao]);
    }
    return leituras + 1;
}

void funcaoGuiaoC()
{
    int leituras, repeticao;
    wscanf(L"%d\n", &leituras);
    for (repeticao = 0; repeticao < leituras; repeticao++)
    {

        wchar_t arrayCartas[300][60]; // arrayCartas[0] é o baralho, a partir disso são as jogadas pretendidas arrayCartas[tamanho] é a jogada
        CartaDef arrayDef[300][60];
        int tamanhoArrays[300] = {0}, numeroDeJogadas; // tamanhos a partir do 0

        wprintf(L"Teste %d\n", repeticao + 1);
        numeroDeJogadas = leituraDaRonda(arrayCartas, arrayDef, tamanhoArrays);
        //wprintfCartas(arrayCartas[0], arrayDef[0], 1);
        int verificado = verificarJogada(arrayDef, tamanhoArrays, numeroDeJogadas);
        if(verificado) removeCardsDeck(arrayCartas[0], arrayDef[0], arrayDef[numeroDeJogadas], tamanhoArrays, numeroDeJogadas);
        //wprintf(L"Vou ler %d linhas, jogada pertence ao baralho? :%d\n", numeroDeJogadas + 1, verify);
        wprintfCartas(arrayCartas[0], arrayDef[0], 1);
        //wprintfCartas(arrayCartas[numeroDeJogadas], arrayDef[numeroDeJogadas], 1);
        //wprintlistacartas(arrayDef[0]);
    }
}