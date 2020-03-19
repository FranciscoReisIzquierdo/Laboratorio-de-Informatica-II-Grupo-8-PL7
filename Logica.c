#include "Logica.h"
#include "Camada de Dados.h"
#define BUF_SIZE 1024




int jogar(ESTADO *e, COORDENADA c) {
    if (jogadaValida(e,c) == 1) {
        COORDENADA ultima = e->ultima_jogada;
        e->tab[7 - c.linha][c.coluna] = BRANCA;
        e->tab[ultima.linha][ultima.coluna] = PRETA;
        e->ultima_jogada.linha = 7 - c.linha;
        e->ultima_jogada.coluna = c.coluna;
        mostrar_tabuleiro(e);
    }
    return 1;
}
/*
int jogoAcabou(COORDENADA c){
    if (c.linha == 8 && c.coluna == 'A' || c.linha == 1 && c.coluna == 'H')
    return 1;
    return 0;
}
*/

int jogadaValida(ESTADO *e, COORDENADA c) {
        if (c.linha < 1 || c.linha > 8 || c.coluna > 'H') {
            printf("É impossível realizar essa jogada\n");
            return 0;
        }
        else if (abs(c.linha - (e -> ultima_jogada.linha) > 1) || abs(c.coluna - (e -> ultima_jogada.coluna) > 1)) {
            printf("É impossível realizar essa jogada\n");
            return 0;
        }
        else if (e -> tab [c.linha] [c.coluna] == PRETA){
            printf("É impossível realizar essa jogada\n");
            return 0;
        }
        return 1;
}

