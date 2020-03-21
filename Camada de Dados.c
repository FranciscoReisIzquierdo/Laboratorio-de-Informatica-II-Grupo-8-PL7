#include "Camada de Dados.h"
#include <stdlib.h>
#include <stdio.h>

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

int giveUltColuna(ESTADO *e){
    int c= e-> ultima_jogada.coluna;
    return c;
}

int giveUltLinha(ESTADO *e){
    int l = e-> ultima_jogada.linha;
    return l;
}

void incrJogada(ESTADO *e){
    e-> num_jogadas++;
}

void changePlayer(ESTADO *e){
    if (e-> jogador_atual== 1) e-> jogador_atual=2;
    else e->jogador_atual=1;
}

int winner(ESTADO *e){
    int r;
    if (e-> jogador_atual== 1) r=2;
    else r=1;
    return r;
}