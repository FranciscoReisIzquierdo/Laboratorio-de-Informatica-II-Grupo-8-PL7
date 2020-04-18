#include "ListasLigadas.h"
#include <stdlib.h>
#include <stdio.h>

LISTA criar_lista(){
    LISTA l= NULL;
    return l;
}

LISTA insere_cabeca(LISTA L, COORDENADA coord){
    if(L== NULL){
        LISTA l= malloc(sizeof(NodoLista));
        l->coord= coord;
        l->proxCoord= NULL;
        L= l;
    }
    else {
        LISTA aux = L;
        LISTA l = malloc(sizeof(NodoLista));
        l->coord = coord;
        l->proxCoord = aux;
        L = l;
    }
    return L;
}

void *devolve_cabeca(LISTA L){
    if(L == NULL) return NULL;
    else return &(L-> coord);
}

LISTA proximo(LISTA L){
    if(L== NULL) return EXIT_SUCCESS;
    L= L->proxCoord;
    return L;
}

LISTA remove_cabeca(LISTA L){
    if(L== NULL) return EXIT_SUCCESS;
    L= L->proxCoord;
    //free(&(L->coord));
    return L;
}

int lista_esta_vazia(LISTA L){
    if(L== NULL) return 0;
    else return 1;
}

int numElementos(LISTA L){
    int num= 0;
    while(lista_esta_vazia(L)!= 0){
        num++;
        L= L->proxCoord;
    }
    return num;
}

void showLista(LISTA L){
    printf("\nLista: ");
    while(L!=NULL){
        printf("%c%d ", colunaaa(L->coord.coluna), linhaaa(L->coord.linha) -1);
        L= L->proxCoord;
    }
}
