#ifndef GUIAO1_H
#define GUIAO1_H
#include <wchar.h>

typedef enum naipe {
  ESPADAS,
  COPAS,
  OUROS,
  PAUS
} Naipe;

typedef struct cartaDef {
  Naipe naipe;   // Naipe da carta
  int valor;  // Valor da carta
} CartaDef;

Naipe naipe(wchar_t carta);
int valor(wchar_t carta);
void guardarvalores(wchar_t cartas[], CartaDef listaatual[]);
void swaplista(CartaDef lista[], int posinicial, int posfinal);
void swapcarta(wchar_t cartas[], int posx, int posy);
char printnaipe(Naipe naipe);
void wprintfCartas(wchar_t cartas[]);
void wprintlistacartas(CartaDef lista[],int tamanho);
void ordCartaNumero(wchar_t carta[], CartaDef lista[], int tamanho);
int tamanhoCartas(wchar_t cartas[]);
int filtarcartas(wchar_t cartas[],int tamanho);
int conjuntoBool(CartaDef lista[],int tamanho);
int sequenciaDupla(CartaDef lista[], int tamanho);
int sequenciaUnica(CartaDef lista[], int tamanho);

void funcaoguiao1();
void funcaoGiaoB();

#endif /* GUIAO1_H */