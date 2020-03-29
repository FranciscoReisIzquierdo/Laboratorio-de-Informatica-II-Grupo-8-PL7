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
    file = fopen("C:\\Users\\franc\\CLionProjects\\ProjetoLI2\\Tabuleiro.txt", "r+");
    char linha[BUF_SIZE];
    char col[2], lin[2];
    putchar('\n');
    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (sscanf(linha, "Q %s")) return 0;
    if (sscanf(linha, "ler %s")){
        le_Tabuleiro(e, file);
        prompt(e);
    }
    if (sscanf(linha, "movs %s")){
        imprime_lista_jogadas(e);
        prompt(e);
    }

    if (sscanf(linha, "gr %s")){
        guarda_tabuleiro(e, file);
        prompt(e);
    }

    else if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        if (jogadaValida(e, coord) == 0) {
            putchar('\n');
           prompt(e);
        } else {
            guarda_jogada(e, coord);
            jogar(e, coord);

            if (jogoAcabou(e, coord) == 1){
                return 0;
            }
            prompt(e);
        }
    }

    else {
        printf("Jogada fora das dimensoes do tabuleiro. Jogue de novo\n");
       prompt(e);
    }

    return 1;
}


void prompt(ESTADO *e){
    printf("Jogador a Jogar:%d     Numero de Jogadas Efectuadas:%d     Jogada Atual:%c%d\n", e-> jogador_atual, e->num_jogadas, colunaAnterior(e), linhaAnterior(e));
    mostrar_tabuleiro(e);
    interpretador(e);
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
    fprintf(file, "Lista de movimentos:\n");
    int j = 1;
    int i=0;
    while (i < e->num_jogadas) {
        fprintf(file, "0%d: ", j);
        fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
        fprintf(file, "\n");
        i++;
        j++;
    }
    if(i== e->num_jogadas && e->jogador_atual==2){
        fprintf(file, "0%d: ", j);
        fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        fprintf(file, "\n");
    }
    fflush(file);
}

void le_Tabuleiro(ESTADO *e, FILE *file) {
    char buffer[BUF_SIZE];
    int l = 0, h=0, coluna, linha;
    while (fgets(buffer, BUF_SIZE, file) != NULL) {
        for (int c = 2; c < 10; c++) {
            if (buffer[c] == '*'){
                e->tab[l][c-2] = BRANCA;
                coluna= c-2;
                linha= l;
            }
            if (buffer[c] == '#'){
                e->tab[l][c-2] = PRETA;
              //h++;
            }
            if (buffer[c] == '.') e->tab[l][c-2] = VAZIO;
            if (buffer[c] == '1') e->tab[l][c-2] = POS1;
            if (buffer[c] == '2') e->tab[l][c-2] = POS2;
            e-> ultima_jogada.coluna= coluna;
            e-> ultima_jogada.linha= linha;
        }
        l++;
    }
    //e->num_jogadas=h;
}

void guarda_jogada(ESTADO *e, COORDENADA c) {
    int i = e-> num_jogadas;
    if (e->jogador_atual== 1) e->jogadas[i].jogador1 = c;
    else if (e->jogador_atual== 2){
        e->jogadas[i].jogador2 = c;
        }
}

void imprime_lista_jogadas(ESTADO *e) {
    printf("Lista de movimentos:\n");
    int j = 1;
    int i=0;
    while (i < e->num_jogadas) {
        printf("0%d: ", j);
        printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        printf("%c%d ", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
        putchar('\n');
        i++;
        j++;
    }
    if(i== e->num_jogadas && e->jogador_atual==2){
        printf("0%d: ", j);
        printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        putchar('\n');
    }
}


