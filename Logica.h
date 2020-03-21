#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H
#include "Camada de Dados.h"
#include "Interface.h"

int jogar(ESTADO *e, COORDENADA c);
int jogadaValida(ESTADO *e, COORDENADA c);
int jogoAcabou(ESTADO *e, COORDENADA c);

#endif //PROJETOLI2_LOGICA_H
