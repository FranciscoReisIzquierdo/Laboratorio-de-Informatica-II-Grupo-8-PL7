#include "Logica.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 1024

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->ultima_jogada.coluna = 4;
    e->ultima_jogada.linha = 3;
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            e-> tab [i][j]= VAZIO;
            if(i==3 && j==4) e-> tab [i][j]= BRANCA;
            if(i==0 && j==7) e-> tab [i][j]= POS2;
            if(i==7 && j==0) e-> tab [i][j]= POS1;
        }
    }
    return e;
}

void mostrar_tabuleiro(ESTADO *e) {
    for (int i=0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (e->tab[i][j] == VAZIO) putchar('.');
            if (e->tab[i][j] == POS2) putchar('2');
            if (e->tab[i][j] == POS1) putchar('1');
            if (e->tab[i][j] == BRANCA) putchar('*');
            if (e->tab[i][j] == PRETA) putchar('#');
        }
        putchar('\n');
    }
}

int jogar(ESTADO *e, COORDENADA c) {
    COORDENADA ultima= e->ultima_jogada;
    e-> tab [7-c.linha][c.coluna]= BRANCA;
    e-> tab [ultima.linha] [ultima.coluna] = PRETA;
    e-> ultima_jogada.linha= 7-c.linha;
    e-> ultima_jogada.coluna= c.coluna;
    mostrar_tabuleiro(e);
    return 1;
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}








