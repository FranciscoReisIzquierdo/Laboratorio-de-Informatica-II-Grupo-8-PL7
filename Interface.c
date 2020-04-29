#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Camada de Dados.h"
#include "Interface.h"
#define BUF_SIZE 1024

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
    char linha[BUF_SIZE];
    char col[2], lin[2];
    fgets(linha, BUF_SIZE, stdin);
    char *command = strtok(linha, "\n");
    char *cmd = strtok(command, " ");
    if (strcmp(cmd, "jog") == 0) {  //Comando jog (Bot)
        printf("Jogada efectuada pelo bot\n");
        guarda_jogada(e, jogadaAleatoria(vizinhas(e)));
        jogar(e, jogadaAleatoria(vizinhas(e)));  //guarda a jogada e joga
        if (jogoAcabou(e) == 1) {     //verifica se o jogo acabou
            mostrar_tabuleiro(e);
            exit(0);
        } else prompt(e);
    }
    if (strcmp(cmd, "jog2") == 0) {
        COORDENADA c= mcts(e, vizinhas(e));
        printf("Jogatana: %d%d\n", c.coluna, 7- c.linha);
        guarda_jogada(e, c);  jogar(e, c);
        if(jogoAcabou(e)== 1){
            mostrar_tabuleiro(e);  exit(0);
        }
        else prompt(e);
    }
    if (strcmp(cmd, "movs") == 0) {  //Comando movs
        imprime_lista_jogadas(e);
        prompt(e);
    }
    if (strcmp(cmd, "Q") == 0) { exit(0); }
    //Comando Q
    if (strcmp(cmd, "gr") == 0) {  //Comando gr
        FILE *file;
        char *nome = strtok(NULL, " ");
        file = fopen(nome, "w");
        guarda_tabuleiro(e, file);
        prompt(e);
    }
    if (strcmp(cmd, "ler") == 0) {  //Comando ler
        FILE *file;
        char *nome = strtok(NULL, " ");
        file = fopen(nome, "r");
        le_Tabuleiro(e, file);
        prompt(e);
    }
    if (strcmp(cmd, "pos") == 0){
        char *num = strtok(NULL, " ");
        int numero;
        sscanf(num, "%d", &numero);//= {num[0] - '0'};
        comandoPos(e, numero);
        prompt(e);
        }
    else if (strlen(command) == 2 && sscanf(command, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        if (jogadaValida(e, coord) == 0) prompt(e);
        else {
            vizinhas(e);  guarda_jogada(e, coord);  jogar(e, coord);   //guarda a jogada e joga
            if (jogoAcabou(e) == 1){     //verifica se o jogo acabou
                 mostrar_tabuleiro(e);  exit(0) ;
            }
            prompt(e);
        }
    }
    else {
        printf("Jogada fora das dimensoes do tabuleiro. Jogue de novo\n");  prompt(e);
        }
    return 1;
    }

void infoDoJogo(ESTADO *e){
    printf("Jogador a Jogar:%d     Numero da Jogada:%d     Jogada Atual:%c%d\n", jogAtual(e), numJogada(e), colunaAnterior(e), linhaAnterior(e));
}

void prompt(ESTADO *e){
    infoDoJogo(e);  mostrar_tabuleiro(e); interpretador(e);
}

