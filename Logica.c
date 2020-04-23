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
    for(int line= branca.linha -1; line!= branca.linha +2; line++){
        for(int column= branca.coluna -1; column!= branca.coluna +2; column++){
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

LISTA brancasVizinhas(ESTADO *e){
    COORDENADA a; a.linha= 2; a.coluna= 2;
    COORDENADA b; b.linha= 3; b.coluna= 3;
    COORDENADA branca= e-> ultima_jogada; LISTA VizinhasVazias= criar_lista();

    /*for(int line= branca.linha -1; line!= branca.linha +2; line++){
        for(int column= branca.coluna -1; column!= branca.coluna +2; column++){
            branca.linha= line;  branca.coluna= column;
            if(e-> tab[line][column] == VAZIO) insere_cabeca(VizinhasVazias, &branca);
        }
    }*/
    insere_cabeca(VizinhasVazias, &a);
    insere_cabeca(VizinhasVazias, &b);
    return VizinhasVazias;
}


