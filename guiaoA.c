#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"

int sequenciaUnica(CartaDef lista[], int tamanho){
    int i;
    for(i = 0;lista[i].valor+1 == lista[i+1].valor && i < tamanho-1;i++);
    if (i == tamanho-1 && i > 1) return 1;
    return 0;
}

int sequenciaDupla(CartaDef lista[], int tamanho){
    int i=0;
    if(lista[i].valor != lista[i+1].valor) return 0;
    for(i = 2;(i < tamanho-1) && (tamanho % 2 == 0);i += 2){
        if(lista[i].valor != lista[i+1].valor || lista[i-1].valor+1 != lista[i].valor) return 0;
    }
    if (i == tamanho && tamanho > 5) return 1;
    return 0;
}

int conjuntoBool(CartaDef lista[],int tamanho)
{
    int i;
    for(i = 0;i < tamanho-1 && lista[i].valor == lista[i+1].valor && tamanho < 5;i++ );
    if (i == tamanho-1){
        for(int w = 0;w < tamanho;w++){
            for(int n = w+1;n < tamanho;n++){
                if(lista[w].naipe == lista[n].naipe) return 0; // nao é nada
            }
        }
    }
    if (i == tamanho-1) return 1;
    return 0;
}

void outputsGuiao1(CartaDef lista[],wchar_t cartas[],int tamanho){
    if(conjuntoBool(lista,tamanho)){
        wprintf(L"conjunto com %d cartas onde a carta mais alta é %lc\n", tamanho,cartas[tamanho-1]);
    } else if (sequenciaUnica(lista,tamanho)){
        wprintf(L"sequência com %d cartas onde a carta mais alta é %lc\n", tamanho,cartas[tamanho-1]);
    } else if (sequenciaDupla(lista,tamanho)){
        wprintf(L"dupla sequência com %d cartas onde a carta mais alta é %lc\n", tamanho/2,cartas[tamanho-1]);
    } else wprintf(L"Nada!\n");
    
}

void funcaoguiao1()
{
    int leituras = 0;
    wscanf(L"%d\n", &leituras);
    
    for (; leituras > 0; leituras--)
    {
        wchar_t cartas[1000];
        CartaDef listaatual[1000];
        int tamanho = 0;
        wscanf(L"%ls",cartas);
        //wprintfCartas(cartas);
        tamanho = tamanhoCartas(cartas);
        if (filtarcartas(cartas,tamanho)){
        guardarvalores(cartas, listaatual);          // atualiza a listaatual
        ordCartaNumero(cartas, listaatual, tamanho); // atualiza a lista atual por ordem
        outputsGuiao1(listaatual,cartas,tamanho);
        } else wprintf(L"Nada!\n");

        //wprintlistacartas(listaatual,tamanho);
        //wprintf(L"%d\n",tamanho);
        
    }
}