#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 1024
#include "Camada de Dados.h"
#include "Interface.h"

void mostrar_tabuleiro(ESTADO *e) {
    int h=8;
    for (int i=0; i < 8; i++) {
        printf("%d ", h);
        h--;
        for (int j = 0; j < 8; j++) {
            if (e->tab[i][j] == VAZIO) printf(".");
            if (e->tab[i][j] == POS2) printf("2");
            if (e->tab[i][j] == POS1) printf("1");
            if (e->tab[i][j] == BRANCA) printf("*");
            if (e->tab[i][j] == PRETA) printf("#");
        }
        printf("\n");
    }
    printf("  abcdefgh\n");
}

int interpretador(ESTADO *e) {
    FILE * file;
    file = fopen("C:\\Users\\franc\\CLionProjects\\ProjetoLI2\\Tabuleiro.txt", "w");
    COORDENADA e5;
    char linha[BUF_SIZE];
    char col[2], lin[2];
    prompt(e);
    putchar('\n');
    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (sscanf(linha, "Q %s")) return 0;
    if (sscanf(linha, "ler %s")){
        le_Tabuleiro(e, file);
        mostrar_tabuleiro (e);
        interpretador(e);
    }

    if (sscanf(linha, "gr %s")){
        guarda_tabuleiro(e, file);
        mostrar_tabuleiro(e);
        interpretador(e);
    }

    else if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        if (jogadaValida(e, coord) == 0) {
            putchar('\n');
            mostrar_tabuleiro(e);
            interpretador(e);
        } else {
            jogar(e, coord);
            if (jogoAcabou(e, coord) == 1){
                return 0;
            }
            interpretador(e);
        }
    }

    else {
        printf("Jogada fora das dimensoes do tabuleiro. Jogue de novo\n");
        mostrar_tabuleiro(e);
        interpretador(e);
    }

    return 1;
}


void prompt(ESTADO *e){
    printf("Jogador a Jogar:%d     Numero de Jogadas Efectuadas:%d     Jogada Atual:%c%d", e-> jogador_atual, e->num_jogadas, colunaAnterior(e), linhaAnterior(e));
}

void guarda_tabuleiro(ESTADO *e, FILE *file) {
    int h=8;
    for (int i=0; i < 8; i++) {
        fprintf(file, "%d ", h);
        h--;
        for (int j = 0; j < 8; j++) {
            if (e->tab[i][j] == VAZIO) fprintf( file, ".");
            if (e->tab[i][j] == POS2) fprintf( file, "2");
            if (e->tab[i][j] == POS1) fprintf( file, "1");
            if (e->tab[i][j] == BRANCA) fprintf( file, "*");
            if (e->tab[i][j] == PRETA) fprintf( file, "#");
        }
        fprintf( file, "\n");
    }
    fprintf(file, "  abcdefgh\n");
}

void le_Tabuleiro(ESTADO *e, FILE *file){
    char *s; int i=0; int j=0;
    fgets(s, 8, file);
    while(i< 8){
        while(j<8){
        if (s[j] == '*') e->tab[i][j]= BRANCA;
        if (s[j] == '#') e-> tab [i][j]= PRETA;
        if (s[j] == '.') e-> tab [i][j]= VAZIO;
        if (s[j] == '1') e-> tab [i][j]= POS1;
        if (s[j] == '2') e-> tab [i][j]= POS2;
            j++;
        }
        j=0;i++;
    }
}
