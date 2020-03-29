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
    if (e-> jogador_atual== 2)
        e-> num_jogadas++;
    else e-> num_jogadas = e->num_jogadas;
}

void changePlayer(ESTADO *e){
    if (e-> jogador_atual== 1)
        e->jogador_atual = 2;
    else
        e->jogador_atual=1;
}

int winner(ESTADO *e){
    int r;
    if (e-> jogador_atual== 1) r=2;
    else r=1;
    return r;
}

int linhaAnterior(ESTADO *e){
    int line;
    int linha= e-> ultima_jogada.linha;
        line= 7- linha +1;
    return line;
}

char colunaAnterior(ESTADO *e){
    char column;
    int coluna= e-> ultima_jogada.coluna;
    if(coluna== 0) column= 'a';
    else if (coluna== 1) column= 'b';
    else if(coluna== 2) column= 'c';
    else if(coluna== 3) column= 'd';
    else if(coluna== 4) column= 'e';
    else if(coluna== 5) column= 'f';
    else if(coluna== 6) column= 'g';
    else if(coluna== 7) column= 'h';
    return column;
}

int linhaaa(int line){
    int l;
    l= line +1;
    return l;
}

char colunaaa(int column){
    char c;
    if(column== 0) c= 'a';
    else if (column== 1) c= 'b';
    else if(column== 2) c= 'c';
    else if(column== 3) c= 'd';
    else if(column== 4) c= 'e';
    else if(column== 5) c= 'f';
    else if(column== 6) c= 'g';
    else if(column== 7) c= 'h';
    return c;
}