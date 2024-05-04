#ifndef GUIAO1_H
#define GUIAO1_H
#include <wchar.h>

typedef enum naipe {
  APAGADO,
  PASSO,
  ESPADAS,
  COPAS,
  OUROS,
  PAUS
} Naipe; //naipe organizado e possivel comparar com < e >

typedef struct CartaDef {
  Naipe naipe;   // Naipe da carta
  int valor;  // Valor da carta
} CartaDef;

Naipe naipe(wchar_t carta);
int valor(wchar_t carta);
void guardarvalores(wchar_t cartas[], CartaDef listaatual[]);
void swaplista(CartaDef lista[], int posinicial, int posfinal);
void swapcarta(wchar_t cartas[], int posx, int posy);
char printnaipe(Naipe naipe);
void wprintfCartas(wchar_t cartas[],CartaDef def[], int space);
void wprintlistacartas(CartaDef lista[]);
void ordCartaNumeroDef(wchar_t carta[], CartaDef lista[], int tamanho);
int tamanhoCartas(wchar_t cartas[]);
int filtarcartas(wchar_t cartas[],int tamanho);
int conjuntoBool(CartaDef lista[],int tamanho);
int sequenciaDupla(CartaDef lista[], int tamanho);
void ordCartas(wchar_t carta[], int tamanho);
int sequenciaUnica(CartaDef lista[], int tamanho);
int checkIfTrue(CartaDef lista[],int tamanho);
int cardBelongToString(CartaDef deck[],CartaDef carta,int tamanhoDeck);
void apagarCarta(wchar_t cartas[],CartaDef defenicoes[],int posErase);
void removeCardsDeck(wchar_t wchardeck[],CartaDef defcartas[],CartaDef paraApagar[],int tamanhos[],int arrayLong);
int cardPos(CartaDef deck[],CartaDef carta,int tamanhoDeck);
void removerCartaEmBaralho(wchar_t cartas[],CartaDef cartasDef[],CartaDef apagar);
void copiarMatrizWChar(wchar_t destino[][60], wchar_t origem[][60]);
void copiarMatrizDef(CartaDef destino[][60], CartaDef origem[][60]);
void copiarMatrizInt(int destino[][60], int origem[][60]);
int conjuntoDeReis(CartaDef jogadaAnterior[],int tamanho);
int maisPequenoCNaipe(CartaDef carta0,CartaDef carta1);
int maisPequenoSNaipe(CartaDef carta0,CartaDef carta1);



void funcaoguiao1();
void funcaoGiaoB();
void funcaoGuiaoC();
void funcaoGuiaoD();

#endif /* GUIAO1_H */