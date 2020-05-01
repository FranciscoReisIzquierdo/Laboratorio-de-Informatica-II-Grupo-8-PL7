#include "../Projeto/Camada de Dados.h"
#include "../Projeto/Interface.h"
#include "../Projeto/Logica.h"
#include <stdlib.h>

int main(int argc, char *argv[ ]) {
    if (argc < 2) { exit(0); }
    ESTADO *e = inicializar_estado();
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");
    le_Tabuleiro(e, fin);
    COORDENADA c = mcts(e, vizinhas(e));
    guarda_jogada(e, c);
    jogar(e, c);
    if (jogoAcabou(e) == 1){
        mostrar_tabuleiro(e);
        exit(0);
    }
    else {
        guarda_tabuleiro(e, fout);
        return 1;
    }
}
