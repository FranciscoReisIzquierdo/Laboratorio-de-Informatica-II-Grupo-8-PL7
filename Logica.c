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
    int r=1; COORDENADA ultima= e->ultima_jogada;
    if (ultima.linha== 7- c.linha && ultima.coluna== c.coluna) {
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
    else if (e-> tab[0][7]== BRANCA) {
        printf("Jogador 2 venceu o jogo! Parabens!\n"); return 1;
    }
    else for(int line= e->ultima_jogada.linha -1; line!= e->ultima_jogada.linha +2; line++) {
            for (int column = e->ultima_jogada.coluna - 1; column != e->ultima_jogada.coluna + 2; column++) {
                if (e->tab[line][column] == PRETA && (line >= 0 && line < 8) && (column >= 0 && column < 8))
                    count++;
            }
        }
    if(((branca.linha == 0 && branca.coluna== 0) || (branca.linha== 7 && branca.coluna== 7)) && count== 3){
        printf("Jogador %d venceu o jogo! Parabens!\n", winner(e)); return 1;
    }
    else if((branca.linha== 0 || branca.linha== 7 || branca.coluna== 0 || branca.coluna== 7) && count== 5) {
        printf("Jogador %d venceu o jogo! Parabens!\n", winner(e));
        return 1;
    }
    else if(count== 8) {
        printf("Jogador %d venceu o jogo! Parabens!\n", winner(e));
        return 1;
    }
    else return 0;
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

int mcts(ESTADO *e, LISTA vizinhasVazias){
    while(lista_esta_vazia(vizinhasVazias)) {
        COORDENADA jogadaPossivel = *((COORDENADA *) vizinhasVazias->valor);
        printf("%d%d\n", jogadaPossivel.coluna, jogadaPossivel.linha);
        if(jogoAcabouMCTS(e, jogadaPossivel)== 8){
            printf("Escolha a coordenada: %d%d\n", jogadaPossivel.coluna, jogadaPossivel.linha);
            return 0;
        }
        verificaErro(e,jogadaPossivel);
        vizinhasVazias = vizinhasVazias->proxCoord;
    }
        /*
        COORDENADA jogadaPossivel= *((COORDENADA *) vizinhasVazias-> valor);
        if(jogoAcabouMCTS(e, jogadaPossivel)== 8) {
        printf("Escolha a coordenada:%d%d\n", jogadaPossivel.coluna, jogadaPossivel.linha);
        return 0;
        }
        verificaErro(e, jogadaPossivel);
        //jogadaPerdeMCTS(e, jogadaPossivel);
        vizinhasVazias= vizinhasVazias-> proxCoord;
        }**/
        return 1;
}

int jogoAcabouMCTS(ESTADO *e, COORDENADA c){
    int count= 0; e->tab [e->ultima_jogada.linha][e->ultima_jogada.coluna]= PRETA;
    for(int line= c.linha -1; line!= c.linha +2; line++) {
        for (int column = c.coluna - 1; column != c.coluna + 2; column++) {
            if (e->tab[line][column] == PRETA)  count++;
        }
    }
    e->tab [e->ultima_jogada.linha][e->ultima_jogada.coluna]= BRANCA;
    return count;
}
/*
int jogadaPerdeMCTS(ESTADO *e, COORDENADA c){
    COORDENADA save= e->ultima_jogada;
    e->tab [e->ultima_jogada.linha][e->ultima_jogada.coluna]= PRETA; e->ultima_jogada= c;

    LISTA temporaria= vizinhasVazias(e);
    while(lista_esta_vazia(temporaria)){
        COORDENADA jogadaPossivel= *((COORDENADA *) temporaria-> valor);
        if(jogoAcabouMCTS(e, jogadaPossivel)== 7) {
            printf("Nao escolha as coordenadas:%d%d\n", c.coluna, c.linha);
        }
        temporaria= temporaria-> proxCoord;
    }
    e->tab [c.linha][c.coluna]= VAZIO;
    e->ultima_jogada= save;
    return 1;
}

int jogadasVazias(ESTADO *e, COORDENADA c){
    int count= 0;
    for(int line= c.linha -1; line!= c.linha +2; line++) {
        for (int column = c.coluna - 1; column != c.coluna + 2; column++) {
            if (e->tab[line][column] == PRETA)count++;
        }
    }
    return count;
}*/

int verificaErro(ESTADO *e, COORDENADA temp){
        COORDENADA save= e->ultima_jogada;
        e->tab [e->ultima_jogada.linha][e->ultima_jogada.coluna]= PRETA;
        e->tab [temp.linha][temp.coluna]= BRANCA;
        e->ultima_jogada= temp;

        LISTA temporaria= vizinhasVazias(e);
        while(lista_esta_vazia(temporaria)){
            COORDENADA jogadaPossivel= *((COORDENADA *) temporaria-> valor);
            if(jogoAcabouMCTS(e, jogadaPossivel)== 8) printf("Nao escolha a coordenada: %d%d\n", temp.coluna, temp.linha);
            temporaria= temporaria-> proxCoord;
        }
        e->tab [e->ultima_jogada.linha][e->ultima_jogada.coluna]= VAZIO;
        e->ultima_jogada= save;
        return 1;
}
