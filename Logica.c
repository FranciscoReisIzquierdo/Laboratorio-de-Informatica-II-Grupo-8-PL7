#include <time.h>
#include "Logica.h"
#include "Camada de Dados.h"
#include "ListasLigadas.h"
#define BUF_SIZE 1024


int jogar(ESTADO *e, COORDENADA c) {
            COORDENADA ultima = e->ultima_jogada;
            e->tab[7 - c.linha][c.coluna] = BRANCA;
            e->tab[ultima.linha][ultima.coluna] = PRETA;
            e->ultima_jogada.linha = 7- c.linha;
            e->ultima_jogada.coluna = c.coluna;
            incrJogada(e);
            changePlayer(e);
    return 1;
}

int jogadaValida(ESTADO *e, COORDENADA c) {
    int r=1;
    if (e-> tab [7- c.linha][c.coluna]== BRANCA) {
        putchar('\n');
        printf("Jogada invalida: a jogada e igual a casa atual\n");
        r=0;
    }
    else if ((7- c.linha) - giveUltLinha(e) > 1 || c.coluna - giveUltColuna(e) > 1 || (7- c.linha) - giveUltLinha(e) < -1 || c.coluna - giveUltColuna(e) < -1){
        putchar('\n');
        printf("Jogada fora do limite: a distancia maxima e de 1 casa\n");
        r=0;
    }
    else if(e-> tab [7- c.linha][c.coluna]== PRETA){
        putchar('\n');
        printf("Jogada invalida: A casa ja esta preenchida\n");
        r=0;
    }
    return r;
}

int jogoAcabou(ESTADO *e){
    COORDENADA branca= e->ultima_jogada;  int count= 0;
    if (e-> tab [7][0]== BRANCA){
        printf("Jogador 1 venceu o jogo! Parabens!\n");  return 1;
    }
    else if (e-> tab[0][7]== BRANCA){
        printf("Jogador 2 venceu o jogo! Parabens!\n");  return 1;
    }
    else if(branca.linha == 0 && branca.coluna== 0){
        for(int line= e->ultima_jogada.linha; line!= e->ultima_jogada.linha +2; line++) {
            for (int column = e->ultima_jogada.coluna; column != e->ultima_jogada.coluna + 2; column++) {
                if(e-> tab[line][column] == PRETA) count++;
                if(count== 3){  printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1; }
            }
        }
    }
    else if(branca.linha == 7 && branca.coluna== 7){
        for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +1; line++) {
            for (int column = e->ultima_jogada.coluna -1; column != e->ultima_jogada.coluna +1; column++) {
                if(e-> tab[line][column] == PRETA) count++;
                if(count== 3){  printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1; }
            }
        }
    }
    else if (branca.linha == 0){
        for(int line= e->ultima_jogada.linha; line!= e->ultima_jogada.linha +2; line++) {
            for (int column = e->ultima_jogada.coluna -1; column != e->ultima_jogada.coluna + 2; column++) {
                if(e-> tab[line][column] == PRETA) count++;
                if(count== 5){  printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1; }
            }
        }
    }
    else if (branca.linha == 7){
        for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +1; line++) {
            for (int column = e->ultima_jogada.coluna -1; column != e->ultima_jogada.coluna + 2; column++) {
                if(e-> tab[line][column] == PRETA) count++;
                if(count== 5){  printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1; }
            }
        }
    }
    else if (branca.coluna == 0){
        for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +2; line++) {
            for (int column = e->ultima_jogada.coluna; column != e->ultima_jogada.coluna + 2; column++) {
                if(e-> tab[line][column] == PRETA) count++;
                if(count== 5){  printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1; }
            }
        }
    }
    else if (branca.coluna == 7){
        for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +2; line++) {
            for (int column = e->ultima_jogada.coluna -1; column != e->ultima_jogada.coluna + 1; column++) {
                if(e-> tab[line][column] == PRETA) count++;
                if(count== 5){  printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1; }
            }
        }
    }
    else for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +2; line++) {
            for (int column = e->ultima_jogada.coluna - 1; column != e->ultima_jogada.coluna + 2; column++) {
                if (e->tab[line][column] == PRETA) count++;
                if (count == 8) {
                    printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1; }
            }
        }
    return 0;
}

