#include "Logica.h"
#include "Camada de Dados.h"
#define BUF_SIZE 1024




int jogar(ESTADO *e, COORDENADA c) {
            COORDENADA ultima = e->ultima_jogada;
            e->tab[7 - c.linha][c.coluna] = BRANCA;
            e->tab[ultima.linha][ultima.coluna] = PRETA;
            e->ultima_jogada.linha = 7 - c.linha;
            e->ultima_jogada.coluna = c.coluna;
            mostrar_tabuleiro(e);
            e -> num_jogadas++;
    return 1;
}

int jogadaValida(ESTADO *e, COORDENADA c) {
        if (c.linha < 1 || c.linha > 8 || c.coluna > 'H') {
            return 0;
        }
        else if (c.linha - (e -> ultima_jogada.linha) > 1 || c.linha - (e -> ultima_jogada.linha) < -1)
            return 0;
        else if (c.coluna - (e -> ultima_jogada.coluna) > 1 || c.coluna - (e -> ultima_jogada.coluna) < -1)
            return 0;
        else if (e -> tab [c.linha] [c.coluna] == PRETA){
            return 0;
        }
        return 1;
}

int jogoAcabou(ESTADO *e){
    if ((e -> ultima_jogada.linha == 8) && (e -> ultima_jogada.coluna == 'A') || (e -> ultima_jogada.linha == 1) && (e -> ultima_jogada.coluna == 'H'))
        return 1;
    return 0;
}



