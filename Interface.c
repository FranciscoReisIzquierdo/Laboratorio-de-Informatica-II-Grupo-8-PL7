#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 1024
#include "Camada de Dados.h"
#include "Interface.h"

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

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
        prompt(e);
    }
    return 1;
}

void prompt(ESTADO *e){
    printf("Player%d Numero da Jogada %d", (e-> jogador_atual), (e->num_jogadas));
}