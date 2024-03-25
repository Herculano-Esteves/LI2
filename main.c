#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include "funcoes1.h"
#include "funcoes1.c"


int main() {
    setlocale(LC_CTYPE, "C.UTF-8");
    wchar_t c;

    scanf("%lc", &c);
    
    printf("Caractere lido: %lc\n", c);
    return 1;
}