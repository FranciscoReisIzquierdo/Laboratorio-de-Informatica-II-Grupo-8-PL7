#ifndef PROJETOLI2_CAMADA_DE_DADOS_H
#define PROJETOLI2_CAMADA_DE_DADOS_H

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
int giveUltColuna(ESTADO *e);
int giveUltLinha(ESTADO *e);
void incrJogada(ESTADO *e);
void changePlayer(ESTADO *e);
int winner(ESTADO *e);
int linhaAnterior(ESTADO *e);
char colunaAnterior(ESTADO *e);
int linhaaa(int line);
char colunaaa(int column);
int jogAtual(ESTADO *e);
int numJogada(ESTADO*e);

#endif //PROJETOLI2_CAMADA_DE_DADOS_H