void guarda_tabuleiro(ESTADO *e, FILE *file) {
    for (int i=0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (e->tab[i][j] == VAZIO) fprintf( file, ".");
            if (e->tab[i][j] == POS2) fprintf( file, "2");
            if (e->tab[i][j] == POS1) fprintf( file, "1");
            if (e->tab[i][j] == BRANCA) fprintf( file, "*");
            if (e->tab[i][j] == PRETA) fprintf( file, "#");
        }
        fprintf( file, "\n");
    }
    fprintf( file, "\n");
    int i=0, j= 1, numjogada= e->num_jogadas, jog= e->jogador_atual, contador= 0;
    if(contador< 10){
        while (i < numjogada -1) {
            fprintf(file, "0%d: ", j);
            fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
            fprintf(file, "%c%d\n", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
            i++, j++; contador++;
        }
        if(i== numjogada -1 && jog== 2){
        fprintf(file, "0%d: ", j);
        fprintf(file, "%c%d\n", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        }
    }
    else{
        while (i < numjogada -1) {
            fprintf(file, "%d: ", j);
            fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
            fprintf(file, "%c%d\n", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
            i++, j++;
        }
        if(i== numjogada -1 && jog== 2){
            fprintf(file, "%d: ", j);
            fprintf(file, "%c%d\n", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        }
    }
    fflush(file);
}

void le_Tabuleiro(ESTADO *e, FILE *file) {
    char buffer[BUF_SIZE];
    int i=0, l= 0, coluna= 0, linha= 0, numJogada= 1, jogador= 1;
    while (fgets(buffer, BUF_SIZE, file) != NULL) {
        if(l<8) {
            for (int c = 0; c < 8; c++) {
                if (buffer[c] == '*') {  e->tab[l][c] = BRANCA;  coluna = c;  linha = l;  }
                if (buffer[c] == '#') e->tab[l][c] = PRETA;
                if (buffer[c] == '.') e->tab[l][c] = VAZIO;
                if (buffer[c] == '1') e->tab[l][c] = POS1;
                if (buffer[c] == '2') e->tab[l][c] = POS2;
                e->ultima_jogada.coluna = coluna;
                e->ultima_jogada.linha = linha;
            }
        }
        if(l>8) {
            strtok(buffer, ":");
            char *sep2 = strtok(NULL, ":");
            char *jog1 = strtok(sep2, " ");
            COORDENADA c1 = {jog1[0]- 'a', jog1[1]- '1'};
            e->jogadas[i].jogador1= c1; jogador= 2;
            char *jog2 = strtok(NULL, "\n");
            if(jog2!=NULL && strlen(jog2)==2){
                COORDENADA c2 =  {jog2[0]- 'a', jog2[1]- '1'};
                e->jogadas[i].jogador2= c2; jogador= 1; numJogada++;
            }
            i++;
        }
        l++;

    }
    e->num_jogadas= numJogada; e->jogador_atual= jogador;
}

void guarda_jogada(ESTADO *e, COORDENADA c) {
    int i = e-> num_jogadas -1;
    if (e->jogador_atual== 1) e->jogadas[i].jogador1 = c;
    else if (e->jogador_atual== 2){
        e->jogadas[i].jogador2 = c;
        }
}

void imprime_lista_jogadas(ESTADO *e) {
    printf("Lista de movimentos:\n");
    int j = 1, i=0, numjogada= e->num_jogadas;
    if(numjogada< 10){
    while (i < numjogada -1) {
        printf("0%d: ", j);
        printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        printf("%c%d ", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
        putchar('\n');
        i++;
        j++;
    }
    if(i== numjogada -1 && e->jogador_atual==2){
        printf("0%d: ", j);
        printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        putchar('\n');
    }
}
    else {
        while (i < numjogada -1) {
            printf("%d: ", j);
            printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
            printf("%c%d ", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
            putchar('\n');
            i++;
            j++;
        }
        if(i== numjogada -1 && e->jogador_atual==2){
            printf("%d: ", j);
            printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
            putchar('\n');
        }
    }
}

int comandoPos(ESTADO *e, int numero) {
    int i = 0, numjog = numJogada(e), jog = jogAtual(e);
    if (numeroValido(e, numero) == 0) return 1;
    else {
        if (jog == 1) {
            if (numero == 0) {
                e->tab[3][4] = BRANCA;
                e->ultima_jogada.coluna = 4;
                e->ultima_jogada.linha = 3;
            }
            for (; i < numero - 1; i++) {
                e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = PRETA;
                e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = PRETA;
            }
            if (i == numero - 1) {
                e->tab[3][4] = PRETA;
                e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = PRETA;
                e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = BRANCA;
                e->ultima_jogada.coluna = e->jogadas[i].jogador2.coluna;
                e->ultima_jogada.linha = 7 - e->jogadas[i].jogador2.linha;
                i++;
            }
            for (; i < numjog - 1; i++) {
                e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = VAZIO;
                e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = VAZIO;
            }
        }
        if (jog == 2) {
            if (numero == 0) {
                e->tab[3][4] = BRANCA;
                e->ultima_jogada.coluna = 4;
                e->ultima_jogada.linha = 3;
            }
            for (; i < numero - 1; i++) {
                e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = PRETA;
                e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = PRETA;
            }
            if (i == numero - 1) {
                e->tab[3][4] = PRETA;
                e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = PRETA;
                e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = BRANCA;
                e->ultima_jogada.coluna = e->jogadas[i].jogador2.coluna;
                e->ultima_jogada.linha = 7 - e->jogadas[i].jogador2.linha;
                i++;
            }
            for (; i < numjog - 1; i++) {
                e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = VAZIO;
                e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = VAZIO;
            }
            if(i== numjog -1) e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = VAZIO;
            e->jogador_atual = 1;
        }
        e->num_jogadas = numero + 1;
        return 0;
    }
}

int numeroValido(ESTADO *e, int numero){
    if(e-> tab [7- e->jogadas[numero].jogador1.linha][e->jogadas[numero].jogador1.coluna]== POS1){
        printf("Valor superior ao permitido\n");
        return 0;
    }
    else return 1;
}
