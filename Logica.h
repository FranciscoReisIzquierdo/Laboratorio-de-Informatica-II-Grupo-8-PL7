#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H
#include "Camada de Dados.h"
#include "Interface.h"
#include "ListasLigadas.h"

int jogar(ESTADO *e, COORDENADA c);
int jogadaValida(ESTADO *e, COORDENADA c);
int jogoAcabou(ESTADO *e);
LISTA vizinhasVazias(ESTADO *e);
COORDENADA jogadaAleatoria(LISTA vizinhasVazias);

#endif //PROJETOLI2_LOGICA_H
