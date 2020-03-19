#include "Logica.h"
#include "Camada de Dados.h"
#define BUF_SIZE 1024

int jogar(ESTADO *e, COORDENADA c) {
    COORDENADA ultima= e->ultima_jogada;
    e-> tab [7-c.linha][c.coluna]= BRANCA;
    e-> tab [ultima.linha] [ultima.coluna] = PRETA;
    e-> ultima_jogada.linha= 7-c.linha;
    e-> ultima_jogada.coluna= c.coluna;
    mostrar_tabuleiro(e);
    return 1;
}
