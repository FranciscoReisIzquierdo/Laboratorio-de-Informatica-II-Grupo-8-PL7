#include <stdio.h>
#include "Logica.h"

int main() {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    prompt(e);
    putchar('\n');
    interpretador(e);
    return 0;
}


