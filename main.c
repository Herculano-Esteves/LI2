#include "guiao1.h"
#include "guiao1.c"

int main() {
    setlocale(LC_CTYPE, "C.UTF-8");
    int contadorcartas[56];
    for (int i = 0; i < 56; i++) {
        contadorcartas[i] = 1;
    }
    funcaoguiao1();    
    return 1;
}





/*
    wchar_t cartasarray[56] = {
    // Cartas com o mesmo numero tem valores diferentes o«conforme a ordem que apareçam
    // Ou seja cartasarray[0] (🃑) < cartasarray[13] (🂡)
    // Espadas
    L'🃑', L'🃒', L'🃓', L'🃔', L'🃕', L'🃖', L'🃗', L'🃘', L'🃙', L'🃚', L'🃛', L'🂬', L'🃝', L'🃞',
    // Copas
    L'🂡', L'🂲', L'🂳', L'🂴', L'🂵', L'🂶', L'🂷', L'🂸', L'🂹', L'🂺', L'🂻', L'🂼', L'🂽', L'🂾',
    // Ouros
    L'🃁', L'🃂', L'🃃', L'🃄', L'🃅', L'🃆', L'🃇', L'🃈', L'🃉', L'🃊', L'🃋', L'🃌', L'🃍', L'🃎',
    // Paus
    L'🂱', L'🂢', L'🂣', L'🂤', L'🂥', L'🂦', L'🂧', L'🂨', L'🂩', L'🂪', L'🂫', L'🃜', L'🂭', L'🂮'
    };
*/