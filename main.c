#include <stdio.h>
#include "Logica.h"
#include "ListasLigadas.h"



int main() {
    ESTADO *e = inicializar_estado();
    prompt(e);
    /*FILE * file;
    file = fopen("C:\\Users\\franc\\CLionProjects\\ProjetoLI2\\Tabuleiro.txt", "r+");
    le_Tabuleiro(e,file);
    mostrar_tabuleiro(e);*/
}

/*
COORDENADA z;
    z.coluna= 2;
    z.linha= 7;
    COORDENADA n; n.coluna= 8; n.linha=5;
    COORDENADA m; m.coluna= 1; m.linha= 4;
    COORDENADA y; y.coluna= 6; y.linha= 6;
    LISTA L;
    L= malloc(sizeof(NodoLista));
    L-> coord= n;
    L-> proxCoord = malloc(sizeof(NodoLista));
    L-> proxCoord-> coord = m;
    L-> proxCoord-> proxCoord = malloc(sizeof(NodoLista));
    L-> proxCoord-> proxCoord-> coord  = y;
    L-> proxCoord-> proxCoord-> proxCoord = NULL;
    showLista(L);
    printf("\n");
   showLista(remove_cabeca(L));

   void showLista(LISTA L){
    printf("Lista: ");
    while(L!=NULL){
        printf("%d%d ", L->coord);
        L= L->proxCoord;
    }
}*/