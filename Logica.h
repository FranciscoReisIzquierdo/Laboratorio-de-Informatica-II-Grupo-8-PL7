#ifndef PROJETOLI2_LOGICA_H
#define PROJETOLI2_LOGICA_H

typedef enum {VAZIO, BRANCA, PRETA, POS1, POS2} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

ESTADO *inicializar_estado();
void mostrar_tabuleiro(ESTADO *e);
int jogar(ESTADO *e, COORDENADA c);
int interpretador(ESTADO *e);

#endif //PROJETOLI2_LOGICA_H
