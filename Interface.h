#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Logica.h"

void mostrar_tabuleiro(ESTADO *e);
int interpretador(ESTADO *e);
void prompt(ESTADO *e);
void guarda_tabuleiro(ESTADO *e, FILE *file);
void le_Tabuleiro(ESTADO *e, FILE *file);
void guarda_jogada(ESTADO *e, COORDENADA c);
void imprime_lista_jogadas(ESTADO *e);


#ifndef PROJETOLI2_INTERFACE_H
#define PROJETOLI2_INTERFACE_H

#endif //PROJETOLI2_INTERFACE_H
