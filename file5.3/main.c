#include "guiao1.h"
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "C.UTF-8");
    funcaoguiao1();
    return 0;
}

//gcc main.c guiao1.c -o exec -lm -g
//(./exec < input.txt) > output.txt
