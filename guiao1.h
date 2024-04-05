#ifndef GUIAO1_H
#define GUIAO1_H

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

void funcaoguiao1();
void swaplista(CartaDef a[], int posinicial, int posfinal);

#endif /* GUIAO1_H */