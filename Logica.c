#include "Logica.h"
#include "Camada de Dados.h"
#define BUF_SIZE 1024

int jogar(ESTADO *e, COORDENADA c) {
            COORDENADA ultima = e->ultima_jogada;
            e->tab[7 - c.linha][c.coluna] = BRANCA;
            e->tab[ultima.linha][ultima.coluna] = PRETA;
            e->ultima_jogada.linha = 7- c.linha;
            e->ultima_jogada.coluna = c.coluna;
            mostrar_tabuleiro(e);
            incrJogada(e);
            changePlayer(e);
    return 1;
}

int jogadaValida(ESTADO *e, COORDENADA c) {
    int r=1;
    if (e-> tab [7- c.linha][c.coluna]== BRANCA) {
        putchar('\n');
        printf("Jogada invalida: a jogada e igual a casa atual");
        r=0;
    }
    else if ((7- c.linha) - giveUltLinha(e) > 1 || c.coluna - giveUltColuna(e) > 1 || (7- c.linha) - giveUltLinha(e) < -1 || c.coluna - giveUltColuna(e) < -1){
        putchar('\n');
        printf("Jogada fora do limite: a distancia max e de 1 casa");
        r=0;
    }
    else if(e-> tab [7- c.linha][c.coluna]== PRETA){
        putchar('\n');
        printf("Jogada invalida: A casa ja esta preenchida");
        r=0;
    }
    return r;
}

int jogoAcabou(ESTADO *e, COORDENADA c){
    if (e-> tab [7][0]== BRANCA){
        printf("Jogador 1 venceu o jogo! Parabens!");
        return 1;
    }
    else if (e-> tab[0][7]== BRANCA){
        printf("Jogador 2 venceu o jogo! Parabens!");
        return 1;
    }

    else if (e-> tab [6- c.linha][c.coluna]== PRETA && e-> tab [6- c.linha][1+ c.coluna]== PRETA && e-> tab [6- c.linha][c.coluna -1]== PRETA && e-> tab [8- c.linha][c.coluna]== PRETA && e-> tab [8- c.linha][c.coluna -1]== PRETA && e-> tab [8- c.linha][c.coluna +1]== PRETA){
        printf("Jogador %d venceu o jogo! Parabens!", winner(e));
        return 1;
        }
    else if(e-> tab[6- c.linha][7]== PRETA && e-> tab[8- c.linha][7]== PRETA && e-> tab [7- c.linha][c.coluna-1]== PRETA){
        printf("Jogador %d venceu o jogo! Parabens!", winner(e));
        return 1;
    }
    else if(e-> tab[6- c.linha][0]== PRETA && e-> tab[8- c.linha][0]== PRETA && e-> tab [7- c.linha][c.coluna+1] == PRETA){
        printf("Jogador %d venceu o jogo! Parabens", winner(e));
        return 1;
    }
    else return 0;
}


