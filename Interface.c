#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
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
    char comando[BUF_SIZE];
    int numero;
    fgets(linha, BUF_SIZE, stdin);
    if (linha == NULL) return 0;
    else {
        char *command = strtok(linha, "\n");
      /*  if (sscanf(linha, "jog %s")){
            printf("PC vs Player\n");
            ESTADO *e= inicializar_estado();
            COORDENADA coord= e-> ultima_jogada;
            infoDoJogo(e);
            mostrar_tabuleiro(e);
            while (jogoAcabou(e) != 1){
                if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
                if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
                    COORDENADA coord = {*col - 'a', *lin - '1'};
                    if (jogadaValida(e, coord) == 0) mostrar_tabuleiro(e);
                    else {
                        infoDoJogo(e);
                        jogar(e, coord);
                        mostrar_tabuleiro(e);
                        LISTA l= jogadasVal(e);
                        if(jogoAcabou(e)== 1) return EXIT_SUCCESS;
                        else {
                            srand(time(NULL));
                            coord= jogAleatoria(l, 1+ (rand() % numElementos(l)));
                            while(jogadaValidaAux(e, coord) == 0){
                                int aux= 1+ (rand() % numElementos(l));
                                coord= jogAleatoria(l, aux);
                            }
                            jogar(e, coord);
                            infoDoJogo(e);
                            mostrar_tabuleiro(e);
                        }
                    }
                }
            }
            return EXIT_SUCCESS;
        }
*/
      char *cmd= strtok(command, " ");
      if (strcmp(cmd, "jog") == 0) {  //Comando jog (Bot)
          printf("Jogada efectuada pelo bot\n");
          guarda_jogada(e, jogadaAleatoria(e));;
          jogar(e, jogadaAleatoria(e));  //guarda a jogada e joga
          if (jogoAcabou(e) == 1) {     //verifica se o jogo acabou
              mostrar_tabuleiro(e);
                    exit(0);
                } else prompt(e);
            }
            if (strcmp(cmd, "movs") == 0) {  //Comando movs
                    imprime_lista_jogadas(e);
                    prompt(e);
            }
            if (strcmp(cmd, "Q") == 0){ exit(0);}  //Comando Q

            if (strcmp(cmd, "gr") == 0) {  //Comando gr
                    FILE *file;
                    char *nome= strtok(NULL, " ");
                    file = fopen(nome, "w+");
                    guarda_tabuleiro(e, file); prompt(e);
                }
                if (strcmp(cmd, "ler") == 0) {  //Comando ler
                    FILE *file;
                    char *nome= strtok(NULL, " ");
                    file = fopen(nome, "r");
                    le_Tabuleiro(e, file);  prompt(e);
                }

        if (sscanf(command, "%s %d", comando, &numero) == 2) {
            if (strlen(comando) == 3 && strcmp(comando, "pos") == 0) {
                if (e->jogador_atual == 1 && e->jogadas[numero].jogador1.linha == 0 && e->jogadas[numero].jogador1.coluna == 0 && e->jogadas[numero].jogador2.linha == 0 && e->jogadas[numero].jogador2.coluna == 0) {
                    printf("Valor superior ao numero de jogadas efectuadas\n");
                    prompt(e);
                }
                else if (e->jogador_atual == 2 && e->jogadas[numero].jogador1.linha == 0 && e->jogadas[numero].jogador1.coluna == 0) {
                    printf("Valor superior ao numero de jogadas efectuadas\n");
                    prompt(e);
                }
                if (numero > e->num_jogadas) {
                    printf("Valor superior ao numero de jogadas efectuadas\n");
                    prompt(e);
                } else if (numero >= 0 && numero <= e->num_jogadas) {
                    numero_jogada(e, numero);
                    prompt(e);
                }
            }
        }
        else if (strlen(command) == 2 && sscanf(command, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            if (jogadaValida(e, coord) == 0) prompt(e);
            else {
                guarda_jogada(e, coord);  jogar(e, coord);   //guarda a jogada e joga
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
}

void infoDoJogo(ESTADO *e){
    printf("Jogador a Jogar:%d     Numero da Jogada:%d     Jogada Atual:%c%d\n", e-> jogador_atual, e->num_jogadas, colunaAnterior(e), linhaAnterior(e));
}

void prompt(ESTADO *e){
    infoDoJogo(e);
    mostrar_tabuleiro(e);
    interpretador(e);
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
    int i=0, j= 1;
    while (i < e->num_jogadas -1) {
        fprintf(file, "0%d: ", j);
        fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
        fprintf(file, "\n");
        i++, j++;
    }
    if(i== e->num_jogadas -1 && e->jogador_atual==2){
        fprintf(file, "0%d: ", j);
        fprintf(file, "%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        fprintf(file, "\n");
    }
    fflush(file);
}

void le_Tabuleiro(ESTADO *e, FILE *file) {
    char buffer[BUF_SIZE];
    char *colon = ":";
    char *sapce = " ";
    int i=0;
    int l = 0, numjog= e-> num_jogadas, coluna, linha;
    while (fgets(buffer, BUF_SIZE, file) != NULL) {
        if(l<8) {
            for (int c = 0; c < 8; c++) {
                if (buffer[c] == '*') {
                    e->tab[l][c] = BRANCA;
                    coluna = c;
                    linha = l;
                }
                if (buffer[c] == '#') {
                    e->tab[l][c] = PRETA;
                }
                if (buffer[c] == '.') e->tab[l][c] = VAZIO;
                if (buffer[c] == '1') e->tab[l][c] = POS1;
                if (buffer[c] == '2') e->tab[l][c] = POS2;
                e->ultima_jogada.coluna = coluna;
                e->ultima_jogada.linha = linha;
            }
        }
        if(l>8) {
            strtok(buffer, ":"); //01: | a1 b1
            char *sep2 = strtok(NULL, ":");// a1 b1
            char *jog1 = strtok(sep2, " "); // a1 | b1
            COORDENADA c1 = {jog1[0]- 'a', '5'- jog1[1]}; //////////////////////
            e->jogadas[i].jogador1= c1;
            char *jog2 = strtok(NULL, " "); //b1
            if(jog2!=NULL && strlen(jog2)==2){
                COORDENADA c2 =  {jog2[0]- 'a', '3'-jog2[1]};
                e->jogadas[i].jogador2= c2;
            }
            i++;
        }
        l++;

    }
   /*if(e->jogador_atual==2){
       changePlayer(e);
       e->num_jogadas= l-7;
   }
   else if((l-7)%2==0 && e->jogador_atual==1){
           changePlayer(e);
           e->num_jogadas= l-8;
       }*/
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
    int j = 1;
    int i=0;
    while (i < e->num_jogadas -1) {
        printf("%d: ", j);
        printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        printf("%c%d ", colunaaa(e->jogadas[i].jogador2.coluna), linhaaa(e->jogadas[i].jogador2.linha));
        putchar('\n');
        i++;
        j++;
    }
    if(i== e->num_jogadas -1 && e->jogador_atual==2){
        printf("%d: ", j);
        printf("%c%d ", colunaaa(e->jogadas[i].jogador1.coluna), linhaaa(e->jogadas[i].jogador1.linha));
        putchar('\n');
    }
}

void numero_jogada(ESTADO *e, int numero){
    int i=0, cvazias= e-> num_jogadas;
    e-> tab[3][4]= PRETA;

    if(numero==0) {
        e->tab[3][4] = BRANCA;
        e->ultima_jogada.coluna = 4;
        e->ultima_jogada.linha = 3;
        for (; i < cvazias - 1; i++) {
            e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = VAZIO;
            e->tab[7 - e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna] = VAZIO;
        }
        if (i == cvazias - 1 && e->jogador_atual == 2) {
            e->tab[7 - e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna] = VAZIO;
            changePlayer(e);
        }
    }
    for(; i< numero -1; i++){
        e-> tab [7- e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna]= PRETA;
        e-> tab [7- e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna]= PRETA;
    }
    if (i== numero- 1){
        e-> tab [7- e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna]= PRETA;
        e-> tab [7- e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna]= BRANCA;
        e->ultima_jogada.coluna = e->jogadas[i].jogador2.coluna;
        e->ultima_jogada.linha = 7- e->jogadas[i].jogador2.linha;
    }
    i++;
    for(; i< cvazias -1; i++){
        e-> tab [7- e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna]= VAZIO;
        e-> tab [7- e->jogadas[i].jogador2.linha][e->jogadas[i].jogador2.coluna]= VAZIO;
    }
    if(i==cvazias -1 && e->jogador_atual== 2){
        e-> tab [7- e->jogadas[i].jogador1.linha][e->jogadas[i].jogador1.coluna]= VAZIO;
        changePlayer(e);
    }
    e->num_jogadas= numero +1;
}
/*
LISTA jogadaAleatoria(LISTA L){
    srand(time(NULL));
    int numJogada= 1+ (rand() % numElementos(L));
    for(; numJogada != 1; numJogada--){
        L= L-> proxCoord;
    }
    L->proxCoord= NULL;
    return L;
}

/*COORDENADA jogAleatoria(LISTA L, int num){
    for(; num!= 1; num--){
        L= L-> proxCoord;
    }
    //return (L->coord);
}
*/