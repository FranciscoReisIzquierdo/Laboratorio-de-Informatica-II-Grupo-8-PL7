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
COORDENADA mcts(ESTADO *e, LISTA L);
int jogoAcabouMCTS(ESTADO *e, COORDENADA c);
int jogadaPerdeMCTS(ESTADO *e, COORDENADA c);
int jogadasVazias(ESTADO *e, COORDENADA c);
int verificaErro(ESTADO *e, COORDENADA tmp);
int jogoAcabouMCTSAux(ESTADO *e, COORDENADA c);
int vizinhasDaCasaVencedora(COORDENADA c);
int imprimeLista(LISTA L);

#endif //PROJETOLI2_LOGICA_H