LISTA vizinhasVazias(ESTADO *e) {
    LISTA vizinhasVazias = criar_lista();
    COORDENADA *casaVazia;  COORDENADA branca= e->ultima_jogada;

    if(branca.linha== 0 && branca.coluna== 0){
        for (int line = branca.linha; line != branca.linha + 1; line++) {
            for (int coluna = branca.coluna; coluna != branca.coluna + 2; coluna++) {
                if (e->tab[line][coluna] == VAZIO) {
                    casaVazia = (COORDENADA *) malloc(sizeof(COORDENADA));
                    casaVazia->linha = line; casaVazia->coluna = coluna;
                    vizinhasVazias = insere_cabeca(vizinhasVazias, casaVazia);
                }
            }
        }
    }
    else if(branca.linha== 7 && branca.coluna== 7){
        for (int line = branca.linha -1; line != branca.linha + 1; line++) {
            for (int coluna = branca.coluna - 1; coluna != branca.coluna + 1; coluna++) {
                if (e->tab[line][coluna] == VAZIO) {
                    casaVazia = (COORDENADA *) malloc(sizeof(COORDENADA));
                    casaVazia->linha = line; casaVazia->coluna = coluna;
                    vizinhasVazias = insere_cabeca(vizinhasVazias, casaVazia);
                }
            }
        }
    }

    else if(branca.linha== 0){
        for (int line = branca.linha; line != branca.linha + 2; line++) {
           for (int coluna = branca.coluna - 1; coluna != branca.coluna + 2; coluna++) {
               if (e->tab[line][coluna] == VAZIO) {
                   casaVazia = (COORDENADA *) malloc(sizeof(COORDENADA));
                   casaVazia->linha = line; casaVazia->coluna = coluna;
                   vizinhasVazias = insere_cabeca(vizinhasVazias, casaVazia);
               }
           }
       }
        return vizinhasVazias;
   }
    else if(branca.linha== 7) {
        for (int line = branca.linha -1; line != branca.linha + 1; line++) {
            for (int coluna = branca.coluna - 1; coluna != branca.coluna + 2; coluna++) {
                if (e->tab[line][coluna] == VAZIO) {
                    casaVazia = (COORDENADA *) malloc(sizeof(COORDENADA));
                    casaVazia->linha = line; casaVazia->coluna = coluna;
                    vizinhasVazias = insere_cabeca(vizinhasVazias, casaVazia);
                }
            }
        }
        return vizinhasVazias;
    }
    else if(branca.coluna== 0){
        for (int line = branca.linha -1; line != branca.linha + 2; line++) {
            for (int coluna = branca.coluna; coluna != branca.coluna + 2; coluna++) {
                if (e->tab[line][coluna] == VAZIO) {
                    casaVazia = (COORDENADA *) malloc(sizeof(COORDENADA));
                    casaVazia->linha = line; casaVazia->coluna = coluna;
                    vizinhasVazias = insere_cabeca(vizinhasVazias, casaVazia);
                }
            }
        }
        return vizinhasVazias;
    }
    else if(branca.coluna== 7){
        for (int line = branca.linha -1; line != branca.linha + 2; line++) {
            for (int coluna = branca.coluna -1; coluna != branca.coluna + 1; coluna++) {
                if (e->tab[line][coluna] == VAZIO) {
                    casaVazia = (COORDENADA *) malloc(sizeof(COORDENADA));
                    casaVazia->linha = line; casaVazia->coluna = coluna;
                    vizinhasVazias = insere_cabeca(vizinhasVazias, casaVazia);
                }
            }
        }
        return vizinhasVazias;
    }
    for (int line = branca.linha -1; line != branca.linha + 2; line++) {
        for (int coluna = branca.coluna -1; coluna != branca.coluna + 2; coluna++) {
            if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2){
                casaVazia = (COORDENADA *) malloc(sizeof(COORDENADA));
                casaVazia->linha = line; casaVazia->coluna = coluna;
                vizinhasVazias = insere_cabeca(vizinhasVazias, casaVazia);

            }
        }
    }
    return vizinhasVazias;
}

COORDENADA jogadaAleatoria(LISTA vizinhasVazias){
    srand(time(NULL));
    int numJogada= 1+ (rand() % numElementos(vizinhasVazias));
    for(; numJogada != 1; numJogada--){
        vizinhasVazias= vizinhasVazias-> proxCoord;
    }
    vizinhasVazias->proxCoord= NULL;
    void *aux; aux = vizinhasVazias-> valor;
    COORDENADA jogadaAl= *((COORDENADA *) aux);

    jogadaAl.linha++;
    jogadaAl.linha= 7- jogadaAl.linha +1;

    return jogadaAl;
}