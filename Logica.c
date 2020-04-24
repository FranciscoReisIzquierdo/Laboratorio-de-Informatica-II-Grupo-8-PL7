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
        printf("Jogada fora do limite: a distancia max e de 1 casa\n");
        r=0;
    }
    else if(e-> tab [7- c.linha][c.coluna]== PRETA){
        putchar('\n');
        printf("Jogada invalida: A casa ja esta preenchida\n");
        r=0;
    }
    return r;
}

int jogadaValidaAux(ESTADO *e, COORDENADA c){
    int r=1;
    if (e-> tab [7- c.linha][c.coluna]== BRANCA) r=0;
    else if ((7- c.linha) - giveUltLinha(e) > 1 || c.coluna - giveUltColuna(e) > 1 || (7- c.linha) - giveUltLinha(e) < -1 || c.coluna - giveUltColuna(e) < -1) r=0;
    else if(e-> tab [7- c.linha][c.coluna]== PRETA) r=0;
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
    for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +2; line++) {
        for (int column = e->ultima_jogada.coluna -1; column != e->ultima_jogada.coluna + 2; column++) {
            if(e-> tab[line][column] == PRETA) count++;
        }
    }
    if((branca.linha == 0 || branca.linha == 7 || branca.coluna == 0 || branca.coluna == 7) && count == 5) {
        printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1;
    }
    else if(((branca.linha == 0 && branca.coluna == 0) || (branca.linha == 7 && branca.coluna == 7)) && count == 3){
        printf("Jogador %d venceu o jogo! Parabens!\n", winner(e));  return 1;
    }
    else if(count == 8){
        printf("Jogador %d venceu o jogo! Parabens!\n", winner(e));  return 1;
    }
    else return 0;
}


/*LISTA jogadasVal(ESTADO *e){
    LISTA L= criar_lista();
    COORDENADA ult; ult.linha= 7- e->ultima_jogada.linha; ult.coluna= e->ultima_jogada.coluna;
    COORDENADA a; a.coluna= ult.coluna +1; a.linha= ult.linha;
    COORDENADA b; b.coluna= ult.coluna -1; b.linha= ult.linha;
    COORDENADA c; c.coluna= ult.coluna; c.linha= ult.linha +1;
    COORDENADA d; d.coluna= ult.coluna +1; d.linha= ult.linha +1;
    COORDENADA f; f.coluna= ult.coluna -1; f.linha= ult.linha +1;
    COORDENADA g; g.coluna= ult.coluna; g.linha= ult.linha -1;
    COORDENADA h; h.coluna= ult.coluna +1; h.linha= ult.linha -1;
    COORDENADA i; i.coluna= ult.coluna -1; i.linha= ult.linha -1;

    if(ult.coluna== 0){
        if (e-> tab [ult.linha][ult.coluna +1]== VAZIO) L= insere_cabeca(L, a);
        if (e->tab[ult.linha +1][ult.coluna] == VAZIO) L = insere_cabeca(L, c);
        if (e->tab[ult.linha +1][ult.coluna +1] == VAZIO) L = insere_cabeca(L, d);
        if (e->tab[ult.linha -1][ult.coluna] == VAZIO) L = insere_cabeca(L, g);
        if (e->tab[ult.linha -1][ult.coluna +1] == VAZIO) L = insere_cabeca(L, h);
    }
    else if(ult.coluna== 7){
        if (e-> tab [ult.linha][ult.coluna -1]== VAZIO) L= insere_cabeca(L, b);
        if (e->tab[ult.linha +1][ult.coluna] == VAZIO) L = insere_cabeca(L, c);
        if (e->tab[ult.linha +1][ult.coluna -1] == VAZIO) L = insere_cabeca(L, f);
        if (e->tab[ult.linha -1][ult.coluna] == VAZIO) L = insere_cabeca(L, g);
        if (e->tab[ult.linha -1][ult.coluna -1] == VAZIO) L = insere_cabeca(L, i);
    }
    else if(ult.linha == 0){
        if (e-> tab [ult.linha][ult.coluna +1]== VAZIO) L= insere_cabeca(L, a);
        if (e->tab[ult.linha][ult.coluna -1] == VAZIO) L = insere_cabeca(L, b);
        if (e->tab[ult.linha +1][ult.coluna] == VAZIO) L = insere_cabeca(L, c);
        if (e->tab[ult.linha +1][ult.coluna +1] == VAZIO) L = insere_cabeca(L, d);
        if (e->tab[ult.linha +1][ult.coluna -1] == VAZIO) L = insere_cabeca(L, f);
    }
    else if(ult.linha == 7){
        if (e->tab[ult.linha][ult.coluna +1] == VAZIO) L = insere_cabeca(L, a);
        if (e->tab[ult.linha][ult.coluna -1] == VAZIO) L = insere_cabeca(L, b);
        if (e->tab[ult.linha -1][ult.coluna] == VAZIO) L = insere_cabeca(L, g);
        if (e->tab[ult.linha -1][ult.coluna +1] == VAZIO) L = insere_cabeca(L, h);
        if (e->tab[ult.linha -1][ult.coluna -1] == VAZIO) L = insere_cabeca(L, i);
    }
    else {
        if (e->tab[ult.linha][ult.coluna + 1] == VAZIO) L = insere_cabeca(L, a);
        if (e->tab[ult.linha][ult.coluna - 1] == VAZIO) L = insere_cabeca(L, b);
        if (e->tab[ult.linha +1][ult.coluna] == VAZIO) L = insere_cabeca(L, c);
        if (e->tab[ult.linha + 1][ult.coluna + 1] == VAZIO) L = insere_cabeca(L, d);
        if (e->tab[ult.linha + 1][ult.coluna - 1] == VAZIO) L = insere_cabeca(L, f);
        if (e->tab[ult.linha - 1][ult.coluna] == VAZIO) L = insere_cabeca(L, g);
        if (e->tab[ult.linha - 1][ult.coluna + 1] == VAZIO) L = insere_cabeca(L, h);
        if (e->tab[ult.linha - 1][ult.coluna - 1] == VAZIO) L = insere_cabeca(L, i);
    }
    return L;
}*/

