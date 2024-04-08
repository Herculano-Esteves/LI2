#ifndef GUIAO1_H
#define GUIAO1_H
#include <wchar.h>

typedef enum naipe {
  ESPADAS,
  COPAS,
  OUROS,
  PAUS
} Naipe;

typedef struct {
    Naipe naipe;   // Naipe da carta
    int valor;  // Valor da carta
} CartaDef;

Naipe naipe(wchar_t carta);
int valor(wchar_t carta);
void guardarvalores(wchar_t cartas[], CartaDef listaatual[]);
void swaplista(CartaDef lista[], int posinicial, int posfinal);
void swapcarta(wchar_t cartas[], int posx, int posy);
char printnaipe(Naipe naipe);

void funcaoguiao1();

#endif /* GUIAO1_H */