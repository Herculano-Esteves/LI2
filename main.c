#include "funcoesAux.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "C.UTF-8");
    funcaoGuiaoC();
    return 0;
}

//gcc main.c guiao1.c -o exec -lm -g
//(./exec < input.txt) > output.txt