COORDENADA jogadaAleatoria(ESTADO *e) {
    LISTA vizinhasVazias = criar_lista();
    COORDENADA *casaVazia;
    /*for(int line= branca.linha -1; line!= branca.linha +2; line++){
        for(int column= branca.coluna -1; column!= branca.coluna +2; column++){
            //branca.linha= line;  branca.coluna= column;
            if(e-> tab[line][column] == PRETA) num++; //insere_cabeca(VizinhasVazias, &branca);
        }
    }*/
/*
    COORDENADA pos1;
    pos1.linha = e->ultima_jogada.linha - 1; pos1.coluna = e->ultima_jogada.coluna - 1;
    COORDENADA pos2;
    pos2.linha = e->ultima_jogada.linha - 1; pos2.coluna = e->ultima_jogada.coluna;
    COORDENADA pos3;
    pos3.linha = e->ultima_jogada.linha - 1; pos3.coluna = e->ultima_jogada.coluna + 1;
    COORDENADA pos4;
    pos4.linha = e->ultima_jogada.linha; pos4.coluna = e->ultima_jogada.coluna - 1;
    COORDENADA pos5;
    pos5.linha = e->ultima_jogada.linha; pos5.coluna = e->ultima_jogada.coluna + 1;
    COORDENADA pos6;
    pos6.linha = e->ultima_jogada.linha + 1; pos6.coluna = e->ultima_jogada.coluna - 1;
    COORDENADA pos7;
    pos7.linha = e->ultima_jogada.linha + 1; pos7.coluna = e->ultima_jogada.coluna;
    COORDENADA pos8;
    pos8.linha = e->ultima_jogada.linha + 1; pos8.coluna = e->ultima_jogada.coluna + 1;

    int line = e->ultima_jogada.linha - 1;
    int coluna = e->ultima_jogada.coluna - 1;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos1.coluna, pos1.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos1);
    }
    coluna++;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos2.coluna, pos2.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos2);
    }
    coluna++;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos3.coluna, pos3.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos3);
    }
    coluna = e->ultima_jogada.coluna - 1;
    line++;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos4.coluna, pos4.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos4);
    }
    coluna = coluna + 2;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos5.coluna, pos5.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos5);
    }
    coluna = e->ultima_jogada.coluna - 1;
    line++;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos6.coluna, pos6.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos6);
    }
    coluna++;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos7.coluna, pos7.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos7);
    }
    coluna++;

    if (e->tab[line][coluna] == VAZIO || e->tab[line][coluna] == POS1 || e->tab[line][coluna] == POS2) {
        printf("CASA VAZIA: %d%d ", pos8.coluna, pos8.linha);  vizinhasVazias = insere_cabeca(vizinhasVazias, &pos8);
    }
    */
    for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +2; line++) {
        for (int coluna = e->ultima_jogada.coluna -1; coluna != e->ultima_jogada.coluna +2; coluna++) {
            if (e->tab[line][coluna] == VAZIO){
                casaVazia= (COORDENADA *) malloc(sizeof(COORDENADA));

                casaVazia->linha= line; casaVazia->coluna= coluna;  printf("CASA VAZIA: %d%d ", casaVazia->coluna, casaVazia->linha);

                vizinhasVazias= insere_cabeca(vizinhasVazias, casaVazia);

                putchar('\n');
            }
        }
    }
    srand(time(NULL));
    int numJogada= 1+ (rand() % numElementos(vizinhasVazias));
    for(; numJogada != 1; numJogada--){
        vizinhasVazias= vizinhasVazias-> proxCoord;
    }
    vizinhasVazias->proxCoord= NULL;
    void *aux; aux = vizinhasVazias-> coord;
    COORDENADA jogadaAl= *((COORDENADA *) aux);

    printf("%d%d\n ", jogadaAl.coluna, jogadaAl.linha++);
    jogadaAl.linha= 7- jogadaAl.linha +1; printf("%d\n", jogadaAl.linha);

    return jogadaAl;
}



//COORDENADA jogadaAleatoria(LISTA vizinhasVazias){


/*int vazia(ESTADO *e){
    LISTA J= brancasVizinhas(e);
    COORDENADA a; a.linha= 2; a.coluna= 3; LISTA H= NULL;
    COORDENADA b; b.linha= 7; b.coluna= 7; int num= 2; int tt= 1;
    while(num!= 0) {
        while (tt != 0) {
            H = insere_cabeca(H, &a);
            a=b;
            COORDENADA *rr= &a;
            H = insere_cabeca(H, rr);
            tt--;
        }
        num--;
    }
    showLista(J);
    return 0;
}
*/

