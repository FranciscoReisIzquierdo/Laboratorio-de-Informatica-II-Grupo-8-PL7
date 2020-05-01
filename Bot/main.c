#include <stdio.h>
#include "C:\Users\franc\CLionProjects\ProjetoLI2/Camada de Dados.h"
#include "C:\Users\franc\CLionProjects\ProjetoLI2/Interface.h"
#include "C:\Users\franc\CLionProjects\ProjetoLI2/Logica.h"
#include "C:\Users\franc\CLionProjects\ProjetoLI2/Interface.h"
#include <stdlib.h>

int main(int argc, char *argv[ ]) {
    if(argc<2){exit(0);}
    ESTADO *e= inicializar_estado();
    le_Tabuleiro(e,argv[1]);
    jogar(e, mcts(e, vizinhasVazias(e)));
    guarda_tabuleiro(e, argv[2]);
    return 1;
}
